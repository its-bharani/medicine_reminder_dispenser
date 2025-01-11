byte incom_value_hr;
byte incom_value_min;
byte incom_value_hr_2;
byte incom_value_min_2;
byte deci;
//char daisy;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


if(Serial.available()>0)
  { 
    //daisy=Serial.read();
    deci=Serial.read();
    Serial.print(deci);
    if(deci==00000000){
    incom_value_hr=Serial.read();
    incom_value_min=Serial.read();
    Serial.println(deci);
    Serial.println(incom_value_hr);
    Serial.println("\n");
    Serial.println(incom_value_min);
    Serial.println("\n");}
    else{
      incom_value_hr_2=Serial.read();
    incom_value_min_2=Serial.read();
   // Serial.print(deci);
    Serial.print(incom_value_hr_2);
    Serial.print("\n");
    Serial.print(incom_value_min_2);
    Serial.print("\n");}
    }
    
}
