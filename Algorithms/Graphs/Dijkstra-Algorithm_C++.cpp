// Dijkstra's algorithm for finding shortest path in a weighted graph.
// I've used STL to implement the Dijkstra's Algorithm

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <climits>
#include <set>

using namespace std;

class Graph{

	unordered_map<int,list<pair<int,int> > > adjList;	

public:
	Graph(){}

	void addEdge(int u,int v,int weight,bool bidir = true){
		adjList[u].push_back(make_pair(v,weight));

		if(bidir){
			adjList[v].push_back(make_pair(u,weight));
		}
	}

	void display(){
		for(auto node:adjList){
			cout<<node.first<<" -> ";

			for(auto val:node.second){
				cout<<"( "<<val.first<<" ,"<<val.second<<" ) ,";
			}
			cout<<endl;
		}
	}

	void dijkstra(int src){

		set<pair<int,int> > s;
		unordered_map<int,int> dist;

		for(auto node:adjList){
			dist[node.first] = INT_MAX;
		}

		dist[src] = 0;

		s.insert(make_pair(0,src));

		while(!s.empty()){

			auto val = *(s.begin());

			int node = val.second;
			int nodeDist = val.first;

			s.erase(s.begin());

			for(auto neighbor:adjList[node]){

				if(nodeDist + neighbor.second < dist[neighbor.first]){

					int destination = neighbor.first;

					auto exist = s.find(make_pair(dist[destination],destination));

					if(exist!=s.end()){
						s.erase(exist);
					}

					dist[destination] = nodeDist + neighbor.second;
					s.insert(make_pair(dist[destination],destination));

				}

			}
		}

		for(auto node:dist){
			cout<<"Node "<<node.first<<" with the distance "<<node.second<<endl;
		}
	}
};

int main(){

	Graph g;

	
	g.addEdge(1,3,4);
	g.addEdge(2,3,2);
	g.addEdge(1,4,7);
	g.addEdge(1,2,1);
	g.addEdge(3,4,2);

	g.display();
	g.dijkstra(1);

	return 0;
}