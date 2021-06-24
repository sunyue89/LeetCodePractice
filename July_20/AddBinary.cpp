/*
Add Binary

Solution
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length();
        int lb = b.length();
        char ct = '0';
        string out;
        for(int i=0;i<max(la,lb);++i){
            char ca = '0', cb = '0';
            if(la-i-1>=0)
                ca = a[la-i-1];
            if(lb-i-1>=0)
                cb = b[lb-i-1];
            int n = (ca=='1') + (cb=='1') + (ct=='1');
            //cout<<n<<endl;
            switch (n){
                case 0:
                    ct = '0';
                    out.insert(out.begin(),'0');
                    break;
                case 1:
                    ct = '0';
                    out.insert(out.begin(),'1');
                    break;
                case 2:
                    ct = '1';
                    out.insert(out.begin(),'0');
                    break;
                case 3:
                    ct = '1';
                    out.insert(out.begin(),'1');
                    break;
                default:
                    break;
            }
        }
        if (ct=='1')
            out.insert(out.begin(),'1');
        return out;
    }
};
