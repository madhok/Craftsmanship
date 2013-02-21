#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class CoinChanger
{
    public:
        vector<int> DispenseChange(double Amount, vector<int>& vDenomination);
        bool test(vector<int> nMinimumNumberOfCoins, int nAmountDispensed, vector<int> vDenominations);
};

vector<int> CoinChanger::DispenseChange(double Amount, vector<int>& vDenominations )
{
    vector<int>nDispensedCoins;
    //Sort the denominations in descending order
    sort(vDenominations.begin(), vDenominations.end());
    reverse(vDenominations.begin(), vDenominations.end());

    int nRemainingamount = round(Amount * 100); //Convert to Cents
   
    for(int i = 0; i < vDenominations.size(); i++)
    {
       nDispensedCoins.push_back(nRemainingamount / vDenominations.at(i));
       nRemainingamount = nRemainingamount % vDenominations.at(i);     
    }
   
    //TEST
    if(!test(nDispensedCoins,round(Amount * 100),vDenominations))
        cout << "*****TEST FAILED*****" << endl;
    else
        cout << endl << "*****TEST PASSED*****" << endl;
    return nDispensedCoins;
}

bool CoinChanger::test(vector<int> nMinimumNumberOfCoins, int nAmountDispensed, vector<int> vDenominations)
{   

    sort(vDenominations.begin(), vDenominations.end());
    reverse(vDenominations.begin(), vDenominations.end()); //Descending order
    //Check if its the minimum number of coins
     for(int i = 1; i < vDenominations.size() - 1; i++)
     {
        if(nMinimumNumberOfCoins.at(i) * vDenominations.at(i)  >= vDenominations.at(i-1))
        {
            return false;            
        }
        
     }
    
 //check if it sums up to the Amount to be Dispensed
     int nSum = 0;     
     for(int i = 0 ; i < vDenominations.size(); i++)
     {
        nSum+= vDenominations.at(i) * nMinimumNumberOfCoins.at(i);
        
     }             
     if (nSum != nAmountDispensed)  
     {
      return false;
     }
     return true;
}

int main()
{
    double nAmount;
    vector<int>vDenominations;
    int size;
    cout << "Enter the amount to be dispensed in dollars" << endl;
    cin >> nAmount;
    
    cout << "Enter the total number of denominations you have" << endl;
    cin >> size;
    vDenominations.resize(size);
    
    cout << "Enter the values of denomination" << endl;
    for (int i=0; i<size; ++i) 
    {
        int input;
        cin >> input;
        vDenominations.at(i) = input;
    }
    CoinChanger objCoinChanger;  
    vector<int>vChange = objCoinChanger.DispenseChange(nAmount, vDenominations);
    
    while(!vChange.empty())
    {
        cout << "Number of " << vDenominations.back() << " coins is " << vChange.back() << endl; 
        vChange.pop_back();
        vDenominations.pop_back();               
    }         
       
return 0;
}
