/*
This program computes the minimum of the maximum flows
between all pairs of vertices in a directed graph.
*/

#include <cstdio>
#include <cassert>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

int edmonds_karp(int num_nodes, int from, int to, int **graph);

int main(int argc, char *argv[]) {
    char *file_path = (char*)"inputs/input1.txt";
    if (argc > 1) {
        file_path = argv[1];
    }
    int from;
    int to;
    int num_nodes;
    int weight;

    // Read input file
    FILE *file= fopen(file_path, "r");
    assert(file);
    fscanf(file, "%d\n", &num_nodes);
    printf("\nGraph with %d vertices\n", num_nodes);

    // Init an empty graph
    int** graph = (int**)malloc(num_nodes * sizeof(int*));
    for (int i = 0; i < num_nodes; i++)
        graph[i] = (int*)malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++)
        for (int j = 0; j < num_nodes; j++)
            graph[i][j] = 0;

    // Add nodes and edges to the graph
    while (!feof(file)) {
        fscanf(file, "%d %d %d\n", &from, &to, &weight);
        printf("%d to %d: %d\n", from, to, weight);
        graph[from][to] = weight;
    }
    fclose(file);

    int min_max_flow = INT_MAX;
    printf("\nMax Flow\n");
    for (int i=0; i<num_nodes; i++) {
        for (int j=0; j<num_nodes; j++) {
            // Compute max flow for each pairs of vertices
            int flow = edmonds_karp(num_nodes, i, j, graph);
            if (flow > 0) {
                printf("%d to %d: %d\n", i, j, flow);
                // Update min max flow
                min_max_flow = min(flow, min_max_flow);
            }
        }
    }
    printf("\nMin Max Flow: %d", min_max_flow);

    // Free memory
    for (int i = 0; i < num_nodes; i++)
        free(graph[i]);
    free(graph);
}


/* Find an augmenting path from source vertex to sink vertex using bfs.
** Returns true if a path is found.
**
** num_nodes - number of nodes in the graph
** from - source vertex
** to - sink vertex
** graph - 2d array representing the residual graph
** prev - store the previous vertex to record the path
**
*/
bool has_path(int num_nodes, int from, int to, int** graph, int prev[]) {
    // Record if a node is visited, init with all false
    bool visited[num_nodes];
    memset(visited, 0, sizeof(visited));

    // Push the source vertex
    queue<int> node_q;
    node_q.push(from);
    visited[from] = true;
    prev[from] = -1;

    // Start breath first search
    while (!node_q.empty()) {
        int src = node_q.front();
        node_q.pop();
        for (int sink=0; sink<num_nodes; sink++) {
            if (!visited[sink] && graph[src][sink] > 0) {
                if (sink == to) {
                    prev[sink] = src;
                    return true;
                }
                node_q.push(sink);
                prev[sink] = src;
                visited[sink] = true;
            }
        }
    }
    return false;
}


/* Returns the max flow from source vertex to sink vertex.
**
** num_nodes - number of nodes in the graph
** from - source vertex
** to - sink vertex
** graph - 2d array representing the original graph
**
*/
int edmonds_karp(int num_nodes, int from, int to, int** graph) {
    // Generate a residual graph which records residual capacities
    int** res_graph = (int**)malloc(num_nodes * sizeof(int*));
    for (int i = 0; i < num_nodes; i++)
        res_graph[i] = (int*)malloc(num_nodes * sizeof(int));
    for (int i=0; i<num_nodes; i++) {
        for (int j=0; j<num_nodes; j++) {
            res_graph[i][j] = graph[i][j];
        }
    }

    // Keep searching until there is no more augmenting path
    int prev[num_nodes];
    int max_flow = 0;
    int sink, src;
    while (has_path(num_nodes, from, to, res_graph, prev)) {
        int flow = INT_MAX;
        // Find the max flow along the path
        for (sink=to; sink!=from; sink=prev[sink]) {
            flow = min(flow, res_graph[prev[sink]][sink]);
        }
        // Update residual capacities of both directions
        for (sink=to; sink!=from; sink=prev[sink]) {
            src = prev[sink];
            res_graph[src][sink] -= flow;
            res_graph[sink][src] += flow;
        }
        // Update max flow
        max_flow += flow;
    }

    // Free memory
    for (int i = 0; i < num_nodes; i++)
        free(res_graph[i]);
    free(res_graph);
    return max_flow;
}
