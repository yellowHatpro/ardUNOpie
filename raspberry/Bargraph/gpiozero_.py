from gpiozero import LEDBarGraph
from time import sleep

# A bargraph is a collection of LEDs
graph = LEDBarGraph(17, 27, 22, 10, 9, 0, 11, 5, 6, 13)  # 5 LEDs

graph.value = 1  # 1 LED on all 1 (1,1,1,1,1,1,1,1,1,1)
sleep(1)
graph.value = 0.5  # 5 LEDs on (1,1,1,1,1,0,0,0,0,0)
sleep(1)
graph.value = -1/2  # 5 LEDs on (0,0,0,0,0,1,1,1,1,1)
sleep(1)
graph.value = 0.2  # 2 LEDs on (1,1,0,0,0,0,0,0,0,0)
sleep(1)
graph.value = -1  # 10 LEDs on (1,1,1,1,1,1,1,1,1,1)
