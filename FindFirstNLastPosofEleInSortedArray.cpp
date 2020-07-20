/*Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9
Last Submission
Last Saved Code*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        int mid = 0;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target)
                break;
            if(nums[mid]<target)
                lo = mid+1;
            else
                hi = mid-1;
        }
        if(lo>hi)
            return {-1,-1};
        lo = mid;
        hi = mid;
        int l,r;
        while(lo>=0 && nums[lo]==target){
            l=lo;
            lo--;
        }
        while(hi<=nums.size()-1 && nums[hi]==target){
            r=hi;
            hi++;
        }
        return {l,r};
    }
};
