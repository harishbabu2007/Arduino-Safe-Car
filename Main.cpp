#include <IRremote.h>

const int ir_pin = 9;
IRrecv ir_sensor(ir_pin);
decode_results results;

int cs;         // CENTER SENSOR
int lmt1 = 5;   // LEFT MOTOR 1
int lmt2 = 3;   // LEFT MOTOR 2
int rmt1 = 6;   // RIGHT MOTOR 1
int rmt2 = 11;  // RIGHT MOTOR 2

// stoped
bool stoped = false;

void setup() {
  // put your setup code here, to run once:

  // pinMode(8, INPUT);
  pinMode(lmt1, OUTPUT);
  pinMode(lmt2, OUTPUT);
  pinMode(rmt1, OUTPUT);
  pinMode(rmt2, OUTPUT);

  Serial.begin(9600);
  ir_sensor.enableIRIn();
}


void loop() {

  if (ir_sensor.decode(&results)){
    int rec = results.value;
    Serial.println("test");
    
    Serial.println(rec);
    ir_sensor.resume();

   //  if (rec == ){
    //  stoped = true;
    // }
  }


  cs = digitalRead(8);

  if (stoped){
    analogWrite(lmt1, 0);
    analogWrite(lmt2, 0);
    analogWrite(rmt1, 100);
    analogWrite(rmt2, 0);

    // stopes the function execution here
    return;
  }

  if (cs == LOW) {
    analogWrite(lmt1, 0);
    analogWrite(lmt2, 255);
    analogWrite(rmt1, 255);
    analogWrite(rmt2, 0);
  }
  if (cs == HIGH) {
    analogWrite(lmt1, 255);
    analogWrite(lmt2, 0);
    analogWrite(rmt1, 0);
    analogWrite(rmt2, 255);
  }
}