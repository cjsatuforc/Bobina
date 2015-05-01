package com.bobina.robot.communication;

import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.UUID;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.widget.Toast;

/**
 * Communicates with the robot throw Bluetooth
 * @author Eduardo
 *
 */
public class BluetoothCommunication implements Communication{

	private Activity	 			activity;
	private CommunicationListener 	communicationListener;
	private BluetoothAdapter 		mBluetoothAdapter;
	private BluetoothDevice 		device;
	private BluetoothSocket			socket;
	private InputStream 			mmInStream;
	private OutputStream 			mmOutStream;
	private boolean					connected;
	private static UUID 			uuid = null;
	
	
	public BluetoothCommunication(Activity activity) {
		this.activity = activity;
	}
	
	@Override
	public void initialize() throws Exception {
		mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
		connected = false;
		//check if bluetooth is supported
		if (mBluetoothAdapter == null) {
			throw new IllegalStateException("Bluetooth not supported");
		}

		//enable bluetooth
		if (!mBluetoothAdapter.isEnabled()) {
		    Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
		    activity.startActivityForResult(enableBtIntent, 0);
		}
	}	
	
	@Override
	public void send(byte[] data) throws Exception {
		mmOutStream.write(data);
	}

	@Override
	public byte[] recieve() throws Exception {
		byte [] buffer = new byte[64];
		mmInStream.read(buffer);
		return buffer;
	}

	@Override
	public void shutdown() throws Exception {
		mmOutStream.close();
		mmInStream.close();
		socket.close();
		connected = false;
	}
	
	@Override
	public boolean isConnected() throws Exception {
		return connected;
	}

	@Override
	public void connect() throws Exception {
		getPairedDevices();
		if ( device != null){
			this.mBluetoothAdapter.cancelDiscovery();	        	   
			uuid= device.getUuids()[0].getUuid();	        	 	       		
			
			socket = this.device.createRfcommSocketToServiceRecord(uuid);
			//socket = this.device.createInsecureRfcommSocketToServiceRecord(uuid);

			socket.connect();

            mmInStream = socket.getInputStream();
            mmOutStream = socket.getOutputStream();
			
			this.communicationListener.onConnect();
			connected = true;
		}
		
	}

	@Override
	public void setListener(CommunicationListener listener) {
		this.communicationListener = listener;
	}
	
	private void discoveryDevices(){

		IntentFilter filter = new IntentFilter(BluetoothDevice.ACTION_FOUND);
		activity.registerReceiver(discoveryDevicesRecieve, filter); // Don't forget to unregister during onDestroy
	}
	private void getPairedDevices(){
	    Set<BluetoothDevice> pairedDevices  = mBluetoothAdapter.getBondedDevices();
	    List<String> devicesFound = new ArrayList<String>();
	    if (pairedDevices.size() > 0) {
	          for (BluetoothDevice device : pairedDevices) {
	           String deviceBTName = device.getName();
	           String deviceBTAddress  = device.getAddress();
	           devicesFound.add(deviceBTName + "\n" + deviceBTAddress);
	           
	           if ( deviceBTName.equalsIgnoreCase("bobina")){
	        	   this.device = device;
	           }
	           
	          }
	          Toast.makeText(activity, devicesFound.toString(), Toast.LENGTH_LONG).show();
	      }
	      
	}
	private final BroadcastReceiver discoveryDevicesRecieve = new BroadcastReceiver() {
	    public void onReceive(Context context, Intent intent) {
	        String action = intent.getAction();
	        // When discovery finds a device
	        if (BluetoothDevice.ACTION_FOUND.equals(action)) {
	           
	            BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
	            Toast.makeText(activity, device.getName() + "\n" + device.getAddress(), Toast.LENGTH_LONG).show();
	       //    mArrayAdapter.add(device.getName() + "\n" + device.getAddress());
	        }
	    }
	};
	

}
