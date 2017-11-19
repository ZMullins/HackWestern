/*
Reference:
 http://arduino.cc/en/Tutorial/WebClientRepeating
 */

#include <SPI.h>
#include <WiFi.h>

const int analogIn = A0;
int analogVal = 0;

char ssid[] = "HackWestern";          //  your network SSID (name) 
char pass[] = "";  // your network password

int status = WL_IDLE_STATUS;
IPAddress server(74,125,115,105);  // Google

// Initialize the client library
WiFiClient client;

void setup() {
  Serial.begin(9600);
  Serial.println("Attempting to connect to WPA network...");
  Serial.print("SSID: ");
  Serial.println(ssid);

  status = WiFi.begin(ssid, pass);
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    // don't do anything else:
    while(true);
  } 
  else {
    Serial.println("Connected to wifi");
    Serial.println("\nStarting connection...");
    // if you get a connection, report back via serial:
    if (client.connect(server, 80)) {
      Serial.println("connected");
      // Make a HTTP request:
      client.println("GET /search?q=arduino HTTP/1.0");
      client.println();
    }
  }
}



unsigned long lastConnectionTime = 0;             // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10L * 1000L; // delay between updates, in milliseconds
// the "L" is needed to use long type numbers


void loop() {
  char server[] = "www.dweet.io";
  // if there's incoming data from the net connection.
  // send it out the serial port.  This is for debugging
  // purposes only:
  if (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if ten seconds have passed since your last connection,
  // then connect again and send data:
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }

}

// this method makes a HTTP connection to the server:
void httpRequest() {
  // close any connection before send a new request.
  // This will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection:
  if (client.connect(server, 80)) {
    Serial.println("connected");
    analogVal = analogRead(analogIn);
    
    // Make a HTTP request:
    String s = "POST /dweet/for/nixon-is-pres1?DogeProperty=";
    s.concat(analogVal);
    Serial.println(s);
    client.println(s);
    
    client.println("Host: www.dweet.io");
    client.println("Connection: close");
    client.println();

    // note the time that the connection was made:
    lastConnectionTime = millis();
  }
  else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
  }
}
