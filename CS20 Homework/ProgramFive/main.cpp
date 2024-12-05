#include <iostream>
#include <cstring>
#include "weightedgraph.h"
#include "vertex.h"

using namespace std;

    // number of vertices in the graph
#define V 5
    // An infinite path length
#define INF 9999999

    // Adjacency matrix to represent the graph
int G[V][V] = {
  { 0, 0, 12, 60, 0},
  {10, 0,  0,  0, 0},
  {0, 20,  0, 32, 0},
  {0,  0,  0,  0, 0},
  {7,  0,  0,  0, 0}
};

int main()
{
    WeightedGraph myGraph(10);
    Vertex* startNode;
    Vertex* aVertex;

    startNode = new Vertex("A"); // node 0
    myGraph.addVertex(startNode);
    aVertex = new Vertex("B"); // node 1
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("C"); // node 2
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("D"); // node 3
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("E"); // node 4
    myGraph.addVertex(aVertex);

    myGraph.addEdge(0, 2, 12);
    myGraph.addEdge(0, 3, 60);
    myGraph.addEdge(1, 0, 10);
    myGraph.addEdge(2, 1, 20);
    myGraph.addEdge(2, 3, 32);
    myGraph.addEdge(4, 0,  7);

    cout << "DFS: ";
    myGraph.DFS(aVertex);
    cout << endl;

    cout << "BFS: ";
    myGraph.BFS(aVertex);
    cout << endl;

    myGraph.findPath(aVertex, startNode);

    return 0;
}
