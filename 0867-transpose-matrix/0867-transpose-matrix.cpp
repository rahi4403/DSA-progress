class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> ans(col,vector<int>(row));//we are creating a matrix with col number of rows,because after transpose,the number of rows is going to be the columns,so we need to make space for it. The second input is having a row vector with row columns.
        //example: if it is ans(A,vector<int> (B)) is A rows with B columns 
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans[j][i]=matrix[i][j];
            }
        }
        return ans;
    }
};