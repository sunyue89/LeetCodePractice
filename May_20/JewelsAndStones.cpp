/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/

//65 A
//97 a

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        long long BM = 0;
        for(int i=0;i<J.length();++i){
            if(J[i]>=97){
                //cout<<(J[i]-97+26)<<endl;
                BM |= (long long)1<<(J[i]-97+26);
                //cout<<BM<<endl;
            }
            else{
                //cout<<(J[i]-65)<<endl;
                BM |= (long long)1<<(J[i]-65);
                //cout<<BM<<endl;
            }
        }
        //cout << BM << endl;
        int ct = 0;
        for(int i=0;i<S.length();++i){
            if(S[i]>=97){
                if(BM & (long long)1<<(S[i]-97+26))
                    ct++;
            }else{
                if(BM & (long long)1<<(S[i]-65))
                    ct++;
            }
        }
        return ct;
    }
};
