#ifndef COMMAND_H
#define COMMAND_H

/*
 *  Builtin Commands
 */

#define NO_COMMAND  0
#define MOVE_ON		1
#define MOVE_BACK	2
#define MOVE_RIGHT	3
#define MOVE_LEFT	4

/**
 *
 */
class Command{
public:
	/*
	 * Reciece Serial data and return 
	 * the corresponding command
	 */
	int proccess();

};

#endif