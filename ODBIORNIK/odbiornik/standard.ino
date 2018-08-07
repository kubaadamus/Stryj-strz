void standard(){
    czas_zbadany=0;
  odb_val = analogRead(odb);
if(odb_val>380 && OdbCheck)
{
  StartTime=millis();
  OdbCheck=false;
}
if(odb_val<10 && !OdbCheck)
{
  EndTime=millis();
  OdbCheck=true;
  czas_zbadany = EndTime-StartTime;
}
  if(czas_zbadany>80 && czas_zbadany<90)
{
  digitalWrite(tak,HIGH);
  digitalWrite(nie,LOW);
}
else{
  digitalWrite(tak,LOW);
  digitalWrite(nie,HIGH);
}
if(millis()-StartTime>200)
{
    digitalWrite(tak,LOW);
  digitalWrite(nie,HIGH);

}
}
