long distance1,distance2,distance3;
int lastPin;
void setup() {
  /*
  ######################
  # Sonar
  # vcc  digital port 2
  # trig digital port 3
  # echo digital port 4
  # Running on 5v
  ######################
  # LED
  # green  port 11
  # yellow port 12
  # red    port 13
  # LEDs running with 220 ohm resistors
  ######################
  */
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode (2,OUTPUT);//attach pin 2 to vcc
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  long currentDistance,duration;
  digitalWrite(2, HIGH);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(5);
  digitalWrite(3, LOW);
  pinMode (4, INPUT);
  duration = pulseIn(4, HIGH);
  currentDistance = microsecondsToCentimeters(duration);

  int light = turnOnLights(currentDistance,distance1,distance2,distance3);

  runLight(light,10,lastPin);

  delay(10);

  distance3 = distance2;
  distance2 = distance1;
  distance1 = currentDistance;
  lastPin = light;
}

void runLight(int pin,int timeDelay,int lPin){
  if(pin > 1 && lPin != pin){
    digitalWrite(lPin, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
    //delay(timeDelay);          // 1000 is one second
  }
}


long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

int turnOnLights(long currentDistance,long dis1,long dis2,long dis3){
  if(distance3 = NULL){
    return 0;
  }
  long distance = (currentDistance + dis1 + dis2 + dis3)/4;

  /*
  //###########
  //#debugging#
  //###########
  Serial.print(currentDistance);
  Serial.print(" currentDistance\n");
  Serial.print(dis1);
  Serial.print(" dis1\n");
  Serial.print(dis2);
  Serial.print(" dis2\n");
  Serial.print(dis3);
  Serial.print(" dis3\n");
  Serial.print(distance);
  Serial.print(" average\n");
  */

  if(distance > 150){
    return 11;
  }
  else if(distance >50){
    return 12;
  }
  else{
    return 13;
  }
}
