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

void dfs(Graph &G, int start, int destination, int numberOfBuilding, std::vector<int> &path) {
    int N = G.n; // Number of nodes in the graph
    // YOUR CODE HERE
    int u = 0;
    std::vector<bool> visited(N,false);
    std::vector<int> trace(N,-1);
    Stack<int> stack;
    for(int i = 0; i < N; i++){
        visited[i] = false;
        trace[i] = -1;
    }
    stack.push(start);
    visited[start] = true;
    while(stack.empty() == false){
        u = stack.pop();
        if(u == destination){
            break;
        }
        if (path.size() >= numberOfBuilding) {
            path.pop_back();  
            visited[u] = false; 
        }
        int numberOfAdjacencyNodes = numberOfAdjacencyNodes = G.e[u].size(); // Get number of adjancy nodes of u 
        LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
            int v = p->value; // v is the adjvancy node of u
            if(!visited[v]){
                visited[v] = true;
                trace[v] = u;
                stack.push(v);
            }
        }
    }
    u = destination;
    while(u != -1){
        path.insert(path.begin(),u);
        u = trace[u];
    }
}
