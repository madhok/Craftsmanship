#include "Order.h"

bool Order::setState(STATE state,string &Errorlog)
{
	bool success = false;
	switch(state)
	{
		case STATE_NEW:
			currentState = state;
		break;
		case STATE_COOKING:
			if(currentState == STATE_NEW && (amount > 0))
			{
				currentState = state;
				success = true;
			}
			else
			{
				Errorlog  = "Error: Cannot change state to COOKING. Amount is not specified. " ;
			}
		break;	

		case STATE_DELIVERING:
			if(currentState == STATE_COOKING)
			{
				currentState = state;
				success = true;
			}
			else
			{
				Errorlog = "Error: Order cannot set to DELIVERING. ";
			}	
		break;

		case STATE_DELIVERED:
			if(currentState == STATE_DELIVERING)
			{
				currentState = state;
				deliveredTime = time(0);
				success = true;
			}
			else
			{
				Errorlog = "Error: Order cannot set to DELIVERED." ;
			}
		break;

		case STATE_REFUNDED:
			if(currentState == STATE_DELIVERED)
			{
				if(difftime(deliveredTime,orderTime) > refundTime)
				{
					currentState = STATE_REFUNDED;
					success = true;
				}	
			}
			else
			{
				Errorlog = "Error: Order cannot be Refunded." ;
			}
		break;

		case STATE_CANCELED:
			success = cancelOrder();
			if(!success)
				Errorlog = "Error: Order cannot set to CANCELED." ;
	
		break;


		case STATE_ERROR:
			//cout << "Error: Cannot identify the state " << endl;
		break;
	}
	return success;
}

bool Order::cancelOrder()
{
	if(currentState != STATE_DELIVERED  && currentState != STATE_REFUNDED)
	{
		currentState = STATE_CANCELED;
		return true;
	}
	return false;
}

void Order::setAmount(int _amount)
{
	amount = _amount;
}

int Order::getAmount()
{
	return amount;
}

STATE Order::getCurrentState()
{
	return currentState;
} 