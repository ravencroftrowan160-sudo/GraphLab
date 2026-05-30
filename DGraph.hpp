#ifndef DGRAPH_H
#define DGRAPH_H

#include <string>
using namespace std;

// Edge structure
struct Edge {
    string value;
    Edge* next;

    Edge(string v);
};

// Node structure
struct Node {
    string value;
    bool visited;
    Edge* adjList;

    Node();
};

class DGraph {
private:
    Node G[20];
    int M[20][20];
    int size;

    int findNode(string value);
    void resetVisited();
    void depthFirstHelper(int index, bool edge);

public:
    // Constructor
    DGraph();

    // Core functions
    void addNode(string value);
    void addEdge(string start, string end);
    void listNodes();
    void displayAdjacency();
    void displayMatrix();

    // Traversals
    void breadthFirst(string start, bool edge = false, bool unreachable = true);
    void depthFirst(string start, bool edge = false, bool unreachable = true);

    // Advanced
    void minTree(string start);
    void connectTable();
};

#endif