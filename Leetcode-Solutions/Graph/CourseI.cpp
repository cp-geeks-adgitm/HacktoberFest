class Solution {
public:
     class Edge{
        public:
        int u=0;
        Edge(int u)
        {
            this->u=u;
        }
    };
    vector<vector<Edge*> >graph;
   void addedge(int x,int y)
    { 
            
        graph[x].push_back(new Edge(y));
        
    }
    void display()
    {
        for(int i=0;i<graph.size();i++)
        {
            cout<<i<<"->";
            for(Edge* e:graph[i])
               { cout<<e->u<<",";}
            cout<<endl;
        }
        
    }
void construct(int numCourses, vector<vector<int>>& prerequisites){
       for(int i=0;i<numCourses;i++)
        {
            vector<Edge*>ar;
            graph.push_back(ar);
        }
        for(int i=0;i<prerequisites.size();i++)
        {
            addedge(prerequisites[i][0],prerequisites[i][1]);
        }
    }
   
  bool topological_(int src,vector<bool>&vis,vector<bool>&cycle)
    {
        vis[src]=true;
      cycle[src]=true;
       bool res=false;
        for(Edge* e:graph[src])
            {
                if(!vis[e->u]){
                   res=res|| topological_(e->u,vis,cycle);
                }
            else if(cycle[e->u])
            {
                return true;            }
        }
            
           cycle[src]=false;
      return res;
    }
  bool topological()
    {
        int n=graph.size();
       bool res=false;
        vector<bool>vis(n,false);
       vector<bool>cycle(n,false);
      
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
             res=res||topological_(i,vis,cycle);
        }
            return res;
       
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        construct(numCourses,prerequisites);             
          return !topological();
    }
       
};