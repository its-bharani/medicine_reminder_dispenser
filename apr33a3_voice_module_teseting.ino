int play1=A0;
int play2=8;
int a=0;
void setup() {
  // put your setup code here, to run once:
pinMode(play1,OUTPUT);
pinMode(play2,OUTPUT);
analogWrite(play1,0);
analogWrite(play2,LOW);
analogWrite(play1,1);
analogWrite(play2,LOW);
//initally low
}

void loop()
 {


  
}
