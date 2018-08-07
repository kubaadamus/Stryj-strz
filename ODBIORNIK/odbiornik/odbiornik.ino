#define tak 3
#define nie 4
#define odb A1
#define rel 0
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
}
void loop() {
  standard();
  
}
