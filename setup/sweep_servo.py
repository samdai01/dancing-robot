"""
Sweeps servo from 0 degrees to 180 degrees
** Used for testing servo functionality **
Feb 17, 2022
"""

# Library imports
import time     # python time library to delay setting setting servo angle to speed of servo rotation
import board    # import circuitpython board library
import pwmio    # import pwm io library for board pwm pins
from adafruit_motor import servo    # import adafruit servo library

# create a PWMOut object on Pin A1.
servo_pwm = pwmio.PWMOut(board.A1, duty_cycle=2 ** 15, frequency=50)

# Create a servo object, my_servo
my_servo = servo.Servo(servo_pwm)

while True:
    for angle in range(0, 180, 5):  # 0 - 180 degrees, 5 degrees at a time.
        my_servo.angle = angle
        time.sleep(0.05)
    for angle in range(180, 0, -5): # 180 - 0 degrees, 5 degrees at a time.
        my_servo.angle = angle
        time.sleep(0.05)
