/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //sum (i,j)
        //sum (k,j) = sum(i,j) - sum(i,k)
        unordered_map <int, int> ct;
        int j = 0;    
        int s = 0;
        int ans = 0;
        
        for(int i=0; i<nums.size(); ++i){

            while(ct[nums[i]]>0){
                s -= nums[j];
                ct[nums[j++]]--;
            }
            ct[nums[i]]++;
            s+=nums[i];
            ans = max(ans,s);
        }
        return ans;
        
    }
};