class Solution {
public:

    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans,
             int row, int col, int delrow[], int delcol[],
             int inicolor, int color, int n, int m) {

        ans[row][col] = color;

        for(int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               image[nrow][ncol] == inicolor &&
               ans[nrow][ncol] != color) {

                dfs(image, ans, nrow, ncol,delrow, delcol, inicolor, color, n, m);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> ans = image;

        int inicolor = image[sr][sc];

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        dfs(image, ans, sr, sc, delrow, delcol,inicolor, color, n, m);

        return ans;
    }
};