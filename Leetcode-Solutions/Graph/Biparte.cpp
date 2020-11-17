class Solution {
public:
    class Edge{
      public:
        int u;
        Edge(int u){
            this->u=u; }
    };
    vector<vector<Edge*>>graph;
    void add(int u,int v){
        graph[u].push_back(new Edge(v));
    }
    bool biparte(int src,vector<int>& vis){
        queue<pair<int,int>>que;
        que.push({src,0});
        while(que.size()>0){
            pair<int,int>top=que.front();
            que.pop();
        if(vis[top.first]!=-1){
            if(vis[top.first]!=top.second){
                // cout<<top.first;
                return false;
            }
            continue;
        }
            vis[top.first]=top.second;
            for(Edge* e:graph[top.first]){
                if(vis[e->u]==-1)
                que.push({e->u,(top.second+1)%2});
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& gr) {
        int n=gr.size();
        for(int i=0;i<n;i++){
            vector<Edge*>ar;
            graph.push_back(ar);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<gr[i].size();j++){
            add(i,gr[i][j]);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<i<<"->";
        //     for(Edge* e:graph[i]){
        //         cout<<e->u<<",";
        //     }
        //     cout<<endl;
        // }
        vector<int>vis(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
               ans=biparte(i,vis);
                if(!ans)
                    // cout<<" "<<i;
                    return false;
            }
        }
        return true;
    }
};