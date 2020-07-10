/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx = coordinates[1][0]-coordinates[0][0];
        int dy = coordinates[1][1]-coordinates[0][1];
        bool ho = (dx==0);
        bool vr = (dy==0);
        bool x_dom = (abs(dx)<=abs(dy));
        //cout<<ho<<" "<<vr<<" "<<x_dom<<endl;
        int k=0,b=0;
        if(!ho && !vr){
            if(x_dom){
                k = dy/dx;
                b = dy%dx;
            }else{
                k = dx/dy;
                b = dx%dy;
            }
        }
        //cout<<k<<" "<<b<<endl;
        for(int i =2; i<coordinates.size(); ++i){
            if(ho||vr){
                if(ho && coordinates[i][0]!=coordinates[i-1][0]) return false;
                if(vr && coordinates[i][1]!=coordinates[i-1][1]) return false;
            }else{
                int k1,b1;
                if(x_dom){
                    if((coordinates[i][0] - coordinates[i-1][0])==0) return false;
                    k1 = (coordinates[i][1] - coordinates[i-1][1])/(coordinates[i][0] - coordinates[i-1][0]);
                    b1 = (coordinates[i][1] - coordinates[i-1][1])%(coordinates[i][0] - coordinates[i-1][0]);
                }else{
                    if((coordinates[i][1] - coordinates[i-1][1])==0) return false;
                    k1 = (coordinates[i][0] - coordinates[i-1][0])/(coordinates[i][1] - coordinates[i-1][1]);
                    b1 = (coordinates[i][0] - coordinates[i-1][0])%(coordinates[i][1] - coordinates[i-1][1]);
                }
                //cout<<k1<<" "<<b1<<endl;
                if(k1!=k || b1!=b) return false;
            } 
        }
        return true;
    }
};
