import rpi_gpio as gpio
from time import sleep

# Turning LED on and off

# BCM : Broadcom pin numbering, pins by Broadcom chip number
gpio.setWarnings(False)  # Disable warnings
gpio.setmode(gpio.BCM)
gpio.setup(17, gpio.OUT)  # Set pin 17 as output
gpio.output(17, True)  # Turn on pin 17
sleep(2)
gpio.output(17, False)  # Turn off pin 17

# Blinking LED
gpio.setWarnings(False)
gpio.setmode(gpio.BCM)
gpio.setup(17, gpio.OUT)
for i in range(0, 10):
    gpio.output(17, True)
    sleep(1)
    gpio.output(17, False)
    sleep(1)

# LED with variable brightness
gpio.setWarnings(False)
gpio.setmode(gpio.BCM)
gpio.setup(17, gpio.OUT)
p = gpio.PWM(17, 100)  # 100 is the frequency in Hz
dc = 0
p.start(dc)  # dc is the duty cycle (0.0 <= dc <= 100.0)
for x in range(3):
    for i in range(0, 10):
        dc += 10
        p.ChangeDutyCycle(dc)  # Change the duty cycle
        sleep(0.2)

    for i in range(0, 10):
        dc -= 10
        p.ChangeDutyCycle(dc)
        sleep(0.2)
p.stop()
gpio.cleanup()  # Reset GPIO settings
