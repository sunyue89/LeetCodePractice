/*
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

 

Example 1:


Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
 

Constraints:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108
*/

class Solution {
public:
    
    bool vis[16];
    bool canMakeSquare(vector < int > & matchsticks, int currentSum, int oneSideLength, int totalSides, int idx = 0) {
        if (totalSides == 0)
            return true;
        if (currentSum == oneSideLength)
            return canMakeSquare(matchsticks, 0, oneSideLength, totalSides - 1, 0);
        if (idx >= size(matchsticks))
            return false;
        for (int i = idx; i < size(matchsticks); i++) {
            if (!vis[i]) {
                if (currentSum + matchsticks[i] <= oneSideLength) {
                    vis[i] = true;
                    if (canMakeSquare(matchsticks, currentSum + matchsticks[i], oneSideLength, totalSides, i + 1))
                        return true;
                    vis[i] = false;
                }
            }
        }
        return false;
    }

    bool makesquare(vector < int > & matchsticks) {
        memset(vis, false, sizeof(vis));
        int sum = 0;
        for (int i: matchsticks)
            sum += i;
        if (sum % 4)
            return false;
        int oneSideLength = sum / 4;
        int totalSides = 4;
        return canMakeSquare(matchsticks, 0, oneSideLength, totalSides);

    }
     
    //recursion solution
    // Function to check if all subsets are filled or not
    #if 0
    bool checkSum(vector<int>& sumLeft, int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (sumLeft[i] != 0) {
                return false;
            }
        }

        return true;
    }
 
    // Helper function for solving `k` partition problem.
    // It returns true if there exist `k` subsets with the given sum
    bool subsetSum(vector<int>& S, int n, vector<int>& sumLeft, int k)
    {
        // return true if a subset is found
        if (checkSum(sumLeft, k)) {
            return true;
        }

        // base case: no items left
        if (n < 0) {
            return false;
        }

        bool result = false;

        // consider current item `S[n]` and explore all possibilities
        // using backtracking
        for (int i = 0; i < k; i++)
        {
            if (!result && (sumLeft[i] - S[n]) >= 0)
            {
                // add the current item to the i'th subset
                sumLeft[i] = sumLeft[i] - S[n];

                // recur for remaining items
                result = subsetSum(S, n - 1, sumLeft, k);

                // backtrack: remove the current item from the i'th subset
                sumLeft[i] = sumLeft[i] + S[n];
            }
        }

        // return true if we get a solution
        return result;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int k = 4;
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%k!=0)
            return false;
        int n = matchsticks.size();
        vector<int> sumLeft(k);
        for(int i=0; i<k; ++i)
            sumLeft[i] = sum/k;
        return subsetSum(matchsticks,n-1,sumLeft,k);
        
    }
    #endif

};
