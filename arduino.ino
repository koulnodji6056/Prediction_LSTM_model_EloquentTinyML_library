#define ESP32 1
#include <EloquentTinyML.h>
#include <eloquent_tinyml/tensorflow.h> //comment it if you're using 0.0.5 version
//#include <eloquent_tinyml/tensorflow/esp32.h>
// sensor_model.h contains the array you exported from the previous step with xxd or tinymlgen
//#include "sensor_model.h"
#include "model.h"
//#include "arduino_model"

#define NUMBER_OF_INPUTS 7
#define NUMBER_OF_OUTPUTS 2
// in future projects you may need to tweak this value: it's a trial and error process
#define TENSOR_ARENA_SIZE 14*1024
//Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml; //uncomment it if you're using version 0.0.5
Eloquent::TinyML::TensorFlow::TensorFlow<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> tf; //comment it if you're using 0.0.5 version

void setup() {
  Serial.begin(115200);
  Serial.println("Initialization model");
  //tf.begin(sensor_model);
  //tf.begin(arduino_model);
  tf.begin(model);
  Serial.println("Model initialized");
}

void loop() {
  float input[7] = {25,	61, 22.1,	70.2,	70,	400,	804};       
  float output[2] = {0, 0};
  tf.predict(input, output);
  float hum_pred = output[1];
  float temp_pred = output[0];
  Serial.print("\t Temperature predicted: " );
  Serial.print(temp_pred );
  Serial.print("\t Humidity predicted: " );
  Serial.println(hum_pred );
 delay (10000);
}