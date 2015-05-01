package com.bobina.robot.commands;
/**
 * Entity class that contains the
 * values to send to the robot
 * @author Eduardo
 *
 */
public class Commands {
	private byte [] moveOnCommand;
	private byte [] moveBackCommand;	
	private byte [] moveLeftCommand;
	private byte [] moveRightCommand;
	
	private byte [] customCommand1;
	private byte [] customCommand2;
	private byte [] customCommand3;
	private byte [] customCommand4;
	
	
	public byte[] getMoveOnCommand() {
		return moveOnCommand;
	}
	public void setMoveOnCommand(byte[] moveOnCommand) {
		this.moveOnCommand = moveOnCommand;
	}
	public byte[] getMoveBackCommand() {
		return moveBackCommand;
	}
	public void setMoveBackCommand(byte[] moveBackCommand) {
		this.moveBackCommand = moveBackCommand;
	}
	public byte[] getMoveLeftCommand() {
		return moveLeftCommand;
	}
	public void setMoveLeftCommand(byte[] moveLeftCommand) {
		this.moveLeftCommand = moveLeftCommand;
	}
	public byte[] getMoveRightCommand() {
		return moveRightCommand;
	}
	public void setMoveRightCommand(byte[] moveRightCommand) {
		this.moveRightCommand = moveRightCommand;
	}
	public byte[] getCustomCommand1() {
		return customCommand1;
	}
	public void setCustomCommand1(byte[] customCommand1) {
		this.customCommand1 = customCommand1;
	}
	public byte[] getCustomCommand2() {
		return customCommand2;
	}
	public void setCustomCommand2(byte[] customCommand2) {
		this.customCommand2 = customCommand2;
	}
	public byte[] getCustomCommand3() {
		return customCommand3;
	}
	public void setCustomCommand3(byte[] customCommand3) {
		this.customCommand3 = customCommand3;
	}
	public byte[] getCustomCommand4() {
		return customCommand4;
	}
	public void setCustomCommand4(byte[] customCommand4) {
		this.customCommand4 = customCommand4;
	}
	
	
}
