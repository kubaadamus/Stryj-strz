#define tak 2
#define nie 4
#define odb A0
#define rel 8
int odb_val=0;
int interval=135;
long StartTime=0;
long  EndTime=0;
boolean ZapalDiode=false;
boolean OdbCheck=true;
int czas_zbadany=0;
void setup() {
  pinMode(tak,OUTPUT);
  pinMode(nie,OUTPUT);
  pinMode(odb,INPUT);
  pinMode(rel,OUTPUT);
  Serial.begin(9600);
  digitalWrite(rel,HIGH);
}

void loop() {
//Timer();
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
  czas_zbadany = EndTime-StartTime;
  Serial.println(czas_zbadany);

}

  if(czas_zbadany>80 && czas_zbadany<90)
{
  digitalWrite(tak,HIGH);
  digitalWrite(nie,LOW);

  Serial.println("T");
}
else{
  digitalWrite(tak,LOW);
  digitalWrite(nie,HIGH);

  Serial.println("N");
}
if(millis()-StartTime>200)
{
    digitalWrite(tak,LOW);
  digitalWrite(nie,HIGH);

  Serial.println("N");
  czas_zbadany=0;
}

}
