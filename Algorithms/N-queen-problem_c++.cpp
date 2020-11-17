#include <iostream>
#define N 8
using namespace std;

bool isSafe(int chess[][N],int row,int col)
{
    for(int i=0;i<col;i++)
    {
        if(chess[row][i]==1)
            return false;
    }
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(chess[i][j]==1)
            return false;
    }
    for(int i=row,j=col;j>=0&&i<N;i++,j--)
    {
        if(chess[i][j]==1)
            return false;
    }
    return true;
}

bool NQueenProblem(int chess[][N],int col)
{
    if(col==N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<chess[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int row=0;row<N;row++)
    {
        if(isSafe(chess,row,col))
        {
            chess[row][col] = 1;
            bool NextQueencanbeplaced = NQueenProblem(chess,col+1);
            if(NextQueencanbeplaced)
            {
                return true;
            }
            chess[row][col]=0;
        }
    }
    return false;
}

int main()
{
    int chess[N][N] = {0};
    if(!NQueenProblem(chess,0))
        cout<<"Not possible"<<endl;
}
