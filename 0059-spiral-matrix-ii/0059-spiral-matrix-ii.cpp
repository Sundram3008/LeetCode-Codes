class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r=n , c= n,cnt=1;
        int row_start=0, row_end= r-1, column_start=0, column_end= c-1;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    while(row_start<= row_end && column_start <= column_end){
        for(int col= column_start ; col<=column_end; col++){
            matrix[row_start][col]=cnt;
            cnt++;
        }
        row_start++;
         for(int row= row_start ; row<=row_end; row++){
            matrix[row][column_end]=cnt;
            cnt++;
        }
        column_end--;
        if(row_start<=row_end)
        {
        for(int col=column_end;col>=column_start;col--)
        {
            matrix[row_end][col]=cnt;
            cnt++;
        }
    }
        row_end--;

  if(column_start<=column_end)
    {

        for(int row=row_end;row>=row_start;row--)
        {
            matrix[row][column_start]=cnt;
            cnt++;
        }
    }
        column_start++;
    }
    return matrix;
    }
};