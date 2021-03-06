#include "Mic.h"
#include "Own_Audio_Classifier.h"

// tune as per your needs
#define SAMPLES 64
#define GAIN (1.0f/50)
#define SOUND_THRESHOLD 1000


float features[SAMPLES];
Mic mic;
Eloquent::ML::Port::Classifier clf;


void setup() {
    Serial.begin(115200);
    PDM.onReceive(onAudio);
    mic.begin();
    delay(3000);
}


void loop() {
    if (recordAudioSample()) {
        Serial.print("You said: ");
        Serial.println(clf.predict(features));

        delay(1000);
    }

    delay(20);
}


/**
 * PDM callback to update mic object
 */
void onAudio() {
    mic.update();
}


/**
 * Read given number of samples from mic
 */
bool recordAudioSample() {
    if (mic.hasData() && mic.data() > SOUND_THRESHOLD) {

        for (int i = 0; i < SAMPLES; i++) {
            while (!mic.hasData())
                delay(1);

            features[i] = mic.pop() * GAIN;
        }

        return true;
    }

    return false;
}
