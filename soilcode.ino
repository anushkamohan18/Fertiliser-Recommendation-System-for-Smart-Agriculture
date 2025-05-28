#include <ModbusMaster.h>

ModbusMaster node;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);  // Confirmed working baud

  node.begin(1, Serial1);  // Confirmed Modbus ID = 1

  Serial.println("🌱 Reading soil data...");
}

void loop() {
  uint8_t result = node.readHoldingRegisters(0x05, 10); // Start at 0x05, read 10 registers

  if (result == node.ku8MBSuccess) {
    // Extract values
    uint16_t nitrogen     = node.getResponseBuffer(0);  // 0x05
    uint16_t potassium    = node.getResponseBuffer(1);  // 0x06
    uint16_t phosphorous  = node.getResponseBuffer(2);  // 0x07
    float ph              = node.getResponseBuffer(3) / 100.0; // 0x08
    float temperature     = node.getResponseBuffer(5) / 10.0;  // 0x0A
    float humidity        = node.getResponseBuffer(6) / 10.0;  // 0x0B

    // Print CSV for ML model
    Serial.print(temperature); Serial.print(",");
    Serial.print(humidity); Serial.print(",");
    Serial.print(ph); Serial.print(",");
    Serial.print(nitrogen); Serial.print(",");
    Serial.print(potassium); Serial.print(",");
    Serial.println(phosphorous);
  } else {
    Serial.print("❌ Modbus error: ");
    Serial.println(result);
  }

  delay(500); // Wait before next read
}
