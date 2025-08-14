import processing.serial.*;
Serial port;

int deltaX ;
int deltaY ;
int Switch;
String portName ;
String value;

void setup()
{
  port = new Serial(this, "COM7", 9600);
  port.bufferUntil('\n');  
  size(1800,900);
  fill(255,30,30);
  stroke(255,255,255);
  strokeWeight(5);
  background(0,0,0);
}

void draw()
{
  clear();
  
  if (Switch == 1) 
  {
    fill(255,0,0);
    circle(deltaX,deltaY,240);
  }
   else 
   {
     fill(0,0,255);
     circle(deltaX,deltaY,240);
  
   }
}
 void serialEvent( Serial port)
 {
   value = port.readStringUntil('\n');
   
   if (value != null)
   {
     value = trim(value);
     int[] values = int(splitTokens(value, ","));
     
     deltaX = values[0];
     deltaY = values[1];
     Switch = values[2];
   }
 }  
