int setupESP8266(void) {
  Serial.begin(115200);   
  Serial.println("AT");   
  delay(10);
  if (!Serial.find("OK")) return 1;
  
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
  delay(10);        
  if (!Serial.find("OK")) return 2;
  
  Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort);
  delay(50);        
  if (!Serial.find("OK")) return 3;
  
  return 0;
}
