// Automatic garden watering version 1.0

int analogPin = A0;
int val = 0;
bool state = true;
int on_time = 60000;

int night_val = 50;
int day_val = 150;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Setup serial
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
}

void loop() {
  
  val = analogRead(analogPin);
  Serial.println(val); // Used for setting correct values for day/night
  if ((val < night_val) && state){
      digitalWrite(2,HIGH);
      delay(on_time);  // keeps valve on for 2 minutes, or 120 seconds...
      digitalWrite(2,LOW);
      state = false;
    }

   if ((!state) && (val > day_val)){
      state = true;
    }
   delay(2000); // pauses the loop for 2 seconds
}
