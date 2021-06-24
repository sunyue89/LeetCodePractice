/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ones = 0, twos = 0, not_threes = 0;
        
        for (const auto& x:nums){
            twos |= ones & x;
            ones ^= x;
            not_threes = ~(ones & twos);
            ones &= not_threes;
            twos &= not_threes;
        }
        return ones;
        
        #if 0
        unordered_map<int,int> tr;
        
        for(int i=0; i<nums.size(); ++i){
            tr[nums[i]]++;
        }
        
        for(const auto& x:tr)
            if(x.second!=3)
                return x.first;
        
        return -1;
        #endif
    }
};
