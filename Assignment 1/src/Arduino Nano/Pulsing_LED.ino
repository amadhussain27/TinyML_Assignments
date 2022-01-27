
int LED = 24;                                    // Blue LED is attached to pin 24

void setup()
{
  pinMode(LED, OUTPUT);                           // Setting up pin 24 as an output
  
}

void loop()
{
  float pi, i;                                   // Declaration of variables
  
 for (pi = 0; pi < 6.283; pi = pi + 0.0001)      // Loop for Pi values (pi = 3.1412 and 2pi = 6.283) Pulsing between 0 to 360
{
  
  i = sin(pi) * 127.5 +127.5 ;                  // Sin function for setting up the brightness
  analogWrite(LED,i);                           // Light the LED
  delay(0.5);                                   //  wait
}
}
