from gpiozero import Buzzer
from time import sleep

# Buzzer
buzzer = Buzzer(17)  # 17 is the GPIO pin number
buzzer.on()  # Turns the buzzer on
sleep(1)
buzzer.off()  # Turns the buzzer off
sleep(1)
