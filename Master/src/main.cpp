#include <Arduino.h>  // Include the Arduino core library
#include <ESP8266WiFi.h>  // Include the ESP8266 WiFi library
#include <espnow.h>  // Include the ESP-NOW library

// REPLACE WITH RECEIVER MAC Address
uint8_t broadcastAddress[] = {0x34, 0x94, 0x54, 0x62, 0x03, 0x03};  // The MAC address of the receiver

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message 
{  // Define a struct to hold data to be sent over ESP-NOW
  char a[32];
  int b;
  float c;
  String d;
  bool e;
} struct_message;

// Create a struct_message called myData
struct_message myData;

unsigned long lastTime = 0;
unsigned long timerDelay = 2000; // send readings timer

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) 
{  // A callback function that is called after data is sent
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0) {  // If sendStatus is 0, the packet was delivered successfully
    Serial.println("Delivery success");
  } 
  else 
  {  // If sendStatus is not 0, the packet delivery failed
    Serial.println("Delivery fail");
  }
}

void setup() 
{
  // Init Serial Monitor
  Serial.begin(115200);  // Start the serial communication at a baud rate of 115200

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);  // Set the ESP8266 module to Station mode

  // Init ESP-NOW
  if (esp_now_init() != 0) {  // Initialize the ESP-NOW library and check if it was successful
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);  // Set the role of the ESP8266 module to controller
  esp_now_register_send_cb(OnDataSent);  // Register the OnDataSent callback function to get the status of transmitted packet

  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);  // Register the peer with the given MAC address and role as slave
}

void loop()
{
  if ((millis() - lastTime) > timerDelay) {  // If the specified time has elapsed
    // Set values to send
    strcpy(myData.a, "THIS IS A CHAR");  // Set the value of the char array to a string
    myData.b = random(1, 20);  // Set the value of an integer to a random number between 1 and 20
    myData.c = 1.2;  // Set the value of a float to 1.2
    myData.d = "Hello";  // Set the value of a String to "Hello"
    myData.e = false;  // Set the value of a boolean to false

    // Send message via ESP-NOW
    esp_now_send(broadcastAddress, (uint8_t *)&myData, sizeof(myData));  // Send the struct data over ESP-NOW

    lastTime = millis();  // Update the lastTime variable with the current time
  }
