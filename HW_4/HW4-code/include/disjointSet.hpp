#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <graph.hpp>

using namespace std;

class DisjointSet {
	private:
		vector<int> parent;
		int find(int u);
		
	public:
		DisjointSet(int n);
		int isOnSameSet(int u, int v);
		void join(int u, int v);

};

#endif
