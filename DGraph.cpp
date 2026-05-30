#include "DGraph.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <sstream>  // add this at top
using namespace std;

// ===== Edge Constructor =====
Edge::Edge(char v) {
    value = v;
    next = nullptr;
}

Node::Node() {
    value = '\0';   // null character instead of ""
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

DGraph::~DGraph() {
    for (int i = 0; i < size; i++) {
        Edge* temp = G[i].adjList;

        while (temp != nullptr) {
            Edge* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }

        G[i].adjList = nullptr;
    }
}

// ===== Helper Functions =====
int DGraph::findNode(char value) {
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

void DGraph::depthFirstHelper(int index, bool edge, stringstream& ss) {
    // mark current node as visited
    G[index].visited = true;

    // traverse adjacency list
    Edge* temp = G[index].adjList;

    while (temp != nullptr) {
        int neighborIndex = findNode(temp->value);

        // only visit unvisited neighbors
        if (!G[neighborIndex].visited) {

            // print based on edge flag
            if (edge) {
                ss << G[index].value << "-" << G[neighborIndex].value << " ";
            } else {
                ss << G[neighborIndex].value << " ";
            }

            // recursive call (CRITICAL for correct DFS order)
            depthFirstHelper(neighborIndex, edge, ss);
        }

        temp = temp->next;
    }
}



// ===== Core Functions =====

void DGraph::addNode(char value) {
    if (size >= 20) {
        throw runtime_error("Graph full");
    }

    G[size].value = value;
    G[size].visited = false;
    G[size].adjList = nullptr;

    size++;
}


void DGraph::addEdge(char start, char end) {
    int s = findNode(start);
    int e = findNode(end);

    // Error check
    if (s == -1 || e == -1 || s == e) {
        throw runtime_error("Invalid edge");
    }

    // Create new edge
    Edge* newEdge = new Edge(end);

    // Add to adjacency list (at the end)
    if (G[s].adjList == nullptr) {
        G[s].adjList = newEdge;
    } else {
        Edge* temp = G[s].adjList;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newEdge;
    }

    // Update adjacency matrix
    M[s][e] = 1;
}





string DGraph::listNodes() {
    string result = "";

    for (int i = 0; i < size; i++) {
        result += G[i].value;
        result += " ";
    }

    return result;
}

string DGraph::displayAdjacency() {
    stringstream ss;

    for(int i = 0; i < size; i++) {
        ss << G[i].value << ": ";

        Edge* temp = G[i].adjList;

        while (temp != nullptr) {
            ss << temp->value << " ";
            temp = temp->next;
        }

        ss << "\n";
    }

    return ss.str();
}

string DGraph::displayMatrix() {
    stringstream ss;

    // header row
    ss << "   ";
    for (int i = 0; i < size; i++) {
        ss << G[i].value << " ";
    }
    ss << "\n";

    // matrix rows
    for (int i = 0; i < size; i++) {
        ss << G[i].value << " ";

        for (int j = 0; j < size; j++) {
            if (M[i][j] == 0)
                ss << ". ";
            else
                ss << "1 ";
        }
        ss << "\n";
    }

    return ss.str();
}


// ===== Traversals =====

string DGraph::breadthFirst(char start, bool edge, bool unreachable) {
    resetVisited();

    int s = findNode(start);
    if (s == -1) return "";

    stringstream ss;

    queue<int> q;
    q.push(s);
    G[s].visited = true;

    ss << G[s].value << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        Edge* temp = G[current].adjList;

        while (temp != nullptr) {
            int neighborIndex = findNode(temp->value);

            if (!G[neighborIndex].visited) {
                G[neighborIndex].visited = true;
                q.push(neighborIndex);

                if (edge) {
                    ss << G[current].value << "-"
                       << G[neighborIndex].value << " ";
                } else {
                    ss << G[neighborIndex].value << " ";
                }
            }

            temp = temp->next;
        }
    }

    if (unreachable) {
        ss << "with ";
        for (int i = 0; i < size; i++) {
            if (!G[i].visited) {
                ss << G[i].value << " ";
            }
        }
        ss << "unreachable ";
    }

    return ss.str();
}

string DGraph::depthFirst(char start, bool edge, bool unreachable) {
    resetVisited();

    int s = findNode(start);
    if (s == -1) return "";

    stringstream ss;

    ss << G[s].value << ": ";

    depthFirstHelper(s, edge, ss);

    if (unreachable) {
        ss << "with ";
        for (int i = 0; i < size; i++) {
            if (!G[i].visited) {
                ss << G[i].value << " ";
            }
        }
        ss << "unreachable";
    }

    return ss.str();
}

// ===== Advanced =====
string DGraph::minTree(char start) {
    return depthFirst(start, true, false);
}


string DGraph::connectTable() {
    stringstream ss;

    for (int i = 0; i < size; i++) {
        resetVisited();

        ss << G[i].value << ": ";

        queue<int> q;
        q.push(i);
        G[i].visited = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            Edge* temp = G[current].adjList;

            while (temp != nullptr) {
                int neighborIndex = findNode(temp->value);

                if (!G[neighborIndex].visited) {
                    G[neighborIndex].visited = true;
                    q.push(neighborIndex);

                    ss << G[neighborIndex].value << " ";
                }

                temp = temp->next;
            }
        }

        ss << "\n";
    }

    return ss.str();
}
