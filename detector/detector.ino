// Ultrasonic HC-SR04 unit interface
// Uses serial port at 115200 baud for communication
// use trig pin for output, echo pin for input
// pulse out (10us) on trig initiates a cycle
// pulse width returned on echo is proportional to distance
// specs say 38ms = no return (beyond limit), but 90ms and more have been seen
// set utimeout when calling usonic (routine will take longer for longer returns)
// higher timeout measures further, but can take longer if no echo
// if return >= utimeout, no valid pulse received
// if return < ~100 unit is faulty/disconnected (routine is timing out waiting for start of return)
// if return == 0 then unit is still sending return from last ping (or is faulty)
// maximum nominal range is 5m => utimeout = 29000 us
// call usonicsetup() during setup
// call usonic(timeout) to get return time in microseconds
// divide result of usonic by 58 to get range in cm
//define pins here
#define TRIG 24
#define ECHO 22
#define USMAX 3000
void setup() {
  Serial.begin(115200); //open serial port
  usonicsetup(); //set up ultrasonic sensor
}
void loop() {
  int d; //variable to store distance
  d=usonic(11600)/58; //distance in cm, time out at 11600us or 2m maximum range
  Serial.println(d); //print distance in cm
  delay(200); //wait a bit so we don't overload the serial port
}
void usonicsetup(void){
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  digitalWrite(TRIG, LOW);
}

long usonic(long utimeout){ //utimeout is maximum time to wait for return in us
  long b;
  if(digitalRead(ECHO)==HIGH){return 0;} //if echo line is still low from last result, return 0;
  digitalWrite(TRIG, HIGH); //send trigger pulse
  delay(1);
  digitalWrite(TRIG, LOW);
  long utimer=micros();
  while((digitalRead(ECHO)==LOW)&&((micros()-utimer)<1000)){} //wait for pin state to change return starts after 460us typically or timeout (eg if not connected)
  utimer=micros();
  while((digitalRead(ECHO)==HIGH)&&((micros()-utimer)<utimeout)){} //wait for pin state to change
  b=micros()-utimer;
  if(b==0){b=utimeout;}
  return b;
}
