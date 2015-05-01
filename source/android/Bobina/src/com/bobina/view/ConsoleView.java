package com.bobina.view;

import android.content.Context;

import android.util.AttributeSet;
import android.widget.TextView;

public class ConsoleView extends TextView{

	public ConsoleView(Context context, AttributeSet attrs) {
		super(context, attrs);
	}
	public ConsoleView(Context context) {
		super(context);
	}
	
	public void write(String label,String text){
		String oldString = getText().toString();
		String newString = oldString + "["+label+"]: "+text+"\n";
		setText(newString);
	}
	
	
	

	

}
