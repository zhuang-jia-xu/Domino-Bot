#include <SoftwareSerial.h>
#include <Stepper.h>
#define STEPS 2048
SoftwareSerial mySerial(13, 12); //RX,TX
Stepper stepperL1(STEPS, 11, 9, 10, 8);
Stepper stepperR1(STEPS, 7, 5, 6, 4);
Stepper stepperL2(STEPS, 17, 15, 14, 16);
Stepper stepperR2(STEPS, 19, 3, 18, 2);


int timer = 0;
bool first = 1;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  //右後輪 逆cw 順ccw
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  //右前輪
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //左前輪 逆cw 順ccw
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  //左後輪
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  stepperL1.setSpeed(10); //設定速度 0-15
  stepperR1.setSpeed(10);
  stepperL2.setSpeed(10);
  stepperR2.setSpeed(10);

  //Serial.begin(9600);
}

void stepBack()
{
  int t = 2;
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(t);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 1);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
}

void stepForward()
{
  int t = 2;
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(14, 1);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 1);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 1);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 0);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(t);
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 1);
  digitalWrite(17, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delay(t);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(t);
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delay(t);
}

bool checkYaw() { //檢查前板是否回傳's'給後板 (to break Rotate Function)

  char cmd2;

  while (true)
  {
    cmd2 = mySerial.read();
    if (cmd2 == 'S')
    {
      return false;
      break;
    }
    else
      return true;
  }

}

void rotateLeft()
{
  while (1) //轉彎
  {
    for (int i = 0; i <= 50; i++)
    {
      stepperL1.step(1);
      stepperL2.step(-1);
      stepperR1.step(-1);
      stepperR2.step(1);
    }
    if (checkYaw() == false) //判斷如果前板說角度足夠就會break出去準備前進
    {
      break;
    }
  }

}

void rotateRight()
{
  while (1) //轉彎
  {
    for (int i = 0; i <= 50; i++)
    {
      stepperL1.step(-1);
      stepperL2.step(1);
      stepperR1.step(1);
      stepperR2.step(-1);
    }
    if (checkYaw() == false) //判斷如果前板說角度足夠就會break出去準備前進
    {
      break;
    }
  }
}

void forward() //rotate後 繼續前進直到最終目的地
{
  //一步大概是5.625度 一圈是step2048的話 就直接 換算得到一百步是3200
  for (int i = 1; i <= 1000; i++)
  {
    stepperL1.step(-1);
    stepperL2.step(1);
    stepperR1.step(-1);
    stepperR2.step(1);
  }
}

void loop() {
  char cmd='#';
  if (mySerial.available())
  {
    cmd = mySerial.read();
    Serial.println(cmd);
    if (cmd == '+')
    {
      rotateLeft();
      //forward();
    }
    if (cmd == '-')
    {
      rotateRight();
      //forward();
    }
    if(cmd=='0')
    {
      forward();
    }
  }

}
