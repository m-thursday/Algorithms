#include <graph.hpp> 
#include <sort.hpp> 
#include <queue>
#include <climits>

using namespace std;

std::vector<Edge> constructMSTPrim(Graph G) {

	vector<Edge> edges = G.exportEdges();
	vector<Edge> MST;
	
	vector<int> distance(G.n,INT_MAX); // distance to partial tree
	vector<int> parent(G.n,-1); // parent node of vertex
	vector<bool> visited(G.n,false); // tracking vector
	
	distance[0] = 0; // 0 is arbitrary starting vector
	parent[0] = 0;
	
	bool done = false;
	
	while(!done){
	//check for new edges
	for (int i = 0; i < G.n; ++i) {
		if (visited[i]) {
		    for (const auto &edge : G.e[i]) { // Iterate over adjacency list
		        if (!visited[edge.v] && edge.w < distance[edge.v]) {
		            distance[edge.v] = edge.w;
		            parent[edge.v] = i;
		        }
		    }
		}
	}
	
	int minDistance = INT_MAX;
	int u = -1;
	
	for(int v = 0; v < G.n; v++){
		if(visited[v] == 0 && distance[v] < minDistance){
			minDistance = distance[v];
			u = v;
		}
	}
		
	// Terminating Conditions
	if (u == -1){
		break;
	}
		
	visited[u] = 1;
	Edge m(parent[u], u, distance[u]);
	MST.push_back(m);
	
	if(sizeof(MST) == G.n - 1){
		done = true;
	} 	
	
	}
	return MST;
}

