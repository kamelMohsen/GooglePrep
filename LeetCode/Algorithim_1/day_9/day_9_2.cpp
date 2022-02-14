// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 13/02/2022

#include <queue>
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> rottenQ; // rotten Queue
        int nonRotten = 0;
        int nMins = 0; // needed minutes
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(grid[i][j] ==2){
                    rottenQ.push(i);
                    rottenQ.push(j);                    
                }else if(grid[i][j] ==1){
                    nonRotten++;
                }
            }
        }
        int rSize = 0; // rotten size
        int x,y;
        while(true){
            rSize = rottenQ.size();
            if(nonRotten == 0 || rSize==0) break;
            for(int i = 0 ; i < rSize/2; i++){
                x = rottenQ.front();rottenQ.pop();
                y = rottenQ.front();rottenQ.pop();
                rotOranges(grid,rottenQ,x,y,nonRotten);
            }
            nMins++;
        }
        if(nonRotten>0) return -1;
        return nMins;
    }
    
    void rotOranges(vector<vector<int>>& grid,queue<int>& rottenQ,int sr, int sc,int &nonRotten) {

        // left
        if(sc - 1 >= 0 && grid[sr][sc-1] == 1){
            nonRotten--;
            grid[sr][sc-1] = 2;
            rottenQ.push(sr);
            rottenQ.push(sc-1);
        }
        // up
        if(sr - 1 >= 0 && grid[sr-1][sc] == 1)
        {
            nonRotten--;
            grid[sr-1][sc] = 2;
            rottenQ.push(sr-1);
            rottenQ.push(sc);            
        }
        // right
        if(sc + 1 < grid[0].size() && grid[sr][sc+1] == 1)
        {
            nonRotten--;
            grid[sr][sc+1] = 2;
            rottenQ.push(sr);
            rottenQ.push(sc+1);            
        }
        // down
        if(sr + 1 < grid.size() && grid[sr+1][sc] == 1)
        {
            nonRotten--;
            grid[sr+1][sc] = 2;
            rottenQ.push(sr+1);
            rottenQ.push(sc);
        }      
    }
    
};






// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.