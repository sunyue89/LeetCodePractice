/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

//a 97

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> p_rgt(26,0);
        vector<int> s_rgt(26,0);
        vector<int> out;
        if(s.length()<p.length())
            return out;
        
        for(int i=0; i<p.length(); ++i){
            p_rgt[p[i]-97]++;
        }
        for(int i=0; i<s.length(); ++i){
            s_rgt[s[i]-97]++;
            if(i>=p.length()){
                s_rgt[s[i-p.length()]-97]--;
            }
            if(i>=p.length()-1){
                int k;
                for(k=0; k<p_rgt.size(); ++k){
                    if(p_rgt[k]!=s_rgt[k])
                        break;
                }
                //cout<<k<<endl;
                if(k>=p_rgt.size())
                    out.push_back(i-p.length()+1);
            }
        }
        return out;
    }
};
