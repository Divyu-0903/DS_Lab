#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector< vector<int> >& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int minutes = 0;
    
    vector< pair<int, int> > directions;
    directions.push_back(make_pair(1, 0));
    directions.push_back(make_pair(-1, 0));
    directions.push_back(make_pair(0, 1));
    directions.push_back(make_pair(0, -1));
    
    queue< pair<int, int> > rotten;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                rotten.push(make_pair(i, j));
            }
        }
    }
    
    while (!rotten.empty()) {
        int numRotten = rotten.size();
        bool changed = false;
        
        for (int i = 0; i < numRotten; ++i) {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();
            
            for (int k = 0; k < directions.size(); ++k) {
                int newX = x + directions[k].first;
                int newY = y + directions[k].second;
                
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    rotten.push(make_pair(newX, newY));
                    changed = true;
                }
            }
        }
        
        if (changed) {
            minutes++;
        }
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    
    return minutes;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector< vector<int> > grid(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int result = orangesRotting(grid);
    cout << result << endl;
    
    return 0;
}
