/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

//1 1 2 3 3 4 4 8 8
//        m = m-1, m = 4
//1 1 3 3 4 4 5 8 8
//        m = m+1, m = 4

//3 3 7 7 10 11 11
//      m = m-1, m = 3

//3 3 4 7 7 11 11
//      m = m+1, m = 3

//1 1 2 2 3
//    m = m+1, m = 2

//0 1 1 2 2
//    m = m-1, m = 2

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        int m = 0;
        while(lo<=hi){
            m = lo + (hi-lo)/2;
            //cout<<m<<endl;
            if(m-1<0 || m+1>nums.size()-1 || (nums[m-1]!=nums[m] && nums[m+1]!=nums[m]))
                return nums[m];
        
            if(m%2==0){
                if(nums[m]==nums[m-1])
                    hi = m-1;
                else
                    lo = m+1;
            }else{
                if(nums[m]==nums[m+1])
                    hi = m-1;
                else
                    lo = m+1;
            }
        }
        return nums[m];
    }
};
