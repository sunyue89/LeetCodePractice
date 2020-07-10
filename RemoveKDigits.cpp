/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

//1432921
//1221
//1107 1
//17 
//107
class Solution {
public:
    void buildsmallstring(string num, string& res, int k){
        if(k==0){
            //cout<<num<<endl;
            res.append(num);
            return;
        }
        if(num.length()<=k){
            return;
        }
        int min_idx = 0;
        for(int i=1;i<=k;++i)
            if(num[i]<num[min_idx])
                min_idx = i;
        if(num[min_idx]!='0'||!res.empty())
            res.push_back(num[min_idx]);
        buildsmallstring(num.substr(min_idx+1,num.length()-min_idx-1),res,k-min_idx);
    }
    string removeKdigits(string num, int k) {
        string out = "";
        buildsmallstring(num,out,k);
        return out.empty()? "0":out;
    }
};
