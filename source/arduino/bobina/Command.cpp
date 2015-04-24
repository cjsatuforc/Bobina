
#if (ARDUINO >= 100)
# include "Arduino.h"
#else
# include "WProgram.h"
#endif


#include "Command.h"



int Command::proccess()
{
	if (Serial.available()){
	    char op = Serial.read();
	    Serial.println(op);
	    switch ( op )
	    {
	    case 't':  
	    	return MOVE_BACK;
	       
	    case 'f':
	    	return MOVE_ON;
	       
	    case 'd':
	        return MOVE_RIGHT;
	       
	    case 'e':
	        return MOVE_LEFT;

	    case 'x':
	    	return TEST_MOTORS;
	        
	        
	    }
	}
    return NO_COMMAND;

}
