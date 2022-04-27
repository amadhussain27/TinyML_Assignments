#include "class_IMU_Classifier.h"
#include <Arduino_LSM9DS1.h>

#include "IMU.h"
#include "Window.h"

float ax = 0, ay = 0, az = 0;
float gx = 0, gy = 0, gz = 0;

Window window;
Eloquent::ML::Port::Classifier clf;

void setup() {
  Serial.begin(115200);
  delay(3000);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1) delay(1000);
  }

  delay(3000);
}

void loop() {
  // await for IMU data
  if (!isIMUReady())
    return;

  readIMU(&ax, &ay, &az, &gx, &gy, &gz);

  float sample[] = {ax, ay, az, gx, gy, gz};

  // feed data to the window and wait until the window is full
  if (!window.transform(sample))
      return;

  // predict gesture
  Serial.print("Gesture: ");
  Serial.println(clf.predict(window.features));
}
