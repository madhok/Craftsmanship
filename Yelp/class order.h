#include <iostream>
#include <ctime>

using namespace srd;

double REFUND_TIME  = 300 * 24 * 60 * 60;
enum STATUS
{
	NEW,
	COOKING,
	DELIVERING,
	DELIVERED,
	REFUNDED,
	CANCELED
};

class order
{
private:
	int amount;
	int orderId;
	STATUS currentState;
	int updatedId;	
	time_t orderTime;
	time_t deliveredTime;
public:
	static int count = 0; 
	static int TotalAmountCharged = 0;

	order()
	{
		count++;
		this.orderId = count;
		currentState = STATUS.NEW;
		orderTime = time(0);
	}

	void changeState()
	{
		switch (currentState)
		{
			case STATUS.NEW:
				if(amount > 0)
					currentState = STATUS.COOKING
				break;

			case STATUS.COOKING:
				currentState = STATUS.DELIVERING
				break;	

			case STATUS.DELIVERING:
				currentState = STATUS.DELIVERED
				break;

			case STATUS.DELIVERED:
				double elapsedSeconds = difftime(deliveredTime,time(0)) 
				if(elapsedSeconds < REFUND_TIME)
					currentState = STATUS.REFUNDED;
				else
					cout << "Order cannot be refunded" << endl;
				break;
				
			default:
				break;
		}
	}

	bool cancelOrder()
	{
		if(currentState != STATUS.DELIVERED || currentState != STATUS.CANCELED)
		{
			currentState = STATUS.CANCELED;
		}
		else
		{
			cout << "Order cannot be cancelled" << endl;
		}
	}

	void setAmount(int amount)
	{
		this.amount = amount;
	}

	int getAmount()
	{
		return amount;
	}

	STATUS getCurrentState()
	{
		return currentState;
	} 
}