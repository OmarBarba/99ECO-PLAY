char dato;
int motor=3;
float vin=0.0;
float vout=0.0;
float r1= 100000.0;
float r2= 10000.0;
int value=0;
int valent=A0;

  void setup()
    {
    pinMode(motor,OUTPUT);//
    Serial.begin(9600);
    Serial2.begin (9600);
    pinMode(valent,INPUT);
  }

  void loop(){
    value= analogRead(valent);
    vout=(value*5.0)/1024.0;
    vin= vout*100/5;
    Serial.println(vin);
    Serial.println(vout);

  
  if(Serial2.available()){
  dato = Serial2.read();
  Serial.println(dato);

  if(dato=='A'){
   digitalWrite(motor,HIGH);
  }
  if(dato=='B'){
   digitalWrite(motor,LOW);
  }
  }
  else Serial.println("esperando informacion");
  Serial.println(dato);
    Serial2.print(vin);
  
  delay (500);
}
