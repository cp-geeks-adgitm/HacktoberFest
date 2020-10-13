/*Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.*/
#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges,int n,int sv,bool* visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty())
    {
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for(int i=0;i<n;i++)
        {
            if(i==currentVertex)
            {
                continue;
                
            }
        	if(edges[currentVertex][i] ==1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
        
    }
    
}

void BFS(int** edges,int n)
{
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i]){
            printBFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}

int main() {
    int n, e;
    cin >> n >> e;

    int **edges=new int*[n];
    //intialization
    for(int i=0;i<n;i++){
      edges[i]=new int[n];
      for(int j=0;j<n;j++)
        edges[i][j]=0;
    }

    for(int i=0;i<e;i++){
      int f,s;
      cin>>f>>s;
      edges[f][s]=1;
      edges[s][f]=1;
    }
    BFS(edges,n);
    for(int i=0;i<n;i++)
      delete [] edges[i];
    
    delete [] edges;
}
