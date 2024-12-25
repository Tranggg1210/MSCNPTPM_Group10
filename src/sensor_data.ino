void anydata(void) {
  int temp = map(analogRead(A0), 20, 358, -40, 125);
  int soilMoisture = map(analogRead(A1), 0, 876, 0, 100);
  int lightLevel = map(analogRead(A2), 6, 679, 0, 100);
  
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("S:");
  lcd.print(soilMoisture);
  lcd.print("%");
  
  bool alert = false;
  
  if (temp > 30) {
    digitalWrite(fan, HIGH); 
    lcd.setCursor(7, 0);
    lcd.print("Fan:ON ");
    alert = true;
  } else {
    digitalWrite(fan, LOW);  
    lcd.setCursor(7, 0);
    lcd.print("Fan:OFF");
  }
  
  if (soilMoisture < 30) {
    digitalWrite(motor, HIGH);
    lcd.setCursor(7, 1);
    lcd.print("Motor:ON ");
    alert = true;
  } else {
    digitalWrite(motor, LOW); 
    lcd.setCursor(7, 1);
    lcd.print("Motor:OFF");
  }
  
  delay(10000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("L:");
  lcd.print(lightLevel);
  lcd.print("%");
  
  if (lightLevel < 30) {
    digitalWrite(bulb, HIGH);
    lcd.setCursor(7, 0);
    lcd.print("Bulb:ON ");
    alert = true;
  } else {
    digitalWrite(bulb, LOW);
    lcd.setCursor(7, 0);
    lcd.print("Bulb:OFF");
  }
  
  if (alert) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
  String httpPacket = "GET " + uri + String(temp)+ "&field2=" + String(soilMoisture) + "&field3=" + String(lightLevel) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  int length = httpPacket.length();
  
  Serial.print("AT+CIPSEND=");
  Serial.println(length);
  delay(10);

  Serial.print(httpPacket);
  delay(10);
  if (!Serial.find("SEND OK\r\n")) return;
}
