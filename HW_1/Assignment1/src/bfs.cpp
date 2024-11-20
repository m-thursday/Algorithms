#include <search.hpp>
#include <vector>


/*
To iterate over the adjancy nodes of u, you can use the following template code 
int numberOfAdjacencyNodes = G.e[u].size(); // Get number of adjancy nodes of u 
LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
    int v = p->value; // v is the adjvancy node of u
    // YOUR CODE HERE
}
*/


void bfs(Graph &G, int start, int destination, int passBy, std::vector<int> &path) {
    int N = G.n; // Number of nodes in the graph
    Queue<int> queue;
    Queue<int> queue1;
    std::vector<bool> visited(N,false);
    std::vector<int> trace(N,-1);
    int u;
    for(int i = 0; i < N; i++){
        visited[i] = false;
        trace[i] = -1;
        
    }

    queue.push(start);
    visited[start] =  true;
    while(queue.empty() != true){
        u = queue.pop();
        if(u == passBy){
            break;
        }
        int numberOfAdjacencyNodes = numberOfAdjacencyNodes = G.e[u].size(); // Get number of adjancy nodes of u 
        LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
            int v = p->value; // v is the adjvancy node of u
            if(!visited[v]){
                visited[v] = true;
                trace[v] = u;
                queue.push(v);
            }
        }
    }
    u = passBy;
    while(u != -1){
        path.insert(path.begin(),u);
        u = trace[u];
    }
    queue1.push(passBy);
    visited[passBy] = true;
    while(queue1.empty() != true){
        u = queue1.pop();
        if(u == destination){
            break;
        }
        int numberOfAdjacencyNodes = numberOfAdjacencyNodes = G.e[u].size(); // Get number of adjancy nodes of u 
        LinkedListNode<int> *p = G.e[u].getRoot(); // Get the head point of the linked list
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) { // iterate over each node
            int v = p->value; // v is the adjvancy node of u
            if(!visited[v]){
                visited[v] = true;
                trace[v] = u;
                queue1.push(v);
            }
        }
    }
    u = destination;
    while(u != -1){
        if(passBy>=path.size()){
            path.push_back(u);
        }
        else{
            path.insert(path.begin() + 1 + passBy,u);
        }
        //path.insert(path.begin() + 1 + passBy,u);
        u = trace[u];
    }

}
