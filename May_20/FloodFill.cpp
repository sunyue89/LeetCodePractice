/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

//1 1 1
//1 1 0
//1 0 1

class Solution {
public:
    
    bool CheckValid(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int sr2, int sc2){
        return (sr2>=0 && sr2<image.size() && sc2>=0 && sc2<image[0].size() && !visited[sr2][sc2] && image[sr][sc] == image[sr2][sc2]);
    }
    
    
    void FillRec(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int newColor){
        vector<vector<int>> con = {{-1,0},{1,0},{0,1},{0,-1}};
        if(sr<0 || sr>=image.size()) return;
        if(sc<0 || sc>=image[0].size()) return;
        if(visited[sr][sc]) return;
        visited[sr][sc] = true;
        for(int i=0;i<con.size();i++){
            if(CheckValid(image,visited,sr,sc,con[i][0]+sr,con[i][1]+sc))
                FillRec(image,visited,con[i][0]+sr,con[i][1]+sc,newColor);
        }
        image[sr][sc] = newColor;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        /*vector<vector<int>> im_out(image.size(),vector<int>(image[0].size(),0));
        for(int i=0;i<image.size();i++){
            for(int j=0;j<image[0].size();j++){
                im_out[i][j] = image[i][j];
            }
        }*/
        //This method, in contrast to commented, will modify original image
        vector<vector<bool>> visited(image.size(),vector<bool>(image[0].size(),false));
        if(image[sr][sc]!=newColor)
            FillRec(image,visited,sr,sc,newColor);
        return image;
    }
};
