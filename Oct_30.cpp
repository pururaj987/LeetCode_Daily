https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m , vector<int>(n , -1));
        queue<vector<int>> q;
        // represents current row , current col , current length , available k
        q.push({0 , 0 , 0 , k});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it[0];
            int y = it[1];
            int currLength = it[2];
            int kAvailable = it[3];
            // check if it is out of bounds
            if(x < 0 || y < 0 || x >= m || y >= n) {
                continue;
            }
            // check if reached the destination
            if(x == m-1 && y == n-1) {
                return currLength;
            }
            // check if obstacle is there
            if(grid[x][y] == 1) {
                if(kAvailable > 0) {
                    kAvailable --;
                } else {
                    continue;
                }
            }
            // check if cell is already visited
            if(vis[x][y] != -1 && vis[x][y] >= kAvailable) {
                continue;
            }
            vis[x][y] = kAvailable;
            q.push({x , y+1 , currLength + 1 , kAvailable});
            q.push({x , y-1 , currLength + 1 , kAvailable});
            q.push({x-1 , y , currLength + 1 , kAvailable});
            q.push({x+1 , y , currLength + 1 , kAvailable});
        }
        return -1;
    }
};