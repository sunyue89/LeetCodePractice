/*
3 Sum

Solution
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
		//We will use this set to avoid duplicates
        set<vector<int>>s;
        int n = arr.size();
		//Loop through all elements one by one till the third last element
        for (int i = 0; i < n - 2; i++)
        {
            int val = arr[i];  // The Current element
			int l = i + 1;   // set left pointer
			int r = n - 1;   // set the right pointer
			//Iterate till l and r cross each other
            while (l < r)
            {
                int csum = val + arr[l] + arr[r]; //The current sum of all three elements
                if (csum == 0){
					// if sum is equal to zero add to the set
                    s.insert({val,arr[l++],arr[r--]}); 
                }
                else if (csum < 0) {
				// If sum is less than zero that means we need a larger number to be close to zero so we should increment left pointer as the array is sorted and so the next element will be larger
                    l++;
                }else{
				// If sum is greater than zero that means we need a smaller number to be close to zero so we should decrement right pointer as the array is sorted and so the next element will be smaller.
                    r--;
                }
            }
        }
		//Add all elements from the set to ans array
        for(auto x: s){
            ans.push_back(x);
        }
        return ans;
    }
    #if 0
public:
    vector<vector<int>> twoSum(const vector<int>& nums, int idx, int sum) {
        vector<vector<int>> out;
        unordered_set <int> delta;
        for(int i=idx+1; i<nums.size(); ++i){
            if(delta.find(sum-nums[i])!=delta.end())
                out.push_back({sum-nums[i],nums[i]});
            else
                delta.insert(nums[i]);
        }
        return out;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> out;
        for(int i=0; i<nums.size(); ++i){
            vector<vector<int>> tmp = twoSum(nums,i,-nums[i]);
            for(auto& x:tmp){
                x.push_back(nums[i]);
                out.insert(x);
            }
        }
        vector<vector<int>> ans;
        for(auto x:out)
            ans.push_back(x);
        return ans;
    }    
    #endif
};
