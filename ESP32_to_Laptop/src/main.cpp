#include <Arduino.h>
#include <WebServer.h>
#include "credentials.h"
#include <stdio.h>
using namespace std;

int getWiFiStrength()
{
    int rssi = WiFi.RSSI(); // Get current signal strength
    return rssi;
}

void setup()
{
    Serial.begin(115200);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

string converdBmToReadable(int strength_dBm)
{
    string qual;
    if (strength_dBm >= -70){
        qual = "Excellent";
    } else if (strength_dBm >= -80){
        qual = "Good";
    } else if (strength_dBm >= -90){
        qual = "Fair";
    } else {
        qual = "Weak";
    }
  
    float perc = 0.25*(-13 * strength_dBm - 330);

    char buffer[50];
    snprintf(buffer, sizeof(buffer), "WiFi strength is: %s at %3.1f%% (%ddBm)", 
             qual.c_str(), perc, strength_dBm);
    return string(buffer);
}

void loop()
{
    int strength = getWiFiStrength();
    string msg = converdBmToReadable(strength);
    Serial.println(msg.c_str());
    delay(500);
}