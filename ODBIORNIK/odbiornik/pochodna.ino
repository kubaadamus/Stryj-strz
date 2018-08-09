

int oldValue=0;
int newValue=0;
int valDiff=0;
long oldTime=0;
long newTime=0;
long timeDiff=0;
boolean sprawdzaj=true;
int iloscSpr=0;
void pochodna(){
  oldValue=newValue;
  newValue=analogRead(odb);

  valDiff=newValue-oldValue;

  if(valDiff>0)
  {
    iloscSpr+=1;
  }
  if(iloscSpr>20 && sprawdzaj){
    Serial.println(valDiff);
    iloscSpr=0;
    sprawdzaj=false;
  }
  if(valDiff<0)
  {
    iloscSpr=0;
    sprawdzaj=true;
  }
  
}

