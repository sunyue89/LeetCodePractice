/*Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Example 2:

Input: nums = [2,9,2,5,6], left = 2, right = 8
Output: 7
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= left <= right <= 109
*/

//[2,2,2,2]
//Cn1 + Cn2 + Cn3 + Cnn .. = (n+1)*n/2

//[2,2,2]
//(n+1)*n/2 = 4*3/2 = 6 

//[2,1,2]
//1+1+3

//[2,1,1,2]
//1+1+1+4

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int s=0,e=0,win=0;
        int rtn=0;
        for(auto n:nums){
            if(n>=left && n<=right){
                win = e-s+1;
            }
            else if(n>right){
                win = 0;
                s = e+1;
            }
            rtn += win;   
            e++;
        }
        return rtn;
    }
};
