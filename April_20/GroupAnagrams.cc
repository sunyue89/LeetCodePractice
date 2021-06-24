/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <vector<int>,int> SumChar;
        int ct = 0;
        vector<vector<string>> rlt;
        for(int i=0;i<strs.size();++i){
            vector<int> ct_char(26,0);
            for(int j=0;j<strs[i].length();++j){
                ct_char[strs[i][j]-97]++;
            }
            if (SumChar.find(ct_char)==SumChar.end()){
                SumChar[ct_char] = ct;
                ct++;
            }
            if(ct>rlt.size())    
                rlt.resize(ct);
            rlt[SumChar[ct_char]].push_back(strs[i]);
            
        }
        return rlt;
    }
};
