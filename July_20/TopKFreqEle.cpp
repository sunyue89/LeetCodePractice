/*
Top K Frequent Elements

Solution
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> ct;
        for(const auto& n:nums){
            ct[n]++;
        }
        for(const auto& c:ct){
            pq.push({c.second,c.first});
        }
        vector<int> out;
        while(k>0){
            out.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return out;
    }
};
