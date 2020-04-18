# NodeMCU-LedStripController-v2
NodeMCU sketch to control led strip

### Using

- To connect the device to the network visit: __[tzapu/WiFIManager](https://github.com/tzapu/WiFiManager)__
- Call API use a __POST__ request and use __JSON__ for the data.
  - Example
    - API:
        | Command | Description |
        | --- | --- |
        | /rgb | To start the action described in the body |
        | /rgb/status | To receive the status of the colors |
        | /ps | To start the action described in the body |
        | /ps/status | To receive the status of the colors |
    - JSON body to send for rgb:
       ```json
         {
           "red": 100,
           "green": 200,
           "blue": 50
         }
       ```
    - JSON body to send for relay:
      - Turn on:
        ```json
          {
            "action": "on",
            "pin": 1
          }
        ```
      - Turn off:
        ```json
          {
            "action": "off",
            "pin": 2
          }
        ```
    - JSON body received following the request /rgb/status:
       ```json
         {
           "red": 40,
           "green": 20,
           "blue": 250
         }
       ```
    - JSON body received following the request /ps/status (with 4 relay):
       ```json
         {
           "relay_1": false,
           "relay_2": true,
           "relay_3": true,
           "relay_4": false
         }
       ```
      
      * _true indicates that the relay is turned on, false indicates that the relay is turned off_

### Development
- [ ] Button to reset wifi

### Notes
_This branch is a combination of the master branch plus the [dj-d/NodeMCU-SmartPowerStrip-v2](https://github.com/dj-d/NodeMCU-SmartPowerStrip-v2) repository in order to divide a single LED strip into multiple sections and to control them individually (this is my specific case)_