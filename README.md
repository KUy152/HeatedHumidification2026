# Data Acquisition Code for:
## Impact of Power Disruptions on Heated Humidification During Infant Respiratory Support

Author: Kenneth Uy
Date: May 4, 2026
License: MIT License

--------------------------------------------------

OVERVIEW
This repository contains the code used to collect real-time temperature and relative humidity (RH) data during experimental evaluation of heated humidification in infant respiratory support systems.

The code supports the study:

Impact of Power Disruptions on Heated Humidification During Infant Respiratory Support
Uy K, Jacob S, Floersch J, Slusher T, Wu A, Fischer G, Bjorklund A, John S

This study investigates how power outages of varying durations affect delivered relative humidity in a bubble CPAP (bCPAP) system using a simulated infant lung model.

--------------------------------------------------

SYSTEM WORKFLOW
DHT22 Sensor → Arduino → Serial (USB) → Python Script → Log File

1. The DHT22 sensor measures temperature and relative humidity
2. The Arduino reads sensor data and transmits it via serial communication
3. The Python script reads serial data from the Arduino
4. Data are timestamped and saved to a log file for analysis

--------------------------------------------------

REPOSITORY CONTENTS
- DHT22SerialMonitorCollect.py
  Python script for serial data acquisition and logging

- DHT22SerialMonitorCollect/DHT22SerialMonitorCollect.ino
  Arduino script for reading DHT22 sensor data and sending it via serial

- dht_data_log.txt
  Example output file containing timestamped RH and temperature data

--------------------------------------------------

ARDUINO SETUP

Requirements:
- Arduino board (e.g., Arduino Uno)
- DHT22 temperature and humidity sensor
- Arduino IDE
- DHT sensor library

Library Installation:
Install the DHT sensor library in the Arduino IDE before uploading the code.

Upload Instructions:
1. Open the .ino file in the Arduino IDE
2. Select the correct board and port
3. Upload the script to the Arduino

Serial Output Format:
<humidity>,<temperature>

Example:
47.70,27.60

Note:
- Time and date data is outputted by Python code.

--------------------------------------------------

PYTHON SETUP

Requirements:
- Python 3.x
- pyserial

Install dependency:
pip install pyserial

--------------------------------------------------

USAGE

1. Clone repository:
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name

2. Configure serial port in Python script:
serial_port = 'COM4'

3. Run the script:
python DHT22SerialMonitorCollect.py

4. Stop data collection:
Press Ctrl + C

--------------------------------------------------

OUTPUT FORMAT
YYYY-MM-DD HH:MM:SS,<RH>,<Temperature>

Example:
2024-12-20 17:38:06,47.70,27.60

--------------------------------------------------

ROLE IN STUDY
This code was used to:
- Collect continuous RH measurements during simulated power outages
- Capture transient and steady-state humidity behavior
- Enable long-duration experiments

--------------------------------------------------

REPRODUCIBILITY NOTES
- Use a DHT22 sensor inside the simulated lung
- Maintain ~5-second sampling intervals
- Match flow rates (3, 6, 9 LPM) and pressure (5 cm H2O)

--------------------------------------------------

LIMITATIONS
- Assumes properly formatted serial input
- No error handling for malformed data
- Serial port must be manually configured

--------------------------------------------------

CITATION
Uy K. Data Acquisition Code for: Impact of Power Disruptions on Heated Humidification During Infant Respiratory Support.
GitHub. 2026.

--------------------------------------------------

LICENSE
MIT License
