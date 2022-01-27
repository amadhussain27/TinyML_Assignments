
 int LED = 24;                                  // Blue LED is attached to pin 24

void setup()
{
  pinMode(LED, OUTPUT);                         // Setting up pin 24 as an output
  
}

void loop()
{
  float in, out;                                // Declaration of variables
  
 for (in = 0; in < 6.283; in = in + 0.001)      // Loop for Pi values (pi = 3.1412 and 2pi = 6.283)
{
  
  out = sin(in) * 127.5 + 127.5 ;             // Sin function for setting up the brightness
  analogWrite(LED,out);                         // Light the LED
  delay(0.0001);                                //  wait
}
}
