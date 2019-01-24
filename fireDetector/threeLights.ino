const int LEDR = 13;
const int LEDY = 12;
const int LEDG = 11; 
const int FLM = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(LEDR, OUTPUT);
  pinMode(LEDY, OUTPUT);  
  pinMode(LEDG, OUTPUT); 
  pinMode(FLM, INPUT); 

  start(); 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  alarm(); 
  delay(500);
}

/* Custom Display */ 
void start() { 
  //start sequence
  clear();
  blinkAll(3,50); 
  sequence(100);
  clear();  
}

void blinkAll(int num, int n) {
  for (int i = 0; i < num; i++) { 
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDY, HIGH);
    digitalWrite(LEDG, HIGH);
    delay(n); 
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDY, LOW);
    digitalWrite(LEDG, LOW);
    delay(n);
  }
}

void sequence(int n) { 
  onlyOn('r'); 
  delay(n);
  onlyOn('y');
  delay(n);
  onlyOn('g');
  delay(n);
}

void clear() {
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDG, LOW);
}

//turns input pin on and sets all others to off
void onlyOn(char color) {  
  switch (color) 
  { 
    case 'r': digitalWrite(LEDR, HIGH);
              digitalWrite(LEDY, LOW);
              digitalWrite(LEDG, LOW);
              break; 
    case 'y': digitalWrite(LEDY, HIGH);
              digitalWrite(LEDR, LOW);
              digitalWrite(LEDG, LOW);
              break;  
    case 'g': digitalWrite(LEDG, HIGH);
              digitalWrite(LEDR, LOW);
              digitalWrite(LEDY, LOW);
              break;  
  } 
}

bool fire = false; //var for yellow LED toggling 
void alarm() { 
  int value = analogRead(FLM);  
  //Serial.println(value); 

  if (value == 0) {
    if (!fire) { 
      onlyOn('y');
      delay(100); 
      fire = true; 
    }
    onlyOn('r'); 
    Serial.println("FIRE!");
  } else {  
    if (fire) { 
      onlyOn('y');
      delay(100); 
      fire = false; 
    }
    onlyOn('g');
    Serial.println("...");
  }
}

void lock() { 
  String combos[6] = { "ABC", "ACB", "BAC", "BCA", "CAB", "CBA" };
  String answer = combos[random(6)]; 

  //TO DO
}

