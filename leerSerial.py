import serial 
import time
import os

# set up the serial line
ser = serial.Serial('COM4', 9600)
#time.sleep(2)

volumen = 0
while(True):
    b = ser.readline()         # read a byte string
    string_n = b.decode()  # decode byte string into Unicode  
    string = string_n.rstrip()
    #print(string)
    if string == "FFA857": # subir volumen
        volumen += 5
        os.system("setvol +3")
        print("subiendo volumen")
        

    if string == "FFE01F":
        volumen -= 5
        os.system("setvol -3")
        print("bajando volumen")
        

    