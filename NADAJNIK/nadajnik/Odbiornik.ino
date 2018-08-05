void Odbiornik(){
  odb_val = analogRead(odb);
//Serial.println(odb_val);

if(odb_val>1000 && OdbCheck)
{
  StartTime=millis();
  OdbCheck=false;
}
if(odb_val<980 && !OdbCheck)
{
  EndTime=millis();
  OdbCheck=true;
  Serial.println(EndTime-StartTime);
}
}

