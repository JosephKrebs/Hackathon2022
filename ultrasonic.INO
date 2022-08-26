#define TRIG 7
#define ECHO 6
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
 if(digitalRead(ECHO)==HIGH){return 0;} //if echo line is still low from last result,
return 0;
 digitalWrite(TRIG, HIGH); //send trigger pulse
 delay(1);
 digitalWrite(TRIG, LOW);
 long utimer=micros();
 while((digitalRead(ECHO)==LOW)&&((micros()-utimer)<1000)){} //wait for pin state to changereturn starts after 460us typically or timeout (eg if not connected)
 utimer=micros();
 while((digitalRead(ECHO)==HIGH)&&((micros()-utimer)<utimeout)){} //wait for pin state to
change
 b=micros()-utimer;
 if(b==0){b=utimeout;}
 ret
