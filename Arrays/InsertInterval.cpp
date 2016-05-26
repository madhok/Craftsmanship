/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].


*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
        if(intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<Interval> result;
        bool added = false;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(newInterval.start < intervals[i].start &&
                    newInterval.end < intervals[i].start)
            {
                 result.push_back(newInterval);
                 added = true;
                 result.push_back(intervals[i]);
            }
            else if(intervals[i].end < newInterval.start)
            {
                result.push_back(intervals[i]);
            }
            else
            {
                added = true;
               int start = min(intervals[i].start, newInterval.start);
               int end = max(intervals[i].end, newInterval.end);
               Interval in(start, end);
                result.push_back(in);
                i++;
                while(i < intervals.size())
                {
                    result.push_back(intervals[i]);
                    i++;
                }
            }
        }
        
        if(!added)
            result.push_back(newInterval);
        
        result = merge(result);
        
        return result;
        
    }
    
    vector<Interval> merge(vector<Interval>intervals)
    {
        vector<Interval> result;
        int size = intervals.size();
        
        result.push_back(intervals[0]);
        for(int i = 1; i < size; i++)
        {
            int resultprev = result.size() -1;
            if(result[resultprev].end >= intervals[i].start)
            {
                
                int start = min(result[resultprev].start, intervals[i].start);
                int end = max(result[resultprev].end, intervals[i].end);
                Interval in(start, end);
                result[resultprev] = in;
            }
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};