#include<bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

void printShortest(int dist[][V]);

void floydWarshall(int graph[][V])
{   
    //dist will store shortest distances between the vertices
    int dist[V][V];

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            dist[i][j] = graph[i][j];
    
    for(int k=0; k<V; k++)
    {
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    printShortest(dist);
}

void printShortest(int dist[][V])
{
    cout<<"Matrix with the shortest distance between all the pairs of vertices: \n";
    for(int i=0; i<V; i++)
    {    for(int j=0; j<V; j++)
        {
            if(dist[i][j] == INF)
                cout<<"INF"<<" ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(void)
{  
    int graph[V][V];

    //Enter 99999 to enter infinity, that denotes absence of edge between the two vertices
    for(int i=0; i<V; i++)
    {   for(int j=0; j<V; j++)
            cin>>graph[i][j];
        cout<<"\n";
    }
    floydWarshall(graph);
}