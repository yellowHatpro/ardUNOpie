from gpiozero import LightSensor, LED
from signal import pause

# LDR: Light Dependent Resistor , When it is dark, the LED turns on

sensor = LightSensor(17)
led = LED(27)

sensor.when_dark = led.on
sensor.when_light = led.off

pause()
