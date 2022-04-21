#include <string.h>
#include <stdio.h>

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

int main()
{
  float temperature[100],chargeRate[100] = {0};
  readDataFromConsole(temperature,chargeRate);
  return 0; 
}
