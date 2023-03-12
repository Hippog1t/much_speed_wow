import keyboard
import serial

# ser = serial.Serial('/dev/ttyACM0', 9600, timeout=0.1)
ser = serial.Serial('COM12', 115200, timeout=0.1)

increment = 10
tab = [ 50 , 50 ]
target_tab = [ 50 , 50 ]
# str old_state
old_state = "neutral"
# bool # state_updated

def synchronize_values (target_value , value , speed_or_dir ):
    if (target_value != value):
        if ( target_value > value ) :
            value =+ increment
        else:
            value -= increment
    if (speed_or_dir == "speed"):
        tab[0] = value
    else:
        tab[1] = value

def update_state( new_state, target_tab, letter_sent_to_arduino ):
    # global old_state
    # letter_sent_to_arduino_in_bytes = bytes( letter_sent_to_arduino, 'utf-8' )
    # ser.write( letter_sent_to_arduino_in_bytes )
    # if ( old_state != new_state ):
    #     # print( "state updated" )
    #     print ( new_state )
    #     old_state = new_state
    global old_state
    synchronize_values( target_tab[0] , tab[0] , "speed" )
    synchronize_values( target_tab[1] , tab[1] , "dir" )

    speed_in_bytes = target_tab[0]
    # bytes( str(target_tab[0], 'utf-8' ),'utf-8' )
    rot_in_bytes = target_tab[1]
    #bytes(  str(target_tab[1], 'utf-8' ),'utf-8' )
# insert sleep HERE
    ser.write( bytes( "h" , 'utf-8' ) )
    ser.write( speed_in_bytes )
    ser.write( bytes( "j" , 'utf-8' ) )
    ser.write( rot_in_bytes )

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
        update_state(  new_state = "neutral" , target_tab = [ 50 , 50] ,  letter_sent_to_arduino = "I")
    # retardation case up+left+right
    elif keyboard.is_pressed( "up+left+right" ):
        update_state(  new_state = "up" , target_tab = [ 99 , 50 ] ,  letter_sent_to_arduino = "A")
    # retardation case down+left+right
    elif keyboard.is_pressed( "left+right+down" ):
        update_state(  new_state = "down" , target_tab = [ 1 , 50 ] ,  letter_sent_to_arduino = "A")
    # retardation case up+left+down
    elif keyboard.is_pressed( "up+down+left" ):
        update_state(  new_state = "left" , target_tab = [ 50 , 99 ] ,  letter_sent_to_arduino = "G")
    # retardation case up+right+down
    elif keyboard.is_pressed( "up+right+down" ):
        update_state(  new_state = "right" , target_tab = [ 50 , 1 ] ,  letter_sent_to_arduino = "C")

    # normal combination of keys
    elif keyboard.is_pressed( "up+right" ):
        update_state(  new_state = "up+right" , target_tab = [ 99 , 1 ] ,  letter_sent_to_arduino = "B")
    elif keyboard.is_pressed( "right+down" ):
        update_state( new_state = "right+down", target_tab = [ 1 , 1 ] ,  letter_sent_to_arduino = "D" )
    elif keyboard.is_pressed( "down+left" ):
        update_state(  new_state = "left+down" , target_tab = [ 1 , 99 ] ,  letter_sent_to_arduino = "F")
    elif keyboard.is_pressed( "left+up" ):
        update_state(  new_state = "up+left" , target_tab = [ 99 , 99 ] ,  letter_sent_to_arduino = "H")


    # up and down, left and right cases for the average retards
    elif keyboard.is_pressed( "up+down" ):
        update_state(  new_state = "neutral" , target_tab = [ 50 , 50 ] ,  letter_sent_to_arduino = "I")
    elif keyboard.is_pressed( "left+right" ):
        update_state(  new_state = "neutral" , target_tab = [ 50 , 50 ] ,  letter_sent_to_arduino = "I")


    elif keyboard.is_pressed( "up" ):
        update_state(  new_state = "up" , target_tab = [ 99 , 50 ] ,  letter_sent_to_arduino = "A")
    elif keyboard.is_pressed( "down" ):
        update_state(  new_state = "down" , target_tab = [ 1 , 50 ] ,  letter_sent_to_arduino = "A")
    elif keyboard.is_pressed( "right" ):
        update_state(  new_state = "right" , target_tab = [ 50 , 1 ] ,  letter_sent_to_arduino = "C")
    elif keyboard.is_pressed( "left" ):
        update_state(  new_state = "left" , target_tab = [ 50 , 99 ] ,  letter_sent_to_arduino = "G")


    else:
        update_state(  new_state = "neutral" , target_tab = [ 50 , 50 ] ,  letter_sent_to_arduino = "I")
