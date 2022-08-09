-----
Software requirement
-----
gcc 4.4.7 or 4.8.5

OS: Linux, MacOS and Windows

-----------
Graph format basics
----------------------
![Alt text](/images/intr_graph.png)

Given a graph G = (V, E, W), as shown in (a), mainstream storage formats are (b) edge (tuple) list format and (c) *Compressed sparse row* (CSR) format. Note, V, E and W stand for the sets of vertices, edges and weights of the graph G, respectively.

**CSR format**: is firstly introduced to store [sparse matrices](http://netlib.org/utk/papers/templates/node91.html). When it comes to graph, we assume each source vertex to be one row of the matrix, and all the destination vertices (originated from the same source vertex) as column indices for the *non-zero* (nnz) entries of this row. The edge weight resembles the content of the corresponding nnz entry. CSR only stores the destination vertices and edge weights in **Adjacency list** and **Weight list**. Further, the **Begin position** array is used to describe the ranges of destination vertices (also edge weights) for every row. Because the begin index of vertex *n+1* is the end index for vertex *n*. Consequently, a dedicated end index array is unnecessary, except one extra entry at the end of the begin position array to indicate the end index of the destination vertices for the last source vertex, as shown in (c).  

In summary, CSR space consumptions are: 
- Begin position: |V| + 1 entries.
- Adjacency list: |E| entries. 
- Weight list: |E| entries.

-----
BFS Implementation
---------
The overall code structure of this project is:

Test Graph Image
------------------
This is the test graph to implement binary search

![Alt text](/images/graph.png)

Converter: edge tuples to CSR
----
- Compile: make
- To execute: type "./text_to_bin.bin", it will show you what is needed
- One example is provided in test_graph folder. The user can use **./text_to_bin.bin ./test_graph/graph_dat.dat 1 0** to run the converter.

-----
Graph reader
----
- Compile: make
- To execute: type "./graph_loader.bin", it will show you what is needed
- You can use the converter converted graph to run this command.
- at the end of the command keep the start node and an end node.

**Graph Test from converter**:
- ./graph_loader.bin ../tuple_text_to_binary_csr_mmap/test_graph/graph.dat_beg_pos.bin ../tuple_text_to_binary_csr_mmap/test_graph/graph.dat_csr.bin ../tuple_text_to_binary_csr_mmap/test_graph/graph.dat_weight.bin 1 9


----
Acknowledgement
----

https://github.com/asherliu/graph_project_start

[SC  '15] Enterprise: Breadth-First Graph Traversal on GPUs [[PDF](http://personal.stevens.edu/~hliu77/docs/sc15.pdf)]

[FAST'17] Graphene: Fine-Grained IO Management for Graph Computing [[PDF](http://personal.stevens.edu/~hliu77/docs/fast17.pdf)]

[HPDC'19] XBFS: eXploring Runtime Optimizations for Breadth-First Search on GPUs [[PDF](http://personal.stevens.edu/~hliu77/docs/hpdc19.pdf)]

[DAC '19] Dr. BFS: Data Centric Breadth-First Search on FPGAs [[PDF](http://personal.stevens.edu/~hliu77/docs/dac19.pdf)]

[USENIX ATC '19] SIMD-X: Programming and Processing of Graph Algorithms on GPUs [[PDF](http://personal.stevens.edu/~hliu77/docs/usenix-atc19.pdf)]

[SC '20] C-SAW: a framework for graph sampling and random walk on GPUs [[PDF](https://personal.stevens.edu/~hliu77/docs/SC20.pdf)]

[TPDS '21] GSOFA: Scalable Sparse Symbolic LU Factorization on GPUs [[PDF](https://personal.stevens.edu/~hliu77/docs/tpds21b.pdf)]
