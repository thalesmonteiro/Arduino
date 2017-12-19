#include <Ultrasonic.h> //Biblioteca do sensor ultrasonico
#include <DMPH.h> //Biblioteca dos motores

#define echoPin 3 //Pino 3 recebe o pulso do echo   
#define trigPin 2 //Pino 2 envia o pulso para gerar o echo  
DMPH motorEsquerdo(7,5,6);
DMPH motorDireito(10,8,9);
Ultrasonic ultrasonic(trigPin, echoPin);   

  // Executado na inicialização do Arduino 
#define ENA  6  
#define IN1  5
#define IN2  7
#define ENB  9
#define IN3  10
#define IN4  8
  
void setup(){   
      Serial.begin(9600); // inicializa a comunicação serial para Debug ou para mostrar dados em um display LCD   
      
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);
      pinMode(IN3, OUTPUT);
      pinMode(IN4, OUTPUT);
      pinMode(ENA, OUTPUT);
      pinMode(ENB, OUTPUT);

}   

void loop(){
  
      int distancia;
      distancia = ultrasonic.Ranging(CM);

      if(distancia <= 15){
          motorDireito.move(170);
          motorEsquerdo.move(-117); //Valor negativo para ocorrer a inversão de polaridade e o motor girar no sentido contrário.
          delay(500);
      }else{
          motorDireito.move(170);
          motorEsquerdo.move(117);
      }
    
}

