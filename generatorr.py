import global_values as g_v
from filterr import filter_controller

##--------thread for signal generaton--------
def generator():
  for i in range (len(g_v.voltage)):
  	Y = filter_controller(g_v.voltage[i])
  	g_v.filt_volt.append(Y)