/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 

Note: You may assume the string contains only lowercase English letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_set <char> Unique;
        unordered_map <char,int> CharMap;
        //map <char,int> CharMap;
        for(int i=0;i<s.length();++i){
            if(Unique.find(s[i])==Unique.end()){//if unique
                Unique.insert(s[i]);
                CharMap[s[i]] = i;
            }else{//not unique
                if(CharMap.find(s[i])!=CharMap.end())
                    CharMap.erase(s[i]);
            }
        }
        int idx = s.length();
        for(auto i:CharMap)
            idx = min(i.second,idx);
        if (idx<s.length()) return idx;
        return -1;
    }
};
