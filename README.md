# NodeMCU-LedStripController-v2
NodeMCU sketch to control led strip

## Using

- To connect the device to the network visit: __[tzapu/WiFIManager](https://github.com/tzapu/WiFiManager)__

- __API__

  | Description | Method | Endpoint | Body elements |
  | --- | --- | --- | --- |
  | To start the action described in the body| __POST__ | /rgb | "*__red__*", "*__green__*" and "*__blue__*" |
  | To receive the status of the colors | __GET__ | /rgb/status | - |
  | To start the action described in the body | __POST__ | /ps | "*__action__*" and "*__pin__*" |
  | To receive the status of the relays | __GET__ | /ps/status | - |
  | To receive the number of the relays | __GET__ | /ps/get_relay_number | - |

- __Supported actions__

    | Action | Description |
    | --- | --- |
    | *on* | Turn on relay |
    | *off* | Turn off relay |

- __Examples__

  - Request body for "*__/rgb__*":
    ```json
        {
          "red": 120,
          "green": 250,
          "blue": 40
        }
    ```

  - Response body for "*__/rgb__*":
    ```json
        {
          "msg": "SOME_MESSAGE"
        }
    ```

  - Response body for "*__/rgb/status__*":
    ```json
        {
          "red": 120,
          "green": 250,
          "blue": 40
        }
    ```
  
  - Request body for "*__/ps__*":
    ```json
        {
          "action": "YOUT_ACTION",
          "pin": 2
        }
    ```

  - Response body for "*__/ps__*":
    ```json
        {
          "msg": "SOME_MESSAGE"
        }
    ```
  
  - Response body for "*__/ps/status__*":
    ```json
        {
          "relay_1": false,
          "relay_2": true,
          "relay_3": true,
          "relay_4": false
        }
    ```
    * ___true__ indicates that the relay is turned on, __false__ indicates that the relay is turned off_

  - Response body for "*__/ps/get_relay_number__*":
    ```json
        {
          "number": 4
        }
    ```

## Development

- [ ] Button to reset wifi

## Note
*This branch is a combination of the master branch plus the [dj-d/NodeMCU-SmartPowerStrip-v2](https://github.com/dj-d/NodeMCU-SmartPowerStrip-v2) repository in order to divide a single LED strip into multiple sections and to control them individually (this is my specific case)*