// CdS + DHT22
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);
// CdS (LDR)
#define CDS_INPUT 1

void setup() {
  dht;
  Serial.begin(9600);
}

void loop() {
  int cds_value, lux;
  float temp, humi;
  // Lux from CdS (LDR)
  cds_value = analogRead(CDS_INPUT);
  lux = int(luminosity(cds_value));
  // Reading temperature or humidity takes a given interval!
  // Sensor readings may also be up to 2 seconds 'old' 
  humi = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temp = dht.;

  // Check if any reads failed and exit early (to try again).
  if (isnan(humi) || isnan(temp) || isnan(lux)) {
    Serial.println("Failed to read from DHT sensor or CdS!");
    return;
  }
  else {    
//    Serial.print("AA00,");
    Serial.print(temp,);  // temperature, float
    Serial.print(",");
    Serial.print(humi,);  // humidity, float
    Serial.print(",");
    Serial.println(lux);   // luminosity, int
  }  
  delay(1000);  // 1000 msec, 1 Hz
}

//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023.0;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}
