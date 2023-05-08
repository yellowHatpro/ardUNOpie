from gpiozero import LED
from time import sleep
from signal import pause
# Turning LED on and off using gpiozero

red = LED(17)  # 17 is the GPIO pin number

while True:
    red.on()  # Turns the LED on
    sleep(1)  # Waits 1 second
    red.off()  # Turns the LED off
    sleep(1)


# Blinking LED using gpiozero
red = LED(17)
red.blink(2, 1, 5)  # Blink 2 times, 1 second off, 5 times blink

# LED with variable brightness using gpiozero
# 17 is the GPIO pin number, PWMLED is a LED with variable brightness
led = PWMLED(17)
while True:
    led.value = 0  # Off
    sleep(1)
    led.value = 0.2  # 20% brightness
    sleep(1)
    led.value = 0.4  # 40% brightness
    sleep(1)
    led.value = 0.6  # 60% brightness
    sleep(1)
    led.value = 0.8  # 80% brightness
    sleep(1)
    led.value = 1  # 100% brightness
    sleep(1)

# Method 2
led = PWMLED(17)
led.pulse(1, 1, 3)  # fade_in in 1 second, fade_out in 1 second, 3 times
pause()
