/*
Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

 

Example 1:

Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
Example 2:

Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= nums.length

*/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& a, int k) {
        const int n = a.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            while (ans.size() > 0 && a[i] < ans.back() && int(ans.size()) - 1 + (n - i) >= k) {
                ans.pop_back();
            }
            if (ans.size() < k) ans.push_back(a[i]);
        }
        return ans;
    }
    
    //brute force does not pass time limits
    #if 0
    void pr(vector<int>&a){
        for(auto x:a)
            cout<<x<<" ";
        cout<<endl;
    }
    void mc(vector<int>&a, vector<int>& b){
        for(int i=0;i<a.size();++i){
            if(a[i]>b[i]){
                a = b;
                return;
            }
        }
    }
    void fdCom(vector<int>& nums, int k, int j, int i, vector<int>& f, vector<int>& r){
        if(j==k){
            //pr(r);
            //pr(f);
            if(r.size()<=0)
                r = f;
            else
                mc(r,f);
            return;
        }else{
            // When no more elements are there to put in data[]  
            if (i >= nums.size())  
                return;  

            // current is included, put next at next location  
            f[j] = nums[i];  
            fdCom(nums, k, j+1, i+1, f, r);  

            // current is excluded, replace it with next (Note that  
            // i+1 is passed, but index is not changed)  
            fdCom(nums, k, j, i+1, f, r); 
        }
    }
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> flr(k);
        fdCom(nums,k,0,0,flr,ans);
        return ans;
    }
    #endif
};
