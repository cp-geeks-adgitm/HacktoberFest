class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int n=routes.size();
        unordered_map<int,vector<int>>map;
        unordered_map<int,bool>bus;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].size();j++){
                if(map.find(routes[i][j])==map.end()){
                    vector<int>arr;
                    map[routes[i][j]]=arr;
                }
                map[routes[i][j]].push_back(i);
                bus[routes[i][j]]=false;
            }
        }
        queue<pair<int,int>>que;
        que.push({S,0});
        bus[S]=true;
        while(que.size()>0){
            pair<int,int>top=que.front();
            que.pop();
            if(top.first==T)
                return top.second;            
        for(int i:map[top.first]){
            if(!vis[i]){
                vis[i]=true;
                for(int j=0;j<routes[i].size();j++){
                    if(!bus[routes[i][j]]){
                        bus[routes[i][j]]=true;
                        que.push({routes[i][j],top.second+1});
                    }
                }
            }
        }
    }
        return -1;
    }
};