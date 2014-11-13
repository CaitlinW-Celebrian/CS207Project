    /* 
    The purpose of this code is to allow the Arduino to use the 
    generic serial output of vixen lights to control 8 channels of LEDs. 
    Author: Matthew Strange 
    Created: 14 October 2010 
    Adapted for 6-PWM-Channels by Charles Gantt on November 14th 2013. 
     
    */  
    
    /*
      Code Edited By: Caitlin Wood
      Date: October 26th, 2014
    */
    
      
    // Output  
    int Chan1 = 9; // green LED, connected to digital pin 11  
    int Chan2 = 8; // red LED, connected to digital pin 10  
    int Chan3 = 7; // green LED, connected to digital pin 9  
    int Chan4 = 6; // red LED, connected to digital pin 7  
    int Chan5 = 5; // green LED, connected to digital pin 6  
    int Chan6 = 4; // red LED, connected to digital pin 5
    int Chan7 = 3; // green LED, connected to digital pin 4
    int Chan8 = 2; // red LED, connected to digital pin 3
    
      
    int i = 0; // Loop counter  
    int incomingByte[8]; // array to store the 7 values from the serial port  
      
    //setup the pins/ inputs & outputs  
    void setup()  
    {  
      Serial.begin(9600); // set up Serial at 9600 bps  
      
      pinMode(Chan1, OUTPUT); // sets the pins as output  
      pinMode(Chan2, OUTPUT);  
      pinMode(Chan3, OUTPUT);  
      pinMode(Chan4, OUTPUT);  
      pinMode(Chan5, OUTPUT);  
      pinMode(Chan6, OUTPUT); 
      pinMode(Chan7, OUTPUT);
      pinMode(Chan8, OUTPUT); 
    }  
      
    void loop()  
    { // 7 channels are coming in to the Arduino  
      if (Serial.available() >= 8) {  
      // read the oldest byte in the serial buffer:  
      for (int i=0; i<8; i++) {  
      // read each byte  
      incomingByte[i] = Serial.read();  
      }  
      
      analogWrite(Chan1, incomingByte[0]); // Write current values to LED pins  
      analogWrite(Chan2, incomingByte[1]); // Write current values to LED pins  
      analogWrite(Chan3, incomingByte[2]); // Write current values to LED pins  
      analogWrite(Chan4, incomingByte[3]); // Write current values to LED pins  
      analogWrite(Chan5, incomingByte[4]); // Write current values to LED pins  
      analogWrite(Chan6, incomingByte[5]); // Write current values to LED pins  
      analogWrite(Chan7, incomingByte[6]); // Write current values to LED pins
      analogWrite(Chan8, incomingByte[7]); // Write current values to LED pins
      }  
    }  
