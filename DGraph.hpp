#ifndef DGRAPH_H
#define DGRAPH_H

#include <string>
using namespace std;

// Edge structure
struct Edge {
    char value;
    Edge* next;

    Edge(char v);
};


// Node structure

struct Node {
    char value;
    bool visited;
    Edge* adjList;

    Node();
};


class DGraph {
private:
    Node G[20];
    int M[20][20];
    int size;

    int findNode(char value);
    void resetVisited();
    void depthFirstHelper(int index, bool edge, stringstream& ss);

public:
    // Constructor
    DGraph();
    ~DGraph();

    // Core functions
    
    void addNode(char value);
    void addEdge(char start, char end);
    string listNodes();
    string displayAdjacency();
    string displayMatrix();

    // Traversals
    string breadthFirst(char start, bool edge = false, bool unreachable = true);
    string depthFirst(char start, bool edge = false, bool unreachable = true);

    // Advanced
    string minTree(char start);
    string connectTable();
};

#endif