#include "stm8s.h"
#include "thermo.h"

//#define ARR_SIZE 
#pragma optimize=none
int16_t Convert(int16_t adc_code, int16_t tcj) 
{
uint8_t x;
uint16_t Vread = Code2uV(adc_code);

for (x = 0; x < NELEMS(vArray) - 2; x+=2)
{
 if (Vread >=vArray[x] && Vread <= vArray[x+2]) 
 {
   return vArray[x+1] + (int16_t)((int32_t)(vArray[x+3] - vArray[x+1]) * (int32_t)(Vread - vArray[x]) / (int32_t)(vArray[x+2] - vArray[x]));  
 }
}
return 777;
}

//Calculate microvolts from OPAMP
#pragma optimize=none
int16_t Code2uV(int16_t adccode)
{
  //5350 - ����������� ��������� 535.0
  //1023 - ����������� ����������� ���
  //510000000 - ������� ���������� ��� 5 �����
  return (((uint32_t)adccode)*((5100000UL/1023UL)/OPAMP_GAIN));///1000;
}


//Calculate input voltage from OPAMP
#pragma optimize=none
int16_t Code2R(int16_t adccode)
{
  //5350 - ����������� ��������� 535.0
  //1023 - ����������� ����������� ���
  //510000000 - ������� ���������� ��� 5 �����
  return adccode;
}