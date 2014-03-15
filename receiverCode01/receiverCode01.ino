//arduino 2 - receiver
char action = 'k';                                                      //this is the message that the arduino on the chair sent
String currentAct = "okay";                                                  //this is the action that occurred just before this one

int startTime = millis();    //start the timer on when the user has started on the computer

int countA = 0;
int countB = 0;
int countD = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  /*
 if(millis() - startTime > (30*60*1000))                      //if it has been more than thirty minutes since the timer reset
   {
   Serial.println("#S|BTIME|[]#");                      //display a popup saying "Break Time!"
   }
   */

  if (Serial.available() > 0)                                  //if there is a message
  {
    action = Serial.read(); //read it into the action variable
    //Serial.println(action);
    //delayed here before

    if (action == 'a')                           //if the message is to turn off the screen
    {                         
      if(!currentAct.equals("offed"))             //and if the last message was to turn off the screen
      {
        Serial.println("#S|MONITOR|[]#");  //turn off the monitor
        currentAct = "offed";       //set the currentAct variable to "offed" so the computer knows the screen is offed
      }
      else                                        //if the screen is already off
      {
        if(countA > 10){
          Serial.println("#S|MONITOR|[]#");  //turn off the monitor
          currentAct = "offed";
          countA = 0;
        } 
        else {       
          countA++;
          countB = 0;
        }
      }
    }
    else if (action == 'b')                    //if the message is to create a popup
    {
      if(!currentAct.equals("popped")){          //and if the last message was to create a popup
        Serial.println("#S|POPUP|[]#");    //create a popup
        currentAct = "popped";      //set the currentAct variable to "popped" sot the computer knows there is a popup already
      }
      else                                       //if there is already a popup
      {
        if(countB > 10){
          Serial.println("#S|POPUP|[]#");  //create a popup
          currentAct = "popped";
          countB = 0;
        } 
        else {       
          countB++;
          countA = 0;
        }
      }
      //int rand = random(9000,16000);
    }
    else if (action == 'c')                      //if the user is sitting correctly
    {
      if(!currentAct.equals("okay"))                //and if the last action involved bad posture
      {
        currentAct = "okay";                  //set the currentAct variable to "okay" so the computer knows there is no problem so far
      }
    }
    else if (action == 'd')
    {
      if(!currentAct.equals("offed"))             //and if the last message was to turn off the screen
      {
        Serial.println("#S|MONITOR|[]#");  //turn off the monitor
        currentAct = "offed";       //set the currentAct variable to "offed" so the computer knows the screen is offed
      }
      else                                        //if the screen is already off
      {

      }

    }
    //int rand = random(4000,8000);
    //delay(rand);                             //wait ten seconds to check for the next message

  }
  else                                                      //if there is no message
  {
    //    Serial.println("No Serial Input Availible"); 
    //    delay(100);                            //only wait a tenth of a second to check for the next message
  }

}

