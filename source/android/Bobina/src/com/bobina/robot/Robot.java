package com.bobina.robot;

import com.bobina.robot.commands.Commands;
import com.bobina.robot.communication.Communication;

public class Robot {
	private Communication communication;
	private Commands	  commands;
	
	public Robot(Communication communication, Commands commands) {
		this.communication = communication;
		this.commands = commands;
	}
	
	public void moveOn() throws Exception{
		send(commands.getMoveOnCommand());
	}	
	public void moveBack() throws Exception{
		send(commands.getMoveBackCommand());
	}	
	public void moveLeft() throws Exception{
		send(commands.getMoveLeftCommand());
	}
	public void moveRight() throws Exception{
		send(commands.getMoveRightCommand());
	}
	public void command1() throws Exception{
		send(commands.getCustomCommand1());
	}
	public void command2() throws Exception{
		send(commands.getCustomCommand2());
	}
	public void command3() throws Exception{
		send(commands.getCustomCommand3());
	}
	public void command4() throws Exception{
		send(commands.getCustomCommand4());
	}
	
	private void send(byte [] data) throws Exception{
		if ( communication!= null && communication.isConnected()){
			communication.send(data);
		}
	}
	
	public Commands getCommands() {
		return commands;
	}
	public Communication getCommunication() {
		return communication;
	}
	
	
}
