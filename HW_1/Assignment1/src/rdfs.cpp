#include <search.hpp>
/*
To iterate over the adjancy nodes of u, you can use the following template code 
int numberOfAdjacencyNodes = G.e[u].size(); // Get number of adjancy nodes of u 
LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
    int v = p->value; // v is the adjvancy node of u
    // YOUR CODE HERE
}
*/
int DFS (int u, Graph &G, std::vector<int> &path, std::vector<int> &visited, int destination, int numberOfBuilding){

    
    
    path.push_back(u);
    
    visited[u] = true;

    if (u == destination){
        return 1;
    }
    if (path.size() >= numberOfBuilding) {
        path.pop_back();  
        visited[u] = false;
        return 0;  
    }
    int numberOfAdjacencyNodes = G.e[u].size(); // Get number of adjancy nodes of u 
    LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
    for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
        int v = p->value; // v is the adjvancy node of u
        if (!visited[v]){
            
            int flag = DFS (v, G, path, visited, destination, numberOfBuilding);
            if (flag == 1){
                return 1;
            }
        }
    }
    path.pop_back();
    visited[u] = false;
    return 0;
}

void rdfs (Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {

    int N = G.n; // Number of nodes in the graph
    std::vector<int> visited(N, false);
    std::vector<int> Distance(N, -1);
    for (int u = 0; u < N; u++){
        visited[u] = false;
    }
    DFS (start, G, path, visited, destination, numberOfBuilding);
}

