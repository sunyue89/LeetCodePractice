/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
 
        while(lo<=hi){
            int idx = (lo+hi)/2;
            //cout<<lo<<" "<<hi<<" "<<idx<<" "<<endl;

            if(nums[idx]==target){
                return idx;
            }
            
            if(nums[idx]>=nums[lo]){
                if(nums[idx]>target && nums[lo]<=target){
                    hi = idx-1;
                }else{
                    lo = idx+1;
                }
            }else{
                if(nums[idx]<target && nums[hi]>=target ){
                    lo = idx+1;
                }else{
                    hi = idx-1;
                }
            }
            
            //cout<<lo<<" "<<hi<<" "<<idx<<" "<<endl;
            
        }
        return -1;
    }
};
