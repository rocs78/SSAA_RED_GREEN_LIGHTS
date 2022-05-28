const int GreenbuttonPin = 2;
const int RedbuttonPin = 3;
const int GreenledPin =  5;
const int RedledPin =  6;
const int relay1 = 9;
const int relay2 = 10;

int GreenbuttonState = 0;
int RedbuttonState = 0;
int relay1state = HIGH;
int relay2state = LOW;

int redlight = 0;
int redledState = 0;
int greenlight = 0;
int greenledState = 0;


void setup()
{
  pinMode(GreenledPin, OUTPUT);
    pinMode(RedledPin, OUTPUT);
  pinMode(GreenbuttonPin, INPUT_PULLUP);
  pinMode(RedbuttonPin, INPUT_PULLUP);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  
}

void loop()
{


    if (greenlight == 0 && digitalRead(GreenbuttonPin) == LOW) {
    greenlight = 1;
    redlight = 0;
    greenledState=!greenledState;
    relay1state = LOW;
    redledState=0;
    relay2state = HIGH;

  }
  //if (greenlight == 1 && digitalRead(GreenbuttonPin) == HIGH) {   
  //  greenlight = 0;
  //}

 
    if (redlight == 0 && digitalRead(RedbuttonPin) == LOW) {
    redlight = 1;
    greenlight = 0;
    redledState=!redledState;
    relay2state = LOW;
    greenledState = 0;
    relay1state = HIGH;
  }
 // if (redlight == 1 && digitalRead(RedbuttonPin) == HIGH) {   
 //   redlight = 0;
 // }
   digitalWrite(GreenledPin, greenledState);
   digitalWrite(RedledPin, redledState);
       digitalWrite(relay1, relay1state);
       digitalWrite(relay2, relay2state);
  
 
}
