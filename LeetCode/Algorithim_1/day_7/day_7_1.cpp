// Language C++
// Author : Kamel Mohsen Kamel 
// Date : 09/02/2022

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        floodFillR(image, sr, sc, newColor,image[sr][sc]);
        return image;
        cout<<endl;
    }
    void floodFillR(vector<vector<int>>& image, int sr, int sc, int newColor,int orval) {

        // To mark the pixel as visited
        image[sr][sc] = -1;        
        
      
        // left
        if(sc - 1 >= 0 && image[sr][sc-1] == orval)
            floodFillR(image, sr, sc-1, newColor,orval);   
        // up
        if(sr - 1 >= 0 && image[sr-1][sc] == orval)
            floodFillR(image, sr-1, sc, newColor,orval);
        // right
        if(sc + 1 < image[0].size() && image[sr][sc+1] == orval)
            floodFillR(image, sr, sc+1, newColor,orval);   
        // down
        if(sr + 1 < image.size() && image[sr+1][sc] == orval)
            floodFillR(image, sr+1, sc, newColor,orval);        
        
        // This set the original pixel with the new color
        image[sr][sc] = newColor;   
        return;
    }
};



// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

// Return the modified image after performing the flood fill.

 

// Example 1:


// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
// Example 2:

// Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
// Output: [[2,2,2],[2,2,2]]
 