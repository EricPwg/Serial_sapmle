# -*- coding: utf-8 -*-
comnum = 'COM19'

import sys
import serial

ser = serial.Serial(comnum, 9600, timeout = 0.5)

try:
    while True:
        if sys.version_info[0] == 2:
            a = raw_input("command:")
        else:
            a = input("command:")
        a = str(a)+'\n'
        a = a.encode()
        ser.write(a)
finally:
    ser.close()