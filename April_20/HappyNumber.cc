/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
    bool isHappy(int n) {
        
        int ct = 0;
        int sum = 0;
        unordered_set <int> cycle;
        while(n!=1){
            // 19/10 = 1; 19%10 = 9;
            // 1/10 = 0; 1%10 = 1;
            sum = 0;
            while(n>0){
                sum += (n%10)*(n%10);
                n /= 10;
            }
            n = sum;
            
            #if 0
            //a more robust solution, but not faster than loop 100 times
            if (cycle.find(sum)!=cycle.end())
                return false;
            else
                cycle.insert(sum);
            #endif
            
            ct++;
            if(ct>100) return false;
            
        }
        return true;
    }
};
