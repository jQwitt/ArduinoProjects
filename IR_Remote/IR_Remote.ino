#include <IRremote.h>
#include <SDisplay.h>

const int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results; 
SDisplay seg1(13,12,11,10,9,8,7,6); 
int count;
unsigned long int code, lastCode; 

void setup() {
  //Debugging setup
  Serial.begin(9600);
  irrecv.enableIRIn();
   
  //startup sequence
  seg1.on(); 
  delay(100); 
  seg1.off();   

}

void loop() {
  if (irrecv.decode(&results)) { 
    lastCode = code; 
    code = results.value; 
    Serial.println(code, HEX);
    switch(code) {
          case 0xFF6897:
            count = 0; 
            break;
          case 0xFF30CF:
            count = 1; 
            break;
          case 0xFF18E7:
            count = 2;
            break;
          case 0xFF7A85:
            count = 3;
            break;
          case 0xFF10EF:
            count = 4;
            break;
          case 0xFF38C7:
            count = 5;
            break;
          case 0xFF5AA5:
            count = 6;
            break;
          case 0xFF42BD:
            count = 7;
            break;
          case 0xFF4AB5:
            count = 8;
            break;
          case 0xFF52AD:
            count = 9;
            break;  
          case 0xFFA857:
            if (count == 9) {
              count = 0;
            } else {    
              count++;
            }
            break; 
          case 0xFFE01F:
            if (count == 0) { 
              count = 9; 
            } else { 
              count--;
            } 
            break;   
          case 0xFFFFFFFF:
            break; 
      }
    seg1.displayNum(count);   
    irrecv.resume();   
  }
}
