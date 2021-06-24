/*
We have a string s of lowercase letters, and an integer array shifts.

Call the shift of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a'). 

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.

Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x times.

Return the final string after all such shifts to s are applied.

Example 1:

Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: 
We start with "abc".
After shifting the first 1 letters of S by 3, we have "dbc".
After shifting the first 2 letters of S by 5, we have "igc".
After shifting the first 3 letters of S by 9, we have "rpl", the answer.
Note:

1 <= s.length = shifts.length <= 20000
0 <= shifts[i] <= 109
*/

class Solution {
public:
    string shiftingLetters(string S, vector<int>& s) {
        s.back() %= 26;
        for(int i=s.size()-2; i>=0; --i){
            s[i] = (s[i]%26 + s[i+1]%26)%26;
        }
        for(int i=0; i<S.length(); ++i){
            if( s[i] > 'z'-S[i])
                S[i] += s[i]-26;
            else
                S[i] += s[i];
        }
        return S;
    }
};
