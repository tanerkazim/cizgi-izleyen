#define SensorEnSol 28  
#define SensorSol 26
#define SensorSag 24
#define SensorEnSag 22 

#define MotorR1 10
#define MotorR2 9
#define MotorRE 8

#define MotorL1 12
#define MotorL2 11
#define MotorLE 13

#define Buzz 2
#define trigPin 4
#define echoPin 3

int inner = 0;
boolean sensorModu = false;
unsigned long secs = 0;
unsigned long dist = 0;
unsigned long pastTimme=0;
boolean baslangic = true;
int currentTime;

void ses(int zaman){
  Serial.println("Zaman: "+(String)zaman);
  if(millis()-pastTimme>(zaman*2)){
    tone(Buzz, 3000, zaman);
    pastTimme=millis(); 
    }
}

void setup() {
  
  pinMode(SensorEnSol, INPUT);
  pinMode(SensorSol, INPUT);
  pinMode(SensorSag, INPUT);
  pinMode(SensorEnSag, INPUT);
  
  Serial.begin(9600);
  Serial3.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  
  pinMode(Buzz, OUTPUT);
  digitalWrite(Buzz, LOW);

  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);

  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);


}

void loop() {
  if(Serial3.available()){
    inner = Serial3.read();
    Serial.write(inner);
    if(inner == 115){//selecte basılmşsa s=115
      sensorModu = !sensorModu;
    }
 }   
  if(baslangic && sensorModu){  
  currentTime = millis();
    while(currentTime+5000 > millis()){
      ses(500);
      Serial.println("milis: " + (String)millis());Serial.println("cT: " + (String)currentTime);  
    }
    baslangic = false;
  }
    
  if(sensorModu && digitalRead(SensorEnSol) == 0 && digitalRead(SensorSol) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorEnSag) == 0) // ileri // 120 100
{
  ileri(120, 100);
}else if(sensorModu && digitalRead(SensorEnSol) == 0 && digitalRead(SensorSol) == 1 && digitalRead(SensorSag) == 0 && digitalRead(SensorEnSag) == 0) // ileri-sol // 90 80
{
  ileri(90, 90);
}else if(sensorModu && digitalRead(SensorEnSol) == 0 && digitalRead(SensorSol) == 0 && digitalRead(SensorSag) == 1 && digitalRead(SensorEnSag) == 0) // ileri-sağ // 100 70
{
  ileri(120, 70);
}else if(sensorModu && digitalRead(SensorEnSol) == 0 && digitalRead(SensorSol) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorEnSag) == 0) // çizgi-ara // 60 50 - Bir kere
{
  ileri(75, 65);
}else if(sensorModu && digitalRead(SensorEnSol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorEnSag) == 1) // siyah-dur -- çizgi-ara // 0 0
{
  ileri(75, 65);
}else if(sensorModu && digitalRead(SensorEnSol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorEnSag) == 0) // tam-sol // 0 75
{
  dur();
  ileri(0, 75);  delay(20);
}else if(sensorModu && digitalRead(SensorEnSol) == 0 && digitalRead(SensorSol) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorEnSag) == 1) // tam-sag // 90 0
{
  dur();
  ileri(90, 0);  delay(20);
}else if(sensorModu && digitalRead(SensorEnSol) == 1 && digitalRead(SensorSol) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorEnSag) == 0) // geri-sol // -60 50
{
  dur();
  geriSol(95, 80);  delay(20);
}else if(sensorModu && digitalRead(SensorEnSol) == 0 && digitalRead(SensorSol) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorEnSag) == 1) // geri-sag // 60 -50
{
  dur();
  geriSag(95, 80);  delay(20);
}else if(sensorModu && digitalRead(SensorEnSol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorSag) == 0 && digitalRead(SensorEnSag) == 0) // tam-sol // 0 75
{
  ileri(0, 105);
}else if(sensorModu && digitalRead(SensorEnSol) == 0 && digitalRead(SensorSol) == 0 && digitalRead(SensorSag) == 1 && digitalRead(SensorEnSag) == 1) // tam-sag // 90 0
{
  ileri(120, 0);
}else if(sensorModu && digitalRead(SensorEnSol) == 1 && digitalRead(SensorSol) == 0 && digitalRead(SensorSag) == 1 && digitalRead(SensorEnSag) == 0) // çizgi-ara // 70 0
{
  ileri(75, 65);
}else if(sensorModu && digitalRead(SensorEnSol) == 0 && digitalRead(SensorSol) == 1 && digitalRead(SensorSag) == 0 && digitalRead(SensorEnSag) == 1) // çizgi-ara // 70 0
{
  ileri(75, 65);
}else if(sensorModu && digitalRead(SensorEnSol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorSag) == 0 && digitalRead(SensorEnSag) == 1) // çizgi-ara // 70 0
{
  ileri(75, 65);
}else if(sensorModu && digitalRead(SensorEnSol) == 1 && digitalRead(SensorSol) == 0 && digitalRead(SensorSag) == 1 && digitalRead(SensorEnSag) == 1) // çizgi-ara // 70 0
{
  ileri(75, 65);
}else if(sensorModu && digitalRead(SensorEnSol) == 1 && digitalRead(SensorSol) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorEnSag) == 1) // çizgi-ara // 70 0
{
  ileri(75, 65);
}else{
    if(inner == 117)//u=117 // 120 100
    ileri(120, 100);
    else if(inner == 100)//d=100 // 120 100
    geri(120, 100);
    else if(inner==114)//r=114 // 110 0
    sag(110, 0);
    else if(inner==108)//l=108 // 0 75
    sol(0, 75);
    else if(!sensorModu){
    delay(150);
    dur();
    }
    else
    dur();
    inner=0;
  }
  //dur();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  secs = pulseIn(echoPin, HIGH, 1600);
  dist = (secs /29.1)/2;
  Serial.print("Süre: "+(String)secs);
  Serial.println("   Uzaklık: "+(String)dist);

  if(dist<15 && dist > 0){ses(200); sensorModu=false;}
else{digitalWrite(Buzz,LOW);}
}


void ileri(int sol, int sag){  

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, sag);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, sol); 
  
  
}


void sag(int sol, int sag){

  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, sag); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, sol); 
  
  
}

void sol(int sol, int sag){

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, sag);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorLE, sol); 
  
}

void geri(int sol, int sag){
  digitalWrite(MotorR1, LOW); 
  digitalWrite(MotorR2, HIGH); 
  analogWrite(MotorRE, sag); 

  digitalWrite(MotorL1, LOW); 
  digitalWrite(MotorL2, HIGH); 
  analogWrite(MotorLE, sol);
}

void geriSol(int sol, int sag){
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, sag); 

  digitalWrite(MotorL1, LOW); 
  digitalWrite(MotorL2, HIGH); 
  analogWrite(MotorLE, sol);
}

void geriSag(int sol, int sag){
  digitalWrite(MotorR1, LOW); 
  digitalWrite(MotorR2, HIGH); 
  analogWrite(MotorRE, sag); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, sol);
}

void dur(){ // Robotun durma hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, LOW);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, LOW);
  
}
