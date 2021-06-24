/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

class Solution {
public:
    vector<int> countBits(int num) {

        if(num==0) return {0};
        int hb = 2;
        int tmp = 2;
        vector<int> out={0,1};
        for(int i=0; i<=num; ++i){

            if(i>=hb){//2,4,8,16,32
                tmp=hb;
                hb<<=1;
            }
            //cout<<hb<<tmp<<endl;
            if(i>=tmp) 
                out.push_back(1+out[(i-tmp)%tmp]);
        }
        return out;
    }
};
