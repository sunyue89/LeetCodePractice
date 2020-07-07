/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1) return true;
        vector <int> maxS(nums.size(),0);
        maxS[0]=nums[0];
        int i = 0;
        int j = 0;
        while(i<nums.size()){
            for(j=i;j<=i+maxS[i];++j){
                //cout<<j<<" "<<maxS[j]<<endl;
                if(j>=nums.size()-1) return true;
                if(j>0) maxS[j] = max(maxS[j-1]-1,nums[j]);
                if(maxS[j]+j >= nums.size()-1) return true;
                if(maxS[j]==0) return false;
            }
            i = j; //incremented by 1 due to for loop
        }
        return false;
    }
};
