/*
A split of an integer array is good if:

The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,1,1]
Output: 1
Explanation: The only good way to split nums is [1] [1] [1].
Example 2:

Input: nums = [1,2,2,2,5,0]
Output: 3
Explanation: There are three good ways of splitting nums:
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
Example 3:

Input: nums = [3,2,1]
Output: 0
Explanation: There is no good way to split nums.
 

Constraints:

3 <= nums.length <= 105
0 <= nums[i] <= 104

*/

const int P = 1000000007;

class Solution {
public:
    int waysToSplit(vector<int>& a) {

        int sum[100010];
        int i, j, k, start, stop, mid, n = a.size(), right, left, R;
        int res = 0, mo = 1000000007;
        sum[0] = 0;
        for (i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i - 1];
        for (i = 3; i <= n; ++i){
            R = sum[n] - sum[i - 1];
            if (sum[i - 1] > R + R) break;
            start = 1; 
            stop = i - 2;
            right = -1;
            while (start <= stop){
                mid = (start + stop) / 2;
                if (sum[mid] <= sum[i - 1] - sum[mid]){
                    right = mid;
                    start = mid + 1;
                }
                else stop = mid - 1;
            }
            
            if (right == -1) continue;
            start = 1;
            stop = right;
            left = -1;
            while (start <= stop){
                mid = (start + stop) / 2;
                if (sum[i - 1] - sum[mid] <= R){
                    left = mid;
                    stop = mid - 1;
                }
                else start = mid + 1;
            }
            
            if (left == -1) continue;            
            res += right - left + 1;
            if (res >= mo) res -= mo;
        }
        
        return res;
    }
};
