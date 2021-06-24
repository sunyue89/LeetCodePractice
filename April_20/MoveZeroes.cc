/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

//[0 1 0 3 12]
//[1 0 0 3 12]
//[1 3 0 0 12]
//[1 3 0 0 12]

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (i<nums.size()){
            if(nums[i]==0){
                j=max(i,j);
                while(nums[j]==0 && j<nums.size()-1){
                    j++;
                }
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                if(j>=nums.size()-1) break;
                //cout<< i << " " <<j <<endl;
            }
            i++;
        }
    }
};
