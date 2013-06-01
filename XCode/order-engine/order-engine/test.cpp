

#include "test.h"
#define TESTING 1

bool testValidOrders()
{
	OrderEngine orderEngine;
	//All valid orders will begin in the NEW state.
    string input = "{\"orderId\": 1, \"status\": \"COOKING\", \"updateId\": 2, \"amount\": 40}";
    if(orderEngine.processOrderUpdate(input) == true)
    {
    	cout << "Test failed: All valid orders should begin in the NEW state" << endl; 
    	return false;
    }	
    return true;
}

bool testUpdateId()
{
    //Update id for an order should be always in increasing order
	OrderEngine orderEngine;
	string input = "{\"orderId\": 1, \"status\": \"NEW\", \"updateId\": 1, \"amount\": 40}";
    orderEngine.processOrderUpdate(input);
    input = "{\"orderId\": 1, \"status\": \"COOKING\", \"updateId\": 1, \"amount\": 40}";
    
    if(orderEngine.processOrderUpdate(input) == true)
    {
    	cout << "Test failed: Update id for an order should be always in increasing order" << endl; 
    	return false;
    }
    return true;
}

bool testStateChange()
{
	OrderEngine orderEngine;
	//Testing state transitions
    string input = "{\"orderId\": 1, \"status\": \"NEW\", \"updateId\": 1, \"amount\": 40}";
    if(orderEngine.processOrderUpdate(input) == false)
    {
    	cout << "Test failed: Create New order " << endl; 
    	return false;
    }	

    input = "{\"orderId\": 1, \"status\": \"COOKING\", \"updateId\": 2, \"amount\": 40}";
    if(orderEngine.processOrderUpdate(input) == false)
    {
    	cout << "Test failed: State change from NEW to COOKING" << endl;
    	return false;
    }
    
    input = "{\"orderId\": 1, \"status\": \"DELIVERING\", \"updateId\": 3, \"amount\": 40}";
    if(orderEngine.processOrderUpdate(input) == false)
    {
    	cout << "Test failed: State change from COOKING to DELIVERING" << endl;
    	return false;
    }

    input = "{\"orderId\": 1, \"status\": \"DELIVERED\", \"updateId\": 4, \"amount\": 40}";
    if(orderEngine.processOrderUpdate(input) == false)
    {
    	cout << "Test failed: State change from DELIVERING to DELIVERED" << endl;
    	return false;
    }
    return true;
}

bool testRefundOrders()
{
	OrderEngine orderEngine;
	string input = "{\"orderId\": 1, \"status\": \"NEW\", \"updateId\": 1, \"amount\": 40}";
    orderEngine.processOrderUpdate(input);
    
    input = "{\"orderId\": 1, \"status\": \"REFUNDED\", \"updateId\": 2}";
    if(orderEngine.processOrderUpdate(input) == true)
    {
    	cout << "Test failed: Can REFUND only from DELIVERED state" << endl; 
    	return false;
    }
    

    return true;
}

bool  testRefundTime()
{
	OrderEngine orderEngine;

	string input = "{\"orderId\": 2, \"status\": \"NEW\", \"updateId\": 1, \"amount\": 40}";
    orderEngine.processOrderUpdate(input);
   
    input = "{\"orderId\": 2, \"status\": \"COOKING\", \"updateId\": 2}";
    orderEngine.processOrderUpdate(input);
    
    input = "{\"orderId\": 2, \"status\": \"DELIVERING\", \"updateId\": 3}";
    orderEngine.processOrderUpdate(input);

   // std::sleep(2);// Setting the time taken for delivery to exceed refund time

    input = "{\"orderId\": 2, \"status\": \"DELIVERED\", \"updateId\": 4}";
    orderEngine.processOrderUpdate(input);

    
    input = "{\"orderId\": 2, \"status\": \"REFUNDED\", \"updateId\": 5}"; 
    //This is test function for refund Time. 
    orderEngine.testRefund();
    if(orderEngine.processOrderUpdate(input) == false)
    {
        cout << "Test failed: REFUND after DELIVERED state" << endl; 
        return false;
    }   


   return true;
}

bool testCancelNewOrders()
{
    OrderEngine orderEngine;
    string input = "{\"orderId\": 3, \"status\": \"NEW\", \"updateId\": 1, \"amount\": 40}";
    orderEngine.processOrderUpdate(input);
    
    input = "{\"orderId\": 3, \"status\": \"CANCELED\", \"updateId\": 2}";
    if(orderEngine.processOrderUpdate(input) == false)
    {
        cout << "Test failed: New order can be canceled " << endl; 
        return false;
    }
    return true;
}

bool testCancelCookingOrders()
{
    OrderEngine orderEngine;
    string input = "{\"orderId\": 4, \"status\": \"NEW\", \"updateId\": 1, \"amount\": 40}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"COOKING\", \"updateId\": 2}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"CANCELED\", \"updateId\": 3}";
    if(orderEngine.processOrderUpdate(input) == false)
    {
        cout << "Test failed: Cooking order can be canceled " << endl; 
        return false;
    }
    return true;
}

bool testCancelDeliveringOrders()
{
   OrderEngine orderEngine;
    string input = "{\"orderId\": 4, \"status\": \"NEW\", \"updateId\": 1, \"amount\": 40}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"COOKING\", \"updateId\": 2}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"DELIVERING\", \"updateId\": 3}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"CANCELED\", \"updateId\": 4}";
    if(orderEngine.processOrderUpdate(input) == false)
    {
        cout << "Test failed: Delivering order can be canceled " << endl; 
        return false;
    }
    return true; 
}

bool testCancelDeliveredOrders()
{
    OrderEngine orderEngine;
    string input = "{\"orderId\": 4, \"status\": \"NEW\", \"updateId\": 1, \"amount\": 40}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"COOKING\", \"updateId\": 2}";
    orderEngine.processOrderUpdate(input);
    
    input = "{\"orderId\": 4, \"status\": \"DELIVERING\", \"updateId\": 3}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"DELIVERED\", \"updateId\": 4}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"CANCELED\", \"updateId\": 5}";
    if(orderEngine.processOrderUpdate(input) == true)
    {
        cout << "Test failed: Delivered order cannot be canceled" << endl; 
        return false;
    }
}

bool testCancelRefundOrders()
{
    OrderEngine orderEngine;
    string input = "{\"orderId\": 4, \"status\": \"NEW\", \"updateId\": 1, \"amount\": 40}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"COOKING\", \"updateId\": 2}";
    orderEngine.processOrderUpdate(input);
    
    input = "{\"orderId\": 4, \"status\": \"DELIVERING\", \"updateId\": 3}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"DELIVERED\", \"updateId\": 4}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"REFUNDED\", \"updateId\": 5}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 4, \"status\": \"CANCELED\", \"updateId\": 6}";
    if(orderEngine.processOrderUpdate(input) == true)
    {
        cout << "Test failed: Refunded Order cannot be canceled" << endl; 
        return false;
    }
    return true;
}

bool testCancelOrders()
{
	return(testCancelNewOrders() && testCancelCookingOrders() &&
        testCancelDeliveringOrders() && testCancelDeliveredOrders() &&
        testCancelRefundOrders());
    
}

bool testChargeOrder()
{
	OrderEngine orderEngine;
	string input = "{\"orderId\": 3, \"status\": \"NEW\", \"updateId\": 1}";
    orderEngine.processOrderUpdate(input);

    input = "{\"orderId\": 3, \"status\": \"COOKING\", \"updateId\": 2}";
    if(orderEngine.processOrderUpdate(input) == true)
    {
    	cout << "Test failed: Order can move to cooking with no amount charged" << endl;
    	return false;
    }
    return true;
}

bool testAmountCharged()
{
	OrderEngine orderEngine;
	string input =	"{\"orderId\": 100, \"status\": \"NEW\", \"updateId\": 287, \"amount\": 20}";
	orderEngine.processOrderUpdate(input);
	
	input =	"{\"orderId\": 100, \"status\": \"COOKING\", \"updateId\": 289, \"cookTime\": 7}";
	orderEngine.processOrderUpdate(input);

	input =	"{\"orderId\": 100, \"status\": \"COOKING\", \"updateId\": 289, \"cookTime\": 7}";
	orderEngine.processOrderUpdate(input);
	
	input =	"{\"orderId\": 101, \"status\": \"NEW\", \"updateId\": 289, \"amount\": 13}";
	orderEngine.processOrderUpdate(input);
	
	input =	"{\"orderId\": 100, \"status\": \"DELIVERING\", \"updateId\": 294}";
	orderEngine.processOrderUpdate(input);

	input =	"{\"orderId\": 102, \"status\": \"NEW\", \"updateId\": 291, \"amount\": 17}";
	orderEngine.processOrderUpdate(input);

	input =	"{\"orderId\": 101, \"status\": \"CANCELED\", \"updateId\": 290}";
	orderEngine.processOrderUpdate(input);

	if(orderEngine.getTotalAmount() != 20)
    {
        cout << orderEngine.getTotalAmount();
        cout << "Test failed: Testing total amount" << endl;
        return false;
    }
		
	return true;
}

void runTests()
{
	if(testValidOrders() &&  testUpdateId() && testStateChange() &&
	   testRefundOrders() && testRefundTime() && testCancelOrders() && 
       testChargeOrder() && testAmountCharged())
        {
            cout << "ALL TESTS PASSED" << endl;    
        }   

}














