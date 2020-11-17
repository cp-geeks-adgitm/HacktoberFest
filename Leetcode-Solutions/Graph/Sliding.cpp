class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int,vector<int>>map;
        map[0]={1,3};
        map[1]={0,2,4};
        map[2]={1,5};
        map[3]={0,4};
        map[4]={1,3,5};
        map[5]={2,4};
        queue<pair<string,int>>que;
        string s="";
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s+=to_string(board[i][j]);
            }
        }
        // cout<<s<<endl;
        string target="123450";
        unordered_set<string>set;
        que.push({s,0});
        while(que.size()>0){
            pair<string,int>top=que.front();
            que.pop();
            // cout<<top.first<<"-"<<top.second;
            if(top.first==target)
                return top.second;
            if(set.find(top.first)!=set.end())
                continue;
            set.insert(top.first);
           for(int i=0;i<top.first.length();i++){
               if(top.first[i]!='0')
                   continue;
               for(int j:map[i]){
                   string t=top.first;
                   char ch=t[j];
                   t[i]=ch;
                   t[j]='0';
                   // cout<<" "<<t;
                   if(set.find(t)==set.end())
                   que.push({t,top.second+1});
               }
           }
            // cout<<endl;
        }
        return -1;
    }
};