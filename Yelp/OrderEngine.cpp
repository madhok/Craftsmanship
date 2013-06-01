#include "OrderEngine.h"

bool OrderEngine::processOrderUpdate(string input)
{
	OrderUpdate update;
	if(constructUpdate(input,update))
	{
		it = Orders.find(update.orderId); //get the order corresponding to the update
		if(it == Orders.end())
		{
			
			if (update.state == STATE_NEW && (update.amount > 0))
			{
			
				Order newOrder(update.orderId);
				newOrder.setUpdateId(update.updateId);
				
				if(update.amount != -1)
					newOrder.setAmount(update.amount);
				if(update.cookTime != -1)
					newOrder.setCookTime(update.cookTime);

				Orders.insert(make_pair(update.orderId,newOrder));
			}
			else
			{
				ErrorLog << "ERROR: Cannot create the order : " << update.orderId << endl;
				return false;
			}
		}
		else
		{
			if(it->second.getUpdateId() < update.updateId)
			{
				string err;
				if(it->second.setState(update.state,err))
				{
					if(update.cookTime != -1)
						it->second.setCookTime(update.cookTime);
				}
				else 
				{
					ErrorLog << "ERROR: Failed to update state of order id: " << update.orderId << " and updateId: " << update.updateId << endl; 
					ErrorLog << err << endl;;
					return false;
				}	
				it->second.setUpdateId(update.updateId);
			}
			else
			{
				return false;
			}
		}
	}
	return true;
	
}

bool OrderEngine::constructUpdate(string input,OrderUpdate &newUpdate)
{
	char * cstr = new char [input.length()+1];
	std::strcpy (cstr, input.c_str());
	json_t *json;
    json_error_t error;
	json = json_loads(cstr, 0, &error);
		if(json ==NULL)
		{
			ErrorLog << "Error: Unable to read the file as json." << endl;
			return false;
		}
	const char *state;
	
	int suc = json_unpack(json, "{s:i, s:s, s:i}", "orderId", &newUpdate.orderId , "status", &state, "updateId", &newUpdate.updateId);
	if(suc == -1)
	{
		ErrorLog << "Error: Update \"" << input << "\"" << "Does not contain required parameters" << endl; 
		return false;
	}
	newUpdate.state = newUpdate.getStateValue(string(state));

    int amount;		
    suc = json_unpack(json, "{s:i}", "amount", &amount);
   	if(suc == 0)
	{
		newUpdate.amount = amount;
	}

	int cookTime;
	suc = json_unpack(json, "{s:i}", "cookTime", &cookTime);
	if(suc == 0)
	{
		newUpdate.cookTime = cookTime;
	}

	return true;
}

int OrderEngine::getTotalAmount()
{
	for(it = Orders.begin(); it != Orders.end(); it++)
    {
    	Order ord = it->second; 
    	if(ord.getCurrentState() == STATE_COOKING)
    	{
    		totalAmountCharged += ord.getAmount();
    	}	
		if(ord.getCurrentState() == STATE_DELIVERING)
		{
			totalAmountCharged += ord.getAmount();
		}
		if(ord.getCurrentState() == STATE_DELIVERED)
		{
			totalAmountCharged += ord.getAmount();
		}
	}
	return totalAmountCharged;
}

string OrderEngine::getSummary()
{
	int newStateOrders = 0;
    int cookingStateOrders = 0;
    int deliveringStateOrders = 0;
    int deiveredStateOrders = 0;
    int canceledStateOrders = 0;
    int refundedStateOrders = 0;

    
	for(it = Orders.begin(); it != Orders.end(); it++)
    {
    	Order ord = it->second; 
    	if(ord.getCurrentState() == STATE_NEW)
    		newStateOrders++;
    	if(ord.getCurrentState() == STATE_COOKING)
    	{
    		cookingStateOrders++;
    	}	
		if(ord.getCurrentState() == STATE_DELIVERING)
		{
			deliveringStateOrders++;
		}
		if(ord.getCurrentState() == STATE_DELIVERED)
		{
			deiveredStateOrders++;
		}
		if(ord.getCurrentState() == STATE_REFUNDED)
			refundedStateOrders++;
			
		if(ord.getCurrentState() == STATE_CANCELED)
			canceledStateOrders++;
	}
	
	ostringstream result;
	result << "NEW : " << newStateOrders << endl;
    result << "Cooking: " << cookingStateOrders << endl;
    result << "Delivering: " << deliveringStateOrders << endl;
    result << "Delivered: " << deiveredStateOrders << endl;
    result << "Canceled: " << canceledStateOrders << endl;
    result << "Refunded: " << refundedStateOrders << endl;
    result << "Total amount charged: " << getTotalAmount() << endl;

    return result.str();

}

