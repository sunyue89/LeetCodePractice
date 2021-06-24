/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045
 

Constraints:

1 <= n <= 50 
*/

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> a = {1,0,0,0,0};
        int j=0;
        int ans = 0;
        while(j++<n){
            ans=0;
            ans+=a[0];
            //cout<<a[0]<<endl;
            for(int i=1;i<a.size();++i){
                a[i] = a[i-1]+a[i];
                //cout<<a[i]<<endl;
                ans+=a[i];
            }
        }
        return ans;
        
        //1+1+1+1+1
        //5+4+3+2+1 = 6*5/2=15
        //15+10+6+3+1 = ?
        //35+20+10+4+1
    }
};
