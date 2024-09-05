/*太阳能追日系统测试

Solar Chasing System Testing
测试平台arduino nano 328p
Test platform Arduino Nano 328p
*/
int PutINlightR=A0;
int PutINlightL=A1;
int PutINlight3=A2;
int PutINlight4=A3;//光敏电阻检测引脚定义 Photoresistor detection pin definition


int number = 0;
int number1 = 0;
int number2 = 0;
int number3 =0;//代数  number
int percentnumber=0;
int percentnumber2=0;
int percentnumber3=0;
int percentnumber4=0;//光敏转换百分数值 Numeric conversion

  int IN1pin= 2;//定义步进电机引脚 Define the stepper motor pins
  int IN2pin=3;
  int IN3pin=4;
  int IN4pin=5;//旋转电机定义  Definition of a rotating machine
  int IN4pin=5;

  int IN5pin= 6;//定义步进电机引脚 Define the stepper motor pins
  int IN6pin=7;
  int IN7pin=8;
  int IN8pin=9;//俯仰电机 Pitch motor

  int Horizontal;//水平计算数值 Calculate the value horizontally
int Horizontal2;//水平计算数值
  int Pitch;//俯仰计算数值 Pitch calculates the value
int Pitch2;//俯仰计算数值

void setup() {
 Serial.begin(9600);
 pinMode(IN1pin,OUTPUT);
  pinMode(IN2pin,OUTPUT);
  pinMode(IN3pin,OUTPUT);
  pinMode(IN4pin,OUTPUT);//电机1 Motor 1

  pinMode(IN5pin,OUTPUT);//电机2 Motor 2
  pinMode(IN6pin,OUTPUT);
  pinMode(IN7pin,OUTPUT);
  pinMode(IN8pin,OUTPUT);//设置电机引脚为输出 Set the motor pin as the output


}

void loop() { 
number=analogRead(A0) ; 
percentnumber =map(number,0,1023,0,100);//一象限 One quadrant

number1=analogRead(A1);
percentnumber2 =map(number1,0,1023,0,100);//二象限 Two quadrants

number2=analogRead(A2) ; 
percentnumber3 =map(number2,0,1023,0,100);//三象限 Three quadrants

number3=analogRead(A3);
percentnumber4 =map(number3,0,1023,0,100);//四象限 Four quadrants
Serial.println(percentnumber);
Serial.println(percentnumber2);
Serial.println(percentnumber3);
Serial.println(percentnumber4);


delay(50);


Horizontal=(percentnumber2+percentnumber3)-(percentnumber+percentnumber4);
Horizontal2=(percentnumber+percentnumber4)-(percentnumber2+percentnumber3);
Pitch=(percentnumber3+percentnumber4)-(percentnumber+percentnumber2);
Pitch2=(percentnumber+percentnumber2)-(percentnumber3+percentnumber4);

 if((Horizontal<=20)&&(Horizontal2<=20)&&(Pitch<=20)&&(Pitch2<=20))
{
delay(500);
}

else if(Horizontal>10)
{digitalWrite(IN4pin,HIGH);//右转 Turn right
  digitalWrite(IN4pin,LOW);

  digitalWrite(IN3pin,HIGH);
  delay(3);
  digitalWrite(IN3pin,LOW);

  digitalWrite(IN2pin,HIGH);
  delay(3);
  digitalWrite(IN2pin,LOW);

  digitalWrite(IN1pin,HIGH);
  delay(3);
  digitalWrite(IN1pin,LOW);
}


else if(Horizontal2>10)
{digitalWrite(IN1pin,HIGH);//左转 Left
  delay(3);
  digitalWrite(IN1pin,LOW);

  digitalWrite(IN2pin,HIGH);
  delay(3);
  digitalWrite(IN2pin,LOW);

digitalWrite(IN3pin,HIGH);
  delay(3);
  digitalWrite(IN3pin,LOW);

  digitalWrite(IN4pin,HIGH);
  delay(3);
  digitalWrite(IN4pin,LOW);

}


else if(Pitch>10)
{
digitalWrite(IN5pin,HIGH);
  delay(3);
  digitalWrite(IN5pin,LOW);

  digitalWrite(IN6pin,HIGH);
  delay(3);
  digitalWrite(IN6pin,LOW);

digitalWrite(IN7pin,HIGH);
  delay(3);
  digitalWrite(IN7pin,LOW);

  digitalWrite(IN8pin,HIGH);
  delay(3);
  digitalWrite(IN8pin,LOW);//上转 Turn up
}

else if(Pitch2>10)
{
digitalWrite(IN4pin,HIGH);//下转 Turn down
  delay(3);
  digitalWrite(IN8pin,LOW);

  digitalWrite(IN7pin,HIGH);
  delay(3);
  digitalWrite(IN7pin,LOW);

  digitalWrite(IN6pin,HIGH);
  delay(3);
  digitalWrite(IN6pin,LOW);

  digitalWrite(IN5pin,HIGH);
  delay(3);
  digitalWrite(IN5pin,LOW);

}


}


