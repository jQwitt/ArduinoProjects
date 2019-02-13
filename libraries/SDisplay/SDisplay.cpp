/*
 *  Jack Witt 2/12/19
 *  SDisplay.cpp
 *      The .cpp file for the Segment Display Library
 */

#include "SDisplay.h"

//Initial settings for the segments 
SDisplay::SDisplay(int seg_E, int seg_D, int seg_C, int seg_DP, int seg_B, int seg_A, int seg_F, int seg_G) {
    E = seg_E; 
    D = seg_D;
    C = seg_C; 
    DP = seg_DP;       
    B = seg_B;
    A = seg_A;
    F = seg_F;        
    G = seg_G; 

    pinMode(E, OUTPUT);
    pinMode(D, OUTPUT); 
    pinMode(C, OUTPUT); 
    pinMode(DP, OUTPUT); 
    pinMode(B, OUTPUT); 
    pinMode(A, OUTPUT); 
    pinMode(F, OUTPUT); 
    pinMode(G, OUTPUT);  
 
}

SDisplay::~SDisplay(){/* Nothing to delete */}

//Turns all segments on 
void SDisplay::on() { 
  digitalWrite(E, HIGH);  
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

//Turns all segments off
void SDisplay::off() { 
  digitalWrite(E, LOW);  
  digitalWrite(D, LOW);
  digitalWrite(C, LOW);
  digitalWrite(DP, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);  
}

//Displays and nuber between 0-9
//Uses recursive calls to dislpay similar patterns 
void SDisplay::displayNum(int num) {
    if (num == 0) {
        on(); 
        digitalWrite(DP, LOW);
        digitalWrite(G, LOW);
    } else if (num == 1) { 
        off();
        digitalWrite(C, HIGH);
        digitalWrite(B, HIGH);  
    } else if (num == 2) { 
        displayNum(0);
        digitalWrite(C, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);  
    } else if (num == 3) { 
        displayNum(1);  
        digitalWrite(D, HIGH);
        digitalWrite(A, HIGH);
        digitalWrite(G, HIGH);  
    } else if (num == 4) { 
        displayNum(1);  
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);  
    } else if (num == 5) { 
        displayNum(8);
        digitalWrite(B, LOW);
        digitalWrite(E, LOW); 
    } else if (num == 6) { 
        displayNum(5); 
        digitalWrite(E, HIGH);   
    } else if (num == 7) { 
        displayNum(1); 
        digitalWrite(A, HIGH);  
    } else if (num == 8) { 
        displayNum(0);
        digitalWrite(G, HIGH);     
    } else if (num == 9) { 
        displayNum(7); 
        digitalWrite(F, HIGH);  
        digitalWrite(G, HIGH);
    }
}