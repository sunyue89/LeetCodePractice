/*
Single Number III

Solution
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int X = 0;
        for(int i=0; i<nums.size(); ++i){
            X ^= nums[i];
        }
        X = X & ~(X-1); //right most setbit
        
        int a=0, b=0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]&X)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        return {a,b};
    }
};
