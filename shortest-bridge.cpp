
    int n;
    vector<vector<bool>> vis;
    queue<pair<int,int>> q;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<int>>& grid) {
        vis[r][c] = true;
        q.push({r, c});

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vis.assign(n, vector<bool>(n, false));
        bool found = false;      
          for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                    found = true;
                }
            }
        }

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n || vis[nr][nc])
                        continue;

                    if (grid[nr][nc] == 1)
                        return steps;

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }

            steps++;
        }

        return -1;
    }
