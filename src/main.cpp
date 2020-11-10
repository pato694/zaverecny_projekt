#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "esp_camera.h"
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include "SparkFunBME280.h"

// Wifi connection
const char* ssid = "DOHNALM";
const char* password = "23.09.1972Md.";

// Id to chat with bot
String chatId = "1482264689";

// Initialize Telegram BOT
String BOTtoken = "1463258443:AAG3CZn8XDMQs7bqG45iL472KoZsfylVCJY";

bool sendPhoto = false;

WiFiClientSecure clientTCP;

UniversalTelegramBot bot(BOTtoken, clientTCP);

//CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

#define FLASH_LED_PIN 4
bool flashState = LOW;

// Motion Sensor
bool motionDetected = false;

// Define I2C Pins for BME280
#define I2C_SDA 14
#define I2C_SCL 15

BME280 bme;
 
int botRequestDelay = 1000;   // mean time between scan messages
long lastTimeBotRan;     // last time messages' scan has been done

void handleNewMessages(int numNewMessages);
String sendPhotoTelegram();

// Get BME280 sensor readings and return them as a String variable
String getReadings(){
  float temperature, humidity;
  temperature = bme.readTempC();
  humidity = bme.readFloatHumidity();
  String message = "Teplota: " + String(temperature) + " ºC \n";
  message += "Vlhkost: " + String (humidity) + " % \n";
  return message;
}

// Indicates when motion is detected
static void IRAM_ATTR detectsMovement(void * arg){
  Serial.println("Zachycen pohyb.");
  motionDetected = true;
}

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}