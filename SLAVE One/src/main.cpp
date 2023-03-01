#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <espnow.h>

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message
{
  char a[32];
  int b;
  float c;
  String d;
  bool e;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len)
{
  // Copy the received data into the myData variable using memcpy
  memcpy(&myData, incomingData, sizeof(myData));
  
  // Print the length of the received data
  Serial.print("Bytes received: ");
  Serial.println(len);
  
  // Print the values of the different variables in myData
  Serial.print("Char: ");
  Serial.println(myData.a);
  Serial.print("Int: ");
  Serial.println(myData.b);
  Serial.print("Float: ");
  Serial.println(myData.c);
  Serial.print("String: ");
  Serial.println(myData.d);
  Serial.print("Bool: ");
  Serial.println(myData.e);
  Serial.println();
}

void setup()
{
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0)
  {
    // If initialization fails, print an error message and return
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  
  // Set the ESP-NOW role of the device to slave
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  
  // Register the callback function for receiving data
  esp_now_register_recv_cb(OnDataRecv);
}

void loop()
{
  // The loop function is empty as all the work is done in the callback function
}
