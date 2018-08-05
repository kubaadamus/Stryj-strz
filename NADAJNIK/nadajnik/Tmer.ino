long long int act_time=0;
void Timer(){
if(millis()>=act_time)
{
  act_time+=interval;

  ZapalDiode=!ZapalDiode;
    digitalWrite(nad,ZapalDiode);
}
}

