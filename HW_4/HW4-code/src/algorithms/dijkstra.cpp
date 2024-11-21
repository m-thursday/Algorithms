#include <graph.hpp>
#include <queue>
#include <climits>


vector<int> searchSinglePath(Graph &G, int start, int dest){
	int V = G.n;

	vector<int> distance(V, INT_MAX);
	vector<int> parent(V, -1);
	vector<bool> visited(V, 0);
	
	distance[start] = 0;
	
	for(int i = 0; i < V; i++){
		int u = -1;
		for(int v = 0; v < V; v++){
			if(!visited[v] && (u == -1 || distance[v] < distance[u])) {u = v;}
		}
		
		if (u == -1 || distance[u] == INT_MAX) {break;}
		
		visited[u] = 1;
		
		if (u == dest) {break;}
		
		for(const auto &edge : G.e[u]){
			int v = edge.v;
			int w = edge.w;
			if((distance[u] + w) < distance[v]){
				distance[v] = (distance[u] + w);
				parent[v] = u;
			}
		}
	}
	
	vector<int> path;
	int u = dest;
	while(u != -1){
		path.push_back(u);
		u = parent[u];
	}
	
	reverse(path.begin(), path.end());
	return path;
}

vector<int> searchShortestPath(Graph &G, int start, int passBy, int destination) { 
	vector<int> start_to_mid = searchSinglePath(G, start, passBy);
	
	vector<int> mid_to_dest = searchSinglePath(G, passBy, destination);
	
	vector<int> path_of_destiny = start_to_mid;
	path_of_destiny.insert(path_of_destiny.end(), mid_to_dest.begin() + 1, mid_to_dest.end());
	
	return path_of_destiny;
}


