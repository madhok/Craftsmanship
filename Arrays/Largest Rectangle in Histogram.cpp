    /*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.



Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].



The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       stack<int> p;
    int current = 0, area = 0;
    height.push_back(0);
    while(current < height.size()) {
        if(p.empty() || height[p.top()] <= height[current])
            p.push(current++);
        else {
            int left = p.top();
            p.pop();
            area = max(area, height[left] * (p.empty() ? current : current - p.top() - 1 ));
        }
    }
    return area;
    }
};