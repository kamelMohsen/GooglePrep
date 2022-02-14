// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 09/02/2022

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        int count;
        for(int i =0 ; i < grid.size();i++){

            for(int j =0 ; j < grid[0].size();j++){
                count = 0;
                if(grid[i][j] == 1)  
                  getCountR(grid,i,j,count);
                if(count>max)
                    max = count;
            }   
        }
        return max;
    }
        void getCountR(vector<vector<int>>& grid, int sr, int sc,int &count) {

        // To mark the pixel as visited
        grid[sr][sc] = -1;        
        count++;
        // left
        if(sc - 1 >= 0 && grid[sr][sc-1] == 1)
            getCountR(grid, sr, sc-1,count);   
        // up
        if(sr - 1 >= 0 && grid[sr-1][sc] == 1)
            getCountR(grid, sr-1, sc,count);
        // right
        if(sc + 1 < grid[0].size() && grid[sr][sc+1] == 1)
            getCountR(grid, sr, sc+1,count);   
        // down
        if(sr + 1 < grid.size() && grid[sr+1][sc] == 1)
            getCountR(grid, sr+1, sc,count);        
    }
};



// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

 

// Example 1:


// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0