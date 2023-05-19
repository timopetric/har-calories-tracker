/*#include "MlClassifier.h"

void setup() {
    Serial.begin(115200);
}

void loop() {
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

// Replace with your MQTT broker details
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttUser = "your_mqtt_username";
const char* mqttPassword = "your_mqtt_password";

// Replace with your Wi-Fi credentials
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";

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
void handleRoot() {
  String header;
  if (!is_authentified()){
    server.sendHeader("Location","/login");
    server.sendHeader("Cache-Control","no-cache");
    server.send(301);
    return;
  }
  
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
  content += "Date: <input type='date' name='date'><br>";
  content += "<input type='submit' name='submit' value='Search'>";
  content += "</form>";
  
  // Add JavaScript code for the counters
  content += "<br><h3>Counters:</h3>";
  content += "<div class='counter-column' style='display: inline-block; margin-right: 20px;'>";
  content += "<h4>Walking</h4>";
  content += "<p id='walking-counter'>0</p>";
  content += "</div>";
  content += "<div class='counter-column' style='display: inline-block; margin-right: 20px;'>";
  content += "<h4>Jogging</h4>";
  content += "<p id='jogging-counter'>0</p>";
  content += "</div>";
  content += "<div class='counter-column' style='display: inline-block;'>";
  content += "<h4>Cycling</h4>";
  content += "<p id='cycling-counter'>0</p>";
  content += "</div>";
  content += "<button onclick='refreshPage()'>End activity</button>";
  content += "<script>";
  content += "setInterval(updateCounters, 5000);";
  content += "function updateCounters() {";
  content += "var walkingCounterElement = document.getElementById('walking-counter');";
  content += "var joggingCounterElement = document.getElementById('jogging-counter');";
  content += "var cyclingCounterElement = document.getElementById('cycling-counter');";
  content += "var walkingCounterValue = parseInt(walkingCounterElement.innerHTML);";
  content += "var joggingCounterValue = parseInt(joggingCounterElement.innerHTML);";
  content += "var cyclingCounterValue = parseInt(cyclingCounterElement.innerHTML);";
  content += "walkingCounterValue++;";
  content += "joggingCounterValue++;";
  content += "cyclingCounterValue++;";
  content += "walkingCounterElement.innerHTML = walkingCounterValue;";
  content += "joggingCounterElement.innerHTML = joggingCounterValue;";
  content += "cyclingCounterElement.innerHTML = cyclingCounterValue;";
  content += "}";
  content += "function refreshPage() {";
  content += "location.reload();";
  content += "}";
  content += "</script>";
  
  content += "</body></html>";
  server.send(200, "text/html", content);
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
    
    // Publish MQTT request
    if (client.connected()) {
      client.publish("AljazACCData", "fuck you!!!!!!!");
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
    client.loop();
    delay(10);
  }
  
  String content = "<html><body>";
  
  // Add MQTT response here
  content += "<h2>MQTT Response:</h2>";
  content += "<p>" + mqttResponse + "</p>";
  
  content += "</body></html>";
  server.send(200, "text/html", content);

  // Reset the flag after serving the content
  mqttCallbackExecuted = false;
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
  WiFi.begin(USERNAME, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  IPAddress myIP = WiFi.localIP();
  Serial.println(myIP);

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
  });

  // Server settings
  server.on("/", handleRoot);
  server.on("/login", handleLogin);
  server.on("/led", handleLED);
  server.on("/history", handleHistory);
  server.on("/response", handleResponse);
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
}
