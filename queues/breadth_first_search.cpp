#include <iostream>
#include <list>
#include <queue>

class Graph {
private:
    int V; // Number of vertices
    std::list<int>* adjList; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adjList = new std::list<int>[V];
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        // For undirected graph, add the reverse edge as well
        // adjList[dest].push_back(src);
    }

    void BFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        std::queue<int> queue;
        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int current = queue.front();
            std::cout << current << " ";
            queue.pop();

            for (auto it = adjList[current].begin(); it != adjList[current].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    queue.push(*it);
                }
            }
        }
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    std::cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    return 0;
}
