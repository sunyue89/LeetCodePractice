/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/

//5 0x0101
//6 0x0110
//7 0x0111

//2 0x0010

//1 0x0001
//4 0x0100
//3 0x0011

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d = n-m;
        int i =0;
        //If adjacent or equal
        if(d<=1) return (m&n);
        while(d>1){
            d>>=1;
            i++;
        }
        cout<<i;
        //If all 31 bits are to be cleared
        if(30==i) return 0;
        int mask = ~((1 << i+1 ) - 1);
        return (m & n & mask);
    }
};
