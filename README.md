# NodeMCU-LedStripController-v2
NodeMCU sketch to control led strip

## Using

- To connect the device to the network visit: __[tzapu/WiFIManager](https://github.com/tzapu/WiFiManager)__

- __API__

  | Description | Method | Endpoint | Body elements |
  | --- | --- | --- | --- |
  | To start the action described in the body| __POST__ | /rgb | "*__red__*", "*__green__*" and "*__blue__*" |
  | To receive the status of the colors | __GET__ | /rgb/status | - |

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

## Development
- [ ] Button to reset wifi