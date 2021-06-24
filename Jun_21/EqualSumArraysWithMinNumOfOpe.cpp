/*
You are given two arrays of integers nums1 and nums2, possibly of different lengths. The values in the arrays are between 1 and 6, inclusive.

In one operation, you can change any integer's value in any of the arrays to any value between 1 and 6, inclusive.

Return the minimum number of operations required to make the sum of values in nums1 equal to the sum of values in nums2. Return -1​​​​​ if it is not possible to make the sum of the two arrays equal.

 

Example 1:

Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed.
- Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
- Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
- Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
Example 2:

Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
Output: -1
Explanation: There is no way to decrease the sum of nums1 or to increase the sum of nums2 to make them equal.
Example 3:

Input: nums1 = [6,6], nums2 = [1]
Output: 3
Explanation: You can make the sums of nums1 and nums2 equal with 3 operations. All indices are 0-indexed. 
- Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
- Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
- Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[i] <= 6
*/

class Solution {
public:
    //[1 6] [1]     
    //[2 12] [12] [6]
    
    //[7 42]
    //[6]
    
    //[6 36] //21 //
    //[6 36] //10 //15
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()*6 < nums2.size() || nums1.size()>nums2.size()*6)
            return -1;
        int s1 = accumulate(nums1.begin(),nums1.end(),0);
        int s2 = accumulate(nums2.begin(),nums2.end(),0);
        if(s1==s2)
            return 0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ans = 0;
        int i,j;
        int dif = s2-s1;
        if(dif>0){
            i=0;
            j = nums2.size()-1;
        }else{
            i = nums1.size()-1;
            j = 0;
        }
        while(dif!=0){
            ans++;
            int d;
            if(dif>0){
                if(i<nums1.size() && j<nums2.size() && i>=0 && j>=0){
                    if((6-nums1[i])>(nums2[j]-1)){
                        d=6-nums1[i];
                        ++i;
                    }
                    else{
                        d=nums2[j]-1;
                        --j;
                    }
                }else if(i==nums1.size()){
                    d=nums2[j]-1;
                    --j;
                }else{
                    d=6-nums1[i];
                    ++i;                    
                }
                dif = max(dif-d,0);
            }else{
                if(i<nums1.size() && j<nums2.size() && i>=0 && j>=0){
                    if((6-nums2[j])>(nums1[i]-1)){
                        d=6-nums2[j];
                        ++j;
                    }
                    else{
                        d=nums1[i]-1;
                        --i;
                    }
                }else if(j==nums2.size()){
                    d=nums1[i]-1;
                    --i;
                }else{
                    d=6-nums2[j];
                    ++j;
                }
                dif = min(dif+d,0);
            }
            //cout<<i<<j<<d<<dif<<endl;
        }
        return ans;
    }
};
