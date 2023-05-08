from gpiozero import Button
from time import sleep
from subprocess import check_call
from signal import pause

# Check if button is pressed

button = Button(2)  # 2 is the GPIO pin number
for i in range(0, 1000):
    if button.is_pressed:
        print("Button is pressed")
    else:
        print("Button is not pressed")
    sleep(1)


# Function every time the button is pressed and released
def button_pressed():
    print("Button is pressed")


def button_released():
    print("Button is released")


button = Button(2)
button.when_pressed = button_pressed
button.when_released = button_released
pause()

# Shutdown button

# Function to shutdown the Raspberry Pi


def shutdown():
    check_call(['sudo', 'poweroff'])


shutdown_btn = Button(2, hold_time=2)
shutdown_btn.when_held = shutdown
pause()
