/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/

class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(a.begin(), a.end());
        reverse(b.begin(),b.end());
        int ia = 0;
        int ib = 0;
        char carry = '0';
        vector<char> result;
        while(ia < a.size() && ib < b.size())
        {
            if(a[ia] == '1' && b[ib] == '1')
            {
                if(carry == '1')
                    result.push_back('1');
                else
                    result.push_back('0');
                carry = '1';    
            }
            else if((a[ia] == '0' && b[ib] == '1') ||
                    a[ia] == '1' && b[ib] == '0')
            {
                if(carry == '1')
                {
                    result.push_back('0');
                    carry = '1';   
                }
                else
                {
                    result.push_back('1');
                    carry = '0';
                }
            }
            else
            {
                result.push_back(carry);
                carry = '0';
            }
            ia++;
            ib++;
        }
        
        while(ia < a.size())
        {
            if(a[ia] == '1')
            {
                if(carry == '1')
                {
                    result.push_back('0');
                    carry = '1';  
                }
                else
                {
                    result.push_back('1');
                    carry = '0';
                } 
            }
            else
            {
                result.push_back(carry);
                carry = '0';
            }
            ia++;
        }
        while(ib < b.size())
        {
            if(b[ib] == '1')
            {
                if(carry == '1')
                {
                    result.push_back('0');
                    carry = '1';  
                }
                else
                {
                    result.push_back('1');
                    carry = '0';
                } 
            }
            else
            {
                result.push_back(carry);
                carry = '0';
            }
            ib++;
        }
        if(carry == '1')
            result.push_back(carry);
        
        string sr;
        for(int i = 0; i < result.size(); i++)
        {
            sr +=result[i];
        }
        reverse(sr.begin(), sr.end());
        
        
        return sr;
    }
};