/*
 * Jack Witt 2/10/19 
 * SDisplay.h 
 *      The .h file for the Segment Display library 
 */ 

#ifndef SDisplay_h
#define SDisplay_h

#include "Arduino.h"

class SDisplay { 
    public:
        SDisplay(int seg_E, int seg_D, int seg_C, int seg_P, int seg_B, int seg_A, int seg_F, int seg_G);
        ~SDisplay(); 
        void on();
        void off();
        void displayNum(int num); 
    private: 
        //see 'onethrunune' project for background 
        int E, D, C, DP, B, A, F, G; 
};

#endif 