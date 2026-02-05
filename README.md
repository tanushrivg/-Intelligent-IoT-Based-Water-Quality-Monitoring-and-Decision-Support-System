# -Intelligent-IoT-Based-Water-Quality-Monitoring-and-Decision-Support-System
IoT-based intelligent water quality monitoring system using pH, electrical conductivity, turbidity and temperature sensors. Data is acquired via a Libelium water board and transmitted through a Meshlium gateway to the cloud for real-time visualization, WQI computation, trend analysis, and automated alerts.

Intelligent IoT-Based Water Quality Monitoring and Decision Support System

An intelligent IoT-based system for real-time water quality monitoring using pH, electrical conductivity (EC), turbidity, and temperature sensors. The system leverages Libelium sensor nodes, a Meshlium gateway, and ThingSpeak cloud analytics to enable monitoring, decision support, trend analysis, and automated alerts.

⸻

Introduction

Water quality monitoring is critical for drinking water management, agriculture, and environmental protection. Traditional water testing methods rely on manual sampling and laboratory analysis, which are time-consuming, labor-intensive, and unsuitable for real-time monitoring.

This project presents an Intelligent IoT-Based Water Quality Monitoring and Decision Support System that continuously monitors key water quality parameters, processes data in the cloud, classifies water conditions, and generates event-based alerts via email and SMS. The system is designed to be scalable, automated, and suitable for real-world deployment.

⸻

 Objectives
	•	Design an IoT-based system for real-time water quality monitoring
	•	Measure pH, electrical conductivity (EC), turbidity, and temperature
	•	Transmit sensor data wirelessly using Libelium sensor nodes and Meshlium gateway
	•	Analyze and visualize data using the ThingSpeak cloud platform
	•	Compute Water Quality Index (WQI) for decision support
	•	Generate event-based email and SMS alerts during abnormal conditions
	•	Demonstrate scalability for large-scale environmental monitoring

⸻

 System Architecture

1. Sensing Layer
	•	pH Sensor
	•	Electrical Conductivity Sensor
	•	Turbidity Sensor
	•	Water Temperature Sensor

2. Edge Device Layer
	•	Libelium Water Sensor Board
	•	Waspmote (data acquisition and preprocessing)

3. Gateway Layer
	•	Meshlium Gateway (data aggregation and internet connectivity)

4. Cloud Layer
	•	ThingSpeak Cloud Platform
	•	Data storage and visualization
	•	MATLAB-based analytics

5. Application Layer
	•	Decision support logic
	•	Email and SMS alert system

⸻

 Hardware Requirements
	•	Libelium Water Vertical Board
	•	Waspmote
	•	pH Sensor
	•	Electrical Conductivity Sensor
	•	Turbidity Sensor
	•	Water Temperature Sensor
	•	Meshlium Gateway
	•	Power Supply

⸻

 Software Requirements
	•	Waspmote IDE
	•	Meshlium Manager
	•	ThingSpeak Cloud Platform
	•	MATLAB Analytics (ThingSpeak)
	•	Webhook services (for SMS alerts)

⸻

 Water Quality Analysis and Decision Support

Water Quality Index (WQI)

To convert multiple sensor readings into a single actionable metric, a Water Quality Index (WQI) is computed in the cloud using ThingSpeak MATLAB analytics.

WQI Formula (Weighted Aggregation):
WQI = w1*pH_norm + w2*EC_norm + w3*Temp_norm







