/*In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

 

Example 1:

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Example 2:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Example 3:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Example 4:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Example 5:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:

 

Note:

1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.
Last Submission
Last Saved Code*/


class Solution {
public:
  int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();    
    DSU dsu(4 * n * n);
    for (int r = 0; r < n; ++r)
      for (int c = 0; c < n; ++c) {
        int index = 4 * (r * n + c);
        switch (grid[r][c]) {
          case '/':
            dsu.merge(index + 0, index + 3);
            dsu.merge(index + 1, index + 2);
            break;
          case '\\':
            dsu.merge(index + 0, index + 1);
            dsu.merge(index + 2, index + 3);
            break;
          case ' ':
            dsu.merge(index + 0, index + 1);
            dsu.merge(index + 1, index + 2);
            dsu.merge(index + 2, index + 3);
            break;
          default: break;
        }
        if (r + 1 < n)
          dsu.merge(index + 2, index + 4 * n + 0);
        if (c + 1 < n)
          dsu.merge(index + 1, index + 4 + 3);
      }
    int ans = 0;
    for (int i = 0; i < 4 * n * n; ++i)
      if (dsu.find(i) == i) ++ans;
    return ans;
  }
private:
  class DSU {
    public:
      DSU(int n): parent_(n) {
        for (int i = 0; i < n; ++i)
          parent_[i] = i;
      }
      
      int find(int x) {
        if (parent_[x] != x) parent_[x] = find(parent_[x]);
        return parent_[x];
      }
      
      void merge(int x, int y) {
        parent_[find(x)] = find(y);
      }
    private:
      vector<int> parent_;
  };
};
