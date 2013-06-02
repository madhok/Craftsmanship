//
//  main.cpp
//  RangeOverlap
//
//  Created by Madhok Shivaratre on 4/3/13.
//  Copyright (c) 2013 Madhok Shivaratre. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

pair<int,int> findOverlapRange(vector<pair<int,int>>pairs)
{
    std::pair<int,int> result;
    vector<int> start;
    vector<int> end;
    for(int i =0; i<pairs.size(); i++)
    {
        start.push_back(pairs[i].first);
        end.push_back(pairs[i].second);
    }
    
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    
    if(start[start.size()-1] < end[0])
    {
        result = make_pair(start[start.size()-1],end[0]);
    }
    return result;
}
int main(int argc, const char * argv[])
{
    vector<pair<int,int>> input;
    input.push_back(make_pair(7,9));
    input.push_back(make_pair(2,10));
    input.push_back(make_pair(5,9));
    input.push_back(make_pair(4,8));
    input.push_back(make_pair(7,17));
    cout << findOverlapRange(input).first  << endl;
    cout << findOverlapRange(input).second  << endl;
    
    return 0;
}
