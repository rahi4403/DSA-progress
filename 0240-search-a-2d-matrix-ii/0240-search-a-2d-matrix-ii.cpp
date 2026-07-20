class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowIndex=0;
        int colIndex=col-1; //for the last column
        while(rowIndex<row && colIndex>=0){
            int element=matrix[rowIndex][colIndex];
            if(element==target){
                return 1;
            }
            if(element<target){
                rowIndex++; //start=mid+1 analogy applied
            }
            else{
                colIndex--; //end=mid-1 analogy applied
            }
        }
        return 0;
    }
};