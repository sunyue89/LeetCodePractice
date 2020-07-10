/*
We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

 

Example 1:


Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2
 

Note:

1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000
*/

//[2,5,1,2,5]
//[10,5,2,1,5,2]

//[1,3,7,1,7,5]
//[1,9,2,5,1]

class Solution {
public:
    int dp(vector<int>& A, vector<int>& B, vector<vector<int>>& mem, int i, int j, int ct){
        if(i<0 || j<0)
            return ct;
        
        int c = (i==0 || j==0 || mem[i-1][j-1]==-1)? dp(A,B,mem,i-1,j-1,ct):mem[i-1][j-1];
        int a = (i==0 || mem[i-1][j]==-1)? dp(A,B,mem,i-1,j,ct):mem[i-1][j];
        int b = (j==0 || mem[i][j-1]==-1)? dp(A,B,mem,i,j-1,ct):mem[i][j-1];
        
        if(i>=0 && j>=0 && A[i]==B[j]){
            ct = c+1;
        }else{
            ct = max(a,b);
        }
        mem[i][j] = ct;
        
        return ct;
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> mem = vector(A.size(),vector(B.size(),-1));
        return dp(A,B,mem,A.size()-1,B.size()-1,0);
    }
};
