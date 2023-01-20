#include <Wire.h>
#include <MS5611.h>


MS5611 ms5611;

double referencePressure;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  
  
  Serial.println("初始化 MS5611");
  while(!ms5611.begin(MS5611_HIGH_RES))
  {
    Serial.println("无法找到MS5611，检查连接情况!");
    delay(500);
  }
  referencePressure = ms5611.readPressure();
  checkSettings();
}

void checkSettings()
{
  Serial.print("Oversampling: ");
  Serial.println(ms5611.getOversampling());
}
float hohe()
{
  // 读取原始值
  uint32_t rawTemp = ms5611.readRawTemperature();
  uint32_t rawPressure = ms5611.readRawPressure();
 
  // 读取转换后的数值
  double realTemperature = ms5611.readTemperature();
  long realPressure = ms5611.readPressure();
 
  // 高度计算
  float absoluteAltitude = ms5611.getAltitude(realPressure);
  float relativeAltitude = ms5611.getAltitude(realPressure, referencePressure);

  return relativeAltitude;
  } 
void loop() {
  // put your main code here, to run repeatedly:
    float val = hohe();
    String stringOne = String(val, 2);
    Serial.println(stringOne);
  
     
  
  delay(100);
 
}
