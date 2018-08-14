int odb_val=0;
int interval=135;
long StartTime=0;
long  EndTime=0;
boolean ZapalDiode=false;
boolean OdbCheck=true;
int czas_zbadany=0;
long czas_do_kalibracji=0;
long czas_trwania_kalibracji=0;
int minThreshold=1023;
int maxThreshold=0;
float midThreshold=0;
float margin=0;
void standard(){


//okresowa kalibracja//
if(millis()>czas_do_kalibracji){
      digitalWrite(13,HIGH);
  czas_do_kalibracji=millis()+5000; // przesun kolejna kalibracje za 5 sekund w przód
  czas_trwania_kalibracji = millis();
  maxThreshold=0;
  minThreshold=1023;
  while(millis()<czas_trwania_kalibracji+250)
  {
    odb_val=analogRead(odb);
    if(odb_val>maxThreshold){
      maxThreshold=odb_val;
    }
    if(odb_val<minThreshold){
      minThreshold=odb_val;
    }

    midThreshold=(maxThreshold+minThreshold)/2.0f;
    margin = (maxThreshold-minThreshold)/5.0f;
  }
  digitalWrite(13,LOW);
  Serial.print("Max threshold: ");
  Serial.print(maxThreshold);
  Serial.print("Min threshold: ");
  Serial.print(minThreshold);
  Serial.print("MID:");
  Serial.print(midThreshold);
  Serial.print("margin: ");
  Serial.println(margin);
  
}

  
odb_val = analogRead(odb);
if(odb_val>midThreshold+margin && OdbCheck)
{
  EndTime=StartTime;
  StartTime=millis();
  OdbCheck=false;
  czas_zbadany=StartTime-EndTime;
}
if(odb_val<midThreshold-margin && !OdbCheck)
{
  OdbCheck=true;
}
  if(czas_zbadany>160 && czas_zbadany<230)
{
  digitalWrite(tak,HIGH);
  digitalWrite(nie,LOW);
  Serial.print("Czas zbadany");
  Serial.println(czas_zbadany);
}
else{
  digitalWrite(tak,LOW);
  digitalWrite(nie,HIGH);
}

}
