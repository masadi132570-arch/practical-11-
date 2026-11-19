#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Use a large value to represent infinity, avoiding integer overflow during addition
const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist) {
    int V = dist.size();

    // Pick all vertices one by one as intermediate vertices (k)
    for (int k = 0; k < V; ++k) {
        // Pick all vertices as source (i)
        for (int i = 0; i < V; ++i) {
            // Pick all vertices as destination (j)
            for (int j = 0; j < V; ++j) {
                // Only update if both intermediate paths are reachable
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < V; ++i) {
        if (dist[i][i] < 0) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }
}

void printSolution(const vector<vector<int>>& dist) {
    int V = dist.size();
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << "\n";
    }
}

int main() {
    // Example weighted directed graph with 4 vertices
    // INF indicates no direct edge between vertices
    vector<vector<int>> graph = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);
    printSolution(graph);

    return 0;
}
