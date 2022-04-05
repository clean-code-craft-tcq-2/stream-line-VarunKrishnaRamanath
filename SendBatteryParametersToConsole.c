#include "GenerateBatteryParameters.h"

int main()
{
 char ToConsole[2000];
 int NumOfValuesToBeGenerated = 50;
 
 GenerateCurrentTemperaturePairToCsv(ToConsole, NumOfValuesToBeGenerated);
 printf("%s",ToConsole);
 return 0; 
}
