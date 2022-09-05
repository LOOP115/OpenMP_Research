# [OpenMP](https://www.openmp.org/resources/)



### [Tutorial Videos](https://www.youtube.com/playlist?list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG)

### [Tutorial Code](https://github.com/tgmattso/OpenMP_intro_tutorial)

### [Tutorial Slides](resources/Intro_To_OpenMP_Mattson.pdf)

### [OpenMP Examples](resources/openmp-examples-4.5.0.pdf)

### [Project 1 - Specification](resources/proj1-spec.pdf)



### Compile and run OpenMP programs

```
gcc -fopenmp [filename].c -o [filename]
```



### Tasks

This problem has particular importance in the design of future high performance interconnection networks for supercomputer architectures, because it represents a quantity that is similar to the more fundamental network bi-section width: the minimum number of edges required to be cut in order to separate the network roughly into two halves. 

1. Research parallel methods for the following problem: determine **the minimum of the maximum flows** between **all pairs of vertices** in a **directed graph with weighted edges**, where each weight is a real value greater than 0.

   1. For clarity, let removal of weight w from the graph mean removing any set of edges whose total weight equals w. Then, the maximum flow from a vertex u to a vertex v in such a graph is the minimum amount of weight required to be removed from the graph in order to eliminate all paths in the graph from u to v. The problem is to find the minimum of these maximum flows over all pairs of vertices in the graph.

2. Choose/devise a parallel method, either that you have found in the literature, in part or in full, or that you have devised yourself, in part or in full, and implement it using OpenMP in the C/C++ language such that it will compile and run on a **4 socket cluster node** provided via the Spartan HPC at Unimelb.

   1. Make sure to think about achieving as much performance as you can on a 4 socket cluster node on Spartan; that may require you to consider its **NUMA characteristics**, and other OpenMP techniques as discussed in the lectures.

3. Design and apply an appropriate methodology for **testing the performance** of your parallel implementation on a 4 socket cluster node. Your experiments should at the very least, i.e. to pass, show measurements of speedup versus number of threads/cores. You may also show more detailed measurements that demonstrate that the techniques you have implemented are indeed contributing to the performance of your approach; in order to achieve a higher grade in the project.



### Checklist

#### Graph Generator

* Randomly generate several nodes
* Randomly generate weights between some pairs of nodes
* Save the generated graph in a file

#### Parallel Method

* Single threaded implementation ✔
  * Generate a directed graph based on the input ✔
  * Compute the max flow between each pairs of nodes ✔
* OpenMP implementation
* Speedup



### References

#### Maximum flow

* https://en.wikipedia.org/wiki/Maximum_flow_problem
* https://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm
* https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm
* https://www.geeksforgeeks.org/max-flow-problem-introduction/
* https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/

