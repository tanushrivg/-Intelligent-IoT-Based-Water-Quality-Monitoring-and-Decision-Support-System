# -Intelligent-IoT-Based-Water-Quality-Monitoring-and-Decision-Support-System
IoT-based intelligent water quality monitoring system using pH, electrical conductivity, turbidity and temperature sensors. Data is acquired via a Libelium water board and transmitted through a Meshlium gateway to the cloud for real-time visualization, WQI computation, trend analysis, and automated alerts.

INTRODUCTION:

Water quality monitoring is a critical requirement in drinking water management, agriculture, and environmental protection. Conventional water testing methods rely on manual sampling and laboratory analysis, which are time-consuming, labour-intensive, and unsuitable for real-time monitoring. With increasing water pollution and resource scarcity, there is a need for an automated, real-time, and intelligent monitoring system.

This project presents an Intelligent IoT-Based Water Quality Monitoring and Decision Support System using Libelium sensor nodes, a Meshlium gateway, and ThingSpeak cloud platform. The system continuously monitors key water quality parameters such as pH, electrical conductivity (EC), and temperature, processes the data in the cloud, classifies water quality conditions, and generates event-based alerts via email and SMS.

Unlike basic monitoring systems, this project integrates decision logic, analytics, and alert mechanisms, making it suitable for real-world deployment and scalable environmental monitoring applications.


OBJECTIVES :

The main objectives of this project are:
•	To design an IoT-based system for real-time water quality monitoring
•	To measure pH, electrical conductivity, and temperature of water
•	To transmit sensor data wirelessly using Libelium and Meshlium
•	To analyze and visualize data using ThingSpeak cloud
•	To classify water quality using predefined thresholds
•	To generate event-based email and SMS alerts during abnormal conditions
•	To demonstrate scalability for large-scale water monitoring applications


SYSTEM ARCHITECTURE:

1.	Sensing Layer
o	pH Sensor
o	Electrical Conductivity Sensor
o	Water Temperature Sensor
2.	Edge Device Layer
o	Libelium Sensor Board (data acquisition and preprocessing)
3.	Gateway Layer
o	Meshlium Gateway (data aggregation and internet connectivity)
4.	Cloud Layer
o	ThingSpeak Cloud Platform
o	Data storage and visualization
o	MATLAB-based analytics
5.	Application Layer
o	Decision support logic
o	Email and SMS alert system


HARDWARE REQUIREMENTS:

•	Libelium Water vertical Board
•	Waspmote
•	pH Sensor
•	Electrical Conductivity Sensor
•	Water Temperature Sensor
. Turbidity Sensor 
•	Meshlium Gateway
•	Power Supply

 
 SOFTWARE REQUIREMENTS:

•	Waspmote IDE 
•	Meshlium Manager
•	ThingSpeak Cloud Platform
•	MATLAB Analytics (ThingSpeak)
•	Webhook services (for SMS alerts)


WATER QUALITY ANALYSIS AND DECISION SUPPORT:

Water Quality Index (WQI)
To enhance decision-making and convert multiple sensor readings into a single actionable metric, a Water Quality Index (WQI) is computed in the cloud using ThingSpeak MATLAB analytics. WQI provides a quantitative representation of overall water quality, widely used in environmental monitoring systems.

The WQI is calculated using a weighted aggregation of normalized sensor parameters:
WQI = w₁·pH_norm + w₂·EC_norm + w₃·Temp_norm
Where:
•	pH_norm, EC_norm, and Temp_norm are normalized values of pH, electrical conductivity, and temperature
•	w₁, w₂, w₃ are weighting factors based on parameter importance

Typical weights used in this system:
•	pH (0.4)
•	Electrical Conductivity (0.4)
•	Temperature (0.2)

WQI Classification:
Based on the computed WQI, water quality is classified as:
WQI Range	Water Quality Status
0 – 50	Excellent
51 – 100	Good
101 – 200	Poor
>200	Unsuitable
Alerts are triggered when the WQI crosses predefined thresholds, enabling faster response compared to monitoring individual parameters alone.

Parameter Thresholds:
Parameter	Normal Range	Warning Range	Critical Range
pH	6.5 – 8.5	5.5–6.5 / 8.5–9	<5.5 or >9
EC (µS/cm)	<1500	1500–3000	>3000
Temperature (°C)	20–30	30–40	>40

Water Quality Classification:
•	Safe Water: All parameters within normal range
•	Warning Condition: One or more parameters in warning range
•	Critical Condition: Any parameter in critical range

 
TREND ANALYSIS AND PREDICTIVE MONITORING:

In addition to real-time monitoring, the system incorporates trend analysis and predictive monitoring using historical data stored in the ThingSpeak cloud.

Trend Analysis
•	Moving average and sliding window techniques are applied to pH, EC, and temperature data
•	Gradual changes in EC and pH are identified to detect early signs of contamination
•	Trend visualization helps distinguish between transient noise and actual degradation

Predictive Threshold Crossing
. Using linear trend estimation, the system predicts potential threshold violations:
•	Rising EC trends indicate increasing ionic concentration
•	pH drift predicts possible contamination events

The system estimates whether parameters will cross critical thresholds within a future time window and proactively generates alerts.
This predictive capability transforms the system from reactive monitoring to proactive decision support.

 
EVENT-BASED ALERT SYSTEM:

Instead of continuous notifications, the system uses an event-driven alert mechanism:
•	Email alerts triggered using ThingSpeak React applications
•	SMS alerts generated via webhooks and external services
•	Independent alerts for pH, EC, and temperature
.This ensures timely notification and reduced data overload.
 
RESULTS AND DISCUSSION:

The system successfully demonstrated:
•	Real-time monitoring of water quality parameters
•	Clear variation in EC 
•	pH variation 
•	Temperature variation 
•	Reliable data visualization on ThingSpeak
•	Effective alert generation during abnormal conditions

APPLICATIONS:

•	Drinking water quality monitoring
•	Agricultural irrigation management
•	River and lake pollution monitoring
•	Industrial wastewater monitoring
•	Smart city water management systems


CONCLUSION:

This project demonstrates an intelligent, scalable, and automated IoT-based water quality monitoring system. By integrating cloud analytics and event-driven alerts, the system moves beyond basic monitoring and provides actionable decision support. The proposed architecture is suitable for real-world deployment and future expansion.






