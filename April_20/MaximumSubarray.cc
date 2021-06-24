/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

//[-2 1 -3 4 -1 2 1 -5 4]
//    i    j    k

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum = nums[0];
        int rollSum = 0;
        for(int k = 0; k<nums.size(); ++k){
            rollSum += nums[k];
            rollSum = max(nums[k],rollSum);
            maxSum = max(maxSum,rollSum); 
        }
        return maxSum;
    }
};
