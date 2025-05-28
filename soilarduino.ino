#include <ModbusMaster.h>

// Create ModbusMaster object
ModbusMaster node;

void setup() {
  Serial.begin(19200);        // For Serial Monitor
  Serial1.begin(19200);       // RS485 on Serial1 (TX1=18, RX1=19)

  node.begin(1, Serial1);    // Sensor Modbus ID = 1
  Serial.println("🌱 Soil Sensor Reader Ready...");
}

void loop() {
  uint8_t result;
  uint16_t data[6];

  // Read 6 registers from address 0x00 (adjust as per your sensor's datasheet)
  result = node.readInputRegisters(0x00, 6);

  if (result == node.ku8MBSuccess) {
    for (int i = 0; i < 6; i++) {
      data[i] = node.getResponseBuffer(i);
    }

    // Decode and print values
    float temperature = data[0] / 10.0;
    float humidity = data[1] / 10.0;
    float ph = data[2] / 100.0;
    float nitrogen = data[3];
    float potassium = data[4];
    float phosphorous = data[5];

    // Send as CSV string to Python
    Serial.print(temperature); Serial.print(",");
    Serial.print(humidity); Serial.print(",");
    Serial.print(ph); Serial.print(",");
    Serial.print(nitrogen); Serial.print(",");
    Serial.print(potassium); Serial.print(",");
    Serial.println(phosphorous);
  } else {
    Serial.print("Modbus Error Code: ");
    Serial.println(result);
  }

  delay(50); // Wait 3 seconds before next reading
}
