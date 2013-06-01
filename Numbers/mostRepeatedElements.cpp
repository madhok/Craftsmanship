//1, 1, 1, 2, 2, 3, 4
#include <iostream>
#include <vector>
#include <map>

using namespace std;


int mostRepeatedElement(map<int,int> &hashmap)
{
    map<int,int>::iterator iter;
    iter= hashmap.begin();
    int MostRepeatedElement = iter->first;
    int countVal = iter->second;
    for(; iter!=hashmap.end(); iter++)
    {
        if(countVal < iter->second)
        {
            MostRepeatedElement= iter->first;    
            countVal = iter->second;
        }
    }
    hashmap.find(MostRepeatedElement)->second = 0;
    return MostRepeatedElement;
}


vector<int> checkMaxNumber(vector<int> head, int k)  //k is the total numbers to be returned
{
    vector<int>mostRepeatedNumber;
    if(head.size() == 0 || k == 0)
        return mostRepeatedNumber;            
     
    map<int, int> hashmap;
    map<int,int>::iterator iter; 
    for(int i = 0; i< head.size(); i++)
    {
        iter = hashmap.find(head[i]);
        if(iter == hashmap.end())
            hashmap.insert(make_pair(head[i], 1));
        else
        {
            iter->second++;
        }   
    } 
    
    for(int i = 0; i < k; i++)
    {
        mostRepeatedNumber.push_back(mostRepeatedElement(hashmap));
    }
    return mostRepeatedNumber;
}

int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(1);
    input.push_back(2);
    input.push_back(2);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);

    std::vector<int> output;
    output = checkMaxNumber(input, 3);
    for(int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
}