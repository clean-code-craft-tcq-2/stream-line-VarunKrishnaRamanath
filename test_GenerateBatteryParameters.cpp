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
  char ExpectedOutput[] = {"0.00,  28.00\n0.50,  28.10\n1.00,  28.20\n1.50,  28.30\n2.00,  28.40\n2.50,  28.50\n3.00,  28.60\n3.50,  28.70\n4.00,  28.80\n4.50,  28.90\n"};
  int NumOfValuesToBeGenerated = 10;
  
  GenerateCurrentTemperaturePairToCsv(ToConsoleOutput, NumOfValuesToBeGenerated);
  
  strcmp(ToConsoleOutput, ExpectedOutput);
}
