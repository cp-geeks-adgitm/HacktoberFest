class Solution {
public:
    bool valid(int x,int y,int n,int m){
        if(x<0||y<0||x>=n||y>=m)
            return false;
        return true;
    }
    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    class dpair{
      public:
        int x,y,t;
        dpair(int x,int y,int t){
            this->x=x;
            this->y=y;
            this->t=t;
        }
    };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<dpair*>que;
        int n=grid.size(),m=grid[0].size(),count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    count++;
                else if(grid[i][j]==2)
                    que.push(new dpair(i,j,0));
            }
        }
        int ans=0;
        while(que.size()>0){
            dpair* top=que.front();
            que.pop();
            ans=top->t;
              for(int d=0;d<4;d++){
                int x=top->x+dir[d][0];
                int y=top->y+dir[d][1];
                if(valid(x,y,n,m) && grid[x][y]==1){
                    count--;
                    grid[x][y]=2;
                    que.push(new dpair(x,y,top->t+1));
           }
       }
    }
        return count==0?ans:-1;
 }
};