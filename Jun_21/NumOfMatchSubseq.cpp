/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 

Constraints:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        //int idx_map[26][50001] = {{-1}};
        vector<vector<int>> idx_map(26,vector<int>(50001,-1));
        int idx_trk[26] = {};
        for(int i = 0; i < s.length(); ++i){
            int cr = s[i]-'a';
            idx_map[cr][idx_trk[cr]] = i;
            idx_trk[cr]++;
        }
        int rlt = 0;
        for(auto& w:words){
            int idx_ct[26] = {}; 
            int idx_roll = -1;
            bool is_sub = true;
            for(auto c:w){
                int cr = c - 'a';
                while(idx_map[cr][idx_ct[cr]]!=-1 && idx_map[cr][idx_ct[cr]] <= idx_roll){
                    idx_ct[cr]++;
                }
                if(idx_map[cr][idx_ct[cr]] > idx_roll){
                    idx_roll = idx_map[cr][idx_ct[cr]];
                    idx_ct[cr]++;
                }else{
                    is_sub = false;
                    break;
                }
            }
            if(is_sub){
                rlt++;
            }
        }
        return rlt;
    }
};
