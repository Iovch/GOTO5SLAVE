// GOTO5SLAVE.ino Written by Igor Ovchinnikov 17/07/2016

#include <IRremote.h>
#include <Wire.h>

#define RECV_PIN   12 //Пин ИК приемника
#define SLAVE_ADDR 10 //Адрес I2C Slave устройства

IRrecv irrecv(RECV_PIN); //Создаем обработчик ИК сигнала
decode_results results;  //Переменная, хранящая результат

unsigned int iLastValue=0;
boolean bDebug=false;

// Здесь следует указать правильное расположение и название подключаемого файла:

#include "IRVitek.h"

void ReqEvent(void)
{
 Wire.write(iLastValue);
 if(bDebug) Serial.println(iLastValue); //Дублируем данные в СОМ порт при отладке
}

void setup()
{
  Wire.begin(SLAVE_ADDR);    // Создаем I2C Slave устройство
  Wire.onRequest(ReqEvent);  // Регистрируем функцию обработки запроса I2C
  if(bDebug) {Serial.begin(9600); Serial.flush();} // Подготавливаем СОМ порт для отладки
  irrecv.enableIRIn();       // Начинаем прием
}

void loop()
{
 unsigned int iValue=0;
 iValue=AskVitekIR(); // Опрос 48 кнопочного пульта от DVD Vitek
 if(iValue!=50) iLastValue=iValue;
 if(bDebug){ ReqEvent(); }
 delay(125);
}
