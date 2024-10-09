
#include "ESP8266WiFi.h"
#include <ESP8266HTTPClient.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>



// WiFi parameters to be configured
const char* ssid = "@FreeWifi"; // Write here your router's username
const char* password = "!@fReewifi"; // Write here your router's passward

IPAddress server_addr(192, 168, 110, 134);  // IP of the MySQL server (your PC)
char user[] = "rootUser";                   // MySQL username (default is 'root' in XAMPP)
char password_db[] = "123";                // MySQL password (leave empty if using XAMPP's default)

WiFiClient client;
MySQL_Connection conn((Client *)&client);


void setup(void)
{ 
  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(ssid, password);

  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED) {
     delay(1000);
     Serial.print(".");
  }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());

  
    Serial.println("Connecting to MySQL...");
  if (conn.connect(server_addr, 3306, user, password_db)) {
    Serial.println("Connected to MySQL!");
  } else {
    Serial.println("Connection failed.");
  }
}

void loop() {
delay(2000);
  
  // Create a cursor object for executing queries
  MySQL_Cursor* cursor = new MySQL_Cursor(&conn);
  
  // Construct SQL query
  String sensor_value = "JC";  // Example sensor value
  int novalue = 900;
  char query[256];
  sprintf(query, "INSERT INTO db_samplesql.samplevalue (sensor_value , novalue) VALUES ('%s' , '%d')",sensor_value.c_str() , novalue );

  // Execute the query
  cursor->execute(query);
  
  Serial.println("Data sent to MySQL.");
  
  // Close the cursor
  delete cursor;

  delay(5000); // Delay for 5 seconds before sending the next data
}
