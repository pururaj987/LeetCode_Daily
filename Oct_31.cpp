https://leetcode.com/problems/toeplitz-matrix/description/

Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 1 && n == 1) {
            return true;
        }
        for(int i = 1 ; i < m ; ++i) {
            for(int j = 1 ; j < n ; ++j) {
                if(matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};