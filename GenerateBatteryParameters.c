#include "GenerateBatteryParameters.h"

void GenerateLinearExpValues(float* RandomData, linerExpParameters LinearExpressionParam, int NumOfValues)
{
  float y;
  int LoopCount = 0;
  int x = 0;
  
  for(LoopCount = 0; LoopCount < NumOfValues; LoopCount++)
  {
    x = LoopCount;
    y = ((LinearExpressionParam.slope*x) + LinearExpressionParam.xIntercept); // y = mx+c
    RandomData[LoopCount] = ROUND_OFF_TO_2_DECIMAL(y);
  }
  
}
