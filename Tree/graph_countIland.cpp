#include <vector>
#include <queue>
using namespace std;
/* graph traversal recursion version: DFS, BFS */
/* 1 represent lands, 0 represents water, find the number of lands in a given grid */

/* DFS recursion: */
void helper(vector<vector<char>>& grid, int r, int c) {
    grid[r][c] = '0';
    int nr = grid.size(), nc = grid[0].size();
    if (r + 1 < nr && grid[r + 1][c] == '1') helper(grid, r + 1, c);
    if (r - 1 >= 0 && grid[r - 1][c] == '1') helper(grid, r - 1, c);
    if (c + 1 < nc && grid[r][c + 1] == '1') helper(grid, r, c + 1);
    if (c - 1 >= 0 && grid[r][c - 1] == '1') helper(grid, r, c - 1);
}

int countIsland(vector<vector<char>> grid) {
    if (grid.empty()) return 0;
    int nr = grid.size(), nc = grid[0].size();
    int ans = 0;
    for (int r = 0; r < nr; ++r) {
        for (int c = 0; c < nc; ++c) {
            if (grid[r][c] == '1') {
                ++ans;
                helper(grid, r, c);
            }
        }
    }
    return ans;
}

/* BFS with queue */
int countIsland2(vector<vector<char>> grid) {
    if (grid.empty()) return 0;
    int nr = grid.size(), nc = grid[0].size();
    int ans = 0;
    queue<pair<int, int>> qu;
    for (int r = 0; r < nr; ++r) {
        for (int c = 0; c < nc; ++c) {
            if (grid[r][c] == '1') {
                ++ans;
                grid[r][c] = '0';
                qu.push(pair<int, int>(r, c));
                while (!qu.empty()) {
                    pair<int, int> p = qu.front();
                    qu.pop();
                    int rr = p.first, cc = p.second;
                    if (rr + 1 < nr && grid[rr + 1][cc] == '1') {
                        qu.push(pair<int, int>(rr + 1, cc));
                        grid[rr + 1][cc] = '0';
                    }
                    if (rr - 1 >= 0 && grid[rr - 1][cc] == '1') {
                        qu.push(pair<int, int>(rr - 1, cc));
                        grid[rr - 1][cc] = '0';
                    }
                    if (cc + 1 < nc && grid[rr][cc + 1] == '1') {
                        qu.push(pair<int, int>(rr, cc + 1));
                        grid[rr][cc + 1] = '0';
                    }
                    if (cc - 1 >= 0 && grid[rr][cc - 1] == '1') {
                        qu.push(pair<int, int>(rr, cc - 1));
                        grid[rr][cc - 1] = '0';
                    }
                }
            }
        }
    }
    return ans;
}

/* Union Find (aka Disjoint Set) */

