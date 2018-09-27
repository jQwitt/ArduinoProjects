//Pins 
/*  
 *  6  7   +  8  9
 *  
 *  G  F Com2 A  B
 *  ||||||||||||||
 *  ||||||||||||||
 *  E  D Com1 C  DP
 *  
 *  13 12  -  11 10
 */
const int E = 13; 
const int D = 12;
const int C = 11; 
const int DP = 10;
const int B = 9;
const int A = 8;
const int F = 7;
const int G = 6; 

//FUNC: turns all on
void on() 
{ 
  digitalWrite(E, HIGH);  
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

//FUNC: turns all off
void off() 
{ 
  digitalWrite(E, LOW);  
  digitalWrite(D, LOW);
  digitalWrite(C, LOW);
  digitalWrite(DP, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);  
}

//FUNC: displays given integer 
//PARAMS: num - int 0-9 that can be displayed
void displayNum(int num)
{
  if (num == 0)
  {
    digitalWrite(E, HIGH);  
    digitalWrite(D, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(DP, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(A, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
  }
  else if (num == 1) 
  { 
    digitalWrite(E, LOW);  
    digitalWrite(D, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(DP, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(A, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);  
  }
  else if (num == 2) 
  { 
    digitalWrite(E, HIGH);  
    digitalWrite(D, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(DP, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(A, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);  
  }
  else if (num == 3) 
  { 
    digitalWrite(E, LOW);  
    digitalWrite(D, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(DP, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(A, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);  
  }
  else if (num == 4) 
  { 
    digitalWrite(E, LOW);  
    digitalWrite(D, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(DP, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(A, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);  
  }
  else if (num == 5) 
  { 
    digitalWrite(E, LOW);  
    digitalWrite(D, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(DP, LOW);
    digitalWrite(B, LOW);
    digitalWrite(A, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);  
  }
  else if (num == 6) 
  { 
    digitalWrite(E, HIGH);  
    digitalWrite(D, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(DP, LOW);
    digitalWrite(B, LOW);
    digitalWrite(A, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);  
  }
  else if (num == 7) 
  { 
    digitalWrite(E, LOW);  
    digitalWrite(D, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(DP, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(A, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);  
  }
  else if (num == 8) 
  { 
    displayNum(0);
    digitalWrite(G, HIGH);     
  }
  else if (num == 9) 
  { 
    displayNum(7); 
    digitalWrite(F, HIGH);  
    digitalWrite(G, HIGH);
  }
 
}

void setup() 
{
  //Set all pins as output
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT); 
  pinMode(C, OUTPUT); 
  pinMode(DP, OUTPUT); 
  pinMode(B, OUTPUT); 
  pinMode(A, OUTPUT); 
  pinMode(F, OUTPUT); 
  pinMode(G, OUTPUT); 
  
  off();
}

void loop() 
{
  for (int i = 0; i < 10; i++) 
  { 
    displayNum(i);
    delay(1000);
    off();   
    delay(100);
  }
   
}
