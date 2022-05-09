#include <string.h>
#include <stdio.h>
#include "ReceiveBatteryParameters.h"

int main()
{
  float temperature[100],chargeRate[100] = {0};
  receiveDataFromConsole(temperature,chargeRate);
  return 0; 
}
