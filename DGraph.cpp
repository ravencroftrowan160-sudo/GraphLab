#include "DGraph.h"
#include <iostream>
#include <queue>
using namespace std;

// ===== Edge Constructor =====
Edge::Edge(string v) {
    value = v;
    next = nullptr;
}

// ===== Node Constructor =====
Node::Node() {
    value = "";
    visited = false;
    adjList = nullptr;
}

// ===== DGraph Constructor =====
DGraph::DGraph() {
    size = 0;

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            M[i][j] = 0;
        }
    }
}

// ===== Helper Functions =====
int DGraph::findNode(string value) {
    for (int i = 0; i < size; i++) {
        if (G[i].value == value) {
            return i;
        }
    }
    return -1;
}

void DGraph::resetVisited() {
    for(int i = 0; i < size - 1; i++){
        G[i].visited = false;
    }
}