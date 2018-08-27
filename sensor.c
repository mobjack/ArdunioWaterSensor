/* Water Sensor with Relay Switch
 *  This code will monitor a water sensor (A0) and if water is 
 *  detected will cause a relay (Dig7) to close thus turning on my
 *  water pump.
 *  
 *  Arduino Pin Setup:
 *    Water Sensor Pins
 *      + (5v)
 *      - (GND)
 *      S (A0)
 *    Relay Pins  
 *      + (Vin)
 *      - (GND)
 *      S (Dig 7)
 */
// Set the minutes to run the pump and the delay, i hate calculating milli seconds in code
const int loopDelayMin = 1;
const int pumpRunMin = 2;

// Run Times
int loopDelaySec = loopDelayMin * 60;
int pumpTime = pumpRunMin * 60;

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(7, OUTPUT); //Relay Setup
}

void loop() {
  // read the analog in value:
  int waterLevel = analogRead(analogInPin);
  Serial.print("Current water level is: ");
  Serial.println(waterLevel);
  
  if (waterLevel > 600){
    Serial.print("Pump On\n");
    digitalWrite(7, HIGH);

    // Let the pump run for x minutes where x = pumpRunMin
    int pumpTrack = 0;
    while(pumpTrack < pumpTime){
      delay(1000);
      //Serial.print("Pump Timer ");
      //Serial.println(pumpTrack);

      // Keep the pump running if the water is still detected
      int waterCheck2 = analogRead(analogInPin);
      Serial.print("Water Check 2 is ");
      Serial.println(waterCheck2);
      if (waterCheck2 < 200){
         break;
      }
      pumpTrack++;
      
    } //end while   
    
    digitalWrite(7, LOW);
    Serial.print("Pump Off\n");
    } //End Level check
  //else{
    //Serial.print("Minute Check Complete\n");
  //}

  int loopTrack = 0;
  Serial.println("Sleeping for 1 Min");
  while(loopTrack < loopDelaySec){
    //delay(1000); //delay 1 second
    delay(10);
    //Serial.print("Loop Delay ");
    //Serial.println(loopTrack);
    loopTrack++;
  }
}
