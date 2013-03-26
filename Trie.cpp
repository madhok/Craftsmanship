#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Trie_Node
{
    string val;
    vector<Trie_Node> adjacentNodes;
    Trie_Node(string str)
    {
        val = str;
    }
}

class TrieClass
{
    vector<Trie_Node> Trie;
     
    void Build_Trie(vector<Trie_Node> newTrie,string str)
    {
        int strlen = str.length();   
        if(strlen == 0)
            return;        
        newTrie.push(new Trie(str[0]));             
        for(int i = 1; i < strlen; i++)
        {
            newTrie[i-1].adjancentNodes[i-1].push(new Trie_Node(str[i]));            
        }
    }
    
    void AddString(string str)
    {
        vector<int> Indexs;            
        GetStringPositon(Trie,str,Indexs,0);
        vector<Trie_Node> InsertTrie = Trie;
        int i = 0;
        while(i < Indexs.size())
        {
            InsertTrie = InsertTrie[Indexs[i]].adjacentNodes[Indexs[++i]];
        }
        Build_Trie(InsertTrie, str);
    }
    
    void GetStringPosition(Trie FoundTrie, string str, vector<int>& Indexs, int& position)
    {
        for(int i = 0; i < FoundTrie.size(); i++)
        {
            if(FoundTrie[i].val == str[position])
            {
                Indexs.push(i);
                position++;
                GetStringPosition(FoundTrie[i].adjacentNodes,str, Indexs, position);                
            }            
        }        
    }    
};

