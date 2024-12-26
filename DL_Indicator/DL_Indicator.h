#ifndef DL_INDICATOR_H
#define DL_INDICATOR_H

#include "stm32f1xx_hal.h"  //Заголовочный файл библиотеки HAL соответствующий Вашей серии МК.

extern const uint8_t ASCII_7SEG[96];  //Массив кодов для 7-сегментного индикатора
extern const uint16_t ASCII_14SEG[96];  //Массив кодов для 14-сегментного индикатора
extern const uint16_t ASCII_16SEG[96];  //Массив кодов для 16-сегментного индикатора

typedef enum
{
	DL_7SEGMENT,
	DL_14SEGMENT,
	DL_16SEGMENT,
	DL_BAR,
	DL_MATRIX
} DL_IndicatorType;  //Перечисление типов индикаторов

typedef struct
{
	I2C_HandleTypeDef* i2c;
	DL_IndicatorType type;
	uint8_t adress;

	uint8_t index;
	uint32_t timer;
} DL_Indicator;  //Структура с данными индикатора

void DL_indInit(DL_Indicator* ind, I2C_HandleTypeDef* i2c, DL_IndicatorType type, uint8_t adress);  //Функция инициализации индикатора

void DL_indClkStart(DL_Indicator* ind);  //Запустить тактирование микросхемы HT16K33
void DL_indClkStop(DL_Indicator* ind);  //Остановить тактирование микросхемы HT16K33

void DL_indDisplayON(DL_Indicator* ind);  //Включить отображение на индикаторе
void DL_indDisplayOFF(DL_Indicator* ind);  //Выключить отображение на индикаторе

void DL_indSetBrightness(DL_Indicator* ind, uint8_t duty);  //Установить яркость отображения 0...100%

void DL_indBlinkingStart2Hz(DL_Indicator* ind);  //Запуск аппаратного мигания с частотой 2Гц
void DL_indBlinkingStart1Hz(DL_Indicator* ind);  //Запуск аппаратного мигания с частотой 1Гц
void DL_indBlinkingStart05Hz(DL_Indicator* ind);  //Запуск аппаратного мигания с частотой 0.5Гц
void DL_indBlinkingStop(DL_Indicator* ind);  //Остановка аппаратного мигания

void DL_indPrintBitMap(DL_Indicator* ind, uint16_t* vals, uint8_t size);  //Передать данные на индикатор через карту битов
void DL_indClear(DL_Indicator* ind);  //Очистить дисплей

void DL_indPrintStr(DL_Indicator* ind, const char* str, uint8_t pos);  //Написать строку на 7- 14- или 16-сегментном индикаторе, начиная с позиции pos
void DL_indPrintInt(DL_Indicator* ind, int32_t num, uint8_t pos);  //Написать целое число на 7- 14- или 16-сегментном индикаторе, начиная с позиции pos
void DL_indPrintFloat(DL_Indicator* ind, float num, uint8_t precision, uint8_t pos);  //Написать число с плавающей точкой на 7- 14- или 16-сегментном индикаторе, начиная с позиции pos
void DL_indPrintLeftRunningStr(DL_Indicator* ind, const char* str, uint8_t seg_amount, uint32_t step_time);  //Запуск бегущей строки влево
void DL_indPrintRightRunningStr(DL_Indicator* ind, const char* str, uint8_t seg_amount, uint32_t step_time);  //Запуск бегущей строки вправо

void DL_indPrintBars(DL_Indicator* ind, uint8_t* vals, uint8_t size);  //Записать данные для шкальных индикаторов

#endif
