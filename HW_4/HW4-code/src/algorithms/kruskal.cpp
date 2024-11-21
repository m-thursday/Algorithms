#include <graph.hpp> 
#include <sort.hpp> 
#include <disjointSet.hpp>


std::vector<Edge> constructMSTKruskal(Graph G) {
    vector<Edge> edges = G.exportEdges(); // Graph's edges
    vector<Edge> MST; // Create the minimum spanning tree
      
    sort(edges, 0, edges.size() - 1); // generate sorted list of edges by weight
    
    DisjointSet dset(G.n); // create the disjoint set 
    
    for(const auto &e : edges){
    	int u = e.u;
    	int v = e.v;
    	
    	if(dset.isOnSameSet(u,v) == 0){
    		MST.push_back(e);
    		dset.join(u,v);
    	}
    }
    
    return MST;
}


