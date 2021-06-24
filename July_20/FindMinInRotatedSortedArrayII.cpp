/*
Find Minimum in Rotated Sorted Array II

Solution
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/

// 6      5
//  0    4
//   1. 3
//    2

// 3      2
//  4    1
//   5. 0
//    6
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            #if 0
            if(nums[mid]==nums[hi] && nums[mid]==nums[lo]){
                lo++;
                hi--;
            }else if(nums[mid]<=nums[hi]){//right side sorted
                hi = mid;
            }else{//left side sorted
                lo = mid+1;
            }
            #endif
            if(nums[mid]<nums[hi]){
                hi = mid;
            }else if(nums[mid]==nums[hi]){//right side sorted
                hi--;
            }else{//left side sorted
                lo = mid+1;
            }
        }
        return nums[lo];
    }
};
