/*Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]
 

Constraints:

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lower-case English letters.*/

class Solution {
public:
    bool CkPal(string& w){
        int i=0, j=w.length()-1;
        while(i<j){
            if(w[i]!=w[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        if(words.size()<2)
            return res;
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++)
            mp[words[i]] = i;
        
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<=words[i].length();j++)
            {
                string prefixString = words[i].substr(0,j);
                string suffixString = words[i].substr(j);

                if(CkPal(prefixString))
                {
                    string reverseString = suffixString;
                    reverse(reverseString.begin(),reverseString.end());
                    if(mp.count(reverseString) && mp[reverseString]!=i)
                    {
                        res.push_back({mp[reverseString],i});
                    }
                }
                
                if(CkPal(suffixString))
                {
                    string reverseString = prefixString;
                    reverse(reverseString.begin(),reverseString.end());
                    if(mp.count(reverseString) && mp[reverseString]!=i && !suffixString.empty())
                    {
                        res.push_back({i,mp[reverseString]});
                    }
                }
                
            }
        }
        return res;
    }
};
