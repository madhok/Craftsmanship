
#ifndef __TEST_HEADER__
#define __TEST_HEADER__

#include <iostream>
#include "OrderEngine.h"
#include <fstream>
#include <string>

bool testValidOrders();
bool testUpdateId();
bool testStateChange();
bool testRefundOrders();
bool  testRefundTime();
bool testCancelOrders();
bool testChargeOrder();
bool testAmountCharged();
void runTests();

#endif