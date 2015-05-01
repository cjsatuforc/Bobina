package com.bobina;

import android.app.Activity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageButton;
import android.widget.Toast;

import com.bobina.robot.Robot;
import com.bobina.robot.commands.CommandsDAO;
import com.bobina.robot.communication.BluetoothCommunication;
import com.bobina.robot.communication.Communication;
import com.bobina.robot.communication.CommunicationListener;
import com.bobina.view.ConsoleView;


public class MainActivity extends Activity {

	private ImageButton 		up;
	private ImageButton 		back;
	private ImageButton 		right;
	private ImageButton 		left;
	
	private ConsoleView 		console;

	private Robot				robot;
	private BluetoothCommunication communication;
    
	@Override
    protected void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);             
    	
    	setContentView(R.layout.main_layout); 
    	
    	this.up 		= (ImageButton) findViewById(R.id.control_button_up);
		this.back 		= (ImageButton) findViewById(R.id.control_button_back);
		this.left 		= (ImageButton) findViewById(R.id.control_button_left);
		this.right 		= (ImageButton) findViewById(R.id.control_button_right);
	
		this.console	= (ConsoleView)findViewById(R.id.console);
		setListeners();
		disableActionButtons();
    }
    
    void hideActionBar(){
//    	android.support.v7.app.ActionBar actionBar = getSupportActionBar();
//    	actionBar.hide();
    }

    
    
    void disableButtons(){
		this.up.setEnabled(false);
		this.back.setEnabled(false);
		this.left.setEnabled(false);
		this.right.setEnabled(false);
	}
	private void setListeners(){
		this.up.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				
				try {
					robot.moveOn();
				} catch (Exception e) {
					e.printStackTrace();
					writeOutput(e.getMessage());
				}
			}
		});
		
		this.back.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				try {
					robot.moveBack();
				} catch (Exception e) {					
					e.printStackTrace();
					writeOutput(e.getMessage());
				}
			}
		});
		
		this.left.setOnClickListener(new OnClickListener() {			
			@Override
			public void onClick(View v) {
				try{
					robot.moveLeft();
				}catch(Exception e){
					writeOutput(e.getMessage());
					e.printStackTrace();
				}
			}
		});
		
		this.right.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				try{				
					robot.moveRight();
				}catch (Exception e){
					e.printStackTrace();
					writeOutput(e.getMessage());
				}
			}
		});
	}
    
   
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
    	MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.main, menu);
    	return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();
        
        switch (id){
        case R.id.action_settings:
        	Toast.makeText(this, "Settings", Toast.LENGTH_LONG).show();
            return true;
        case R.id.action_disconnect:
        	Toast.makeText(this, "Disconnect", Toast.LENGTH_LONG).show();
        	try{
        		disconned();
        	}catch (Exception e) {
        		writeOutput(e.getMessage());
        		e.printStackTrace();
			}
            return true;
        case R.id.action_connect:
        	Toast.makeText(this, "Connect", Toast.LENGTH_LONG).show();
        	try{
        		writeOutput("connecting");
        		connect();
        		
        	}catch (Exception e) {
        		writeOutput(e.getMessage());
        		e.printStackTrace();
			}
        	
            return true;
            
        }
        
        
        return super.onOptionsItemSelected(item);
    }
    
    
    void connect() throws Exception{
    	//connect to robot
    	communication = new BluetoothCommunication(this);
    	communication.setListener(communicationListener);
		communication.initialize();
		communication.connect();
		
    }
    void disconned() throws Exception{
    	communication.shutdown();
    	communication 	= null;
    	robot 			=  null;
    	disableActionButtons();
    }
    void enableActionButtons(){
    	this.up.setEnabled(true);
    	this.back.setEnabled(true);
    	this.right.setEnabled(true);
    	this.left.setEnabled(true);
    }
    void disableActionButtons(){
    	this.up.setEnabled(false);
    	this.back.setEnabled(false);
    	this.right.setEnabled(false);
    	this.left.setEnabled(false);
    }

    void writeOutput(String message){
    	console.write("OUTPUT",message);;
    }
    
    void writeInput(String message){
    	console.write("INPUT",message);;
    }
    private CommunicationListener communicationListener = new CommunicationListener() {
		
		@Override
		public void onConnect() {
			CommandsDAO commandDao = new CommandsDAO(); 
			MainActivity.this.robot = new Robot(communication, commandDao.getDefaultCommands());
			
			//enable the buttons
			enableActionButtons();
			
			//start recieve task
			new RecieveTask().execute(communication);
			
			writeOutput("connected");
		}
	};
    
	
	private class RecieveTask extends AsyncTask<Communication, byte [] , Void>{

		@Override
		protected Void doInBackground(Communication... params) {
			if ( params.length<=0)
				throw new IllegalStateException("Invalid parameter");
			Communication communication = params[0];
			try{
				do{
					byte [] data = communication.recieve();
					this.publishProgress(data);
				}while(communication.isConnected());
			}catch (Exception e) {
				publishProgress(("Error:"+e.getMessage()).getBytes());
			}
			return null;
		}
		
		@Override
		protected void onProgressUpdate(byte[]... values) {
			if ( values.length >0){
				byte [] data = values[0];
				writeInput(new String(data));
			}
			
		}
		
	}
}
