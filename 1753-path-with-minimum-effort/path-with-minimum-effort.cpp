class Solution {
public:
    // Return minimum possible maximum adjacent height difference.
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
 
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> minHeap;
        effort[0][0] = 0;
        minHeap.push({0, 0, 0});
 
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, 1, 0, -1};
 
        // Process cells by smallest known route effort.
        while (!minHeap.empty()) {
            auto [currentEffort, row, col] = minHeap.top();
            minHeap.pop();
 
            // Skip an outdated heap state.
            if (currentEffort != effort[row][col]) {
                continue;
            }
 
            // Destination effort is final after extraction.
            if (row == rows - 1 && col == cols - 1) {
                return currentEffort;
            }
 
            // Relax all four neighboring cells.
            for (int direction = 0; direction < 4; direction++) {
                int nextRow = row + dRow[direction];
                int nextCol = col + dCol[direction];
                if (nextRow < 0 || nextRow >= rows ||
                    nextCol < 0 || nextCol >= cols) {
                    continue;
                }
 
                int edgeEffort = abs(
                    heights[row][col] - heights[nextRow][nextCol]
                );
                int candidate = max(currentEffort, edgeEffort);
                if (candidate < effort[nextRow][nextCol]) {
                    effort[nextRow][nextCol] = candidate;
                    minHeap.push({candidate, nextRow, nextCol});
                }
            }
        }
 
        return 0;
    }
};