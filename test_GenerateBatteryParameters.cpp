#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <string.h>
#include "GenerateBatteryParameters.h"
#include <stdio.h>

TEST_CASE("To test if 10 random values are generated from function GenerateLinearExpValues")
{
  float RandomData[10];
  float ExpectedData[10] = {2, 2.2, 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.6, 3.8}; // with slope = 0.2 and xIntercept = 2
  int NumOfValuesToBeGenerated = SIZE_OF_ARRAY(RandomData);
  linerExpParameters LinearExpressionParam = {0.2, 2.0}; // Slope, xIntercept
  
  //call the FUT
  GenerateLinearExpValues(RandomData, LinearExpressionParam, NumOfValuesToBeGenerated);
  
  REQUIRE(memcmp(RandomData, ExpectedData, sizeof(RandomData)) == 0);
}

TEST_CASE("To check if charging current is generated")
{
  float RandomData[10];
  float ExpectedData[10] = {0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5}; // with slope = 0.5 and xIntercept = 0
  int NumOfValuesToBeGenerated = SIZE_OF_ARRAY(RandomData);
  
  GenerateChargingCurrentValues(RandomData, NumOfValuesToBeGenerated);
  
  REQUIRE(memcmp(RandomData, ExpectedData, sizeof(RandomData)) == 0);
}

TEST_CASE("To check if battery temperature is generated")
{
  float RandomData[10];
  float ExpectedData[10] = {28.0, 28.1, 28.2, 28.3, 28.4, 28.5, 28.6, 28.7, 28.8, 28.9}; // with slope = 0.1 and xIntercept = 28 (deg)
  int NumOfValuesToBeGenerated = SIZE_OF_ARRAY(RandomData);
  
  GenerateBatteryTemperatureValues(RandomData, NumOfValuesToBeGenerated);
  
  REQUIRE(memcmp(RandomData, ExpectedData, sizeof(RandomData)) == 0);
}

TEST_CASE("Finally integrate the generated Charging current and Battery temperature values into CSV format")
{
  char ToConsoleOutput[1000];
  char ExpectedOutput[] = {"0, 28.0\n", "0.5, 28.1\n", "1.0, 28.2\n", "1.5, 28.3\n", "2.0, 28.4\n", "2.5, 28.5\n", "3.0, 28.6\n", "3.5, 28.7\n", "4.0, 28.8\n", "4.5, 28.9\n"};
  int NumOfValuesToBeGenerated = 10;
  
  GenerateCurrentTemperaturePairToCsv(ToConsoleOutput, NumOfValuesToBeGenerated);
  
  strcmp(ToConsoleOutput, ExpectedOutput);
}
