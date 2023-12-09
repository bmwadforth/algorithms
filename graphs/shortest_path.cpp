#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define INF std::numeric_limits<int>::max()

// Edge structure representing an edge in the graph
struct Edge {
    int dest;
    int weight;
};

// Graph class representing the graph structure and implementing Dijkstra's algorithm
class Graph {
private:
    int V; // Number of vertices
    std::vector<std::vector<Edge>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        Edge edge = {dest, weight};
        adjList[src].push_back(edge);
    }

    // Dijkstra's algorithm to find the shortest path from source to all other vertices
    void dijkstra(int source) {
        std::vector<int> distance(V, INF);
        distance[source] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const Edge& edge : adjList[u]) {
                int v = edge.dest;
                int weight = edge.weight;

                if (distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }

        // Print shortest distances from source to all vertices
        std::cout << "Shortest distances from source " << source << " to all vertices:\n";
        for (int i = 0; i < V; ++i) {
            std::cout << "Vertex " << i << ": ";
            if (distance[i] == INF) {
                std::cout << "INF\n";
            } else {
                std::cout << distance[i] << "\n";
            }
        }
    }
};

int main() {
    int V = 6; // Number of vertices
    Graph g(V);

    // Adding edges to the graph (source, destination, weight)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 4);
    g.addEdge(3, 5, 11);
    g.addEdge(4, 5, 6);

    int source = 0; // Source vertex
    g.dijkstra(source);

    return 0;
}
