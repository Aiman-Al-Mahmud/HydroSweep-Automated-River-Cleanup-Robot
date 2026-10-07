# 🌊 HydroSweep: Automated Eco-Friendly River-Cleaning Robot

[![GitHub license](https://img.shields.io/github/license/Aiman-Al-Mahmud/HydroSweep-Automated-River-Cleanup-Robot?color=blue)](LICENSE)
[![Arduino Supported](https://img.shields.io/badge/Arduino-Compatible-00979D?logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Eco Friendly](https://img.shields.io/badge/Environment-Eco--Friendly-4CAF50?logo=eco&logoColor=white)](#-the-eco-friendly-aspect)

<<<<<<< HEAD
HydroSweep is a 2 to 3-foot functional scale-model of a solar-powered, waste-collecting catamaran designed to combat plastic pollution in rivers before it reaches the ocean. Inspired by the groundb[...]
=======
HydroSweep is a 2 to 3-foot functional scale-model of a solar-powered, waste-collecting catamaran designed to combat plastic pollution in rivers before it reaches the ocean. Inspired by the groundbreaking work of ocean cleanup initiatives, this project aims to catch floating waste before it disperses into the ocean.
>>>>>>> 9e6e0fd75cf1c38c26fda0cbf5608b4abfe698ff

---

## 🖼️ Prototype Showcase

<div align="center">
  <img src="Project picture/hydrosweep-prototype-hardware.jpeg" alt="HydroSweep Functional Scale Model Prototype" width="800">
  <p><i>The functional "HydroSweep" catamaran prototype sitting on the workbench.</i></p>
</div>

---

## 💡 What is HydroSweep?
**HydroSweep** is a smart, solar-assisted catamaran (double-hulled) vessel that uses an angled conveyor belt to scoop floating waste out of the water and deposit it into an onboard collection buck[...]

<<<<<<< HEAD
Controlled by an **Arduino Mega**, the robot automatically manages its operations. When the collection bucket is empty, the conveyor belt runs. When the on-board ultrasonic sensor detects that the[...]
=======
Controlled by an **Arduino Mega**, the robot automatically manages its operations. When the collection bucket is empty, the conveyor belt runs. When the on-board ultrasonic sensor detects that the bucket is nearly full, the system pauses and waits for manual emptying, preventing overflow and protecting the mechanism.
>>>>>>> 9e6e0fd75cf1c38c26fda0cbf5608b4abfe698ff

---

## 🌊 How Can It Help To Clean Our Rivers?

<<<<<<< HEAD
Historically, marine waste was collected only after it reached the open ocean, where dispersion makes it nearly impossible to retrieve. **HydroSweep targets waste at the source—our rivers.** Mov[...]

By operating autonomously and utilizing renewable solar energy to track environmental states, a fleet of automated systems like HydroSweep can intercept metric tons of debris daily without human i[...]
=======
Historically, marine waste was collected only after it reached the open ocean, where dispersion makes it nearly impossible to retrieve. **HydroSweep targets waste at the source—our rivers.** Moving with the natural current, it intercepts trash before it reaches deeper waterways and the sea.

By operating autonomously and utilizing renewable solar energy to track environmental states, a fleet of automated systems like HydroSweep can intercept metric tons of debris daily without human intervention.
>>>>>>> 9e6e0fd75cf1c38c26fda0cbf5608b4abfe698ff

### 🎥 See It in Action (The Inspiration)
This project is scaled from real-world technology tackling major global waterways. Watch how the full-scale system operates on the front lines of environmental cleanup:

<<<<<<< HEAD
[![The Ocean Cleanup Interceptor Inspiration](https://img.shields.io/badge/YouTube-The%20Ocean%20Cleanup%20Interceptor-red?style=for-the-badge&logo=youtube)](https://youtu.be/bm1rH70wfJo?si=bHwk6IV0R0[...]
=======
[![The Ocean Cleanup Interceptor Inspiration](https://img.shields.io/badge/YouTube-The%20Ocean%20Cleanup%20Interceptor-red?style=for-the-badge&logo=youtube)](https://youtu.be/bm1rH70wfJo?si=bHwk6Ivvz5s2m0Q7)
>>>>>>> 9e6e0fd75cf1c38c26fda0cbf5608b4abfe698ff

---

## 📐 High-Level Infrastructure

Below is the design overview and scaled cutaway inspired by "The Ocean Cleanup Interceptor" project infrastructure:

<div align="center">
  <img src="Project picture/concept-interceptor.png.jpeg" alt="The Ocean Cleanup Interceptor Concept Scale-Model" width="45%">
  &nbsp;&nbsp;
  <img src="Project picture/infrastructure-design.jpeg" alt="Interceptor Project Infrastructure Raw Design" width="45%">
  <p><i>Left: 3D concept overview. Right: Architectural infrastructure & system layout.</i></p>
</div>

---

## 🛠️ Components Used

| Category | Component | Description |
|---|---|---|
| **Brain** | Arduino Mega 2560 | Microcontroller to process sensor inputs and coordinate system feedback. |
| **Sensing** | HC-SR04 Ultrasonic Sensor | Mounted vertically on a tower above the collection bucket to monitor waste levels. |
| **Sensing** | Small Solar Panel | Integrated to analog pin A0 to simulate and verify sunlight/renewable power availability. |
| **Control** | SRD-05VDC-SL-C Relay Module | Safely handles the high current of the motor using Arduino's logic. |
| **Drive** | 3-6V DC Gear Motor | Powers the conveyor belt rollers. |
| **Power** | 3.7V Li-ion Battery | Dedicated high-current battery specifically for the gear motor. |
| **Signaling** | LED Indicators (Red, Yellow, Green) | Provide visual status of the bucket (Normal/Full) and solar panel active state. |
| **Safety** | Resistors (220Ω) | Protect the signaling LEDs from overcurrent. |
| **Struct** | White Foam Board & Glue | Lightweight, bouyant double-hull catamaran build. |

---

## 🔌 Circuit and Data Flow Diagrams

### ⚡ Complete Wiring Schematics

<div align="center">
  <img src="Project picture/circuit-diagram.jpeg" alt="Revised and Clarified Circuit Diagram of Automated Conveyor System" width="800">
  <p><i>High-precision wiring scheme linking the Arduino Mega, Relay Module, DC Motor, Ultrasonic Sensor, and Status LEDs.</i></p>
</div>

### 📡 Data & Control Flow Diagram

The following diagram illustrates how the Arduino Uno/Mega processes visual and telemetry inputs to direct automated actions to the display and actuator modules:

<div align="center">
  <img src="Project picture/output-flow-diagram.jpeg" alt="HydroSweep Output Data and Control Flow Diagram" width="800">
  <p><i>Visual flowchart tracking logic states and control routing from microcontroller to output interfaces.</i></p>
</div>

---

## ⚙️ How It Works

1. **Environmental Harvesting**: Moving river water naturally funnels debris toward the front hulls.
2. **Waste Ascent**: An inclined conveyor belt, driven by the 3V-6V gear motor, continuously drags floating garbage out of the water.
3. **Smart Level Monitoring**: The HC-SR04 Ultrasonic Sensor, positioned 16 cm above the bottom of a 6 cm deep collection bucket, repeatedly fires ping requests downward.
4. **Safety Automation (Full Detection)**:
   - When trash rises to within **10 cm** of the sensor (indicating the bucket is full), the Arduino Mega triggers a `HIGH` command to Pin 8 (the Relay Module IN).
   - Because the relay uses *Active LOW* logic, sending a `HIGH` breaks the motor circuit, instantly stopping the conveyor.
   - The solid green **Status LED (Pin 5)** goes `LOW` (OFF), and the red **Warning LED (Pin 6)** begins to flicker rapidly at 250ms intervals.
   - The system pauses and re-inspects the bucket every 3 seconds while refusing to restart until the obstruction/trash is cleared.
5. **Normal Operation**: When the sensor registers a distance > 10 cm, the Arduino commands the motor to run and maintains a steady green **Status LED**, allowing hands-free collection to continue.
6. **Solar Energy Indication**: A small solar panel read by A0 checks for ambient light. If sunlight is detected (value > 300), the **Solar LED (Pin 7)** remains illuminated independently of the colle[...]

---

## 📜 Installation and Uploading
Ensure you have the Arduino IDE installed.

Clone this repository:

```bash
git clone https://github.com/Aiman-Al-Mahmud/HydroSweep-Automated-River-Cleanup-Robot.git
```

Open `HydroSweep.ino` inside Arduino IDE.

Go to Tools > Board and select Arduino Mega or Mega 2560.

Go to Tools > Port and select the active port connected to your device.

Click the Upload button to run it.

Open the Serial Monitor (9600 Baud) to track the automated system state and distance logs!

## 🌿 The Eco-Friendly Aspect

- **Solar Harvesting Simulation**: Fully integrates onboard solar sensing to simulate self-sustaining operations, demonstrating how the robot can harvest environmental energy during daylight hours.
- **Low-Impact Passive Funneling**: Uses the natural flow of rivers to capture debris rather than using heavy, energy-draining marine propulsion systems.
<<<<<<< HEAD
- **Micro-Power Safety Configuration**: By utilizing a 3.7V Li-ion battery entirely isolated from the Arduino's logic system through a highly efficient relay module, HydroSweep maintains massive opera[...]
=======
- **Micro-Power Safety Configuration**: By utilizing a 3.7V Li-ion battery entirely isolated from the Arduino's logic system through a highly efficient relay module, HydroSweep maintains massive operational efficiency with minimal energy use.
>>>>>>> 9e6e0fd75cf1c38c26fda0cbf5608b4abfe698ff

---

## 🤝 Contributing
Contributions, suggestions, and hardware optimizations are highly encouraged! Feel free to open an Issue or PR to suggest a feature or troubleshoot scale efficiency.

<<<<<<< HEAD
## 👥 Contributors

<div align="left">
  <a href="https://github.com/Aiman-Al-Mahmud">
    <img src="https://github.com/Aiman-Al-Mahmud.png" width="40" height="40" alt="Aiman Al Mahmud" style="border-radius: 50%;" />
  </a>
  <a href="https://github.com/SYAAGalib">
    <img src="https://github.com/SYAAGalib.png" width="40" height="40" alt="SYAAGalib" style="border-radius: 50%;" />
  </a>
  <a href="https://github.com/Pushpita007">
    <img src="https://github.com/Pushpita007.png" width="40" height="40" alt="Pushpita007" style="border-radius: 50%;" />
  </a>
  <a href="https://github.com/Borsha959">
    <img src="https://github.com/Borsha959.png" width="40" height="40" alt="Borsha959" style="border-radius: 50%;" />
  </a>
  <a href="https://github.com/aishwariyaroy">
    <img src="https://github.com/aishwariyaroy.png" width="40" height="40" alt="aishwariyaroy" style="border-radius: 50%;" />
  </a>
</div>

<br>

=======
🌿 Let’s use technology to protect our rivers and build a sustainable future!
>>>>>>> 9e6e0fd75cf1c38c26fda0cbf5608b4abfe698ff

## Contributors
- Aiman Al Mahmud
- SYAAGalib
