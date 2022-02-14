// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 13/02/2022

#include <queue>
class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int rows = mat.size(), cols =mat[0].size();
        for(int i= 0 ; i < rows ; i++){
            for(int j= 0 ; j < cols ; j++){
                if(mat[i][j] == 1){
                    mat[i][j] = -1;
                }
            }        
        }
        for(int i= 0 ; i < rows ; i++){
            for(int j= 0 ; j < cols ; j++){
                if(mat[i][j] != 0){
                    setNearest(mat,i,j);
                }
            }        
        }
        for(int i= rows-1 ; i >= 0 ; i--){
            for(int j= cols-1 ; j >= 0 ; j--){
                if(mat[i][j] != 0){
                    setNearest(mat,i,j);
                }
            }        
        }
        return mat;
    }
    void setNearest(vector<vector<int>>& mat, int sr , int sc){
        int min;
            
        min = 999999;

        // left
        if(sc - 1 >= 0 )
        {
            if(mat[sr][sc-1] == 0)
            {
                mat[sr][sc] = 1;
                return;
            }    
            else if(mat[sr][sc-1] != -1)
            {
                if(mat[sr][sc-1] < min)
                    min = mat[sr][sc-1] ;
            }
        }     
        // up
        if(sr - 1 >= 0)
        {
            if(mat[sr-1][sc] == 0)
            {
                mat[sr][sc] = 1;
                return;
            }    
            else if(mat[sr-1][sc] != -1)
            {
                if(mat[sr-1][sc] < min)
                    min = mat[sr-1][sc];
            }
        }
        // right
        if(sc + 1 < mat[0].size()){
            if(mat[sr][sc+1] == 0)
            {
                mat[sr][sc] = 1;
                return;
            }    
            else if(mat[sr][sc+1] != -1)
            {
                if(mat[sr][sc+1] < min)
                    min = mat[sr][sc+1];
            }       
        }
        // down
        if(sr + 1 < mat.size()){
            if(mat[sr+1][sc] == 0)
            {
                mat[sr][sc] = 1;
                return;
            }    
            else if(mat[sr+1][sc] != -1)
            {
                if(mat[sr+1][sc] < min)
                    min = mat[sr+1][sc];
            }
        }
        if((min!=999999 && mat[sr][sc] == -1) || min < mat[sr][sc]){
            mat[sr][sc] = min + 1;
        }

        
    }

};


// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

 

// Example 1:


// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:


// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]