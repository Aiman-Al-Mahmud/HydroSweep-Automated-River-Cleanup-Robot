/*Below is the core control program. It features **non-blocking time 
management** using `millis()`, allowing the Arduino to monitor sensors,
manage safety timeouts, and flicker status LEDs simultaneously without 
"freeze bugs."
*/


// Pin Connections
const int trigPin = 9;             // Ultrasonic sensor Trigger action
const int echoPin = 10;            // Ultrasonic sensor Echo
const int motorPin = 8;            // Relay module IN pin
const int ledStatus = 5;           // LED 1: Solid ON when system is running (empty)
const int ledWarning = 6;          // LED 2: FLICKERS when bucket is full
const int ledSolar = 7;            // LED 3: ON when solar panel is active
const int solarPin = A0;           // Solar panel voltage sensing (Analog)

// Distance Configuration
const int fullDistanceCm = 10;     // 16cm to bottom, 6cm bucket height = 10cm threshold
const int solarThreshold = 300;    // Threshold for solar activity (0-1023)

// Timing Variables
unsigned long previousSensorTime = 0;
const long sensorInterval = 3000;  // 3-second interval for checking the bucket

unsigned long previousBlinkTime = 0;
const long blinkInterval = 250;    // 250ms interval for a fast flicker
bool blinkState = LOW;

bool bucketIsFull = false;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(ledStatus, OUTPUT);
  pinMode(ledWarning, OUTPUT);
  pinMode(ledSolar, OUTPUT);
  
  // Initial state: Assume empty, turn ON motor (Active LOW means LOW = ON)
  digitalWrite(motorPin, LOW); 
  digitalWrite(ledStatus, HIGH);

  Serial.println("System Initialized. Waiting for 3 seconds...");
}

void loop() {
  unsigned long currentMillis = millis();

  // 1. Solar Panel Logic
  int solarValue = analogRead(solarPin);
  if (solarValue > solarThreshold) {
    digitalWrite(ledSolar, HIGH);
  } else {
    digitalWrite(ledSolar, LOW); 
  }

  // 2. Ultrasonic Sensor Logic & Terminal Output
  if (currentMillis - previousSensorTime >= sensorInterval) {
    previousSensorTime = currentMillis;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // 30-millisecond timeout so a disconnected sensor won't freeze the board
    long duration = pulseIn(echoPin, HIGH, 30000); 
    int distance = duration * 0.034 / 2;
    
    // Check if distance is valid and less than or equal to 10 cm
    if (distance > 0 && distance <= fullDistanceCm) {
      bucketIsFull = true;
    } else {
      bucketIsFull = false;
    }

    // --- PRINT FULL SYSTEM STATUS TO TERMINAL ---
    Serial.println("====== SYSTEM STATUS ======");
    Serial.print("Sensor Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    if (bucketIsFull) {
      Serial.println("Bucket State:    FULL");
      Serial.println("Motor State:     STOPPED");
    } else {
      Serial.println("Bucket State:    HAS SPACE");
      Serial.println("Motor State:     RUNNING");
    }
    Serial.println("===========================\n");
  }

  // 3. Automated Relay and LED Action Logic
  if (bucketIsFull) {
    // Bucket is FULL
    digitalWrite(motorPin, HIGH);      // STOP the motor (Active LOW means HIGH = OFF)
    digitalWrite(ledStatus, LOW);      // Turn off normal status light
    
    // Flicker the warning light
    if (currentMillis - previousBlinkTime >= blinkInterval) {
      previousBlinkTime = currentMillis;
      blinkState = !blinkState; 
      digitalWrite(ledWarning, blinkState);
    }
  } else {
    // Bucket is EMPTY / Has Space
    digitalWrite(motorPin, LOW);       // RUN the motor (Active LOW means LOW = ON)
    digitalWrite(ledStatus, HIGH);     // Turn status light solidly ON
    digitalWrite(ledWarning, LOW);     // Turn off warning light
    blinkState = LOW;
  }
}
