
/*
 * Returns true if the input string is a number and false otherwise
 */
 
 Test: "-"
 
public boolean isNumber(String toTest)
{
    // implementation here
    if(toTest.length() == 0)
        return false;
    
    int index = 0;
    bool isdecimal = false;
    while(toTest[index])
    {
        if(toTest[index] == '+' || toTest[index] == '-')
        {
            if(index != 0)
                return false;
            if(index == toTest.length()-1)
                return false;        
        }
        else if(toTest[index] == '.')
        {
            if(isdecimal)
                return false;
            else
            {
                isdecimal = true;
            if(index == toTest.length()-1)
                return false;    
            }
        }
        else if(toTest[index] < '0' || toTest[index] > '9' )
            return false;
        index++;
    }    
}





class TwoSum {
public:
    /*
     * Stores input in an internal data structure.
     */
   private:
    map<int,int>hashMap;
    map<int,int>::iterator it;

    public:
    virtual void store(int input) = 0;
 
    /*
     * Returns true if there is any pair of numbers in the internal data structure which
     * have sum test, and false otherwise.
     * For example, if the numbers 1, -2, 3, and 6 had been stored,
     * the method should return true for 4, -1, and 9, but false for 10, 5, and 0
     */
    virtual bool test(int val) = 0;
};

void TwoSum::store(int input)
{
     it = hashMap.find(input);
     if(it == hashMap.end())
     {
         hashMap.insert(make_pair(input, 1));
     }
     else
     {
         it->second++;
     }
}

bool TwoSum::test(int val)
{
    for(it = hashMap.begin(); it != hashMap.end(); it++)
    {
        int reqValue;
        reqValue = val - (it->first);
        map<int,int>::iterator reqIt
        if(reqIt = hashMap.find(reqValue))
        {
            if(reqvalue == val)
            {
                if(reqIt->second > 1)
                    return true;
            }
            else
                return true;
        }
    }
    return false;
}

void TwoSum::storeNew(int input)
{
     
     map<int,int>::iterator itNew;
     
     for(itNew = hashMap.begin(); itNew!= hashMap.end(); itNew++)
     {
        hashMap.insert(make_pair(input + itNew->first,1));
     }
}

bool TwoSum::testNew(int val)
{
    it = hashMap.find(val);
    if(it == hashMap.end())
        return false;
    return true;    
}