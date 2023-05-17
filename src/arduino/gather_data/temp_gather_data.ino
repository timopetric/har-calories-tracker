/*
 ESP8266 MQTT example
 This sketch demonstrates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.
 
 Prerequisites:
 
 PubSubClient -> Install the library through : Arduino -> Tools -> Manage Libraries -> type PubSubClient -> install the package created by Nick O'Leary (newest version)
 
 Git: https://github.com/knolleary/pubsubclient
 API: https://pubsubclient.knolleary.net/
  
ESP8266 first reads acceleration data, then it connects to an MQTT server "broker.mqtt-dashboard.com", and finally publishes acceleration measurements to the topic "RatkoACCData" 
    
 More info:
 "broker.mqtt-dashboard.com" is a publicly available MQTT broker. You can set your own MQTT broker on ESP8266 or your laptop
 MQTT introduction: https://www.hivemq.com/mqtt-essentials/
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include<Wire.h>
#include<Ticker.h>

#define INTERVAL 100
#define PIN_LED 2
#define I2C_ADD_MPU 104
#define I2C_ADD_BMP 118
#define TABLE_SIZE_MPU 7
#define GYRO_OBCUT 131
#define REG_GYRO_CONFIG 0x1B // 27
#define RATE 1
#define I2C_ADD_IO1 32
#define ACC_X_OUT 59
// Naslov registra za pospesek tudi na vodilu
#define ACC_MEAS_REG 59
// Naslov registra za ziroskop in tudi na vodilu
#define GYRO_MEAS_REG 67
// Naslov MPU9250 na I2C vodilu
#define MPU_ADD 104

// Meritve senzorja 
uint8_t gyroMeas[] = {0,0,0,0,0,0};
uint8_t accMeas[] = {0,0,0,0,0,0};

// Stevilo uzorcev za kalibracijo
#define CAL_NO 1000
// Stevilo uzorcev za branje
#define READ_NO 10
// Globalni stevec zanke 
uint8_t iter = 0;

// Update these with values suitable for your network.

//const char* ssid = "esp8266";
const char *ssid = "Mi Phone";
//const char* password = "adminadmin";
const char *password = "6a2ce2f58db9";
const char* mqtt_server = "broker.mqtt-dashboard.com";
const char* topic = "AljazACCData"; 
String str = "";


WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(1000)
char msg[MSG_BUFFER_SIZE];
int value = 0;

Ticker tick;
int32_t table[TABLE_SIZE_MPU];
float delilnik = 131.0f;
float acc_x_calib = 0.0;

// Kalibracijske vrednosti 
float gyroX_off = 0; 
float gyroY_off = 0; 
float gyroZ_off = 0; 
float accX_off = 0;
float accY_off = 0;
float accZ_off = 0;
float value_x;
float value_y;
float value_z;
// funkcije:
void beriPodatke();
void acc_config();


/*void beriPodatke() {
  Serial.println("b beri podatke");
  static uint32_t count = 0;
  digitalWrite(PIN_LED, 0);
  static float acc_x = 0.0f;
  int32_t table;
  
  //**** MPU-9250
  //**** Naslov registra 
  // "zapiši", od katerega naslova registra dalje želimo brati
  Wire.beginTransmission(I2C_ADD_MPU);
  Wire.write(ACC_X_OUT);
  Wire.endTransmission();
  
  //** Branje: pospešek v x_osi
  //** Zdaj mikrokrmilnik bere od naslova ACC_X_OUT
  //** Bere dva bajta prvi bajt: 
  Wire.requestFrom(I2C_ADD_MPU, 2);
  table = (int8_t)Wire.read();
  table = table << 8;
  table += (uint8_t)Wire.read();

  
  acc_x += ((table / delilnik)-acc_x_calib)/RATE;


  if (count % RATE == 0)
  {
    // Izpišemo
    Serial.print("ACC_X: X= ");
    Serial.print(acc_x);
    Serial.println("");

    // MQTT
    // sends acceleration data as string stored in msg variable
    client.loop();
    snprintf (msg, MSG_BUFFER_SIZE, "%4.2f", acc_x);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish(topic, msg);
    // resetiramo vrednost
    acc_x = 0;
  }

  
  // števec 
  count = count+1;
  digitalWrite(PIN_LED, 1);
}*/

void I2CReadRegister(uint8_t I2CDevice, uint8_t RegAdress, uint8_t NBytes, uint8_t *Value){
  //BRANJE
  Wire.beginTransmission(I2CDevice);//pošljemo naslov
  // Napravi sporočimo naslov registra, s katerega želimo brati:
  Wire.write(RegAdress);
  // Končamo prenos:
  Wire.endTransmission();
  
  // Napravi sporočimo, da želimo prebrati določeno število 8-bitnih registrov:
  Wire.requestFrom(I2CDevice, NBytes);
  for (int q = 0; q < NBytes; q++) {
    // Preberemo naslednji 8-bitni register oz. naslednji bajt:
    *Value = (uint8_t)Wire.read();
    Value++;
    //uint32_t vrednost = Wire.read();
  }

}

void beriPodatke() {
  //Serial.println("b beri podatke");
  static uint32_t count = 0;
  digitalWrite(PIN_LED, 0);
  static float acc_x = 0.0f, acc_y = 0.0f, acc_z = 0.0f;
  static float gyro_x = 0.0f, gyro_y = 0.0f, gyro_z = 0.0f;
  int16_t acc_table[3], gyro_table[3];

  //**** MPU-9250
  //**** Accelerometer Registers
  Wire.beginTransmission(I2C_ADD_MPU);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(I2C_ADD_MPU, 6);
  acc_table[0] = Wire.read() << 8 | Wire.read();
  acc_table[1] = Wire.read() << 8 | Wire.read();
  acc_table[2] = Wire.read() << 8 | Wire.read();

  //**** Gyroscope Registers
  Wire.beginTransmission(I2C_ADD_MPU);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(I2C_ADD_MPU, 6);
  gyro_table[0] = Wire.read() << 8 | Wire.read();
  gyro_table[1] = Wire.read() << 8 | Wire.read();
  gyro_table[2] = Wire.read() << 8 | Wire.read();

  acc_x += ((acc_table[0] / delilnik) - acc_x_calib) / RATE;
  //Serial.println(String(acc_x));
  acc_y += ((acc_table[1] / delilnik) - acc_x_calib) / RATE;
  acc_z += ((acc_table[2] / delilnik) - acc_x_calib) / RATE;

  gyro_x += gyro_table[0] / GYRO_OBCUT / RATE;
  gyro_y += gyro_table[1] / GYRO_OBCUT / RATE;
  gyro_z += gyro_table[2] / GYRO_OBCUT / RATE;
  /*str += String(acc_x);
  str += ";";
  str += String(acc_y);
  str += ";";
  str += String(acc_z);
  str += ";";
  str += String(gyro_x);
  str += ";";
  str += String(gyro_y);
  str += ";";
  str += String(gyro_z);*/



  //if (count % RATE == 0)
  //{
    // Accelerometer data
    /*Serial.print("Accelerometer: X= ");
    Serial.print(acc_x);
    Serial.print(", Y= ");
    Serial.print(acc_y);
    Serial.print(", Z= ");
    Serial.print(acc_z);
    Serial.println("");

    // Gyroscope data
    Serial.print("Gyroscope: X= ");
    Serial.print(gyro_x);
    Serial.print(", Y= ");
    Serial.print(gyro_y);
    Serial.print(", Z= ");
    Serial.print(gyro_z);
    Serial.println("");*/

    // MQTT
    // sends acceleration and gyroscope data as string stored in msg variable
    client.loop();
    unsigned long current_time = millis();
    snprintf(msg, MSG_BUFFER_SIZE, "%lu;0;%4.2f;%4.2f;%4.2f;%4.2f;%4.2f;%4.2f", current_time, acc_x, acc_y, acc_z, gyro_x, gyro_y, gyro_z);
    //snprintf(msg, MSG_BUFFER_SIZE, )
    //Serial.print("Publish message: ");
    //Serial.println(msg);
    //Serial.println(str.c_str());
    //client.publish(topic, "hellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohello");
    //client.publish(topic, str.c_str());
    client.publish(topic, msg);
    // resetiramo vrednost
    acc_x = 0;
    acc_y = 0;
    acc_z = 0;

    gyro_x = 0;
    gyro_y = 0;
    gyro_z = 0;
    str = "";
    //Serial.println("here in");
  //}
  //Serial.println("here out");
  //str = "";
  count = count+1;
  digitalWrite(PIN_LED, 1);
}


void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  Serial.println("here bitch");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void calibrateGyro(){
  //Funkcija za kalibracijo. Če ploščico pustimo v stanju mirovanja. Tu bi pričakoval 0, ampkak bo nekaj drugače od 0. Želimo ugotoviti koliko je ta razlika in ga naslednjič odstranimo,
  //ker to je nek bias, šum. S to funkcijo to naredimo. Tu najdemo povprečje meritev teh biasov, šumov. Podobno lahko naredimo za pospeškometer, le zamenjati moramo registre.
  uint32_t ITER = 1000; // Stevilo vzorcev za glajenje 
  int32_t tmp;
  Serial.println("Kalibracija ziroskopa");
  for(int i=0; i< CAL_NO; i++){
     I2CReadRegister(MPU_ADD,GYRO_MEAS_REG,6,gyroMeas);
     // GYRO_XOUT = Gyro_Sensitivity * X_angular_rate
     tmp = (((int8_t)gyroMeas[0] << 8) + (uint8_t)gyroMeas[1]);
     gyroX_off += tmp*1.0/131.0; //iz integerja v kotno histrost. Le deliti moramo s 131.
      // GYRO_YOUT = Gyro_Sensitivity * Y_angular_rate
     tmp = (((int8_t)gyroMeas[2] << 8) + (uint8_t)gyroMeas[3]);
     gyroY_off += tmp*1.0/131.0;
     // GYRO_ZOUT = Gyro_Sensitivity * Z_angular_rate
     tmp = (((int8_t)gyroMeas[4] << 8) + (uint8_t)gyroMeas[5]);
     gyroZ_off += tmp*1.0/131.0;
     Serial.print(".");
  }
  Serial.println("Konec kalibracije");

  gyroX_off /= CAL_NO;
  gyroY_off /= CAL_NO;
  gyroZ_off /= CAL_NO;
  
  /*Serial.println("Ziroskop X os");
  Serial.println(gyroX_off);
  Serial.println("Ziroskop Y os");
  Serial.println(gyroY_off);
  Serial.println("Ziroskop Z os");
  Serial.println(gyroZ_off);*/

}

/*void calibrateAccelerometer() {
  uint32_t ITER = 1000; // Number of samples for smoothing
  int32_t tmp;
  Serial.println("Calibrating accelerometer");

  for (int i = 0; i < CAL_NO; i++) {
    int16_t accelMeas[3];
    I2CReadRegister(MPU_ADD, ACC_MEAS_REG, 6, (uint8_t *)accelMeas);

    accelerometerX_off += accelMeas[0] / 16384.0;
    accelerometerY_off += accelMeas[1] / 16384.0;
    accelerometerZ_off += (accelMeas[2] / 16384.0) - 1.0; // Subtract 1g for the Z-axis

    Serial.print(".");
  }
  Serial.println("Calibration complete");

  accelerometerX_off /= CAL_NO;
  accelerometerY_off /= CAL_NO;
  accelerometerZ_off /= CAL_NO;

  /*Serial.println("Accelerometer X offset");
  Serial.println(accelX_off);
  Serial.println("Accelerometer Y offset");
  Serial.println(accelY_off);
  Serial.println("Accelerometer Z offset");
  Serial.println(accelZ_off);
}*/

void calibrateSensors(){
  //Funkcija za kalibracijo. Če ploščico pustimo v stanju mirovanja. Tu bi pričakoval 0, ampkak bo nekaj drugače od 0. Želimo ugotoviti koliko je ta razlika in ga naslednjič odstranimo,
  //ker to je nek bias, šum. S to funkcijo to naredimo. Tu najdemo povprečje meritev teh biasov, šumov. Podobno lahko naredimo za pospeškometer, le zamenjati moramo registre.
  uint32_t ITER = 1000; // Stevilo vzorcev za glajenje 
  int32_t tmp;
  Serial.println("Kalibracija ziroskopa in pospeskometra");
  for(int i=0; i< CAL_NO; i++){
     I2CReadRegister(MPU_ADD,GYRO_MEAS_REG,6,gyroMeas);
     // GYRO_XOUT = Gyro_Sensitivity * X_angular_rate
     tmp = (((int8_t)gyroMeas[0] << 8) + (uint8_t)gyroMeas[1]);
     gyroX_off += tmp*1.0/131.0; //iz integerja v kotno histrost. Le deliti moramo s 131.
      // GYRO_YOUT = Gyro_Sensitivity * Y_angular_rate
     tmp = (((int8_t)gyroMeas[2] << 8) + (uint8_t)gyroMeas[3]);
     gyroY_off += tmp*1.0/131.0;
     // GYRO_ZOUT = Gyro_Sensitivity * Z_angular_rate
     tmp = (((int8_t)gyroMeas[4] << 8) + (uint8_t)gyroMeas[5]);
     gyroZ_off += tmp*1.0/131.0;

     I2CReadRegister(MPU_ADD,ACC_MEAS_REG,6,accMeas);
     // ACC_XOUT = Acc_Sensitivity * X_acceleration
     tmp = (((int8_t)accMeas[0] << 8) + (uint8_t)accMeas[1]);
     accX_off += tmp*1.0/16384.0;
     // ACC_YOUT = Acc_Sensitivity * Y_acceleration
     tmp = (((int8_t)accMeas[2] << 8) + (uint8_t)accMeas[3]);
     accY_off += tmp*1.0/16384.0;
     // ACC_ZOUT = Acc_Sensitivity * Z_acceleration
     tmp = (((int8_t)accMeas[4] << 8) + (uint8_t)accMeas[5]);
     accZ_off += tmp*1.0/16384.0;
     
     Serial.print(".");
  }
  Serial.println("Konec kalibracije");

  gyroX_off /= CAL_NO;
  gyroY_off /= CAL_NO;
  gyroZ_off /= CAL_NO;

  accX_off /= CAL_NO;
  accY_off /= CAL_NO;
  accZ_off /= CAL_NO;
  
  /*Serial.println("Ziroskop X os");
  Serial.println(gyroX_off);
  Serial.println("Ziroskop Y os");
  Serial.println(gyroY_off);
  Serial.println("Ziroskop Z os");
  Serial.println(gyroZ_off);

  Serial.println("Pospeskometer X os");
  Serial.println(accX_off);
  Serial.println("Pospeskometer Y os");
  Serial.println(accY_off);
  Serial.println("Pospeskometer Z os");
  Serial.println(accZ_off);*/
}


void readData() {
  int32_t tmp;

  I2CReadRegister(MPU_ADD,GYRO_MEAS_REG,6,gyroMeas);
  // GYRO_XOUT = Gyro_Sensitivity * X_angular_rate
  tmp = (((int16_t)gyroMeas[0] << 8) + (uint8_t)gyroMeas[1]);
  value_x = tmp*1.0/131.0 - gyroX_off;
  // GYRO_YOUT = Gyro_Sensitivity * Y_angular_rate
  tmp = (((int16_t)gyroMeas[2] << 8) + (uint8_t)gyroMeas[3]);
  value_y = tmp*1.0/131.0 - gyroY_off;
  // GYRO_ZOUT = Gyro_Sensitivity * Z_angular_rate
  tmp = (((int16_t)gyroMeas[4] << 8) + (uint8_t)gyroMeas[5]);
  value_z = tmp*1.0/131.0 - gyroZ_off;

  //accelerometer
  uint8_t accelMeas[6];
  int16_t accelX, accelY, accelZ;
  float accelX_g, accelY_g, accelZ_g;

  I2CReadRegister(MPU_ADD,ACC_MEAS_REG,6,accelMeas);
  accelX = (((int16_t)accelMeas[0]) << 8) | accelMeas[1];
  accelY = (((int16_t)accelMeas[2]) << 8) | accelMeas[3];
  accelZ = (((int16_t)accelMeas[4]) << 8) | accelMeas[5];

  accelX_g = accelX / 16384.0;
  accelY_g = accelY / 16384.0;
  accelZ_g = accelZ / 16384.0;

  //Serial.print("Accel X: ");
  //Serial.println(accelX_g, accelY_g, accelZ_g, value_x, value_y, value_z);
  /*Serial.print(" g, Accel Y: ");
  Serial.print(accelY_g);
  Serial.print(" g, Accel Z: ");
  Serial.print(accelZ_g);
  Serial.println(" g");
  Serial.println(value_x);
  Serial.println(value_y);
  Serial.println(value_z);*/
  Serial.print(accelX_g);
  Serial.print(", ");
  Serial.print(accelY_g);
  Serial.print(", ");
  Serial.print(accelZ_g);
  Serial.print(", ");
  Serial.print(value_x);
  Serial.print(", ");
  Serial.print(value_y);
  Serial.print(", ");
  Serial.println(value_z);
}

void setup() {
  Serial.println("in setup first");
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setBufferSize(1000000);

  // Inicializiramo I2C na podanih pinih
  Wire.begin(12,14);
  // nastavimo frekvenco vodila na 100 kHz
  Wire.setClock(100000);

  Serial.println("in setup");
  // calibrate both sensors
  calibrateSensors();
  //calibrateGyro();
  //calibrateAccelerometer();

  tick.attach_ms(100, readData);
  //tick.attach_ms(100, beriPodatke);

  if (!client.connected()) {
    reconnect();
  }
}

void loop() {

}
