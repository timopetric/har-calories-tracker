/*void loop() {
        Serial.println("############## new loop ##############");
        // 100 random MotionSense test dataset samples
        float input0[30] = {-0.226400, -0.124900, 0.218100, 33.427900, 13.781400, -110.101600, -1.322900, -0.606200, -0.133200, 20.524800, 24.426900, -62.719400, -0.660400, -1.602400, 0.083200, -4.720200, -68.541200, -6.655800, -0.607700, -1.552900, 0.029700, -17.612600, -0.345200, 93.968700, -0.430600, -1.656800, 0.063200, -30.697300, -10.054800, 133.245000};
        Serial.println("input0: " + String(mlClassifier.predict(input0)) + " should be: 0");
        float input1[30] = {-0.790300, -0.060100, -0.002400, 12.452600, -3.058700, 22.359100, -0.706400, -0.326900, 0.058200, -7.136300, -12.458100, 22.858800, -0.577100, -0.561700, 0.129000, 1.463000, -14.277200, -38.222100, -0.590500, -0.759600, 0.111500, 0.656100, 7.946500, -80.705400, -0.721600, -1.070500, -0.023600, -4.886200, -18.154100, -112.158300};
        Serial.println("input1: " + String(mlClassifier.predict(input1)) + " should be: 0");
        float input2[30] = {-0.472700, -0.762300, 0.109500, 9.739300, -13.071900, -46.620600, -0.503300, -0.842100, 0.083200, 4.624100, -12.578700, -35.993300, -0.438200, -1.002200, 0.056700, -9.335200, -2.544800, -19.592400, -0.444600, -1.040000, 0.025000, -2.538500, -5.794800, 1.126700, -0.397800, -1.122800, 0.083100, -5.688900, -10.430300, 27.401500};
        Serial.println("input2: " + String(mlClassifier.predict(input2)) + " should be: 0");
        float input3[30] = {0.138500, -0.973100, 0.080100, -11.465600, -9.491200, 17.657300, 0.137800, -0.978800, 0.054200, -4.777100, -14.761500, 36.595500, 0.067100, -1.061100, 0.093500, -2.253500, -19.837800, 89.836000, 0.123500, -1.428000, 0.057200, 4.369700, -16.383000, 136.826800, 0.166000, -1.606400, -0.011400, -13.466600, -75.438000, 193.472200};
        Serial.println("input3: " + String(mlClassifier.predict(input3)) + " should be: 1");
        float input4[30] = {-0.420600, -1.468300, 0.117900, 24.572900, 42.613000, 140.923700, -0.486700, -1.507900, 0.232200, 19.929400, 41.294500, 113.214800, -0.295200, -0.732700, -0.062400, 10.294300, 65.476200, 30.267300, -0.112700, -0.513900, 0.135700, 39.431000, 22.072200, -26.390100, -0.270500, -0.169600, 0.047700, 66.319500, 9.134700, -55.650700};
        Serial.println("input4: " + String(mlClassifier.predict(input4)) + " should be: 0");
        float input5[30] = {-0.014800, -1.019300, 0.058800, 1.394700, -34.008800, 34.838200, 0.002000, -1.186200, 0.181900, -2.729700, -8.920700, 106.700100, 0.148100, -1.737300, -0.138800, -43.829200, -35.387400, 199.652000, 0.094600, -1.169100, 0.015000, -4.236600, -77.614900, 153.114700, 0.616100, -0.332800, 0.267000, 12.622900, 42.649300, -106.557900};
        Serial.println("input5: " + String(mlClassifier.predict(input5)) + " should be: 1");
        float input6[30] = {-0.476600, -0.567100, 0.166500, 9.728400, -20.456600, -75.977900, -0.543500, -0.723400, 0.091900, 2.883900, -15.438100, -60.877500, -0.591500, -0.805800, 0.044300, -4.312200, -18.290900, -39.069500, -0.504100, -1.053100, 0.023000, 6.639300, -18.532900, -14.771000, -0.490400, -1.112200, -0.015800, 1.801900, -17.994000, 13.481700};
        Serial.println("input6: " + String(mlClassifier.predict(input6)) + " should be: 0");
        float input7[30] = {0.031500, -0.963700, 0.005000, -11.871000, -32.417800, 21.435600, 0.076700, -1.089200, 0.049900, -11.012200, -25.941300, 73.648500, 0.156800, -1.525500, -0.004800, -37.415700, -22.201600, 182.559900, 0.453800, -1.552400, 0.048400, -34.536100, -90.588900, 209.208800, 0.597900, -0.498400, 0.101100, 41.680200, -1.165300, -49.515200};
        Serial.println("input7: " + String(mlClassifier.predict(input7)) + " should be: 1");
        float input8[30] = {0.446100, -1.820500, -0.080600, -35.865300, -83.414400, 226.625300, 0.366800, -1.108300, 0.013700, 17.462600, -9.324100, 121.976400, 0.404900, -0.400400, 0.255300, 47.006900, 36.244600, -181.149500, 0.143300, -1.126600, 0.210100, 51.846800, -25.614900, -250.503000, -0.948700, -1.993900, -0.070800, -6.420600, -10.315700, -246.742000};
        Serial.println("input8: " + String(mlClassifier.predict(input8)) + " should be: 1");
        float input9[30] = {0.107500, -1.077800, 0.078500, 4.050800, -33.006600, 67.089900, 0.233800, -1.430100, 0.170400, -27.443100, 2.810400, 158.352000, 0.430800, -1.707000, -0.018200, -14.241900, -71.311600, 213.182500, 0.265900, -0.663200, 0.062200, 29.169000, -22.504200, 36.222200, 0.307300, -0.462400, 0.239100, 41.385500, 55.452300, -183.557200};
        Serial.println("input9: " + String(mlClassifier.predict(input9)) + " should be: 1");
        float input10[30] = {0.187900, -1.017200, 0.162200, -16.706100, -19.692000, 51.019900, 0.177200, -0.975100, 0.109800, -18.365600, -6.557700, 24.442100, 0.182200, -0.974600, 0.086800, -12.826100, -13.264400, 20.609300, 0.135800, -0.993000, 0.072700, -3.304500, -13.546000, 36.703900, 0.126500, -1.056200, 0.099300, -2.638100, -21.462200, 74.260400};
        Serial.println("input10: " + String(mlClassifier.predict(input10)) + " should be: 1");
        float input11[30] = {0.090300, -1.091000, 0.132700, -1.380900, -23.291200, 80.180300, 0.229800, -1.556900, 0.125300, -38.922500, -7.597500, 191.319200, 0.519000, -1.514200, -0.077800, -6.426700, -75.085600, 221.686100, 0.620200, -0.404500, 0.084400, 50.496200, 47.444600, -56.910500, 0.186100, -0.751600, 0.228400, 75.547700, 15.821000, -246.654100};
        Serial.println("input11: " + String(mlClassifier.predict(input11)) + " should be: 1");
        float input12[30] = {-0.378900, -1.291300, 0.039600, -27.154600, 8.363200, 91.942000, -0.541800, -1.210200, -0.038400, -25.288500, 6.821300, 99.767500, -0.410400, -1.089300, -0.030300, -18.452300, 14.960200, 74.698600, -0.352200, -0.819700, -0.008200, 0.047000, 23.396500, 16.694600, -0.273900, -0.494600, 0.060600, 29.479000, 10.257100, -60.517600};
        Serial.println("input12: " + String(mlClassifier.predict(input12)) + " should be: 0");
        float input13[30] = {0.115500, -1.058200, 0.224400, -26.745000, -18.056100, 30.660400, 0.095500, -0.976400, 0.097700, -9.962600, -22.567600, 16.014000, 0.119500, -1.003400, 0.088300, -11.443400, -32.615700, 28.801300, 0.112400, -1.144900, 0.109200, -22.244200, -35.963000, 87.552400, 0.379800, -1.696700, 0.165800, -61.834700, -45.828500, 205.214500};
        Serial.println("input13: " + String(mlClassifier.predict(input13)) + " should be: 1");
        float input14[30] = {0.032100, -1.051900, 0.080100, -2.636600, -23.550000, 65.618000, 0.086500, -1.380700, 0.105300, -15.743000, 2.186800, 155.068800, 0.348300, -1.829100, -0.074000, -37.094900, -73.326100, 225.221500, 0.401100, -0.628700, 0.102500, 19.154200, -38.056900, 37.423000, 0.326100, -0.571900, 0.223700, 31.793300, 61.623600, -200.717500};
        Serial.println("input14: " + String(mlClassifier.predict(input14)) + " should be: 1");
        float input15[30] = {-0.046900, -0.294600, 0.337100, 33.050000, -12.000200, -74.764900, -0.126000, -0.163500, 0.210400, 54.128600, -13.133800, -100.953400, -0.730900, -0.364600, 0.166000, 30.505600, -5.429900, -84.962600, -0.919700, -0.853500, 0.092900, 8.614900, -23.579500, -47.655000, -0.840600, -1.348100, 0.068300, -4.938800, -21.148500, 5.978600};
        Serial.println("input15: " + String(mlClassifier.predict(input15)) + " should be: 0");
        float input16[30] = {-0.426600, -0.395100, 0.137500, 29.645400, 4.909800, -72.158000, -0.531300, -0.472800, 0.212100, 19.499400, -26.562900, -74.393100, -0.547000, -0.604900, 0.219500, -4.922500, -33.652600, -67.024400, -0.621600, -0.774000, 0.114400, -16.107200, -20.470600, -54.170800, -0.613600, -1.007800, 0.099800, -10.846200, -34.092200, -24.216000};
        Serial.println("input16: " + String(mlClassifier.predict(input16)) + " should be: 0");
        float input17[30] = {-0.288600, -1.927600, -0.133700, 4.902300, 26.395600, -250.503000, -1.592100, -1.602300, -0.154900, -18.414000, 40.662900, -76.131100, 0.403900, -1.175700, 0.206600, -17.580900, 32.618600, 135.574900, 0.081600, -1.081600, 0.224700, -27.616800, -2.208000, 57.655100, 0.217800, -0.976900, 0.115800, -24.191800, -10.776700, 25.068000};
        Serial.println("input17: " + String(mlClassifier.predict(input17)) + " should be: 1");
        float input18[30] = {0.654900, -0.582300, -0.003100, 67.190100, 47.712600, -62.736600, 0.335100, -0.826500, -0.037300, 94.599300, -8.597800, -243.636600, -0.322700, -1.863300, -0.381400, -6.127400, 85.314700, -250.503000, -1.956600, -1.598600, -0.729700, -16.747100, 59.015700, -85.328800, 0.054700, -1.212100, -0.029400, -31.266200, 39.169200, 151.051200};
        Serial.println("input18: " + String(mlClassifier.predict(input18)) + " should be: 1");
        float input19[30] = {-0.691500, -1.520400, 0.009800, -14.813400, 12.631900, 128.958800, -0.523200, -1.422300, 0.047000, -19.308900, 30.465500, 128.058700, -0.484300, -0.900900, 0.041400, -10.253300, 33.644900, 47.787000, -0.024300, -0.312100, 0.254500, 27.744900, -8.655800, -59.175000, -0.054200, -0.266300, 0.311000, 37.618700, -35.240600, -125.753400};
        Serial.println("input19: " + String(mlClassifier.predict(input19)) + " should be: 0");
}*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Ticker.h>
#include <PeakDetection.h>
#include "MlClassifier.h"

// Replace with your MQTT broker details
const char* mqttServer = "broker.mqtt-dashboard.com";
const int mqttPort = 1883;
const char* mqttUser = "your_mqtt_username";
const char* mqttPassword = "your_mqtt_password";

// Replace with your Wi-Fi credentials
const char* ssid = "fake TV";
const char* password = "testtest1";

// Replace with your username and password
#define USERNAME "Mi Phone"
#define PASSWORD "6a2ce2f58db9"

// Global flag to indicate if MQTT callback has been executed
bool mqttCallbackExecuted = false;




// Initialize server on port 80
ESP8266WebServer server(80);

// Initialize MQTT client
WiFiClient espClient;
PubSubClient client(espClient);

// Global variables
const int PIN_LED = 2; // GPIO2
bool ledState = false;
String mqttResponse; // Variable to store the MQTT response
int count_walk = 0;
int count_run = 0;
int count_bike = 0;
int count_non = 0;
int history_walk = 0;
int history_run = 0;
int history_bike = 0;
char *history_date;
int yesterday_walk = 0;
int yesterday_run = 0;
int yesterday_bike = 0;
char *yesterday_date;





// ------------------------------------------

#define WINDOW_SIZE 50

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
uint8_t accelMeas[6];  // TODO: could be accMeas - refractor

// Stevilo uzorcev za kalibracijo
#define CAL_NO 1000
// Stevilo uzorcev za branje
#define READ_NO 10
// Globalni stevec zanke 
uint8_t iter = 0;
uint8_t iter_win = 0;

// array of doubles of size 30
float window_prediction[6*WINDOW_SIZE];

int iterSampleCount = 0;
int lastSampleIter = 0;
float delAccel = 1.0/16384.0;
float delGyro = 1.0/131.0;
int prediction = 1;

PeakDetection peakDetectionAccX;                     // create PeakDetection object
PeakDetection peakDetectionAccY;                     // create PeakDetection object
PeakDetection peakDetectionAccZ;                     // create PeakDetection object
PeakDetection peakDetectionGyrX;                     // create PeakDetection object
PeakDetection peakDetectionGyrY;                     // create PeakDetection object
PeakDetection peakDetectionGyrZ;                     // create PeakDetection object

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(1000)
char msg[MSG_BUFFER_SIZE];
int value = 0;

Ticker tick;
int32_t table[TABLE_SIZE_MPU];
float delilnik = 131.0f;
float acc_x_calib = 0.0;

// Kalibracijske vrednosti 
float gyroX_off = -2.16; 
float gyroY_off = -6.40; 
float gyroZ_off = 42.28; 
float accX_off = -279.41;
float accY_off = -16276.09;
float accZ_off = 3829.15;

float gyro_x;
float gyro_y;
float gyro_z;
float acc_x;
float acc_y;
float acc_z;
int16_t accelX;
int16_t accelY;
int16_t accelZ;


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


void calibrateSensors(){
    //Funkcija za kalibracijo. Če ploščico pustimo v stanju mirovanja. Tu bi pričakoval 0, ampkak bo nekaj drugače od 0. Želimo ugotoviti koliko je ta razlika in ga naslednjič odstranimo,
    //ker to je nek bias, šum. S to funkcijo to naredimo. Tu najdemo povprečje meritev teh biasov, šumov. Podobno lahko naredimo za pospeškometer, le zamenjati moramo registre.
    int32_t tmp;
    Serial.println("Kalibracija ziroskopa in pospeskometra");
    for(int i=0; i< CAL_NO; i++){
         I2CReadRegister(MPU_ADD,GYRO_MEAS_REG,6,gyroMeas);
         // GYRO_XOUT = Gyro_Sensitivity * X_angular_rate
         tmp = (((int8_t)gyroMeas[0] << 8) + (uint8_t)gyroMeas[1]);
         gyroX_off += tmp; //iz integerja v kotno histrost. Le deliti moramo s 131.
            // GYRO_YOUT = Gyro_Sensitivity * Y_angular_rate
         tmp = (((int8_t)gyroMeas[2] << 8) + (uint8_t)gyroMeas[3]);
         gyroY_off += tmp;
         // GYRO_ZOUT = Gyro_Sensitivity * Z_angular_rate
         tmp = (((int8_t)gyroMeas[4] << 8) + (uint8_t)gyroMeas[5]);
         gyroZ_off += tmp;

         I2CReadRegister(MPU_ADD,ACC_MEAS_REG,6,accMeas);
         // ACC_XOUT = Acc_Sensitivity * X_acceleration
         tmp = (((int8_t)accMeas[0] << 8) + (uint8_t)accMeas[1]);
         accX_off += tmp;
         // ACC_YOUT = Acc_Sensitivity * Y_acceleration
         tmp = (((int8_t)accMeas[2] << 8) + (uint8_t)accMeas[3]);
         accY_off += tmp;
         // ACC_ZOUT = Acc_Sensitivity * Z_acceleration
         tmp = (((int8_t)accMeas[4] << 8) + (uint8_t)accMeas[5]);
         accZ_off += tmp;
         
         Serial.print(".");
    }
    Serial.println("Konec kalibracije");

    gyroX_off /= CAL_NO;
    gyroY_off /= CAL_NO;
    gyroZ_off /= CAL_NO;

    accX_off /= CAL_NO;
    accY_off /= CAL_NO;
    accZ_off /= CAL_NO;
    
    Serial.print("Ziroskop X os ");
    Serial.println(gyroX_off);
    Serial.print("Ziroskop Y os ");
    Serial.println(gyroY_off);
    Serial.print("Ziroskop Z os ");
    Serial.println(gyroZ_off);

    Serial.print("Pospeskometer X os ");
    Serial.println(accX_off);
    Serial.print("Pospeskometer Y os ");
    Serial.println(accY_off);
    Serial.print("Pospeskometer Z os ");
    Serial.println(accZ_off);
}

void readData() {
    int32_t tmp;

    I2CReadRegister(MPU_ADD,GYRO_MEAS_REG,6,gyroMeas);
    // GYRO_XOUT = Gyro_Sensitivity * X_angular_rate
    tmp = (((int8_t)gyroMeas[0] << 8) + (uint8_t)gyroMeas[1]);
    gyro_x = (tmp - gyroX_off) *delGyro;
    // GYRO_YOUT = Gyro_Sensitivity * Y_angular_rate
    tmp = (((int8_t)gyroMeas[2] << 8) + (uint8_t)gyroMeas[3]);
    gyro_y = (tmp - gyroY_off) *delGyro;
    // GYRO_ZOUT = Gyro_Sensitivity * Z_angular_rate
    tmp = (((int8_t)gyroMeas[4] << 8) + (uint8_t)gyroMeas[5]);
    gyro_z = (tmp - gyroZ_off) *delGyro;

    float accelX_g, accelY_g, accelZ_g;

    I2CReadRegister(MPU_ADD, ACC_MEAS_REG,6,accMeas);
    tmp = (((int8_t)accMeas[0] << 8) + (uint8_t)accMeas[1]);
    accelX_g = (tmp - accX_off) * delAccel;
    tmp = (((int8_t)accMeas[2] << 8) + (uint8_t)accMeas[3]);
    accelY_g = (tmp - accY_off) * delAccel - 1.0;
    tmp = (((int8_t)accMeas[4] << 8) + (uint8_t)accMeas[5]);
    accelZ_g = (tmp - accZ_off) * delAccel;

    peakDetectionAccX.add(accelX_g);
    peakDetectionAccY.add(accelY_g);
    peakDetectionAccZ.add(accelZ_g);

    peakDetectionGyrX.add(gyro_x);
    peakDetectionGyrY.add(gyro_y);
    peakDetectionGyrZ.add(gyro_z);

    if (++iter % 10 == 0) {  // to achieve 10Hz with 10 sample smoothing
        double filAccX = peakDetectionAccX.getFilt();
        double filAccY = peakDetectionAccY.getFilt();
        double filAccZ = peakDetectionAccZ.getFilt();
        double filGyrX = peakDetectionGyrX.getFilt();
        double filGyrY = peakDetectionGyrY.getFilt();
        double filGyrZ = peakDetectionGyrZ.getFilt();
        // Serial.printf("accelX_g: %8.4lf, accelY_g: %8.4lf, accelZ_g: %8.4lf, gyro_x: %8.4lf, gyro_y: %8.4lf, gyro_z: %8.4lf\n", filAccX, filAccY, filAccZ, filGyrX, filGyrY, filGyrZ);

        // fill array window_prediction with data combining all 6 axis 5 times (30 samples)
        window_prediction[iter_win*6] = (float) filAccX;
        window_prediction[iter_win*6+1] = (float) filAccY;
        window_prediction[iter_win*6+2] = (float) filAccZ;
        window_prediction[iter_win*6+3] = (float) filGyrX;
        window_prediction[iter_win*6+4] = (float) filGyrY;
        window_prediction[iter_win*6+5] = (float) filGyrZ;
        iter_win += 1;

        if (iter_win == WINDOW_SIZE) {
            // 50 samples - 5 seconds - collected, time to classify
            
            // classify data
            prediction = mlClassifier.predict(window_prediction);

            // array of thresholds for each class
            // labels = ["wlk", "bik", "run", "non"]
            const float THRESHOLDS[4] = {1.8, 1.2, 1.9, 999999.9};
            const int AWAY_FROM_PREVIOUS_PEAK[4] = {8, 7, 5, 99};
            int *COUNTERS[4] = {&count_walk, &count_bike, &count_run, &count_non};

            float threshold = THRESHOLDS[prediction];
            int away_from_previous_peak = AWAY_FROM_PREVIOUS_PEAK[prediction];

            // select counter for current class
            int *counter = COUNTERS[prediction];

            for (int zamik = 0; zamik < WINDOW_SIZE; zamik++) {
                iterSampleCount++;
                float accX = window_prediction[zamik*6];
                float accY = window_prediction[zamik*6+1];
                float accZ = window_prediction[zamik*6+2];
                float intensity = sqrt(accX*accX + accY*accY + accZ*accZ);

                // Serial.printf("iterSampleCount: %d, intensity: %f, threshold: %f, lastSampleIter: %d, away_from_previous_peak: %d\n", iterSampleCount, intensity, threshold, lastSampleIter, away_from_previous_peak);

                if (intensity > threshold && iterSampleCount - lastSampleIter > away_from_previous_peak) {
                    lastSampleIter = iterSampleCount;
                    (*counter)++;
                    
                    Serial.printf("prediction: %d, counters: bike %d, run %d, walk %d\n", prediction, count_bike, count_run, count_walk);

                }
            }            

            Serial.println("Classifier prediction: " + String(prediction));
            Serial.print("\t");
            for (int i = 0; i < WINDOW_SIZE; i++) {
                Serial.printf("%7.4f", window_prediction[i]);
            }
            Serial.println();
            
            iter_win = 0;
        }


        // client.loop();
        // snprintf(msg, MSG_BUFFER_SIZE, "%d;%.4f;%.4f;%.4f;%.4f;%.4f;%.4f", msgSendCount++, filAccX, filAccY, filAccZ, filGyrX, filGyrY, filGyrZ);
        // // Serial.print("Publish message: ");
        // // Serial.println(msg);
        // client.publish(topic, msg);

        iter = 0;
    }


    
}


    // "sketch": "har-calories-tracker/src/arduino/temp_gather_data/temp_gather_data.ino",


// ------------------------------------------


/* ----------------------------------------------------------------
 * is_authentified:
 */
// Check if header is present and correct
bool is_authentified(){
    if (server.hasHeader("Cookie")){
        String cookie = server.header("Cookie");
        if (cookie.indexOf("ESPSESSIONID=1") != -1) {
            return true;
        }
    }
    return false;
}

/* ----------------------------------------------------------------
 * handleLogin:
 */
// Login page, also called for disconnect
void handleLogin(){
    String msg;
    if (server.hasHeader("Cookie")){
        String cookie = server.header("Cookie");
    }
    if (server.hasArg("DISCONNECT")){
        server.sendHeader("Location","/login");
        server.sendHeader("Cache-Control","no-cache");
        server.sendHeader("Set-Cookie","ESPSESSIONID=0");
        server.send(301);
        return;
    }
    if (server.hasArg("USERNAME") && server.hasArg("PASSWORD")){
        if (server.arg("USERNAME") == USERNAME &&  server.arg("PASSWORD") == PASSWORD ){
            server.sendHeader("Location","/");
            server.sendHeader("Cache-Control","no-cache");
            server.sendHeader("Set-Cookie","ESPSESSIONID=1");
            server.send(301);
            return;
        }
        msg = "Wrong username/password! try again.";
    }
    String content = "<html><body><form action='/login' method='POST'>To log in, enter user id and password:<br>";
    content += "User:<input type='text' name='USERNAME' placeholder='user name'><br>";
    content += "Password:<input type='password' name='PASSWORD' placeholder='password'><br>";
    content += "<input type='submit' name='SUBMIT' value='Submit'></form>" + msg + "<br>";
    content += "You can also go <a href='/inline'>here</a></body></html>";
    server.send(200, "text/html", content);
}

/* ----------------------------------------------------------------
 * handleRoot:
 */
// Root page can be accessed only if authentication is OK
String getCountersHTML() {
    String countersHTML = "";
    countersHTML += "<div class='counter-column' style='display: inline-block; margin-right: 20px;'>";
    countersHTML += "<h4>Walking</h4>";
    countersHTML += "<p id='walking-counter'>" + String(count_walk) + "</p>";
    countersHTML += "</div>";
    countersHTML += "<div class='counter-column' style='display: inline-block; margin-right: 20px;'>";
    countersHTML += "<h4>Jogging</h4>";
    countersHTML += "<p id='jogging-counter'>" + String(count_run) + "</p>";
    countersHTML += "</div>";
    countersHTML += "<div class='counter-column' style='display: inline-block;'>";
    countersHTML += "<h4>Cycling</h4>";
    countersHTML += "<p id='cycling-counter'>" + String(count_bike) + "</p>";
    countersHTML += "</div>";

    return countersHTML;
}

void handleRoot() {
    String header;
    if (!is_authentified()){
        server.sendHeader("Location","/login");
        server.sendHeader("Cache-Control","no-cache");
        server.send(301);
        return;
    }

//   while (!mqttCallbackExecuted) {
//     client.loop();
//     delay(10);
//   }
//   mqttCallbackExecuted = false;

    // Add HTML code with JavaScript for counter
    String content = "<html><body><h2>Hello! You have successfully connected to ESP8266!</h2><br>";
    content += "You can access this page until you <a href=\"/login?DISCONNECT=YES\">disconnect</a><br><hr />";

    // Add HTML code to turn on/off the built-in LED light
    content += "<form action='/led' method='POST'>";
    content += "<button name='led' value='" + String(!ledState) + "'>" + (ledState ? "Turn off" : "Turn on") + " LED</button>";
    content += "</form>";

    // Add HTML code for history search window
    content += "<br><h3>Search History</h3>";
    content += "<form action='/history' method='POST'>";
    content += "Date: <input type='text' name='date'><br>"; // Changed type to 'text'
    content += "<input type='submit' name='submit' value='Search'>";
    content += "</form>";

    // Add JavaScript code for the counters
    content += "<br><h3>Counters:</h3>";
    content += getCountersHTML();
    content += "<button onclick='endActivity()'>End activity</button>";
    content += "<button onclick='redirectToYesterday()'>Go to Yesterday</button>";
    content += "<script>";
    content += "setInterval(updateCounters, 5000);";
    content += "function updateCounters() {";
    content += "  var xhttp = new XMLHttpRequest();";
    content += "  xhttp.onreadystatechange = function() {";
    content += "    if (this.readyState == 4 && this.status == 200) {";
    content += "      var response = JSON.parse(this.responseText);";
    content += "      document.getElementById('walking-counter').innerHTML = response.count_walk;";
    content += "      document.getElementById('jogging-counter').innerHTML = response.count_run;";
    content += "      document.getElementById('cycling-counter').innerHTML = response.count_bike;";
    content += "    }";
    content += "  };";
    content += "  xhttp.open('GET', '/getCounters', true);";
    content += "  xhttp.send();";
    content += "}";
    content += "function endActivity() {";
    content += "  var xhttp = new XMLHttpRequest();";
    content += "  xhttp.onreadystatechange = function() {";
    content += "    if (this.readyState == 4 && this.status == 200) {";
    content += "      document.getElementById('counters').innerHTML = this.responseText;";
    content += "    }";
    content += "  };";
    content += "  xhttp.open('GET', '/updateCounter', true);";
    content += "  xhttp.send();";
    content += "}";
    content += "function redirectToYesterday() {";
    content += "  window.location.href = '/yesterday';";
    content += "}";
    content += "</script>";

    content += "</body></html>";
    server.send(200, "text/html", content);
}

// Handle the '/getCounters' endpoint
void handleGetCounters() {
    String response = "{";
    response += "\"count_walk\": " + String(count_walk) + ",";
    response += "\"count_run\": " + String(count_run) + ",";
    response += "\"count_bike\": " + String(count_bike);
    response += "}";

    server.send(200, "application/json", response);
}

// Handle the '/updateCounter' endpoint
void handleUpdateCounter() {
    if (client.connected()) {
        String send = "STORE;" + String(count_walk) + ";" + String(count_run) + ";" + String(count_bike);
        client.publish("AljazACCData", send.c_str());
        count_walk = 0; count_run = 0; count_bike = 0;
    }

    count_walk = 0;
    count_run = 0;
    count_bike = 0;

    while (!mqttCallbackExecuted) {
        client.loop();
        delay(10);
    }
    String countersHTML = getCountersHTML();

    server.send(200, "text/html", countersHTML);
}


/* ----------------------------------------------------------------
 * handleLED:
 */
void handleLED(){
    if (!is_authentified()){
        server.sendHeader("Location","/login");
        server.sendHeader("Cache-Control","no-cache");
        server.send(301);
        return;
    }
    
    if (server.hasArg("led")) {
        ledState = server.arg("led") == "1";
        digitalWrite(PIN_LED, ledState ? HIGH : LOW);
    }
    
    server.sendHeader("Location","/");
    server.sendHeader("Cache-Control","no-cache");
    server.send(301);
}

/* ----------------------------------------------------------------
 * handleHistory:
 */
void handleHistory(){
    if (!is_authentified()){
        server.sendHeader("Location","/login");
        server.sendHeader("Cache-Control","no-cache");
        server.send(301);
        return;
    }
    
    if (server.hasArg("date")) {
        String date = server.arg("date");
        date = "DATE;" + date;
        // Serial.print(date);
        
        // Publish MQTT request
        if (client.connected()) {
            client.publish("AljazACCData", date.c_str());
        }
    }
    
    // Redirect to a new HTML page to display the response
    server.sendHeader("Location","/response");
    server.sendHeader("Cache-Control","no-cache");
    server.send(301);
}

/* ----------------------------------------------------------------
 * handleResponse:
 */
void handleResponse(){
    if (!is_authentified()){
        server.sendHeader("Location","/login");
        server.sendHeader("Cache-Control","no-cache");
        server.send(301);
        return;
    }

    while (!mqttCallbackExecuted) {
        Serial.println("in response");
        client.loop();
        delay(10);
    }

        Serial.println("fdsfasf");
        Serial.println(history_walk);
        Serial.println(history_run);
        Serial.println(history_bike);

    
        //   String content = "<html><body>";
        
        //   // Add MQTT response here
        //   content += "<h2>MQTT Response:</h2>";
        //   content += "<p>" + mqttResponse + "</p>";
        
        //   content += "</body></html>";
        //   server.send(200, "text/html", content);
        String content = "<html><body><h2>Hello! You have successfully connected to ESP8266!</h2><br>";
        content += "You can access this page until you <a href=\"/login?DISCONNECT=YES\">disconnect</a><br><hr />";

        // Add JavaScript code for the counters
        content += "<br><h3>Counters:</h3>";
        content += "<div class='counter-column' style='display: inline-block; margin-right: 20px;'>";
        content += "<h4>Walking</h4>";
        content += "<p id='walking-counter'>" + String(history_walk) + "</p>";
        content += "</div>";
        content += "<div class='counter-column' style='display: inline-block; margin-right: 20px;'>";
        content += "<h4>Jogging</h4>";
        content += "<p id='jogging-counter'>" + String(history_run) + "</p>";
        content += "</div>";
        content += "<div class='counter-column' style='display: inline-block;'>";
        content += "<h4>Cycling</h4>";
        content += "<p id='cycling-counter'>" + String(history_bike) + "</p>";
        content += "</div>";
        content += "<script>";
        content += "setInterval(updateCounters, 5000);";
        content += "function updateCounters() {";
        content += "  var walkingCounterElement = document.getElementById('walking-counter');";
        content += "  var joggingCounterElement = document.getElementById('jogging-counter');";
        content += "  var cyclingCounterElement = document.getElementById('cycling-counter');";
        content += "  walkingCounterElement.innerHTML = " + String(history_walk) + ";";
        content += "  joggingCounterElement.innerHTML = " + String(history_run) + ";";
        content += "  cyclingCounterElement.innerHTML = " + String(history_bike) + ";";
        content += "}";
        content += "function refreshPage() {";
        content += "  location.reload();";
        content += "}";
        content += "</script>";


        content += "</body></html>";
        server.send(200, "text/html", content);

    // Reset the flag after serving the content
    mqttCallbackExecuted = false;
}
int walk;
int run;
int bike;

void handleYesterday() {
    // show yesterday's data and compare it to today's
    if (!is_authentified()) {
        server.sendHeader("Location", "/login");
        server.sendHeader("Cache-Control", "no-cache");
        server.send(301);
        return;
    }

    if (client.connected()) {
        String send = "YESTERDAY;";
        client.publish("AljazACCData", send.c_str());
    }

    while (!mqttCallbackExecuted) {
        Serial.println("in in yesterday");
        client.loop();
        delay(10);
    }
    mqttCallbackExecuted = false;

    int diff_walk = yesterday_walk - walk;
    int diff_run = yesterday_run - run;
    int diff_bike = yesterday_bike - bike;

    String content = "<html><body><h2>Hello! You have successfully connected to ESP8266!</h2><br>";
    content += "You can access this page until you <a href=\"/login?DISCONNECT=YES\">disconnect</a><br><hr />";
    content += "<style>";
    content += ".counter-column {";
    content += "  display: inline-block;";
    content += "  margin-right: 20px;";
    content += "  position: relative;";
    content += "}";
    content += ".counter-column::after {";
    content += "  content: '';";
    content += "  position: absolute;";
    content += "  top: 0;";
    content += "  right: -10px;"; // Adjust the value to control the position of the vertical line
    content += "  height: 100%;";
    content += "  width: 1px;";
    content += "  background-color: black;"; // Change the color as needed
    content += "}";
    content += "</style>";
    content += "<br><h3>Counters for yesterday:</h3>";
    content += "<div class='counter-column'>";
    content += "<h4>Walking</h4>";
    content += "<p id='walking-counter'>" + String(yesterday_walk) + "</p>";
    content += "<p id='walking-difference'>Steps needed to reach yesterday: " + String(diff_walk) + "</p>"; // Add difference column
    content += "</div>";
    content += "<div class='counter-column'>";
    content += "<h4>Jogging</h4>";
    content += "<p id='jogging-counter'>" + String(yesterday_run) + "</p>";
    content += "<p id='jogging-difference'>Running steps needed to reach yesterday: " + String(diff_run) + "</p>"; // Add difference column
    content += "</div>";
    content += "<div class='counter-column'>";
    content += "<h4>Cycling</h4>";
    content += "<p id='cycling-counter'>" + String(yesterday_bike) + "</p>";
    content += "<p id='cycling-difference'>Strokes needed to reach yesterday: " + String(diff_bike) + "</p>"; // Add difference column
    content += "</div>";
    content += "<script>";
    content += "setInterval(updateCounters, 2000);"; // Update every 2 seconds
    content += "function updateCounters() {";
    content += "  var xhttp = new XMLHttpRequest();";
    content += "  xhttp.onreadystatechange = function() {";
    content += "    if (this.readyState == 4 && this.status == 200) {";
    content += "      var response = JSON.parse(this.responseText);";
    content += "      document.getElementById('walking-counter').innerHTML = response.yesterday_walk;";
    content += "      document.getElementById('jogging-counter').innerHTML = response.yesterday_run;";
    content += "      document.getElementById('cycling-counter').innerHTML = response.yesterday_bike;";
    content += "      document.getElementById('walking-difference').innerHTML = 'Steps needed to reach yesterday: ' + response.diff_walk;";
    content += "      document.getElementById('jogging-difference').innerHTML = 'Running steps needed to reach yesterday: ' + response.diff_run;";
    content += "      document.getElementById('cycling-difference').innerHTML = 'Strokes needed to reach yesterday: ' + response.diff_bike;";
    content += "    }";
    content += "  };";
    content += "  xhttp.open('GET', '/getDifference', true);";
    content += "  xhttp.send();";
    content += "}";
    content += "</script>";
    content += "</body></html>";
    server.send(200, "text/html", content);

    // Reset the flag after serving the content
    mqttCallbackExecuted = false;
}
 
// Handle the '/getDifference' endpoint
void handleGetDifference() {
    int diff_walk = yesterday_walk - walk;
    int diff_run = yesterday_run - run;
    int diff_bike = yesterday_bike - bike;

    String response = "{";
    response += "\"yesterday_walk\": " + String(yesterday_walk) + ",";
    response += "\"yesterday_run\": " + String(yesterday_run) + ",";
    response += "\"yesterday_bike\": " + String(yesterday_bike) + ",";
    response += "\"diff_walk\": " + String(diff_walk) + ",";
    response += "\"diff_run\": " + String(diff_run) + ",";
    response += "\"diff_bike\": " + String(diff_bike);
    response += "}";

    server.send(200, "application/json", response);
}


/* ----------------------------------------------------------------
 * handleNotFound:
 */
// No need for authentication
void handleNotFound(){
    String content = "<html><body><h1>404 Not Found</h1>";
    content += "<p>The requested URL was not found on this server.</p>";
    content += "<p><a href='/'>Back to the main page</a></p>";
    content += "</body></html>";
    server.send(404, "text/html", content);
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
            client.subscribe("AljazACCDataRec");
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

/* ----------------------------------------------------------------
 * setup:
 */
void setup() {
    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED, LOW);
    
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    // Connect to Wi-Fi network
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    IPAddress myIP = WiFi.localIP();
    Serial.println(myIP);

    // --------------------------------------------------
    const int SMOOTHING_WINDOW_SIZE = 10;
    peakDetectionAccX.begin(SMOOTHING_WINDOW_SIZE, 3, 0.6);
    peakDetectionAccY.begin(SMOOTHING_WINDOW_SIZE, 3, 0.6);
    peakDetectionAccZ.begin(SMOOTHING_WINDOW_SIZE, 3, 0.6);
    peakDetectionGyrX.begin(SMOOTHING_WINDOW_SIZE, 3, 0.6);
    peakDetectionGyrY.begin(SMOOTHING_WINDOW_SIZE, 3, 0.6);
    peakDetectionGyrZ.begin(SMOOTHING_WINDOW_SIZE, 3, 0.6);

    // Inicializiramo I2C na podanih pinih
    Wire.begin(12,14);
    // nastavimo frekvenco vodila na 100 kHz
    Wire.setClock(100000);

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // call only once per device and manually update the offsets accX_off, ...
    // calibrateSensors();
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!

    tick.attach_ms(10, readData);  // 100 Hz

    // --------------------------------------------------

    // Set up MQTT client
    client.setServer(mqttServer, mqttPort);
    client.setCallback([](char* topic, byte* payload, unsigned int length) {
    // MQTT callback function
    // Process the received MQTT response here
    Serial.print("in callback: ");
    Serial.println(topic);
    mqttResponse = "";
    for (int i = 0; i < length; i++) {
        mqttResponse += (char)payload[i];
    }
    Serial.println(mqttResponse);
    mqttCallbackExecuted = true;

    // Parse mqttResponse by ';'
    char* temp = strdup(mqttResponse.c_str());
    char* token = strtok(temp, ";");
    if (token != NULL) {
        // Check the first element
        if (strcmp(token, "STORED") == 0) {
            // First element is "STORED"
            // Perform actions accordingly
            Serial.println("First element is STORED");
        } else if (strcmp(token, "DATE") == 0) {
            // First element is "DATE"
            // store the second element in history_date, the third in history_walk, the fourth in history_run and the fifth in history_bike
                token = strtok(NULL, ";");
                history_date = token;
                token = strtok(NULL, ";");
                history_walk = atoi(token);
                token = strtok(NULL, ";");
                history_run = atoi(token);
                token = strtok(NULL, ";");
                history_bike = atoi(token);
        } else if (strcmp(token, "YESTERDAY") == 0) {
            // First element is "YESTERDAY"
            // store the second element in yesterday_date, the third in yesterday_walk, the fourth in yesterday_run and the fifth in yesterday_bike
                token = strtok(NULL, ";");
                yesterday_date = token;
                token = strtok(NULL, ";");
                yesterday_walk = atoi(token);
                token = strtok(NULL, ";");
                yesterday_run = atoi(token);
                token = strtok(NULL, ";");
                yesterday_bike = atoi(token);
        }
    }
    free(temp);
    });




    // Server settings
    server.on("/", handleRoot);
    server.on("/login", handleLogin);
    server.on("/led", handleLED);
    server.on("/history", handleHistory);
    server.on("/response", handleResponse);
    server.on("/yesterday", handleYesterday);
    server.on("/getDifference", HTTP_GET, handleGetDifference);
    server.on("/getCounters", HTTP_GET, handleGetCounters);
    server.on("/updateCounter", HTTP_GET, handleUpdateCounter);
    server.on("/inline", [](){
        server.send(200, "text/plain", "This works without the need for authentication.");
    });
    server.onNotFound(handleNotFound);
    
    // Collect headers to be recorded
    const char* headerkeys[] = {"User-Agent", "Cookie"};
    size_t headerkeyssize = sizeof(headerkeys) / sizeof(char*);
    // Ask server to track these headers
    server.collectHeaders(headerkeys, headerkeyssize );
    
    // Start the server
    server.begin();

    Serial.println("HTTP server started");

    if (!client.connected()) {
        reconnect();
    }
}

/* ----------------------------------------------------------------
 * loop:
 */
void loop() {
    server.handleClient();

//   // Check MQTT client connection
//   if (!client.connected()) {
//     // Attempt to reconnect
//     if (client.connect("ESP8266Client", mqttUser, mqttPassword)) {
//       // Subscribe to necessary MQTT topics
//       client.subscribe("history_response");
//     }
//   }

    // Handle MQTT client events
    client.loop();
    delay(500);
    // walk = walk - 1;
    // run = run + 1;
    // bike = bike + 1;
//   Serial.println(walk);
//   Serial.println("here in loop");

    // check if wifi is still connected
    reconnect();
}
