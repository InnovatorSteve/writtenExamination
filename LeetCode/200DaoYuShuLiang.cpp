#include <iostream>
#include <vector>
using namespace std;

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        grid[i][j] == '0';
        if(grid[i][j] == '1'){
            dfs(grid, i + 1, j);
            dfs(grid, i - 1, j);
            dfs(grid, i, j + 1);
            dfs(grid, i, j - 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int nums_islands = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == '1'){
                       dfs(grid, i, j);
                       nums_islands++; 
                }
            }
        }
        return nums_islands;
    }

int main()
{
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << numIslands(grid) << endl;
    return 0; 
}