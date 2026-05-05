import serial
import time

# Set the serial port and baud rate
serial_port = 'COM4'  # Replace with your Arduino's port (e.g., COM3, /dev/ttyUSB0)
baud_rate = 9600
output_file = "dht_data_log.txt"

# Open the serial port
with serial.Serial(serial_port, baud_rate, timeout=1) as ser, open(output_file, "a") as log:
    print(f"Logging data to {output_file}. Press Ctrl+C to stop.")
    try:
        while True:
            # Read a line of data from the serial port
            line = ser.readline().decode('utf-8').strip()
            if line:
                print(line)  # Display data in the terminal
                log.write(f"{time.strftime('%Y-%m-%d %H:%M:%S,')}{line}\n")  # Log data with timestamp and date
                log.flush()  # Force save data to file
    except KeyboardInterrupt:
        print("Logging stopped.")