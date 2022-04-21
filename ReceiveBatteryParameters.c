#include <string.h>
#include <stdio.h>
#include "ReceiveBatteryParameters.h"

void receiveDataFromConsole(float* temperature, float* chargeRate);

void receiveDataFromConsole(float* temperature, float* chargeRate) {
    char unusedData[300];
    for(int j = 0; j < 50; j++){
        if(scanf("%50s", unusedData) == EOF) 
        {
            break;
        } 
        scanf("%f", &temperature[j]);     
        scanf("%50s", unusedData);
        scanf("%50s", unusedData);
        scanf("%50s", unusedData);
        scanf("%f", &chargeRate[j]);
        printf("%.2f \t %.2f\n",temperature[j],chargeRate[j]);
    }
   
}
