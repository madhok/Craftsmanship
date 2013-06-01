#ifndef __ORDER_ENGINE_HEADER__
#define __ORDER_ENGINE_HEADER__


#include <iostream>
#include <map>
#include "Order.h"
#include <jansson.h>
#include <sstream>

using namespace std;

class OrderEngine
{
private:
	int totalAmountCharged;
	bool constructUpdate(string input,OrderUpdate &newUpdate);
	map<int, Order> Orders;
	map<int, Order>::iterator it;

public:
	
	int getTotalAmount();
	bool processOrderUpdate(string line);
	string getSummary();
	ostringstream ErrorLog;
	
	OrderEngine()
	{
		ErrorLog.str() = "";
		totalAmountCharged = 0;
	}
	
	void testRefund() // Function used only for testing the refund time
	{
		int orderId = 2;
		double refundTime = 1.0;
		Orders.find(orderId)->second.setRefundTime(refundTime);
	}
	

};

#endif

