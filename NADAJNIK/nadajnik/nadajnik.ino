#define nad 3
#define odb A0
int odb_val=0;
int interval=100; //75-84 nadawania dla 86-120 odbierania
long StartTime=0;
long  EndTime=0;
boolean ZapalDiode=false;
boolean OdbCheck=true;
void setup() {
  pinMode(nad,OUTPUT);
  pinMode(odb,INPUT);
  Serial.begin(9600);
}

void loop() {
Timer();

}
