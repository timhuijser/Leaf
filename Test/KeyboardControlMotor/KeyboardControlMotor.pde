 import processing.serial.*; 
 
 Serial port; 
 
 void setup()  {
 //println(Serial.list()); 
 
 // Open the port that the Arduino board is connected to (in this case #0) 
 // Make sure to open the port at the same speed Arduino is using (9600bps) 
 port = new Serial(this, Serial.list()[5], 9600); 
 
 }
 
 void keyPressed() {
   
  // Check if key is coded
  if (key == CODED) {
    println(keyCode);
    if (keyCode == UP) {
      port.write('U'); 
    } else if (keyCode == DOWN) {
      port.write('D'); 
    } else if (keyCode == LEFT) {
      port.write('T'); 
    } else if (keyCode == RIGHT) {
      port.write('R'); 
    }
  }
}

void keyReleased() {
  port.write('S');
}
