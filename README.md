# Automatic Water Dispenser using Arduino UNO
This repository consists of the details for an **Automatic Water Dispenser Project**.

## Working
The working is based on a simple mechanism:
1. The Water Dispenser would have a **[PIR sensor](https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor)** installed.
2. As soon as the PIR sensor would detect hand movement under its range, it would rotate the servo motor, enabling the water to fall.
3. After a *1 second delay*, if movement is not detected again, the servo motor would rotate back to its original position; hence stopping the flow of water.



> To view the circuit simulation design of this project, Click on the below image.
<a href="https://www.tinkercad.com/things/25j5h8029Og" target='blank'>
  <img src="https://user-images.githubusercontent.com/97667653/198984585-1d7c08d7-8f4b-4185-b751-3e75d70e1b65.png" alt="circuit simulation image">
</a>
