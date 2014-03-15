
//arduino 1 - transmitter
int readOne = 0;
int readTwo = 0;
int readThree = 0;

int pinOne = 0;
int pinTwo = 3;
int pinThree = 2;

int thresOne = 150;
int thresTwo = 150;
int thresThree = 150;

int startTime = millis();

void setup()
{
  Serial.begin(9600);
  pinMode(pinOne, INPUT);
  pinMode(pinTwo, INPUT);
  pinMode(pinThree, INPUT);
}

void loop()
{
  //read and assign values
  readOne = analogRead(pinOne);
  readTwo = analogRead(pinTwo);
  readThree = analogRead(pinThree);


  //check if sitting
  if(readThree < thresThree)  //if the user is not sitting
  {
    Serial.println('d');                      //turn off the screen and let the comp now it
    startTime = millis();                //reset the thirty-minute timer to the current time, as the user has just taken a break
  }
  else                                                    //if the user is sitting
  {
    if( readOne < thresOne && readTwo < thresTwo)      //if both sensors return that the user has bad posture
    { //check if posture wrong
      Serial.println('a');                    //a means "turn the monitor off"
    }
    else if(readOne < thresOne || readTwo < thresTwo) //if only one sensor returns that the user has bad posture
    {
      Serial.println('b');                    //b means "create a popup"
    }
    else                                          //if the user has good posuture
    {
      Serial.println('c');                    //c means "the user's posture is okay"
    }
  }
    delay(1000);
}
