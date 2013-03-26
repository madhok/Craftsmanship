//
//  Trie.cpp
//  Trees
//
//  Created by Madhok Shivaratre on 3/21/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#include "Trie.h"
void TrieClass::Build_Trie(vector<Trie_Node> newTrie,string str)
{
  
    newTrie.push_back(Trie_Node(' '));
    newTrie = newTrie[0].adjacentNodes;
    if(str.length() == 0)
        return;
    
    newTrie.push_back(Trie_Node(str[0]));
    for(int i = 1; i < str.length(); i++)
    {
        newTrie.at(i-1).adjacentNodes.push_back(Trie_Node(str[i]));
    }
}
    
void TrieClass::AddString(string str)
{
    vector<int> Indexs;
    int startPosition = 0;
    GetStringPosition(Trie,str,Indexs,startPosition);
    vector<Trie_Node> InsertTrie = Trie;
    int i = 0;
    while(i < Indexs.size())
    {
        InsertTrie = InsertTrie[Indexs[i++]].adjacentNodes;
    }
    Build_Trie(InsertTrie, str);
}
    
void TrieClass::GetStringPosition(vector<Trie_Node> FoundTrie, string str, vector<int>& Indexs, int& position)
{
    for(int i = 0; i < FoundTrie.size(); i++)
    {
        if(FoundTrie[i].node.val == str[position])
        {
            Indexs.push_back(i);
            position++;
            GetStringPosition(FoundTrie[i].adjacentNodes,str, Indexs, position);
        }
    }
}


