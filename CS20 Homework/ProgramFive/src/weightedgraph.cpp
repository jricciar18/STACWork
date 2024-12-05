#include "weightedgraph.h"
#include <iostream>
#include <queue>
#include <stack>

WeightedGraph::WeightedGraph(int size)
{
    m_numVertices = 0;
    m_maxVertices = size;
    m_vertices.resize(size);
    for (int i=0; i<size; i++){
        m_vertices[i] = NULL;
    }

    m_marks.resize(size);

    int rows = size;
    int columns = size;
    m_edges.resize(rows, vector<int>(columns, 0));
}

void WeightedGraph::addVertex(Vertex* aVertex)
{
    m_vertices[m_numVertices] = aVertex;
    for (int i=0; i<m_maxVertices; i++) {
        m_edges[m_numVertices][i] = NULL_EDGE;
        m_edges[i][m_numVertices] = NULL_EDGE;
    }
    m_numVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight)
{
    int row;
    int column;
    row = indexIs(m_vertices[fromVertex]);
    column = indexIs(m_vertices[toVertex]);
    m_edges[row][column] = weight;
}

int WeightedGraph::indexIs(Vertex* aVertex)
{
     int i = 0;
     while (i < m_numVertices) {
        if (m_vertices[i] == aVertex) {
            return i;
        }
        i++;
     }
     return -1;
}

void WeightedGraph::clearMarks()
{
    for (int i=0; i<m_numVertices; i++) {
        m_marks[i] = false;
    }
}

void WeightedGraph::doDFS (Vertex* aVertex)
{
    int ix, ix2;
    if (aVertex == NULL) return;
    vector<Vertex*> path;

        // Add current vertex to path and print it
    cout << aVertex->getTitle() << " ";
    path.push_back(aVertex);

        // Marks vertex as visited
    ix = indexIs(aVertex);
    m_marks[ix] = true;

        // Explore all adjacent vertices
    for (int i=0; i<m_numVertices; i++) {
        ix2 = indexIs(m_vertices[i]);
        if(m_edges[ix][ix2] != NULL_EDGE && !m_marks[ix2]) {
            m_totalCost += m_edges[ix][ix2];
            doDFS(m_vertices[i]);
        }
    }
}

void WeightedGraph::DFS(Vertex* aVertex)
{
    clearMarks();
    m_totalCost = 0;

    doDFS(aVertex);

    cout << "\nTotal Cost: " << m_totalCost << endl;
}

void WeightedGraph::doBFS(Vertex* aVertex)
{
    int ix, ix2;
    queue<Vertex*> que;

    ix = indexIs(aVertex);
    m_marks[ix] = true;
    que.push(aVertex);

    while (!que.empty()) {
        Vertex* node = que.front();
        que.pop();
        ix = indexIs(node);
        cout << node->getTitle() << " ";

        for (int i = 0; i < m_numVertices; i++) {
            ix2 = indexIs(m_vertices[i]);

            if (m_edges[ix][ix2] != NULL_EDGE && !m_marks[ix2]) {
                m_marks[ix2] = true;
                que.push(m_vertices[i]);

                m_totalCost += m_edges[ix][ix2];
            }
        }
    }
}

void WeightedGraph::BFS(Vertex* aVertex)
{
    clearMarks();
    m_totalCost = 0;

    doBFS(aVertex);

    cout << "\nTotal cost: " << m_totalCost << endl;
}


void WeightedGraph::findPath(Vertex* source, Vertex* destination) {
    clearMarks();
    int ixSource = indexIs(source);
    int ixDest = indexIs(destination);

    // Check if source or destination are invalid
    if (ixSource == -1 || ixDest == -1) {
        cout << "Invalid source or destination." << endl;
        return;
    }

    // Use DFS to explore paths
    stack<Vertex*> pathStack;
    vector<Vertex*> predecessors(m_numVertices, nullptr);
    bool found = false;

    pathStack.push(source);
    m_marks[ixSource] = true;

    while (!pathStack.empty() && !found) {
        Vertex* current = pathStack.top();
        pathStack.pop();
        int ix = indexIs(current);

        if (current == destination) {
            found = true;
            break;
        }

        for (int i = 0; i < m_numVertices; i++) {
            if (m_edges[ix][i] != NULL_EDGE && !m_marks[i]) {
                m_marks[i] = true;
                pathStack.push(m_vertices[i]);
                predecessors[i] = current;
            }
        }
    }

    // Output the path and its length
    if (found) {
        stack<Vertex*> pathResult;
        Vertex* step = destination;

        while (step != nullptr) {
            pathResult.push(step);
            step = predecessors[indexIs(step)];
        }

        int pathLength = 0;
        cout << "Path found: ";
        while (!pathResult.empty()) {
            Vertex* v = pathResult.top();
            pathResult.pop();
            cout << v->getTitle() << " ";
            if (!pathResult.empty())
                pathLength += m_edges[indexIs(v)][indexIs(pathResult.top())];
        }
        cout << "\nPath length: " << pathLength << endl;
    } else {
        cout << "No path found from " << source->getTitle() << " to " << destination->getTitle() << endl;
    }
}
