char val;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(38400);
  

}

void loop() 
{
  // put your main code here, to run repeatedly:
 
  if(Serial.available()>0)
  {
    val = Serial.read();
    
    
    Serial.print(val);
  }
  
    
}
