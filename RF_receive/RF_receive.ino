#include <SPI.h>  
#include "RF24.h" 
long long oldTime=0;
RF24 myRadio (7, 8); 
struct package
{
  int id=0;

};

byte addresses[][6] = {"0"}; 



typedef struct package Package;
Package data;

void setup() 
{
  Serial.begin(115200);
  delay(1000);
  myRadio.begin(); 
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();

  pinMode(5,OUTPUT);
}


void loop()  
{
  if ( myRadio.available()) 
  {
    while (myRadio.available())
    {
      myRadio.read( &data, sizeof(data) );
    }
    Serial.print(data.id);
    if(data.id==1){
      digitalWrite(5,HIGH);
      oldTime=millis();
      Serial.println("MOZNA");
    }
  }
      if(millis()>oldTime+300){
        digitalWrite(5,LOW);
        Serial.println("NIE MOZNA");
    }

}
