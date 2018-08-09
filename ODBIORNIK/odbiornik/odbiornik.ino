

#define tak 3
#define nie 4
#define odb A0
#define rel 0
void setup() {
  pinMode(tak,OUTPUT);
  pinMode(nie,OUTPUT);
  pinMode(odb,INPUT);
  pinMode(rel,OUTPUT);
  Serial.begin(9600);
}
void loop() {
standard();


}
