#include <graph.hpp>

Edge::Edge() {};
Edge::Edge(int u, int v, int w) {
    this->u = u;
    this->v = v;
    this->w = w;
}

Edge::Edge(const Edge &e) {
    this->u = e.u;
    this->v = e.v;
    this->w = e.w;
}

bool Edge::operator<(const Edge &second) {
    return this->w < second.w;
}

bool Edge::operator>(const Edge &second) {
    return this->w > second.w;
}

bool Edge::operator==(const Edge &second) {
    return this->w == second.w;
}

bool Edge::operator>=(const Edge &second) {
    return this->w >= second.w;
}

bool Edge::operator<=(const Edge &second) {
    return this->w <= second.w;
}


Graph::Graph(int n) {
    this->n = n;
    this->e = std::vector<std::vector<Edge> >(n, std::vector<Edge>());
}

Graph::~Graph() {
    this->e.clear();
}

std::vector<Edge> Graph::exportEdges() {
    std::vector<Edge> edges;
    for (int u = 0; u < this->n; ++u) {
        for (int i = 0; i < this->e[u].size(); i += 1)
            edges.push_back(Edge(this->e[u][i])); 
    }
    return edges;
}

void Graph::insertEdge(int u, int v, int w, bool directed) {
    this->e[u].push_back(Edge(u, v, w));
    if (not directed)
        this->e[v].push_back(Edge(v, u, w));
}

#ifdef DIJKSTRA
std::vector<int> Graph::search(int start, int passBy, int destination) {
    return searchShortestPath(*this, start, passBy, destination); 
}
#endif
