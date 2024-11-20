#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u;
    int v;
    int w;
    Edge();
    Edge(int u, int v, int w);
    Edge(const Edge &e);
    bool operator<(const Edge &second);
    bool operator>(const Edge &second);
    bool operator==(const Edge &second);
    bool operator<=(const Edge &second);
    bool operator>=(const Edge &second);
};

class Graph {
    public:
        int n; // Number of vertices 
        std::vector<std::vector<Edge> > e; // Adjacent list 
    public:
        Graph(int n);
        ~Graph();
        void insertEdge(int u, int v, int w, bool directed = false);
        std::vector<Edge> exportEdges(); 
        

#ifdef DIJKSTRA
        std::vector<int> search(int start, int passBy, int destination);
        friend std::vector<int> searchShortestPath(Graph &G, int start, int passBy, int destination);
#endif

#ifdef PRIM 
        friend std::vector<Edge> constructMSTPrim(Graph G);
#endif

#if KRUSKAL
        friend std::vector<Edge> constructMSTKruskal(Graph G);
#endif
};

