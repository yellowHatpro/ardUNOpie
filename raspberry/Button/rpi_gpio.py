import rpio.gpio as gpio
from time import sleep

# check if button is pressed

gpio.setwarnings(False)
gpio.setmode(gpio.BCM)
gpio.setup(2, gpio.IN)  # set pin 2 as input
for i in range(0, 1000):
    if gpio.input(2) == 0:
        print("Button is pressed")
        sleep(1)
