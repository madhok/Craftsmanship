

/* 
Your previous Java content is preserved below:

import java.io.*;
import java.util.*;

/*
 * To execute Java, please define "static void main" on a class
 * named Solution.
 *
 * If you need more classes, simply define them inline.
 */

// given a company, start with ceo, employee1 and 2, find the common manager of 1 and 2 //which is at the lowest level to 1 and 2.

/*    ceo
  vp1   vp2 ... vpn 
 d1 d2
 m1  m2
  e1  e2   
*/

#include <iostream>
using namespace std;

#define MAXN 10000

vector<int> tree[MAXN]
int path[3][MAXN];

struct employee {
    int id;
    vector<employee> child;
    employee(int val) :id(val) {}
}

void addEdge(int a, int b) {
    tree[a].push_back(b);
    tree[b].push_back(a);
}


void LCA(employee e, int a, int b) {
    if(a== b) return a;
    path[1][0] = path[2][0] = 1;
    
    bool flag = false;
    dfs(1,0,1,a,flag,e);
    
    flag = false;
    dfs(1,0,2,b,flag,e);
    
    int i = 0;
    while(path[1][i] == path[2][i])
        ++i;
    
    
    return path[1][i-1];
    
}

void dfs(int cur, int prev, int pathNumber, int node, bool& flag, employee p) {
    
    for(int i = 0; i< tree[cur].size();++i) {
        if(tree[cur][i] != prev && !flag) {
            path[pathNumber][path.size()] = tree[cur][i];
            if(tree[cur][i] == node) {
                flag = true;
                //path[pathNumber][path.] = -1;
                return;
            }
            for(i)
            dfs(tree[cur][i], cur, pathNumber, node, flag, p.child[i]);
        }
}


// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  return 0;
}
