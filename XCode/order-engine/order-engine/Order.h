#ifndef __ORDER_HEADER__
#define __ORDER_HEADER__


#include <iostream>
#include <ctime>
#include <map>

using namespace std;

enum STATE
{
	STATE_NEW,
	STATE_COOKING,
	STATE_DELIVERING,
	STATE_DELIVERED,
	STATE_REFUNDED,
	STATE_CANCELED,
	STATE_ERROR,
};

struct OrderUpdate
{
	int orderId;
	int updateId;
	int amount;
	int cookTime;
	double refundTime;
	STATE state;

	OrderUpdate()
	{
		amount = -1;
		cookTime = -1;	
		refundTime = 0.0;
	}

	STATE getStateValue(string state)
	{
		if(state == "NEW")
			return STATE_NEW;
		if(state == "COOKING")
			return STATE_COOKING;
		if(state == "DELIVERING")
			return STATE_DELIVERING;
		if(state == "DELIVERED")
			return STATE_DELIVERED;
		if(state == "REFUNDED")
			return STATE_REFUNDED;
		if(state == "CANCELED")
			return STATE_CANCELED;
		return STATE_ERROR;
	}
};

class Order
{
private:
	int amount;
	int orderId;
	STATE currentState;
	int cookTime;
	time_t orderTime;
	time_t deliveredTime;
	double refundTime;
	int lastUpdateId;

public:
	Order(int id)
	{
		lastUpdateId = 0;
		orderId = id;
		currentState = STATE_NEW;
		orderTime = time(0);
		refundTime  = 300 * 24 * 60 * 60;//300 days
		amount = -1;
	}

	bool cancelOrder();
	void setAmount(int amount);
	int getAmount();
	STATE getCurrentState();
	bool setState(STATE state,string &Errorlog);
	int getCookTime()
	{
		return cookTime;
	}
	void setCookTime(int time)
	{
		cookTime = time;
	}
	int getUpdateId()
	{
		return lastUpdateId;
	}
	void setUpdateId(int updateId)
	{
		lastUpdateId = updateId;
	}
	void setRefundTime(double time)
	{
		refundTime = time;
	}
};

#endif
