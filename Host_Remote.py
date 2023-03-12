import keyboard
import serial

# ser = serial.Serial('/dev/ttyACM0', 9600, timeout=0.1)
ser = serial.Serial('COM12', 115200, timeout=0.1)

# str old_state
old_state = "neutral"
# bool # state_updated
## OLD CODE to update state with letters
# def update_state( new_state, letter_sent_to_arduino ):
#     global old_state
#     letter_sent_to_arduino_in_bytes = bytes( letter_sent_to_arduino, 'utf-8' )
#     ser.write( letter_sent_to_arduino_in_bytes )
#     if ( old_state != new_state ):
#         # print( "state updated" )
#         print ( new_state )
#         old_state = new_state
def update_state( new_state, letter_sent_to_arduino ):
    global old_state
    letter_sent_to_arduino_in_bytes = bytes( letter_sent_to_arduino, 'utf-8' )
    ser.write( letter_sent_to_arduino_in_bytes )
    if ( old_state != new_state ):
        # print( "state updated" )
        print ( new_state )
        old_state = new_state

while True:
    ######## print arduino output
    output = ser.readline()
    print(output)
    ########

    # Maximum retardation case
    if keyboard.is_pressed("up+right+down+left"):
        update_state(  new_state = "neutral" ,  letter_sent_to_arduino = "I")
    # retardation case up+left+right
    elif keyboard.is_pressed( "up+left+right" ):
        update_state(  new_state = "up" ,  letter_sent_to_arduino = "A")
    # retardation case down+left+right
    elif keyboard.is_pressed( "left+right+down" ):
        update_state(  new_state = "down" ,  letter_sent_to_arduino = "E")
    # retardation case up+left+down
    elif keyboard.is_pressed( "up+down+left" ):
        update_state(  new_state = "left" ,  letter_sent_to_arduino = "G")
    # retardation case up+right+down
    elif keyboard.is_pressed( "up+right+down" ):
        update_state(  new_state = "right" ,  letter_sent_to_arduino = "C")

    # normal combination of keys
    elif keyboard.is_pressed( "up+right" ):
        update_state(  new_state = "up+right" ,  letter_sent_to_arduino = "B")
    elif keyboard.is_pressed( "right+down" ):
        update_state( new_state = "right+down",  letter_sent_to_arduino = "D" )
    elif keyboard.is_pressed( "down+left" ):
        update_state(  new_state = "left+down" ,  letter_sent_to_arduino = "F")
    elif keyboard.is_pressed( "left+up" ):
        update_state(  new_state = "up+left" ,  letter_sent_to_arduino = "H")


    # up and down, left and right cases for the average retards
    elif keyboard.is_pressed( "up+down" ):
        update_state(  new_state = "neutral" ,  letter_sent_to_arduino = "I")
    elif keyboard.is_pressed( "left+right" ):
        update_state(  new_state = "neutral" ,  letter_sent_to_arduino = "I")


    elif keyboard.is_pressed( "up" ):
        update_state(  new_state = "up" ,  letter_sent_to_arduino = "A")
    elif keyboard.is_pressed( "down" ):
        update_state(  new_state = "down" ,  letter_sent_to_arduino = "E")
    elif keyboard.is_pressed( "right" ):
        update_state(  new_state = "right" ,  letter_sent_to_arduino = "C")
    elif keyboard.is_pressed( "left" ):
        update_state(  new_state = "left" ,  letter_sent_to_arduino = "G")


    else:
        update_state(  new_state = "neutral" ,  letter_sent_to_arduino = "I")
