/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
    struct Comp{
        template <typename T>
        bool operator()(const T a, const T b) const
        {
            return a.second>=b.second;
        }
    };
public:
    string frequencySort(string s) {
        unordered_map<char,int> ct;
        for(int i=0;i<s.length();++i){
            ct[s[i]]++;
        }
        set<pair<char,int>,Comp> pq;
        for(auto const &x:ct){
            pq.insert(make_pair(x.first,x.second));
            //cout<<x.first<<" "<<x.second<<endl;
        }
        int i=0;
        string out="";
        for(auto const &x:pq){
            i = x.second;
            //cout<<x.first<<endl;
            while(i>0){
                out+=x.first;
                i--;
            }
        }
        return out;
    }
};
