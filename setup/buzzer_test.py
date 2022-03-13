"""
Buzzer test code from https://learn.adafruit.com/using-piezo-buzzers-with-circuitpython-arduino?view=all
This tests the basic functionality of the piezo buzzer that will be used to play the dance songs.
February 18, 2022
"""

# library imports
import time     # Imports to delay the buzzer to allow it to react
import board    # import circuitpython board library
import pulseio  # circuitpython pulse library for the buzzer


# Define a list of tones/music notes to play.
TONE_FREQ = [ 262,  # C4
              294,  # D4
              330,  # E4
              349,  # F4
              392,  # G4
              440,  # A4
              494 ] # B4

# Create piezo buzzer PWM output.
buzzer = pulseio.PWMOut(board.D5, variable_frequency=True)

# Start at the first note and start making sound.
buzzer.frequency = TONE_FREQ[0]
buzzer.duty_cycle = 2**15  # 32768 value is 50% duty cycle, a square wave.

# Main loop will go through each tone in order up and down.
while True:
    # Play tones going from start to end of list.
    for i in range(len(TONE_FREQ)):
        buzzer.frequency = TONE_FREQ[i]
        time.sleep(0.5)  # Half second delay.
    # Then play tones going from end to start of list.
    for i in range(len(TONE_FREQ)-1, -1, -1):
        buzzer.frequency = TONE_FREQ[i]
        time.sleep(0.5)