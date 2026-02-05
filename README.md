# Intelligent IoT Based Water Quality Monitoring and Decision Support System
IoT-based intelligent water quality monitoring system using pH, electrical conductivity, turbidity and temperature sensors. Data is acquired via a Libelium water board and transmitted through a Meshlium gateway to the cloud for real-time visualization, WQI computation, trend analysis, and automated alerts.

## Introduction
- Water quality monitoring is critical for drinking water management, agriculture, and environmental protection.
- Traditional water testing methods rely on manual sampling and laboratory analysis.
- These methods are time-consuming, labor-intensive, and unsuitable for real-time monitoring.
- This project presents an Intelligent IoT-Based Water Quality Monitoring and Decision Support System.
- The system continuously monitors key water quality parameters.
- Cloud-based analytics classify water conditions and generate event-based email and SMS alerts.
- The architecture is scalable, automated, and suitable for real-world deployment.


## Objectives
- Design an IoT-based system for real-time water quality monitoring.
- Measure pH, electrical conductivity (EC), turbidity, and temperature.
- Transmit sensor data wirelessly using Libelium sensor nodes.
- Use Meshlium gateway for data aggregation and internet connectivity.
- Analyze and visualize data using the ThingSpeak cloud platform.
- Compute Water Quality Index (WQI) for decision support.
- Generate event-based email and SMS alerts during abnormal conditions.
- Demonstrate scalability for large-scale environmental monitoring.


## System Architecture

### 1. Sensing Layer
- pH Sensor
- Electrical Conductivity Sensor
- Turbidity Sensor
- Water Temperature Sensor

### 2. Edge Device Layer
- Libelium Water Sensor Board
- Waspmote (data acquisition and preprocessing)

### 3. Gateway Layer
- Meshlium Gateway
- Data aggregation and internet connectivity

### 4. Cloud Layer
- ThingSpeak Cloud Platform
- Data storage and visualization
- MATLAB-based analytics


## Hardware Requirements
- Libelium Water Vertical Board
- Waspmote
- pH Sensor
- Electrical Conductivity Sensor
- Turbidity Sensor
- Water Temperature Sensor
- Meshlium Gateway
- Power Supply


## Software Requirements
- Waspmote IDE
- Meshlium Manager
- ThingSpeak Cloud Platform
- MATLAB Analytics (ThingSpeak)
- Webhook services for SMS alerts


## Water Quality Analysis and Decision Support
### Water Quality Index (WQI)
- To enhance decision-making, multiple sensor readings are converted into a single actionable metric called the Water Quality Index (WQI).
- WQI is computed in the cloud using ThingSpeak MATLAB analytics.
- It provides a quantitative representation of overall water quality and is widely used in environmental monitoring systems.

**WQI Calculation:**
**Where:**
- `pH_norm`, `EC_norm`, `Temp_norm` are normalized sensor values
- `w1`, `w2`, `w3` are weighting factors based on parameter importance

**Weights Used:**
- pH: 0.4  
- Electrical Conductivity: 0.4  
- Temperature: 0.2  

### WQI Classification

| WQI Range | Water Quality Status |
|---------|----------------------|
| 0 – 50  | Excellent            |
| 51 – 100| Good                 |
| 101 – 200 | Poor              |
| >200    | Unsuitable           |

- Alerts are triggered when WQI crosses predefined thresholds.
- This enables faster response compared to monitoring individual parameters.
### Parameter Thresholds

| Parameter | Normal Range | Warning Range | Critical Range |
|---------|--------------|---------------|----------------|
| pH | 6.5 – 8.5 | 5.5–6.5 / 8.5–9 | <5.5 or >9 |
| EC (µS/cm) | <1500 | 1500–3000 | >3000 |
| Temperature (°C) | 20–30 | 30–40 | >40 |

### Water Quality Classification
- **Safe Water:** All parameters within normal range
- **Warning Condition:** One or more parameters in warning range
- **Critical Condition:** Any parameter in critical range

---

## Trend Analysis and Predictive Monitoring
- Historical data stored in the ThingSpeak cloud is used for trend analysis.
- The system supports predictive monitoring in addition to real-time observation.

### Trend Analysis
- Moving average and sliding window techniques applied to pH, EC, and temperature data
- Gradual changes in EC and pH identified to detect early contamination
- Trend visualization distinguishes sensor noise from actual water quality degradation

---

### Predictive Threshold Crossing
- Linear trend estimation predicts future threshold violations
- Rising EC trends indicate increasing ionic concentration
- pH drift predicts possible contamination events
- Alerts are generated proactively if thresholds are expected to be crossed
- This transforms the system from reactive monitoring to proactive decision support.



## Event-Based Alert System
- Event-driven alert mechanism avoids continuous notifications
- Email alerts triggered using ThingSpeak React applications
- SMS alerts generated via webhooks and external services
- Independent alerts for pH, EC, and temperature
- Ensures timely notification with reduced data overload



## Results and Discussion
- Successful real-time monitoring of water quality parameters
- Clear variation observed in electrical conductivity
- Observable pH variation under different conditions
- Temperature variation captured accurately
- Reliable data visualization on ThingSpeak
- Effective alert generation during abnormal conditions

## Conclusion
- The system provides intelligent and automated water quality monitoring.
- Cloud analytics enable real-time decision support.
- Event-based alerts improve response time during abnormal conditions.
- The architecture supports scalable and real-world deployments.
