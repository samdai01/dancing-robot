"""
This file was used for centering the servo
Feb 17, 2022
"""

# Imports required to run the servos
import board       # Circuitpython board library
import pwmio       # PWM pin i/o library
from adafruit_motor import servo # servo library

# create a PWMOut object on Pin A1.
servo_pwm = pwmio.PWMOut(board.A1, duty_cycle=2 ** 15, frequency=50)

# Create a servo object, my_servo
my_servo = servo.Servo(servo_pwm)

# Set servo to 90 degrees or center
while True:
    my_servo.angle = 90
