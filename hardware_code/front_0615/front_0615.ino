//0, 1, 2, 3    ->     右前輪
//4, 5, 6, 7    ->     左前輪
//0, 1          ->     TX, RX
//2, 3        ->     連接後板
//A0, A1        ->     SCL, SDA
#include <Wire.h>
//#include <MPU6050.h>
#include <SoftwareSerial.h>

SoftwareSerial BT (9, 8);
char text;

void setup()
{
    //左前輪
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);

    //右前輪
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);

    //bluetooth
    BT.begin(115200);

    //gyro
    Serial.begin(115200);
    // Serial.println("Initialize MPU6050");

    // while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
    // {
    //     Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    //     delayMicroseconds(500);
    // }

    // checkSettings();

}

int t = 1000;

void stepForward()
{

  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delayMicroseconds(t);

  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delayMicroseconds(t);

  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delayMicroseconds(t);

  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delayMicroseconds(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delayMicroseconds(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delayMicroseconds(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delayMicroseconds(t);

  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delayMicroseconds(t);
}

void stepBack()
{
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delayMicroseconds(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delayMicroseconds(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 1);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  delayMicroseconds(t);

  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delayMicroseconds(t);

  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 1);
  digitalWrite(19, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delayMicroseconds(t);

  digitalWrite(2, 0);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  delayMicroseconds(t);

  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delayMicroseconds(t);

  digitalWrite(2, 1);
  digitalWrite(3, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  delayMicroseconds(t);

}


void loop()
{
    //bluetooth
    if (Serial.available())
    {
        text = Serial.read();
        BT.write(text);
    }

    if (BT.available())
    {
        Serial.println(char(BT.read()));
    }
    
    
    // stepper 
    for(int i=1;i<=512;i++){
        stepForward();
    }
//    //Serial.println("One round");
//        delayMicroseconds(200);
//
//    for(int i=1;i<=512;i++){
//        stepBack();
//    //  Serial.println(String(i));
//    }
//    //Serial.println("One round");
//        delayMicroseconds(200);

}
