class Solution {
public:
    void dfs(vector<vector<char>>& board , int i , int j) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '.') return;

        board[i][j] = '.';
        dfs(board , i-1 , j);
        dfs(board , i+1,  j);
        dfs(board , i , j+1);
        
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size() , n = board[0].size();
        int ans = 0;
        for(int i = 0; i< m; i++) {
            for(int j = 0; j< n; j++) {
                if(board[i][j] == 'X') {
                    ans++;
                    dfs(board , i, j);
                }
            }
        }
        return ans;
    }
};