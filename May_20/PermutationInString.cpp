/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector <int> s1_reg_(26,0);
        vector <int> s2_reg_(26,0);
        
        if(s1.length()>s2.length())
            return false;
        
        for(int i=0;i<s1.length();++i){
            s1_reg_[s1[i]-97]++;
        }
        
        for(int i=0;i<s2.length();++i){
            s2_reg_[s2[i]-97]++;
            
            if(i>=s1.length())
                s2_reg_[s2[i-s1.length()]-97]--;
            
            if(i>=s1.length()-1){
                int j=0;
                for(j=0;j<s1_reg_.size();j++){
                    if(s1_reg_[j] != s2_reg_[j])
                        break;
                }
                if(j>=s1_reg_.size())
                    return true;
            }
        }
        return false;
    }
};
