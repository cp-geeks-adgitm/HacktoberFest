#include <iostream>
#include <algorithm>
using namespace std;
int row = 10;
int col = 10;

bool isValid(int arr[10][10],int i,int j,bool isVisited[10][10])
{
    return i>=0 && j>=0 && i<row && j<col && arr[i][j] == 1 && !isVisited[i][j];
}

int shortestpath(int arr[10][10],int i,int j,int x,int y,bool isVisited[10][10])
{
    if(!isValid(arr,i,j,isVisited))
        return  999999999;
    if(i==x && j==y) return 0;
    isVisited[i][j] = true;
    int left = shortestpath(arr,i,j-1,x,y,isVisited) + 1;
    int bottom = shortestpath(arr,i+1,j,x,y,isVisited) + 1;
    int right = shortestpath(arr,i,j+1,x,y,isVisited) + 1;
    int top = shortestpath(arr,i-1,j,x,y,isVisited) + 1;
    isVisited[i][j] = false;
    return min(min(left,bottom),min(right,top));

}

int backtracking(int arr[10][10],int i,int j,int x,int y)
{
    bool isVisited[10][10];
    return shortestpath(arr,i,j,x,y,isVisited);
}


int main()
{
    int arr[10][10] =
    {
        {1,1,1,1,1,0,0,1,0,1},
        {0,1,1,1,1,1,1,1,0,1},
        {0,1,1,1,1,1,0,1,0,0},
        {0,1,1,1,1,1,0,1,0,0},
        {1,1,1,1,0,1,0,1,0,1},
        {0,1,1,1,1,1,0,1,0,1},
        {0,1,1,1,1,0,0,1,0,0},
        {0,1,1,1,1,1,0,1,1,1},
        {1,0,1,1,0,1,0,1,0,1},
        {0,1,1,0,1,0,0,1,0,1},
    };
    int result = backtracking(arr,0,0,0,1);
    if(result<999999999)
        cout<<result<<endl;
    else
        cout<<"No path found"<<endl;
}
