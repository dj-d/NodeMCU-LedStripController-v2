# NodeMCU-LedStrip-v2
NodeMCU sketch to control led strip

### Using

- To connect the device to the network visit: __[tzapu/WiFIManager](https://github.com/tzapu/WiFiManager)__
- Call API use a __POST__ request and use __JSON__ for the data.
  - Example
    - API:
        | Command | Description |
        | --- | --- |
        | / | To start the action described in the body |
        | /status | To receive the status of the colors |
    - JSON body to send:
       ```json
         {
           "red": 100,
           "green": 200,
           "blue": 50
         }
       ```
    -JSON body received following the request /status:
       ```json
         {
           "red": 40,
           "green": 20,
           "blue": 250
         }
       ```

### Development
- [ ] Button to reset wifi


