/*
Subsets

Solution
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

//          ""
//  1       2.     3
//1   2    2 3
//1. 2. 3
//1.  3

class Solution {
public:
 
    #if 0
    //recursion & backtracking
    void rec(vector<int>& nums, vector<vector<int>>& out, vector<int>& subset, int idx){
        out.push_back(subset);
        
        for(int i=idx;i<nums.size();++i){
            subset.push_back(nums[i]);
            rec(nums,out,subset,i+1);
            subset.pop_back();
        }
        return;
            
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> subset;
        rec(nums,out,subset,0);
        return out;
    }
    #endif
    
    //DP
    vector<vector<int>> subsets(vector<int>& nums) {
        //initilize a non-empty output vector
        vector<vector<int>> out={{}};
        
        for(const auto& x:nums){
            vector<vector<int>> subset;
            for(auto o:out){
                o.push_back(x);
                subset.push_back(o);
            }
            for(const auto& s:subset){
                out.push_back(s);
            }
        }
        return out;
    }
    
};
