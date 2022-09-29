
#define TMP36_INPUT 0  // A0
#define CDS_INPUT 1     // A1

void setup() { 
  Serial.begin(9600);
}

void loop(){
  // Temperature from TMP36
  int temp_value = analogRead(TMP36_INPUT);
  // converting the analog value to voltage
  float voltage = temp_value * 5.0 * 1000;  // in mV
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10 ;  // in C

  // Lux from CdS (LDR)
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));  // in lux
 
  // Serial output --> 온도,조도
  Serial.print(tempC);
  Serial.print(",");
  Serial.println(lux);
  
  delay(1000);
}

//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10;  
  // lux = 500 / Rldr, 
  // Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}
