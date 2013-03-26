//
//  Trie.h
//  Trees
//
//  Created by Madhok Shivaratre on 3/21/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#ifndef __Trees__Trie__
#define __Trees__Trie__

#include <iostream>
#include <map>
#include <vector>

using namespace std;
struct Node
{
    char val;
};

 class Trie_Node
{
public:
    Node node;
    vector<Trie_Node> adjacentNodes;
    Trie_Node(char str)
    {
        node.val = str;
    }
};

class TrieClass
{
    vector<Trie_Node> Trie;
    
    void Build_Trie(vector<Trie_Node> newTrie,string str);
    void AddString(string str);
    void GetStringPosition(vector<Trie_Node> FoundTrie, string str, vector<int>& Indexs, int& position);
};

#endif /* defined(__Trees__Trie__) */
