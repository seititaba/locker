import sys
import serial
import time

try:
    com = serial.Serial(sys.argv[1], 9600) 
    time.sleep(1)  
except:
    print("Error COM")
    exit()

if(len(sys.argv) == 4):
    if(sys.argv[2] == "logo"):
        if(sys.argv[3] == "on"):
            com.write('1'.encode('utf-8'))
        elif(sys.argv[3] == "off"):
            com.write("2".encode('utf-8'))
    if(sys.argv[2] == "room"):
        if(sys.argv[3] == "on"):
            com.write("3".encode('utf-8'))
        elif(sys.argv[3] == "off"):
            com.write("4".encode('utf-8'))
    if(sys.argv[2] == "entry"):
        if(sys.argv[3] == "on"):
            com.write('5'.encode('utf-8'))
        elif(sys.argv[3] == "off"):
            com.write("6".encode('utf-8'))
    if(sys.argv[2] == "exit"):
        if(sys.argv[3] == "on"):
            com.write("7".encode('utf-8'))
        elif(sys.argv[3] == "off"):
            com.write("8".encode('utf-8'))
else:
    print("Wrong number of args")

com.flush()