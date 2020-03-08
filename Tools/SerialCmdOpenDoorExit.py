import serial
import time

com = serial.Serial("/dev/ttyUSB0", 9600)

time.sleep(1)
print(com)
#com.flush()
print(com.write("3".encode('utf-8')))
#com.flush()

com.close()