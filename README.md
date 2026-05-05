# HeatedHumidification2026
# Data Acquisition Code for:
## *Impact of Power Disruptions on Heated Humidification During Infant Respiratory Support*

**Author:** Kenneth Uy  
**Date:** May 4, 2026  
**License:** MIT License  

---

## Overview
This repository contains a Python script used to collect real-time temperature and relative humidity (RH) data from a DHT22 sensor during experimental evaluation of heated humidification in infant respiratory support systems.

The code supports the study:

> **Impact of Power Disruptions on Heated Humidification During Infant Respiratory Support**  
> Uy K, Jacob S, Floersch J, Slusher T, Wu A, Fischer G, Bjorklund A, John S

This study investigates how power outages of varying durations affect delivered relative humidity in a bubble CPAP (bCPAP) system using a simulated infant lung model.

---

## Experimental Context
- **System:** Fisher & Paykel FP850 heated humidifier with bCPAP circuit  
- **Model:** Simulated infant lung (latex balloon) in incubator  
- **Sensor:** DHT22 (temperature and relative humidity sensor)
- **Interface:** Arduino Uno (serial communication)
- **Measured Variable:** Relative humidity (RH) over time

This script was used specifically for **automated, high-frequency data collection** during extended experiments, including:
- Indefinite power outage simulations (multi-hour to multi-day)
- Continuous RH monitoring at ~5-second intervals

---

## Repository Contents
- `DHT22SerialMonitorCollect.py`  
  Python script for serial data acquisition and logging  

- `dht_data_log.txt`  
  Example output file containing timestamped RH and temperature data  

---

## How the Script Works
The script:
1. Connects to a serial port receiving data from an Arduino
2. Reads incoming DHT22 sensor data
3. Appends a timestamp to each reading
4. Writes the data to a log file in real time

Example:
2025-01-28 16:28:22,5.30,34.10

- Date = YYYY-MM-DD
- Time = HH:MM:SS
- RH = Relative Humidity (%)  
- Temperature = °C  

---

## Requirements
- Python 3.x  
- Required package:
  - `pyserial`

Install dependency:
```bash
pip install pyserial
