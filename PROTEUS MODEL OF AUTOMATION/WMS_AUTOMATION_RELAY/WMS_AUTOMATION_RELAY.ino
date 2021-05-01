#define RELAY1 7
#define RELAY2 6
#define RELAY3 5
#define RELAY4 4
#define Sensor1 8
char t;
 
void setup() {
 
pinMode(RELAY1,OUTPUT);   
pinMode(RELAY2,OUTPUT);   
pinMode(RELAY3,OUTPUT);   
pinMode(RELAY4,OUTPUT);
pinMode(Sensor1,INPUT);    
Serial.begin(9600);
 }
 void loop() {
  
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'L'){            
  digitalWrite(RELAY1,LOW);

  
}
  else if(t == 'l'){ 
  digitalWrite(RELAY1,HIGH);
}
 
 else if(t == 'F'){ 
  digitalWrite(RELAY2,LOW);

}
  else if(t == 'f'){ 
  digitalWrite(RELAY2,HIGH);
  
}
  else if(t == 'C'){ 
  digitalWrite(RELAY3,LOW);
}
  else if(t == 'c'){ 
  digitalWrite(RELAY3,HIGH);
}
  else if(t == 'D'){ 
  digitalWrite(RELAY4,LOW);
}
  else if(t == 'd'){ 
  digitalWrite(RELAY4,HIGH);
} 

  


 }
