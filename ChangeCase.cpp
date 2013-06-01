#include <iostream>
#include <vector>

using namespace std;

char invertCase(char c)
{
    return islower(c)? toupper(c): tolower(c);
}

bool isAlphabet(char c)
{
    if((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
        return true;
     return false;   
}

vector<string> listAllStrings(string input)
{
    vector<string> result;
    result.push_back(input);
    
    for(int i = 0; i < input.length(); i++)
    {
        if(isAlphabet(input[i]))
        {
            string original = input;
            original[i] = invertCase(original[i]);
            result.push_back(original);
            for(int j = 0; j < i; j++)
            {
                if(isAlphabet(input[j]))
                {
                    original[j] = invertCase(original[j]);
                    result.push_back(original);
                }
            }
        }
    }
    return result;
}

int main()
{
    string input = "c90hara98_cter";
    vector<string> output = listAllStrings(input); 
    for(int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}