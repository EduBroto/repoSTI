int analogllama = A0;
int digillama = 24;
const int alarma = 7;
const int pinLed = 3;
const int pinLdr = A1;
const int pinLed2 = 5;
const int limite = 250;
const int pinagua = A5;
int input = 0;
int pirpin = 11;
int valorpir;
int espera = 1000;
int Relay = 26;



void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLdr, INPUT);
  digitalWrite(pinLed,LOW);
  pinMode(alarma, OUTPUT);
  pinMode(digillama,INPUT);
  pinMode(analogllama,INPUT);
  pinMode(pirpin, INPUT);
  pinMode(pinagua, INPUT);
  digitalWrite(alarma, LOW);
  pinMode(Relay, OUTPUT);

}

void loop() {

valorpir = digitalRead(pirpin);
Serial.println(valorpir);
digitalWrite(alarma, valorpir);
  
llama();
ldr();
agua();


/*
  if (Serial.available()>0)
  {
    char option = Serial.read();
    if(option = '1')
    { 
digitalWrite(pinLed, HIGH);
    }
    else {
      digitalWrite(pinLed, LOW);
    }
    else if (option = '2'){
    tone(22,500);
    }
delay(200);

      
    }
    
  }
  
*/
 

}

void ldr(){

input = analogRead(pinLdr);

if (input > limite) {
digitalWrite(pinLed2, HIGH);
Serial.println((String)"ValorLdr = "  + input);
}
else {
  digitalWrite(pinLed2, LOW);
  Serial.println((String)"ValorLdr = "  + input);
  
}

Serial.println("--------------");
delay(1000);
  
}


void llama(){

int valorllama1 = analogRead(analogllama);
int valorllama2 = digitalRead(digillama);

  Serial.println((String)"Sensor llama: " + valorllama1);
if (valorllama1 < 200){
  Serial.println("-------------");
  Serial.println("Fuego detectado");
  digitalWrite(alarma, HIGH);
  digitalWrite(Relay,HIGH);
  digitalWrite(pinLed, HIGH);
  
 
}

else {
  Serial.println("No hay fuego");
  digitalWrite(alarma,LOW);
  digitalWrite(Relay,LOW);
  digitalWrite(pinLed, LOW);
}


  
}

void agua(){

 int valagua = analogRead(pinagua); //Read data from analog pin and store it to value variable
  Serial.println(valagua);
  Serial.println("-------------------------");


if (valagua <= 5) {
    Serial.println("Nivel agua: 0mm - Vacío!");
    
    delay(espera);
  }
  else if (valagua > 6 && valagua <= 100) {
    Serial.println("Nivel agua: 0mm to 5mm");
    
    delay(espera);
  }
  else if (valagua > 100 && valagua <= 110) {
    Serial.println("Nivel agua: 5mm to 10mm");
    
    delay(espera);
  }
  else if (valagua > 110 && valagua <= 120) {
    Serial.println("Nivel agua: 10mm to 15mm");
    
    delay(espera);
  }
  else if (valagua > 120 && valagua <= 130) {
    Serial.println("Nivel agua: 15mm to 20mm");
   
    delay(espera);
  }
  else if (valagua > 140 && valagua <= 150) {
    Serial.println("Nivel agua: 20mm to 25mm");
    
    delay(espera);
  }
  else if (valagua > 160 && valagua <= 170) {
    Serial.println("Nivel agua: 25mm to 30mm");
    
    delay(espera);
  }
  else if (valagua > 180 && valagua <= 190) {
    Serial.println("Nivel agua: 30mm to 35mm");
   
    delay(espera);
  }

  else if (valagua > 200) {
    Serial.println("Nivel agua: 35mm to 40mm");
    
    delay(espera);
  }
  Serial.println("--------------------");
  
}
