# Graphs

Graphs are non-linear data structures consisting of nodes (vertices) and edges that connect these nodes. They represent relationships between various entities. Graphs can be directed (edges have a specific direction) or undirected (edges do not have a direction).

Example usage:
```c++
#include <iostream>
#include <vector>

// Node structure for graph representation using adjacency lists
struct Node {
    int val;
    std::vector<Node*> neighbors;

    Node(int value) : val(value) {}
};

int main() {
    // Creating nodes for the graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    // Creating edges by adding neighbors
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    node2->neighbors.push_back(node4);
    node3->neighbors.push_back(node4);

    // Visual representation of the undirected graph
    std::cout << "Graph:" << std::endl;
    std::cout << "1 -- 2" << std::endl;
    std::cout << "|    |" << std::endl;
    std::cout << "3 -- 4" << std::endl;

    return 0;
}
```

Common algorithms and operations used with graphs include:

1. Traversal:
   Depth-first Search (DFS): Traversing the graph by exploring as far as possible along each branch before backtracking.
   Breadth-first Search (BFS): Traversing the graph level by level.
2. Shortest Path:
   Dijkstra's Algorithm: Finding the shortest path between nodes in a weighted graph.
   Bellman-Ford Algorithm: Finding the shortest path in a graph with negative weight edges.
   Floyd-Warshall Algorithm: Finding the shortest paths between all pairs of nodes in a graph.
3. Minimum Spanning Tree:
   Prim's Algorithm: Finding the minimum spanning tree (MST) in a graph.
   Kruskal's Algorithm: Finding the MST by repeatedly adding the shortest edge that doesn't form a cycle.
4. Cycle Detection:
   Detect Cycle in Directed Graph: Determining if a directed graph has a cycle.
   Detect Cycle in Undirected Graph: Determining if an undirected graph has a cycle.
5. Connectivity:
   Connected Components: Finding connected components in an undirected graph.
   Strongly Connected Components (SCC): Finding SCCs in a directed graph.
   These algorithms are fundamental in graph theory and are used for various applications, such as route planning, network analysis, social network analysis, and more.