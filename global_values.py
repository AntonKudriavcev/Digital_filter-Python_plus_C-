
from math       import sin, pi 
import numpy as np

import threading

##--------------------------------------------------------
##------------------signal settings-----------------------
##--------------------------------------------------------
f_s_1 = 25
f_s_2 = 50
f_s_3 = 100
f_s_4 = 200
f_s_5 = 400
f_s_6 = 800

A   = 1
##--------------------------------------------------------
##------------------sample settings-----------------------
##--------------------------------------------------------
f_d = 22050
T   = 10.0
dt  = 1/f_d
t   = np.linspace(0.1, T, int(T * f_d), endpoint = False) # time variable

##---buffer for input data------
voltage = []

##-----------list for filtred voltage--------------
filt_volt = []





