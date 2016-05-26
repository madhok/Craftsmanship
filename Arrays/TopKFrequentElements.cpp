/*
Top K Frequent Elements
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

*/
struct comparator {
    bool operator() (pair<int,int>i, pair<int,int> j) {
        if(i.second > j.second) {
            return true;
        } return false;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        if(size<k) return nums;
        map<int,int> m;
        for(int i = 0; i <size; ++i) {
            if(m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            } else {
                m[nums[i]]++;
            }
        }
        vector<int> occurences;
        map<int,int>::iterator it;
        for(it = m.begin(); it != m.end(); ++it) {
            occurences.push_back(it->second);
        }
        sort(occurences.begin(),occurences.end());
        int k_occurence = occurences[occurences.size()-k];
        vector<int> result;
        for(it = m.begin(); it != m.end(); ++it) {
            if(it->second >= k_occurence) 
                result.push_back(it->first);
        }
        return result;
    }
};