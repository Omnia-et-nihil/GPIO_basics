#include <buttons.h>

pullupButton singleButton;
pullupButton releaseButton;
pullupButton multiButton;
pullupButton holdButton;

unsigned long multi;
bool mTracker;
unsigned long multiTotal;

unsigned long hold;
bool holdTracker;
unsigned long holdTotal;

void setup(){
  singleButton.begin(12);
  releaseButton.begin(11);
  multiButton.begin(10);
  holdButton.begin(9);
  Serial.begin(9600);
}

void loop(){
  if(singleButton.singlePressRead()){
    Serial.println("Single press button read.");
  }

  if(releaseButton.releaseRead()){
    Serial.println("Release button read.");
  }

  multi = multiButton.multiClickRead(500);
  if(multi){
    Serial.println(multi);
    multiTotal = multi;
    multiTracker = true;
  }else if(multiTracker){
    Serial.print("Multi button pressed ");
    Serial.print(multiTotal);
    Serial.println(" times");
    multiTotal = 0;
    multiTracker = false;
  }

  hold = holdButton.pressHoldRead(1000);
  if(hold){
    Serial.println(hold);
    holdTotal = hold;
    holdTracker = true;
  }else if(holdTracker){
    Serial.print("Hold button pressed for");
    Serial.print(holdTotal);
    Serial.println(" seconds");
    holdTracker = false;
  }
}




