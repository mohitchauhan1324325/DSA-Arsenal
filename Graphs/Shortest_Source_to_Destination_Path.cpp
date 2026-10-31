/*
Shortest Source to Destination Path

Medium

Problem Statement
You are given a binary matrix grid of size n × m, where:
- 0 represents a blocked cell (you cannot move through it).
- 1 represents a valid cell (you can move through it).

You are also given two positions:
- source: The starting position, represented by {sourceRow, sourceColumn}.
- destination: The target position, represented by {destinationRow, destinationColumn}.

Your task is to find the shortest distance (minimum number of moves) required to travel from the source cell to the destination cell.

You can move in four directions:
1. Up
2. Down
3. Left
4. Right
You cannot move diagonally.

Rules
1. You can only move through cells containing 1.
2. You cannot move outside the matrix boundaries.
3. You cannot visit blocked cells containing 0.
4. Each movement to an adjacent cell costs exactly 1.
5. If the destination cannot be reached, return -1.
Return the minimum number of moves required to reach the destination.


Example 1
Input:
grid = {
    {1, 1, 1, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};
source = {0, 0};
destination = {2, 3};
Output: 5
Explanation:
One shortest path is:
(0,0) → (0,1) → (0,2)
      → (1,2) → (2,2) → (2,3)
Total moves = 5.

Example 2
Input:
grid = {
    {1, 0, 1},
    {0, 0, 1},
    {1, 1, 1}
};
source = {0, 0};
destination = {2, 2};
Output: -1
Explanation:
There is no valid path from the source to the destination.
Function Signature


Topics:
Graph, BFS,Matrix


Constraints
- \(1 \leq n,m \leq 500\) (check the exact constraints on your GFG version).
- grid[i][j] is either 0 or 1.
- Source and destination are valid matrix coordinates.


Expected Complexity
- Time Complexity: O(n times m)
- Space Complexity: O(n times m)

*/


#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>& grid, pair<int, int> source,
                 pair<int, int> destination) {

    int n = grid.size();
    int m = grid[0].size();

    // Check if source or destination is blocked
    if (grid[source.first][source.second] == 0 ||
        grid[destination.first][destination.second] == 0) {
        return -1;
    }

    // Distance matrix
    vector<vector<int>> dist(n, vector<int>(m, -1));

    queue<pair<int, int>> q;

    int sr = source.first;
    int sc = source.second;

    dist[sr][sc] = 0;
    q.push({sr, sc});

    // Four directions
    int directionOfRow[] = {1, -1, 0, 0};
    int directionOfColumn[] = {0, 0, 1, -1};

    while (!q.empty()) {

        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // Destination reached
        if (r == destination.first && c == destination.second) {
            return dist[r][c];
        }

        for (int i = 0; i < 4; i++) {

            int newRow = r + directionOfRow[i];
            int newColumn = c + directionOfColumn[i];

            // Boundary and blocked cell check
            if (newRow >= 0 && newColumn >= 0 &&
                newRow < n && newColumn < m &&
                grid[newRow][newColumn] == 1 &&
                dist[newRow][newColumn] == -1) {

                dist[newRow][newColumn] = dist[r][c] + 1;

                q.push({newRow, newColumn});
            }
        }
    }

    return -1;
}

int main() {

    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1}
    };

    pair<int, int> source = {0, 0};
    pair<int, int> destination = {2, 3};

    cout << "Shortest Path: "
         << shortestPath(grid, source, destination);

    return 0;
}
