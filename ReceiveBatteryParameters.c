#include <string.h>
#include <stdio.h>
#include "ReceiveBatteryParameters.h"

void receiveDataFromConsole(float* temperature, float* chargeRate);
void printMinMaxValuesInStream(float* temperature, float* chargeRate);

void printMinMaxValuesInStream(float* temperature, float* chargeRate) {
    float minTemp=0, maxTemp=0, minChargeRate=0, maxChargeRate=0;
    for (int j = 0; j < 50 ; j++)
    {
        if(temperature[j] < minTemp) {
            minTemp = temperature[j];
        } else if(temperature[j]> maxTemp) {
            maxTemp = temperature[j];
        }

        if(chargeRate[j] < minChargeRate) {
            minChargeRate = chargeRate[j];
        } else if(chargeRate[j] > maxChargeRate) {
            maxChargeRate = chargeRate[j];
        }
    }
    printf("Minimum Temperature in the stream: %f Maximum Temperature in the stream: %f Minimum Charge Rate in the stream: %f Maximum Charge Rate in the stream: %f\n", minTemp, maxTemp, minChargeRate, maxChargeRate);
}

void receiveDataFromConsole(float* temperature, float* chargeRate) {
    char unusedData[300];
    for(int j = 0; j < 50; j++){ 
        scanf("%f", &temperature[j]);     
        scanf("%50s", unusedData);
        scanf("%f", &chargeRate[j]);
        //printf("%.2f \t %.2f\n",temperature[j],chargeRate[j]);
    }
    /*for(int j = 0; j < 50; j++)
    {
        printf("%.2f \t %.2f\n",temperature[j],chargeRate[j]);
    }*/
   
}
