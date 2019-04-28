# -*- coding: utf-8 -*-
comnum = 'COM19'

import sys
import serial
if sys.version_info[0] == 2:
    import Tkinter as tk
else:
    import tkinter as tk

ser = serial.Serial(comnum, 9600, timeout = 0.5)


def send_onclick():
    global L1, ser, e1, e2
    try:
        en1 = int(e1.get())
        en2 = int(e2.get())
    except:
        L1.config(text='type error', bg = 'red')
        return
    
    try:
        s = str(en1)+' '+str(en2)+'\n'
        se = s.encode()
        ser.write(se)
        L1.config(text='Sent successfully:\n'+s, bg = 'green')
    except:
        L1.config(text='sent error', bg = 'red')


win = tk.Tk()
win.title('tk test')

win.geometry('350x100')
e1 = tk.Entry(win)
e1.grid(row=0, column=0)
e2 = tk.Entry(win)
e2.grid(row=0, column=1)
b1 = tk.Button(win, text='send', command=send_onclick)
b1.grid(row = 0, column = 2)

L1 = tk.Label(win, text='123')
L1.grid(row = 1, column = 0, columnspan = 3, rowspan = 3)

win.mainloop()
ser.close()