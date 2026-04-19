# Kruskal Minimum Spanning Tree (C++)

Simple standalone implementation of Kruskal's algorithm with DSU.

Build:

```bash
g++ -std=c++17 -O2 kruskal.cpp -o kruskal
```

Run (example):

```bash
printf "4 5\n1 2 1\n1 3 4\n2 3 2\n2 4 7\n3 4 3\n" | ./kruskal
```

Input format:
- First line: `n m` (number of vertices and edges)
- Next `m` lines: `u v w` (1-based vertex indices and weight)

Output:
- Total MST weight on first line, followed by `n-1` edges in the MST as `u v w`.
