/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].


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
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if(intervals.size() == 0)
        return intervals;
        vector<Interval> result;
        int size = intervals.size();
        
        sort(intervals.begin(), intervals.end(), myobject);
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

struct myclass {
  bool operator() (Interval i,Interval j) { return (i.start<j.start);}
} myobject;
    
    
};