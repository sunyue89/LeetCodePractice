/*
Reverse Words in a String

Solution
Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.
*/

class Solution {
public:
    string reverseWords(string s) {
        if(s.length()<=0)
            return "";
        string o;
        string t;
        int i=s.length()-1;
        while(i>=0){
            while(i>=0 && s[i]==' '){
                if(t.length()>0){
                    o+=t;
                    o+=" ";
                    t="";
                }
                i--;
            }
            if(i>=0){
                t.insert(t.begin(),s[i]);
                i--;
            }
        }
        if(t.length()>0)
            o+=t;
        else if(o.length()>0)
            o.pop_back();
        return o;
    }
};
