#include <ModbusMaster.h>

ModbusMaster node;

void setup() {
  Serial.begin(9600);         // USB Serial (to Python)
  Serial1.begin(9600);        // RS485 Serial (TX1=18, RX1=19)

  node.begin(1, Serial1);     // Modbus ID = 1
  pinMode(7, OUTPUT);         // Pump control pin
  digitalWrite(7, LOW);       // Start pump OFF

  Serial.println("🌱 Soil sensor + pump control ready...");
}

void loop() {
  uint8_t result = node.readHoldingRegisters(0x05, 10); // Read 10 registers starting from 0x05

  if (result == node.ku8MBSuccess) {
    // Extract and scale values
    uint16_t nitrogen     = node.getResponseBuffer(0);            // 0x05
    uint16_t potassium    = node.getResponseBuffer(1);            // 0x06
    uint16_t phosphorous  = node.getResponseBuffer(2);            // 0x07
    float ph              = node.getResponseBuffer(3) / 100.0;    // 0x08
    float temperature     = node.getResponseBuffer(5) / 10.0;     // 0x0A
    float humidity        = node.getResponseBuffer(6) / 10.0;     // 0x0B

    // Send as CSV to Python
    Serial.print(temperature); Serial.print(",");
    Serial.print(humidity); Serial.print(",");
    Serial.print(ph); Serial.print(",");
    Serial.print(nitrogen); Serial.print(",");
    Serial.print(potassium); Serial.print(",");
    Serial.println(phosphorous);

    delay(500);  // Wait for Python to reply

    // Read response from Python: '1' = ON, '0' = OFF
    if (Serial.available()) {
      char command = Serial.read();
      Serial.println(command);
      if (command == 'f') {
        digitalWrite(7, HIGH);   // Turn ON pump
      } else if (command == 'o') {
        digitalWrite(7, LOW);    // Turn OFF pump
      }
    }
  } else {
    Serial.print("❌ Modbus Error: ");
    Serial.println(result);
  }

  delay(500); // Small delay before next read cycle
}
