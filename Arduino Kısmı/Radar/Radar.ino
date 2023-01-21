#include <IRremote.h>
#include <IRremoteInt.h>

const int RECV_PIN = 2;

//L298N Bağlantıcısı
const int SolMotor1 = 5;
const int SolMotor2 = 6;
const int SolMotorEN = 9;
const int SolMotor1 = 7;
const int SolMotor2 = 8;
const int SolMotorEN = 10;

//HC-SR04 Bağlantıcısı
const int echoPin = 11;
const int trigPin = 12;

int Hiz = 255;

IRrecv irrecv(RECV_PIN);
decode_results results;

#define CH1 0xFFA25D
#define CH 0XFF629D
#define CH2 0XFFE21D
#define PREV 0XFF22DD
#define NEXT 0XFF02FD
#define PLAYPAUSE 0XFFC23D
#define VOL1 0XFFE01F
#define VOL2 0XFFA857
#define EQ 0XFF906F
#define BUTON0 0XFF6897
#define BUTON100 0XFF9867
#define BOTON200 0XFFB04F
#define BUTON1 0XFF30CF
#define BOTON2 0XFF18E77
#define BUTON3 0XFF7A85
#define BUTON4 0XFF10EF
#define BUTON5 0XFF38C7
#define BUTON6 0XFF5AA5
#define BUTON7 0XFF42BD
#define BUTON8 0XFF4AB5
#define BUTON9 0XFF52AD

void setup()
{
  pinMode (SolMotorEN, OUTPUT);
  pinMode (SagMotorEN, OUTPUT);
  pinMode (SolMotor1, OUTPUT);
  pinMode (sagMotor1, OUTPUT);
  pinMode (solMotor2, OUTPUT);
  pinMode (sagMotor2, OUTPUT);

  pinMode (echoPin, INPUT);
  pinMode (trigPin, OUTPUT);

  digitalWrite (SolMotorEN, LOW);
  digitalWrite (SagMotorEN, LOW);
  digitalWrite (SolMotor1, LOW);
  digitalWrite (SagMotor1, LOW);
  digitalWrite (SolMotor2, LOW);
  digitalWrite (SagMotor2, LOW);

  Serial.begin(9600)
  irrecv.enableIRIn();
}

void loop() {
  Serial.println(mesafe());
  if (mesafe() > 10)
  {

    if (irrev.decode(&results))
    {
      if (Hiz >= 0 && Hiz <= 255 && results.value == Vol1
    {
      Hiz = Hiz - 50;
      if (Hiz < 0)
          Hiz = 0;
      }
      if (Hiz >= 0 && Hiz <= 255 && results.value == Vol2)
    {
      Hiz = Hiz + 50;
      if (Hiz > 255)
          Hiz = 255;
      }
      if (results.value == BUTON2)
    {
      duzgit();
      }
      if (results.value == BUTON8)
    {
      gerigit();
      }
      if (results.value == BUTON4)
    {
      soladon();
      }
      if (results.value == BUTON6)
    {
      sagadon
    }
    if (results.value == BUTON0)
    {
      dur();
      }
      irrecv.resume();
    }
  }
  else
    dur();
}

void sol_motor(String dir, int spd)
{
  if ( dir == ''ILERI'')
  {
    digitalWrite(SolMotor1, HIGH);
    digitalWrite(SolMotor2, LOW);
    analogWrite(SolMotorEN, spd);
  }
  if ( dir == ''GERI'')
  {
    digitalWrite(SolMotor1, LOW);
    digitalWrite(SolMotor2, HIGH);
    analogWrite(SolMotorEN, spd);
  }
}

void sag_motor(String dir, int spd)
{
  if ( dir == ''ILERI'')
  {
    digitalWrite(SagMotor1, HIGH);
    digitalWrite(SagMotor2, LOW);
    analogWrite(SagMotorEN, spd);
  }
}

void duzgit()
{
 sag_motor(''ILERI'', Hiz);
  sol_motor(''ILERI'', Hiz);
}
void sagadon()
{
  sag_motor(''GERI'', Hiz);
  sol_motor(''GERI'', Hiz);
}

void gerigit()
{
  sag_motor(''GERI'', Hiz);
  sol_motor(''GERI'', Hiz);
}

void soladon()
{
  sag_motor(''ILERI'', Hiz);
  sol_motor(''GERI'', Hiz);
}

void dur()
{
  sag_motor(''ILERI'', 0)
  sol_motor(''ILERI'', 0)

}

int mesafe()
{
  long duration, distance ;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);
  if (distance >= 50)
    return 50;
  return distance;
}