/*
Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
Example 2:

Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".
Example 3:

Input: s = "zzzzz"
Output: 15
 

Constraints:

1 <= s.length <= 105
s consists of lowercase letters.
*/

class Solution {
public:
    //aa 2^2-1 = 3 = 2*3/2
    //ccc 2^3-2 = 6 = 3*4 / 2
    //cccc 4+3+2+1 =  10 = 4*5/2
    const long M = 1000000007;
    int countHomogenous(string s) {
        long ct = 1;
        int ans = 0;
        for(int i=1; i<s.length(); ++i){
            if (s[i]==s[i-1]){
                ct++;
            }else{
                ans += (ct%M * (ct+1)%M) /2;
                ct = 1;
            }
        }
        ans += (ct%M * (ct+1)%M) /2;
        return ans;
    }
};
