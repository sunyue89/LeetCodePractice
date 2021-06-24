/*
ou are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.

*/

// Sij = S0j - S0i

// S0j
// S0i,Sij
class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int max_so_far = a[0]; 
        int curr_max = a[0]; 

        for (int i = 1; i < a.size(); i++) 
        { 
            curr_max = max(a[i], curr_max + a[i]); 
            max_so_far = max(max_so_far, curr_max); 
        } 
        //cout<<max_so_far<<endl;
        for (int& x:a){
            x = -x;
        }

        curr_max = a[0]; 
        max_so_far = max(max_so_far, curr_max); 
        
        for (int i = 1; i < a.size(); i++) 
        { 
            curr_max = max(a[i], curr_max + a[i]); 
            max_so_far = max(max_so_far, curr_max); 
        } 
        //cout<<max_so_far<<endl;
        return max_so_far;
        
    }
};
