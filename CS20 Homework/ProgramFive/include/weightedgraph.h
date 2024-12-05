#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <vector>
#include "Vertex.h"

class WeightedGraph
{
    public:
        WeightedGraph(int);
        bool isEmpty();
        void addVertex(Vertex*);
        void addEdge(int, int, int);
        bool isFull();
        void DFS(Vertex*);
        void BFS(Vertex*);
            //Program 5 Functions
        void findPath(Vertex*, Vertex*);

    protected:
        int m_totalCost;

        int indexIs(Vertex*);
        void clearMarks();
        void doDFS(Vertex*);
        void doBFS(Vertex*);

    private:
        static const int NULL_EDGE = 0;
        int m_numVertices;
        int m_maxVertices;
        vector <Vertex*> m_vertices;
        vector <vector <int>> m_edges;
        vector <bool> m_marks;
};

#endif // WEIGHTEDGRAPH_H
