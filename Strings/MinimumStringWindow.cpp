//WRONG

class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int minLength = INT_MAX;
        string foundString = "";
        bool found =false;
        int foundIter = -1;
        map<char,vector<int>> startPositions;
        for(int j =0; j< S.length(); j++)
        {
         startPositions.insert(pair<char,int>(S[j],0);    
        } 
        pair<int,int>startEndpos;
        startEndpos = findTheFirstOccurence(S, T);
        
        foundString = T.substr(startEndpos.fist,startEndpos.second);
        
        for(int i = foundString.second; i < T.length(); i++)
        {
            if(foundString[0] == T[i])
            {
                foundString = foundString.subs(1);
            }
        }
        return foundString;
        
    }
    
    pair<int,int> findTheFirstOccurence(string S, string T)
    {
        string firstSInT;
        int startPointer = 0;
        map<char,int> startPositions;
        for(int j =0; j< S.length(); j++)
        {
         startPositions.insert(pair<char,int>(S[j],0);    
        } 
        
        for(int i = 0; i <T.length(); i++)
        {
            if(startPositions.count(T[i]) > 0)
            {
                if(startPositions.find(T[i])->second == 0)
                {
                    startPositions.find(T[i])->second = 1;
                    firstSInT = firstSInT + T[i];
                }
               else 
               {
                   if(firstSInT[0] == T[i])
                        startPointer++;
               }                
            }
            if(firstSInT.length() == S.length())
                break;
        }
        return pair<startPointer, firstSInT.length()-1);        
    }
};