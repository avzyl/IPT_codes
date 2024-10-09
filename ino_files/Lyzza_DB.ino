#include "ESP8266WiFi.h"
#include <ESP8266HTTPClient.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

// WiFi parameters to be configured
const char* ssid = "Pegasus Hunter"; // Your Wi-Fi SSID
const char* password = "AT8H029JJB7";    // Your Wi-Fi password

// MySQL server credentials
IPAddress server_addr(192, 168, 254, 114); // IP of the MySQL server (your PC)
char user[] = "mingae";                    // MySQL username
char password_db[] = "12345";              // MySQL password

WiFiClient client;
MySQL_Connection conn((Client *)&client);

void setup(void) {
  Serial.begin(9600);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  // Connect to MySQL
  Serial.println("Connecting to MySQL...");
  if (conn.connect(server_addr, 3306, user, password_db)) {
    Serial.println("Connected to MySQL!");
  } else {
    Serial.println("Connection failed. Check your credentials or server IP.");
  }
}

void loop() {
  // Check if connected to MySQL
  if (!conn.connected()) {
    Serial.println("Reconnecting to MySQL...");
    if (conn.connect(server_addr, 3306, user, password_db)) {
      Serial.println("Reconnected to MySQL!");
    } else {
      Serial.println("Reconnection failed. Check your credentials or server IP.");
      return; // Exit loop if reconnection fails
    }
  }

  // Create a cursor object for executing queries
  MySQL_Cursor* cursor = new MySQL_Cursor(&conn);
  
  // Construct SQL query
  String sensor_value = "Lyzza"; // Example sensor value
  int novalue = random(800, 1000); // Generate a random value for demonstration
  char query[256];
  sprintf(query, "INSERT INTO db_samplesql.samplevalue (sensor_value, novalue) VALUES ('%s', %d)", sensor_value.c_str(), novalue);

  // Execute the query
  if (cursor->execute(query)) {
    Serial.println("Data sent to MySQL.");
  } else {
    // If execution fails, print the error message from the cursor
    Serial.println("Error executing query. Please check your SQL syntax or database state.");
  }
  
  // Close the cursor
  delete cursor;

  delay(5000); // Delay for 5 seconds before sending the next data
}
