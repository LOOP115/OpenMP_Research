#include <stdio.h>
#include <omp.h>

int main() {
    int num_procs = omp_get_num_procs();
    printf("%d", num_procs);
}
