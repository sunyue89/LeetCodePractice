/*
You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.

Your goal is to satisfy one of the following three conditions:

Every letter in a is strictly less than every letter in b in the alphabet.
Every letter in b is strictly less than every letter in a in the alphabet.
Both a and b consist of only one distinct letter.
Return the minimum number of operations needed to achieve your goal.

 

Example 1:

Input: a = "aba", b = "caa"
Output: 2
Explanation: Consider the best way to make each condition true:
1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
The best way was done in 2 operations (either condition 1 or condition 3).
Example 2:

Input: a = "dabadd", b = "cda"
Output: 3
Explanation: The best way is to make condition 1 true by changing b to "eee".
 

Constraints:

1 <= a.length, b.length <= 105
a and b consist only of lowercase letters.
*/

class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> ac(26,0);
        vector<int> bc(26,0);
        
        int p = INT_MIN, q = INT_MIN;
        for(auto x:a){
            if(++ac[x-'a']>p)
                p = ac[x-'a'];
            
        }
        for(auto x:b){
            if(++bc[x-'a']>q)
                q = bc[x-'a'];
        }
        int n = a.size() - p + b.size() - q;
        //cout<<n<<endl;
        
        int l = INT_MAX, m = INT_MAX ;
        for(int i = 'b';i<='z';++i){
            int s1 = 0, s2 = 0, s3 = 0;
            for(int j='a'; j<='z'; ++j){
                if(j>=i){
                    s1+=ac[j-'a']; //a
                    s2+=bc[j-'a'];
                }
                else{
                    s1+=bc[j-'a']; //b
                    s2+=ac[j-'a'];
                }
            }
            //cout<<s1<<" "<<s2<<endl;
            if(s1<l)
                l = s1;
            if(s2<m)
                m = s2;
        }
        return min(min(l,m),n);
        
    }
};
