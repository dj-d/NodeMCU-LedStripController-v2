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
    - Body of JSON:
       ```json
         {
           "red": 100,
           "green": 200,
           "blue": 50
         }
       ```

### Development
- [ ] Button to reset wifi


