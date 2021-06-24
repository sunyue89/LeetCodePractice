/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int k  = nums.size();
        vector<int> output(k,1);
        int p = 1;
        //vector<int> left(k,1);
        //vector<int> right(k,1);
        for(int i=0;i<k;++i){
            output[i] = p;
            p*=nums[i];
            //left[i] = left[i-1]*nums[i-1];
        }
        p=1;
        for(int i=k-1;i>=0;--i){
            output[i]*=p;
            p*=nums[i];
            //right[i] = right[i+1]*nums[i+1];
        }
        //for(int i=0;i<k;++i){
          //  output[i] = left[i]*right[i];
        //}
        return output;
    }
};
