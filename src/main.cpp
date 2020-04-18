#ifndef UNIT_TEST

#include <Arduino.h>

#endif

#include <DNSServer.h>
#include <WiFiManager.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <ArduinoJson.h>

// TODO: Make button to reset wifi

/*********************************************************************/

ESP8266WebServer server(80);

/*********************************************************************/

const int red_pin = 0;
const int green_pin = 5;
const int blue_pin = 4;

int color[] = {0, 0, 0};

/*********************************************************************/

/**
 * Send response
 * 
 * @param html_code HTML status code
 * @param message 
 */
void sendResponse(int html_code, String message) {
    String body;
    DynamicJsonDocument raw_body(1024);

    raw_body["msg"] = message;

    serializeJson(raw_body, body);

    server.send(html_code, "text/json", body);
}

/*********************************************************************/

/**
 * Check if the value received for the color is correct
 * 
 * @param value color value
 * @return "true" if is correct | "false" if is incorrect
 */
bool is_valid_color_value(int value) {
    if (value >= 0 && value <= 255) {
        return true;
    }
    return false;
}

/**
 * Size of color array
 * 
 * @return number of element in array
 */
int get_color_size() {
    return sizeof(color) / sizeof(color[0]);
}

/**
 * Set all colors to 0
 */
void reset_color() {
    analogWrite(red_pin, 0);
    analogWrite(green_pin, 0);
    analogWrite(blue_pin, 0);

    for (int i = 0; i < get_color_size(); i++) {
        color[i] = 0;
    }
}

/**
 * Initialization of rgb pins
 */
void init_rgb() {
    pinMode(red_pin, OUTPUT);
    pinMode(green_pin, OUTPUT);
    pinMode(blue_pin, OUTPUT);

    reset_color();
}

/**
 * Set the color of the leds
 * 
 * @param red_input red value
 * @param green_input green value
 * @param blue_input blue value
 */
void set_color(int red, int green, int blue) {
    analogWrite(red_pin, red);
    analogWrite(green_pin, green);
    analogWrite(blue_pin, blue);

    color[0] = red;
    color[1] = green;
    color[2] = blue;
}

/*********************************************************************/

/**
 * Receives the value of the colors and sets them
 */
void checkArgs() {
    int html_code;
    String message = "";

    DynamicJsonDocument color(1024);

    if (server.hasArg("plain") == false) {
        html_code = 400;
        message = "Body not found";
    } else {
        deserializeJson(color, server.arg("plain"));
        
        int red = color["red"];
        int green = color["greeb"];
        int blue = color["blue"];

        if (!is_valid_color_value(red) || !is_valid_color_value(green) || !is_valid_color_value(blue)) {
            html_code = 400;
            message = "Color value not found";
        } else {
            html_code = 200;
            message = "Successful action";

            set_color(red, green, blue);
        }
    }

    sendResponse(html_code, message);
}

/*********************************************************************/

/**
 * Send the status of colors
 */
void getStatus() {
    int html_code = 200;
    String status;
    DynamicJsonDocument doc(1024);

    doc["red"] = color[0];
    doc["green"] = color[1];
    doc["blue"] = color[2];

    serializeJson(doc, status);

    sendResponse(html_code, status);
}

/*********************************************************************/

void setup() {
    Serial.begin(9600);

    init_rgb();

    // WiFiManager
    WiFiManager wifiManager;

    // Reset settings - for testing
    // wifiManager.resetSettings();

    wifiManager.setTimeout(180);
    wifiManager.setHostname("ESP_LedStrip");

    if (!wifiManager.autoConnect("ESP_LedStrip - Access Poinit")) {
        Serial.println("Failed to connect and hit timeout");
        delay(3000);

        ESP.reset();
        delay(5000);
    }

    Serial.println("Connected");

    server.on("/rgb", checkArgs);
    server.on("/rgb/status", getStatus);

    server.begin();
}

void loop() {
    server.handleClient();
}