/*
You are given a string time in the form of hh:mm, where some of the digits in the string are hidden (represented by ?).

The valid times are those inclusively between 00:00 and 23:59.

Return the latest valid time you can get from time by replacing the hidden digits.

 

Example 1:

Input: time = "2?:?0"
Output: "23:50"
Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
Example 2:

Input: time = "0?:3?"
Output: "09:39"
Example 3:

Input: time = "1?:22"
Output: "19:22"
 

Constraints:

time is in the format hh:mm.
It is guaranteed that you can produce a valid time from the given string.
*/

class Solution {
public:
    string maximumTime(string t) {
        string h = "",m = "";
        if(t[0] == '?' && t[1] == '?'){
            h = "23";
        }else if(t[0] == '?'){
            
            if(t[1]<'4')
                h = "2" + t.substr(1,1);
            else
                h = "1" + t.substr(1,1);
        }else if(t[1] == '?'){
            
            if(t[0]=='2')
                h =  t.substr(0,1) + "3";
            else
                h =  t.substr(0,1) + "9";
        }else{
            h = t.substr(0,2);
        }
        
        m += min(t[3],'5');
        m += min(t[4],'9');
        
        return h+":"+m;
    }
};
