/*
This program computes the minimum of the maximum flows
between all pairs of vertices in a directed graph.
*/

#include <stdio.h>
#include <assert.h>


int main(int argc, char *argv[]) {
    // Generate graph
    char *file_path = "inputs/input1.txt";
    if (argc > 1) {
        file_path = argv[1];
    }
    char from;
    char to;
    float weight;
    FILE *file= fopen(file_path, "r");
    assert(file);
    printf("\nGraph Info\n");
    while (!feof(file)) {
        fscanf(file, "%c %c %f\n", &from, &to, &weight);
        printf("%c to %c: %f\n", from, to, weight);
    }
    fclose(file);
}
