## Some basic terminology and functions

### PinMode

```c
pinMode(pin, mode)
```

`pin`: the number of the pin whose mode you wish to set
`mode`: INPUT, OUTPUT, or INPUT_PULLUP.

#### INPUT

it is used to read the state of a sensor (like a button), or send a signal to a module (like a LED).

#### OUTPUT

it is used to send a signal to a module (like a LED).

### DigitalWrite

```c
digitalWrite(pin, value)
```

it can be used to turn on an LED at a pin, or write a HIGH or LOW value to a pin.

### DigitalRead

```c
digitalRead(pin)
```

it can be used to read the value of a pin, either HIGH or LOW.

### AnalogWrite

```c
analogWrite(pin, value)
```

it can be used to write a value between 0 and 255 to a pin, enabling us to control the brightness of an LED.
It uses PWM (pulse width modulation) for getting analog results with digital means.

### AnalogRead

```c
analogRead(pin)
```

it can be used to read the value from an analog pin, between 0 and 1023.

### Serial

```c
Serial.begin(speed)
```

it is used to initialize the serial communication with the computer. The speed is measured in bits per second, and the most common rates are 9600, 19200 and 115200.
