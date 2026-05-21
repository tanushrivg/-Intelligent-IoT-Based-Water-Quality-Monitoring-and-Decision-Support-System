Waspmote code :

#include <WaspSensorSW.h>
#include <WaspXBee802.h>
#include <WaspFrame.h>

char RX_ADDRESS[] = "0013A20041CBF7B6";
char WASPMOTE_ID[] = "node_01";
uint8_t error;

float temperatureC;
float pHVoltage;
float pHValue;
float ECResistance;
float ECValue;

#define CAL_PH_10   1.985
#define CAL_PH_7    2.070
#define CAL_PH_4    2.227
#define CAL_TEMP    23.7


#define EC_POINT1_COND  10500
#define EC_POINT2_COND  40000
#define EC_POINT1_CAL   197.00
#define EC_POINT2_CAL   150.00


pt1000Class temperatureSensor;
pHClass pHSensor;
conductivityClass conductivitySensor;

void setup()
{
  USB.ON();
  USB.println(F("Smart Water node with Xbee Transmission"));
  
  frame.setID(WASPMOTE_ID);
  Water.ON();
  xbee802.ON();

  pHSensor.setCalibrationPoints(
    CAL_PH_10,
    CAL_PH_7,
    CAL_PH_4,
    CAL_TEMP
  );

  conductivitySensor.setCalibrationPoints(
    EC_POINT1_COND,
    EC_POINT1_CAL,
    EC_POINT2_COND,
    EC_POINT2_CAL
  );
  USB.println(F("Sensors initialized and calibrated."));
}

void loop()
{
  temperatureC = temperatureSensor.readTemperature();
  pHVoltage = pHSensor.readpH();
  pHValue   = pHSensor.pHConversion(pHVoltage, temperatureC);
  ECResistance = conductivitySensor.readConductivity();
  ECValue      = conductivitySensor.conductivityConversion(ECResistance);


  USB.print(F("Temperature (°C): "));
  USB.println(temperatureC);
  USB.print(F("pH Voltage (V): "));
  USB.print(pHVoltage);
  USB.print(F(" | pH Value: "));
  USB.println(pHValue);
  USB.print(F("EC Resistance (Ohms): "));
  USB.print(ECResistance);
  USB.print(F(" | EC (uS/cm): "));
  USB.println(ECValue);

  frame.createFrame(ASCII);

  frame.addSensor(SENSOR_WATER_WT , temperatureC);   
  frame.addSensor(SENSOR_WATER_PH ,  pHValue);        
  frame.addSensor(SENSOR_WATER_COND,  ECValue);       
  //frame.addSensor(SENSOR_BAT, PWR.getBatteryLevel());


  error = xbee802.send(RX_ADDRESS, frame.buffer, frame.length);

  if (error == 0)
  {
    USB.println(F("Frame sent successfully"));
    Utils.blinkGreenLED();
  }
  else
  {
    USB.println(F("Transmission error"));
    Utils.blinkRedLED();
  }
  
  USB.println(F("Entering deep sleep..."));
  PWR.deepSleep("00:00:05:00", RTC_OFFSET, RTC_ALM1_MODE1, ALL_OFF);
  
  USB.OFF();
  Water.OFF();
}

