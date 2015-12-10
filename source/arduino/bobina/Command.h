#ifndef COMMAND_H
#define COMMAND_H

/*
 *  Builtin Commands
 */

#define NO_COMMAND  	0
#define MOVE_ON			1
#define MOVE_BACK		2
#define MOVE_RIGHT		3
#define MOVE_LEFT		4
#define TEST_MOTORS		5

/*
*  Commands mode
*/

#define AUTOMATIC_MODE	99
#define MANUAL_MODEq	88


/**
 * Sends commands to the Robot. It can be 
 * automatic or manual
 */
class Command{
public:
	/*
	 * Reciece Serial data and return 
	 * the corresponding command
	 */
	int proccess();


	/*
	*
	*/
	bool setMode(int mode);

private:
	bool automatic;

};

#endif