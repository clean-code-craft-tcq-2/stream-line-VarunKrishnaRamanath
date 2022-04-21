#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <string.h>
#include <stdio.h>

TEST_CASE("Test for Receiever to read from console") 
{
  float temp[50], chargeRate[50]  = {0};
  receiveDataFromConsole(temp,chargeRate);                                                              
  float expectedTempValue[50] = {28.0, 28.1, 28.2, 28.3};
  float expectedChargeRate[50] = {0.0, 0.50, 1.0, 1.5};
  for(int i =0; i< 4; i++){
  REQUIRE( (temp[i] - expectedTempValue[i]) <= 0.001);
  REQUIRE( (chargeRate[i] - expectedChargeRate[i]) <= 0.001);
  }
}
