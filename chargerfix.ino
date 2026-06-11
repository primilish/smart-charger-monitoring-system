#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(115200);
  if (!ina219.begin()) {
    Serial.println("INA219 not found");
    while (1);
  }

  // Pilih salah satu
  ina219.setCalibration_32V_2A();     // paling umum
  // ina219.setCalibration_16V_400mA();
}

void loop() {
  float busVoltage = ina219.getBusVoltage_V();
  float shuntVoltage = ina219.getShuntVoltage_mV() / 1000.0;
  float current_mA = ina219.getCurrent_mA();
  float power_mW = ina219.getPower_mW();

  Serial.print("V = "); Serial.print(busVoltage); Serial.println(" V");
  Serial.print("I = "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("P = "); Serial.print(power_mW/1000.0); Serial.println(" W");
  Serial.println("-----------------------");

  delay(1000);
}
