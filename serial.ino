
//Initializing Variables  
byte byteRead;
int led =13;
int x;
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  //start serial communication
  Serial.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Checking serial communication availability
if(Serial.available( )){
  //reading data from detect blink py file
  byteRead= Serial.read();
  x= byteRead;

  //at the 1st blink detection lights turn on
  if(x==1)
    {
      digitalWrite(led, HIGH);
      digitalWrite(A0, HIGH);
      counter++;
      Serial.println("ONNNNNNNN");
    }

    //at the 2nd blink detection lights turn off and counter is reset
    if(counter==2){
      digitalWrite(led, LOW);
      digitalWrite(A0, LOW);
      counter=0;
      Serial.println("OFFFFFFFF");
    }

  //printing streamed data
  Serial.println(x);
}
}
