#include <math.h>

#define ROUND_OFF_TO_2_DECIMAL(Num)   floorf(((Num)*100)/100)
#define SIZE_OF_ARRAY(array)  (sizeof(array)/sizeof(array[0]))

typedef struct{
  int slope;
  int xIntercept;
}linerExpParameters;

void GenerateLinearExpValues(float* RandomData, linerExpParameters LinearExpressionParam, int NumOfValues);
