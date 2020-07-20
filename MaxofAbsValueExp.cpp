/*
Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.

 

Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13
Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20
 

Constraints:

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6
Last Submission
Last Saved Code*/

class Solution {
public:
    
    int getVal(vector <int>& v){
      int maxVal = INT_MIN;
      int minVal = INT_MAX;
      for(int i = 0; i < v.size(); i++){
         minVal = min(v[i], minVal);
         maxVal = max(v[i], maxVal);
      }
      return maxVal - minVal;
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
      vector <int> ret[4];
      int n = arr1.size();
      for(int i = 0; i < n; i++){
         ret[0].push_back(arr1[i] - arr2[i] + i);
         ret[1].push_back(arr1[i] + arr2[i] + i);
         ret[2].push_back(arr1[i] - arr2[i] - i);
         ret[3].push_back(arr1[i] + arr2[i] - i);
      }
      int ans = INT_MIN;
      for(int i = 0; i < 4; i++){
         ans = max(ans, getVal(ret[i]));
      }
      return ans;
    }
};

