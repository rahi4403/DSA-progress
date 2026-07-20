class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int count=0;
        int startRow=0;
        int startCol=0;
        int endRow=row-1;
        int endCol=col-1;
        int total=row*col;
        while(count<total){
            //this 1st loop is for printing the first/starting row
            for(int index=startCol;count<total && index<=endCol;index++){
                ans.push_back(matrix[startRow][index]);
                count++;
            }
                startRow++;//we do this so that we dont end up repeating the same row
                //this second for loop is to print the ending column
            for(int index=startRow;count<total && index<=endRow;index++){
                ans.push_back(matrix[index][endCol]); //only the row portion changes,the column number remains same
                count++;
            }
                endCol--;
                //the 3rd loop is to print the last row 
            for(int index=endCol;count<total && index>=startCol;index--){
                ans.push_back(matrix[endRow][index]);
                count++;
            }
                endRow--;
                //the 4th loop is to print the starting column now
            for(int index=endRow;count<total && index>=startRow;index--){
                ans.push_back(matrix[index][startCol]);
                count++;
            }
                startCol++;
        }
            return ans;
        }
};