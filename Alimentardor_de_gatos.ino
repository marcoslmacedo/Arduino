// temporizador para acionamento do motor do alimentador

//int seg=0, min=0, hor=0;      // inteiros referente ao relógio
//int Pino_motor = 04;              // pino de saida do sinal para o servo motor
//int motState = LOW; // motState usado para armazena o estado atual do motor aceso o desligado
//long intervalo = 1000; // intervalo de um segundo


#include <Servo.h> 
 
Servo microservo;                      // cria um objeto chavado 'microservo' para controlar o servo motor 
                
 
int pos = 0;                          // variavel para armazenar a posicao do servo
int seg=0, min=0, hor=0;              // variaveis referete ao relógio temporizador

// rotacionando o micro servo

void setup() 
{ 
  microservo.attach(4);                // adicionando o servo a porta 04 do arduino
} 
 
void loop ()
{
  relogio();                          // aciona comando relógio 
  mot ();                             // aciona o comando motor
}

void relogio()
{
  static unsigned long ult_tempo = 0;
  int tempo = millis();
  if(tempo - ult_tempo >= 1000) 
    {
      ult_tempo = tempo;
      seg++;
    }
  if(seg>=60) 
    {
      seg = 0;
      min++;
    }
  if(min>=60)
    {
      min = 0;
      hor++;
    }
   if(hor>=24) 
    {
      hor=0;
      min=0;
    }

Serial.print(hor);                 // imprime a hora no monitor serial para verificar se o relógio está funcionando
Serial.print(":");
Serial.print(min);
Serial.print(":");
Serial.println(seg);
}

// em construção
void mot (){

if (hor == 6 || hor == 18 && min == 0 && seg <= 30)     // liga o motor quando for 6 ou 18 horas por aproximadamente 30 seg

  { 
    for(pos = 0; pos <= 180; pos += 1)                 // movimenta o servo de 0 a 180 graus avancando de 1 a 1 grau 
  {                                  
    microservo.write(pos);                             // diz ao servo para ir para a posicao definida na variavel 'pos' 
    delay(15);                                         // tempo que o servo vai levar para chegar na posicao desejada 
    Serial.println("ligou");                           // imprime ligou no serial monitor para verificar se o código está funcionando
  } 
  for(pos = 180; pos>=0; pos-=1)                       // movimenta o servo de 0 a 180 graus retrocedendo de 1 a 1 grau 
  {                                
    microservo.write(pos);                             // diz ao servo para ir para a posicao definida na variavel 'pos'
    delay(15);                                         // tempo que o servo vai levar para chegar na posicao desejada
    Serial.println("desligou");// imprime "desligou" no serial monitor para verificar se o código está funcionando
  } 
 
digitalWrite(Pino_motor, motState);
if (motState == HIGH)
Serial.println("ligou"); // imprime ligou no serial monitor para verificar se o código está funcionando
else
Serial.println("desligou");// imprime "desligou" no serial monitor para verificar se o código está funcionando
}// fim














{
motState = LOW; // caso contrário desliga o motor no restante do tempo
} 

digitalWrite(Pino_motor, motState);
if (motState == HIGH)
Serial.println("ligou"); // imprime ligou no serial monitor para verificar se o código está funcionando
else
Serial.println("desligou");// imprime "desligou" no serial monitor para verificar se o código está funcionando
}// fim


































// original
void mot (){

if (hor == 6 || hor == 18 && min == 0 && seg <= 30){ // liga o motor quando for 6 ou 18 horas por aproximadamente 30 seg
motState = HIGH;// 
}
else // caso contrário desliga o motor
{
motState = LOW; // caso contrário desliga o motor no restante do tempo
} 

digitalWrite(Pino_motor, motState);
if (motState == HIGH)
Serial.println("ligou"); // imprime ligou no serial monitor para verificar se o código está funcionando
else
Serial.println("desligou");// imprime "desligou" no serial monitor para verificar se o código está funcionando
}// fim




void loop() 
{ 
  for(pos = 0; pos <= 180; pos += 1) // movimenta o servo de 0 a 180 graus avancando de 1 a 1 grau 
  {                                  
    microservo.write(pos);              // diz ao servo para ir para a posicao definida na variavel 'pos' 
    delay(15);                       // tempo que o servo vai levar para chegar na posicao desejada 
  } 
  for(pos = 180; pos>=0; pos-=1)     // movimenta o servo de 0 a 180 graus retrocedendo de 1 a 1 grau 
  {                                
    microservo.write(pos);              // diz ao servo para ir para a posicao definida na variavel 'pos'
    delay(15);                       // tempo que o servo vai levar para chegar na posicao desejada
  } 






















void setup()
{
pinMode(Pino_motor, OUTPUT); // saida do sinal para ativar o motor
Serial.begin(9600);
}
void loop (){
relogio();// aciona comando relógio 
mot (); // aciona o comando motor
}

