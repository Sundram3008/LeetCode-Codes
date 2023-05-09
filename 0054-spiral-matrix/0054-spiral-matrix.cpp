class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r= matrix.size() , c= matrix[0].size();
        int row_start=0, row_end= r-1, column_start=0, column_end= c-1;
    vector<int> v;
    while(row_start<= row_end && column_start <= column_end){
        for(int col= column_start ; col<=column_end; col++){
            v.push_back(matrix[row_start][col]);
        }
        row_start++;
         for(int row= row_start ; row<=row_end; row++){
            v.push_back(matrix[row][column_end]);
        }
        column_end--;
          if(row_start<=row_end)
    {
    
        for(int col=column_end;col>=column_start;col--)
        {
            v.push_back(matrix[row_end][col]);
        }
    }
        row_end--;

  if(column_start<=column_end)
    {

        for(int row=row_end;row>=row_start;row--)
        {
            v.push_back(matrix[row][column_start]);
        }
    }
        column_start++;
    }
    return v;
    }
};