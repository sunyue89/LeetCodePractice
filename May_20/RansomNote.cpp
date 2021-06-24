/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters.
*/

//a 97
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      
        if(ransomNote.length()>magazine.length())
            return false;
        
        vector<int> CharCt(26,0);
        
        for(int i=0;i<ransomNote.length();++i){
            CharCt[ransomNote[i]-97]++;
        }
        for(int j=0;j<magazine.length();++j){
            CharCt[magazine[j]-97]--;
        }
        for(int i=0;i<CharCt.size();++i)
            if(CharCt[i]>0) return false;
        return true;
    }
};
