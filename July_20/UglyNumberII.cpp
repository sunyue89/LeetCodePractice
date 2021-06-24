/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/

class Solution {
public:
    int nthUglyNumber(int n) {

        int idx2=0, idx3=0, idx5 = 0;
        
        vector<int> rlt={1};
        
        for(int i=1;i<n;i++){
            
            int tmp = min(2*rlt[idx2],min(3*rlt[idx3],5*rlt[idx5]));
            
            rlt.push_back(tmp);
            
            if(tmp==2*rlt[idx2])
                idx2++;
            
            if(tmp==3*rlt[idx3])
                idx3++;
            
            if(tmp==5*rlt[idx5])
                idx5++;
        }
        
        return rlt[rlt.size()-1];
    }
};
