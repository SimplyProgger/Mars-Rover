import smbus
import time
import os

bus = smbus.SMBus(1)
SLAVE_ADDRESS = 0x04

def request_reading():
    reading = int(bus.read_byte(SLAVE_ADDRESS))
    print(reading)

while True:
    command = raw_input("Enter command: 1 - Включить лампочку, r - измерить температуру")
    if command == '1':
        bus.write_byte(SLAVE_ADDRESS,ord('1'))
    elif command == 'r':
        request_reading()