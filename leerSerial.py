import serial 
import time
import os

# set up the serial line
ser = serial.Serial('/dev/ttyACM0', 9600)

# COM4: windows
# /dev/ttyACM0: ubuntu

#time.sleep(2)

volumen = 0
while(True):
    b = ser.readline()         # read a byte string
    string_n = b.decode()  # decode byte string into Unicode  
    string = string_n.rstrip()
    #print(string)
    if string == "FFA857": # subir volumen
        volumen += 5
        os.system("./SetVol.exe +3")
        print("subiendo volumen")
        

    if string == "FFE01F":
        volumen -= 5
        os.system("./SetVol.exe -3")
        print("bajando volumen")
        

    