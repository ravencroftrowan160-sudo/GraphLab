//
//  main.cpp
//  CS 260 Lab 8
//
//  Created by Jim Bailey on June 2, 2020.
//  with modifications by Tina Majchrzak
//  Licensed under a Creative Commons Attribution 4.0 International License.
//

#include <iostream>

#include "DGraph.hpp"

#define BASE_LAB
#define MIN_TREE
#define CONNECT

int main() {
  std::cout << "Creating a directed graph, adding nodes and edges\n\n";

  // create the graph
  DGraph graph;

  // add nodes
  graph.addNode('A');
  graph.addNode('C');
  graph.addNode('T');
  graph.addNode('Z');
  graph.addNode('X');
  graph.addNode('K');
  graph.addNode('Q');
  graph.addNode('J');
  graph.addNode('M');
  graph.addNode('U');

  // add some directed edges
  graph.addEdge('A', 'T');
  graph.addEdge('A', 'Z');
  graph.addEdge('A', 'C');
  graph.addEdge('T', 'Q');
  graph.addEdge('Z', 'X');
  graph.addEdge('C', 'X');
  graph.addEdge('C', 'K');
  graph.addEdge('Q', 'J');
  graph.addEdge('X', 'C');
  graph.addEdge('K', 'X');
  graph.addEdge('J', 'M');
  graph.addEdge('K', 'Q');
  graph.addEdge('U', 'M');

#ifdef BASE_LAB
  std::cout << "Now testing base lab functionality " << std::endl << std::endl;

  std::cout << "The list of nodes \n expected: A C T Z X K Q J M U"
            << std::endl;
  std::cout << " actually: " << graph.listNodes() << std::endl << std::endl;

  std::cout << "The graph adjacency lists are " << std::endl;
  std::cout << "Expected\nA: T Z C\nC: X K\nT: Q\nZ: X\nX: C\nK: X Q\nQ: J\nJ: "
               "M\nM: \nU: M\n";
  std::cout << "\nActual\n";
  std::cout << graph.displayAdjacency() << std::endl;

  std::cout << "The graph adjacency matrix is" << std::endl;
  std::cout << "Expected\n     A   C   T   Z   X   K   Q   J   M   U";
  std::cout << "\n A   .   1   1   1   .   .   .   .   .   .";
  std::cout << "\n C   .   .   .   .   1   1   .   .   .   .";
  std::cout << "\n T   .   .   .   .   .   .   1   .   .   .";
  std::cout << "\n Z   .   .   .   .   1   .   .   .   .   .";
  std::cout << "\n X   .   1   .   .   .   .   .   .   .   .";
  std::cout << "\n K   .   .   .   .   1   .   1   .   .   .";
  std::cout << "\n Q   .   .   .   .   .   .   .   1   .   .";
  std::cout << "\n J   .   .   .   .   .   .   .   .   1   .";
  std::cout << "\n M   .   .   .   .   .   .   .   .   .   .";
  std::cout << "\n U   .   .   .   .   .   .   .   .   1   .";
  std::cout << "\n\nActual\n";
  std::cout << graph.displayMatrix() << std::endl;

  std::cout << "The breadth first traversal from A" << std::endl;
  std::cout << " expected A: T Z C Q X K J M with U unreachable" << std::endl;
  std::cout << " actually " << graph.breadthFirst('A') << std::endl;

  std::cout << "The depth first traversal from A" << std::endl;
  std::cout << " expected A: T Q J M Z X C K with U unreachable" << std::endl;
  std::cout << " actually " << graph.depthFirst('A') << std::endl;

  std::cout << "Done testing base lab" << std::endl << std::endl << std::endl;
#endif // BASE_LAB

#ifdef MIN_TREE
  std::cout << "Now testing the depth-first minimum spanning tree" << std::endl
            << std::endl;

  std::cout << "The minimum spanning tree from Z " << std::endl;
  std::cout << " expected Z: Z-X X-C C-K K-Q Q-J J-M " << std::endl;

  std::cout << " actually ";
  std::cout << graph.minTree('Z') << std::endl;

  std::cout << "The minimum spanning tree from C " << std::endl;
  std::cout << " expected C: C-X C-K K-Q Q-J J-M " << std::endl;

  std::cout << " actually ";
  std::cout << graph.minTree('C') << std::endl;

  std::cout << "Done with testing minimum spanning tree " << std::endl
            << std::endl
            << std::endl;
#endif // MIN_TREE

#ifdef CONNECT
  std::cout << "Now testing the connection table" << std::endl << std::endl;

  std::cout << "The graph connect table should be: " << std::endl;
  std::cout << "A: T Z C Q X K J M" << std::endl;
  std::cout << "C: X K Q J M" << std::endl;
  std::cout << "T: Q J M" << std::endl;
  std::cout << "Z: X C K Q J M" << std::endl;
  std::cout << "X: C K Q J M" << std::endl;
  std::cout << "K: X Q C J M" << std::endl;
  std::cout << "Q: J M" << std::endl;
  std::cout << "J: M" << std::endl;
  std::cout << "M:" << std::endl;
  std::cout << "U: M " << std::endl << std::endl;

  std::cout << "The graph connect table is: " << std::endl;
  std::cout << graph.connectTable() << std::endl;

  std::cout << "End of testing connection table" << std::endl << std::endl;
#endif // CONNECT

  return 0;
}
