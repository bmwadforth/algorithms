#include <iostream>
#include <vector>
#include <algorithm>

class Edge {
public:
    int src, dest, weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {
private:
    int V;
    std::vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
    }

    int findParent(std::vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return findParent(parent, parent[i]);
    }

    void unionSets(std::vector<int>& parent, int x, int y) {
        int x_set = findParent(parent, x);
        int y_set = findParent(parent, y);
        parent[x_set] = y_set;
    }

    void kruskalMST() {
        std::vector<Edge> result(V - 1);

        std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        std::vector<int> parent(V, -1);
        int e = 0, i = 0;

        while (e < V - 1 && i < edges.size()) {
            Edge nextEdge = edges[i++];
            int x = findParent(parent, nextEdge.src);
            int y = findParent(parent, nextEdge.dest);

            if (x != y) {
                result[e++] = nextEdge;
                unionSets(parent, x, y);
            }
        }

        std::cout << "Edges in the minimum spanning tree:\n";
        for (i = 0; i < e; ++i) {
            std::cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << std::endl;
        }
    }
};

int main() {
    int V = 4; // Number of vertices
    Graph g(V);

    // Adding edges to the graph (source, destination, weight)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
