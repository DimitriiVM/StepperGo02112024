/*
#AUTHOR Дмитрий Витальевич Мельник
#MAIL i.x.c.o.n@yandex.ru
#LICENSE Использование  только  для не коммерческих проектов, без упоминания автора. При использовании автор не несет ни какой отвественности, и не дает ни какой гарантии работы. Не ведет поддержку или исправление ошибок. 
*/

#include <Stepper.h> //Библиотека для  шагового двигателя
#define PINSPEED A6
#define PINBUTTON 2
#define PINRADIO 3

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, A0, A1, A2, A3);

int setSpeed = 60;
int pos = 0;

void setup()
{
  myStepper.setSpeed(setSpeed);
  Serial.begin(115200);  
  pinMode(PINSPEED, INPUT);
  pinMode(PINBUTTON, INPUT_PULLUP);
  pinMode(PINRADIO, INPUT_PULLUP);

}
 
void loop()
{
  pos = analogRead(PINSPEED);
  pos = map(pos, 0, 1023, 0, 200);
  Serial.print("Speed: ");
  Serial.println(pos);
  if(pos != 0){
    if(digitalRead(PINBUTTON) == 0)
    {
      // step one revolution  in one direction:
      if(digitalRead(PINRADIO) == 0)
      {
        pos = pos*-1;
      }
      myStepper.step(pos);
      delay(1000); 
    } 
  }  
  else
  {
    delay(100);
  }      
}