/*Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.
 

Last Submission
Last Saved Code*/

class Solution {
public:
    bool isPal(string s){
        int mid = (s.length()-1)/2;
        int lo;
        if(s.length()%2==0)
            lo = max(0,mid);
        else
            lo = max(0,mid-1);
        int hi= mid+1>s.length()-1 ? s.length()-1:mid+1;
        while(lo>=0 && hi<=s.length()-1){
            if(s[lo]!=s[hi])
                return false;
            lo--;
            hi++;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ct=0;
        for(int i=1;i<=s.length();++i){
            for(int j=0;j<=s.length()-i;++j){
                //cout<<s.substr(j,i)<<endl;
                if(isPal(s.substr(j,i))){
                    //cout<<s.substr(j,i)<<endl;
                    ct++;
                }
            }
        }
        return ct;
    }
};

