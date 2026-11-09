# Sessions 17, 18 & 19: Graphs and Applications

**Course:** Algorithms and Data Structures Using Java  
**Program:** PGCP-AC – August 2026  
**Institute:** ACTS, Pune  
**Duration:** 6 Theory + 6 Lab Hours

---

# 1. Introduction to Graphs

A **Graph** is a non-linear data structure consisting of a collection of vertices (nodes) and edges (connections between vertices).

Graphs are used to represent relationships and connections between different objects.

A graph is generally represented as:

\[
G = (V, E)
\]

Where:

- `G` = Graph
- `V` = Set of vertices
- `E` = Set of edges

### Example

Consider a graph:

```text
        A
       / \
      B---C
      |   |
      D---E
```

Vertices:

```text
V = {A, B, C, D, E}
```

Edges:

```text
E = {(A,B), (A,C), (B,C), (B,D), (C,E), (D,E)}
```

### Real-Life Applications of Graphs

- Google Maps and GPS navigation
- Social networking platforms
- Computer networks
- Airline and railway routes
- Web page linking
- Recommendation systems
- Network routing
- Dependency management

---

# 2. Graph Terminologies

Consider the following graph:

```text
       A -------- B
       |          |
       |          |
       C -------- D
                  |
                  E
```

| Term | Definition | Example |
|---|---|---|
| Vertex / Node | Fundamental element of a graph | A, B, C |
| Edge | Connection between two vertices | A-B |
| Adjacent Vertices | Vertices directly connected by an edge | A and B |
| Degree | Number of edges connected to a vertex in an undirected graph | Degree of D = 3 |
| In-Degree | Number of incoming edges in a directed graph | Incoming edges |
| Out-Degree | Number of outgoing edges in a directed graph | Outgoing edges |
| Path | Sequence of connected vertices | A → B → D |
| Cycle | Path that starts and ends at the same vertex | A → B → D → C → A |
| Connected Graph | Every pair of vertices has a path between them | Connected network |
| Connected Component | Maximal connected part of a graph | Separate network groups |
| Self Loop | Edge connecting a vertex to itself | A → A |
| Parallel Edges | Multiple edges connecting the same pair of vertices | Two edges between A and B |
| Weighted Edge | Edge having a cost or weight | A --5-- B |
| Simple Graph | Graph without self-loops or parallel edges | Ordinary simple network |
| Isolated Vertex | Vertex with degree zero | Unconnected node |

### Important Properties

For an undirected graph:

\[
\sum Degree(v) = 2|E|
\]

This is called the Handshaking Lemma.

For a directed graph:

\[
\sum InDegree(v) = \sum OutDegree(v) = |E|
\]

Where `|E|` represents the number of edges.

---

# 3. Types of Graphs

## 3.1 Undirected Graph

An undirected graph contains edges without any direction.

If A is connected to B, then B is also connected to A.

```text
       A -------- B
       |          |
       |          |
       C -------- D
```

Example: Friendship connections in a social network.

## 3.2 Directed Graph (Digraph)

A directed graph contains edges with a specific direction.

```text
       A -------> B
       ^          |
       |          |
       C <------- D
```

Example: Following relationships on social media.

## 3.3 Weighted Graph

A weighted graph contains edges with associated weights or costs.

```text
          A
        5/ \3
        B---C
          2
```

Example: Road networks where weights represent distances.

## 3.4 Unweighted Graph

An unweighted graph has edges without numerical weights.

```text
       A ------ B
       |        |
       |        |
       C ------ D
```

## 3.5 Connected Graph

A graph is connected if there is a path between every pair of vertices.

```text
       A ------ B
       |        |
       C ------ D
```

## 3.6 Disconnected Graph

A graph is disconnected if at least one pair of vertices has no path between them.

```text
       A ------ B

       C ------ D
```

## 3.7 Cyclic Graph

A graph containing at least one cycle.

```text
       A ------ B
       |        |
       D ------ C
```

## 3.8 Acyclic Graph

A graph that does not contain any cycle.

Example:

```text
          A
         / \
        B   C
       /
      D
```

## 3.9 Complete Graph

A complete graph is a simple undirected graph in which every pair of distinct vertices is connected by an edge.

For `n` vertices:

\[
E = \frac{n(n-1)}{2}
\]

Example:

```text
          A
         /|\
        / | \
       B--|--C
        \ | /
          D
```

## 3.10 Directed Acyclic Graph (DAG)

A DAG is a directed graph that does not contain any directed cycle.

Example:

```text
       A ------> B
        \         \
         \         v
          ------> C
```

Applications:

- Task scheduling
- Build systems
- Course prerequisites
- Dependency management

---

# 4. Graph Representation

A graph can be represented mainly using:

1. Adjacency Matrix
2. Adjacency List

Consider this undirected graph:

```text
        A -------- B
        |          |
        |          |
        C -------- D
```

Edges:

```text
(A,B)
(A,C)
(B,D)
(C,D)
```

## 4.1 Adjacency Matrix

An Adjacency Matrix is a two-dimensional array used to represent connections between vertices.

- `1` indicates an edge exists.
- `0` indicates no edge exists.

### Example

Vertices:

```text
A, B, C, D
```

Adjacency Matrix:

| Vertex | A | B | C | D |
|---|---:|---:|---:|---:|
| A | 0 | 1 | 1 | 0 |
| B | 1 | 0 | 0 | 1 |
| C | 1 | 0 | 0 | 1 |
| D | 0 | 1 | 1 | 0 |

### Java Implementation

```java
public class AdjacencyMatrix {

    public static void main(String[] args) {

        int vertices = 4;

        int[][] graph = new int[vertices][vertices];

        // Add edges
        graph[0][1] = 1;
        graph[1][0] = 1;

        graph[0][2] = 1;
        graph[2][0] = 1;

        graph[1][3] = 1;
        graph[3][1] = 1;

        graph[2][3] = 1;
        graph[3][2] = 1;

        // Display matrix
        for (int i = 0; i < vertices; i++) {

            for (int j = 0; j < vertices; j++) {

                System.out.print(graph[i][j] + " ");
            }

            System.out.println();
        }
    }
}
```

Output:

```text
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
```

### Advantages

- Simple to implement.
- Checking whether an edge exists takes O(1) time.
- Suitable for dense graphs.
- Easy to represent weighted graphs by storing weights instead of 1.

### Disadvantages

- Requires O(V²) memory.
- Wastes memory for sparse graphs.
- Finding all neighbors of a vertex takes O(V).

## 4.2 Adjacency List

An Adjacency List stores the neighbors of each vertex using a list.

Example graph:

```text
        A -------- B
        |          |
        |          |
        C -------- D
```

Adjacency List:

```text
A → B → C

B → A → D

C → A → D

D → B → C
```

### Java Implementation

```java
import java.util.ArrayList;

public class AdjacencyList {

    public static void main(String[] args) {

        int vertices = 4;

        ArrayList<ArrayList<Integer>> graph =
            new ArrayList<>();

        for (int i = 0; i < vertices; i++) {

            graph.add(new ArrayList<>());
        }

        // Add undirected edges
        addEdge(graph, 0, 1);
        addEdge(graph, 0, 2);
        addEdge(graph, 1, 3);
        addEdge(graph, 2, 3);

        // Display adjacency list
        for (int i = 0; i < vertices; i++) {

            System.out.print(i + " → ");

            for (int neighbour : graph.get(i)) {

                System.out.print(neighbour + " ");
            }

            System.out.println();
        }
    }

    static void addEdge(
        ArrayList<ArrayList<Integer>> graph,
        int u, int v
    ) {

        graph.get(u).add(v);

        graph.get(v).add(u);
    }
}
```

### Advantages

- Requires less memory for sparse graphs.
- Easy to find all neighbors of a vertex.
- Efficient for graph traversal.

### Disadvantages

- Checking whether a particular edge exists may take O(degree of vertex) time.
- Slightly more complex than an adjacency matrix.

## 4.3 Adjacency Matrix vs Adjacency List

| Feature | Adjacency Matrix | Adjacency List |
|---|---|---|
| Representation | 2D Array | Array/List of Lists |
| Space Complexity | O(V²) | O(V + E) |
| Check Edge | O(1) | O(degree of vertex) |
| Find Neighbors | O(V) | O(degree of vertex) |
| Suitable For | Dense Graphs | Sparse Graphs |
| Implementation | Simple | Flexible |

Where:
- `V` = Number of vertices
- `E` = Number of edges

---

# 5. Graph Traversal Algorithms

Graph Traversal means visiting all reachable vertices of a graph in a systematic order.

The two major graph traversal algorithms are:

1. Breadth First Search (BFS)
2. Depth First Search (DFS)

Consider this graph:

```text
             A
           /   \
          B     C
         / \     \
        D   E     F
```

## 5.1 Breadth First Search (BFS)

BFS visits vertices level by level.

It explores all immediate neighbors before moving to the next level.

**Data Structure Used: Queue (FIFO)**

### Working Principle

1. Start from a source vertex.
2. Mark it as visited.
3. Insert it into a queue.
4. Remove a vertex from the queue.
5. Visit its unvisited neighbors.
6. Insert those neighbors into the queue.
7. Repeat until the queue becomes empty.

### Example

Starting vertex = A

```text
Level 0: A

Level 1: B, C

Level 2: D, E, F
```

BFS Traversal:

```text
A → B → C → D → E → F
```

### Java Implementation Using Adjacency List

```java
import java.util.*;

public class BFSGraph {

    static void bfs(
        ArrayList<ArrayList<Integer>> graph,
        int start,
        int vertices
    ) {

        boolean[] visited = new boolean[vertices];

        Queue<Integer> queue = new LinkedList<>();

        visited[start] = true;

        queue.add(start);

        while (!queue.isEmpty()) {

            int current = queue.poll();

            System.out.print(current + " ");

            for (int neighbour : graph.get(current)) {

                if (!visited[neighbour]) {

                    visited[neighbour] = true;

                    queue.add(neighbour);
                }
            }
        }
    }
}
```

### Complexity

- Time Complexity: O(V + E) using an adjacency list.
- Auxiliary Space: O(V).

For an adjacency matrix, traversal takes O(V²) time.

## 5.2 Depth First Search (DFS)

DFS explores one branch as deeply as possible before backtracking.

It uses:
- Stack (LIFO), or
- Recursion (call stack).

### Working Principle

1. Start from a source vertex.
2. Mark it as visited.
3. Visit an unvisited neighbor.
4. Continue exploring deeper.
5. Backtrack when no unvisited neighbor remains.
6. Repeat until all reachable vertices are visited.

### Example

Starting vertex = A

One possible DFS traversal:

```text
A → B → D → E → C → F
```

The exact traversal order depends on the order in which neighbors are stored or examined.

### Java Implementation Using Recursion

```java
import java.util.*;

public class DFSGraph {

    static void dfs(
        ArrayList<ArrayList<Integer>> graph,
        int current,
        boolean[] visited
    ) {

        visited[current] = true;

        System.out.print(current + " ");

        for (int neighbour : graph.get(current)) {

            if (!visited[neighbour]) {

                dfs(graph, neighbour, visited);
            }
        }
    }
}
```

### Complexity

- Time Complexity: O(V + E) using an adjacency list.
- Auxiliary Space: O(V), including the visited array and recursion stack.

For an adjacency matrix, traversal takes O(V²) time.

## 5.3 BFS vs DFS

| Feature | BFS | DFS |
|---|---|---|
| Full Form | Breadth First Search | Depth First Search |
| Approach | Level by level | Deep first |
| Data Structure | Queue | Stack / Recursion |
| Shortest Path | Finds shortest path in an unweighted graph | Does not guarantee shortest path |
| Memory | Can use more memory for wide graphs | Depends on depth |
| Applications | Unweighted shortest path, level traversal | Cycle detection, connectivity, path exploration |

<LearningViz type_id="BFS_DFS_TRAVERSAL" initial_values={{"initial_algorithm":"BFS"}} />

---

# 6. Graph Traversal Using Stack and Queue

The syllabus specifically includes graph traversal using stack and queue.

- Queue is used for BFS.
- Stack is used for iterative DFS.

### Iterative DFS Using Stack

```java
import java.util.*;

public class IterativeDFS {

    static void dfs(
        ArrayList<ArrayList<Integer>> graph,
        int start,
        int vertices
    ) {

        boolean[] visited = new boolean[vertices];

        Stack<Integer> stack = new Stack<>();

        stack.push(start);

        while (!stack.isEmpty()) {

            int current = stack.pop();

            if (!visited[current]) {

                visited[current] = true;

                System.out.print(current + " ");

                // Push neighbors
                for (int i = graph.get(current).size() - 1;
                     i >= 0; i--) {

                    int neighbour = graph.get(current).get(i);

                    if (!visited[neighbour]) {

                        stack.push(neighbour);
                    }
                }
            }
        }
    }
}
```

**Note:** The neighbor insertion order affects the DFS traversal sequence. Reversing the neighbor order before pushing onto the stack can help visit the first listed neighbor first.

### BFS Using Queue

```java
Queue<Integer> queue = new LinkedList<>();

queue.add(start);

visited[start] = true;

while (!queue.isEmpty()) {

    int current = queue.poll();

    System.out.print(current + " ");

    for (int neighbour : graph.get(current)) {

        if (!visited[neighbour]) {

            visited[neighbour] = true;

            queue.add(neighbour);
        }
    }
}
```

---

# 7. Shortest Path Algorithms

The **Shortest Path Problem** is the problem of finding a path between vertices such that the total path cost or distance is minimum.

Shortest paths are useful in:

- Google Maps
- GPS navigation
- Computer network routing
- Flight route planning
- Delivery applications

### Example

Consider a weighted graph:

```text
          4
      A ------- B
       \       /
      2 \     / 1
         \   /
           C
```

Possible paths from A to B:

- Direct: A → B = 4
- Through C: A → C → B = 2 + 1 = 3

Therefore, the shortest path is:

```text
A → C → B

Total Cost = 3
```

Two shortest-path approaches included in your syllabus:

1. Dijkstra's Algorithm – Level Setting.
2. Floyd-Warshall Algorithm – Level Correcting / All-Pairs Shortest Path.

---

# 8. Dijkstra's Algorithm (Level Setting)

Dijkstra's Algorithm finds the shortest paths from a single source vertex to all other reachable vertices in a weighted graph.

It uses a greedy approach.

**Important:** Dijkstra's algorithm requires non-negative edge weights. It does not correctly handle negative-weight edges.

### Working Principle

1. Select a source vertex.
2. Initialize its distance to 0.
3. Initialize the distance of all other vertices to infinity.
4. Select the unvisited vertex with the smallest tentative distance.
5. Mark that vertex as settled.
6. Update the distances of its neighboring vertices.
7. Repeat until all reachable vertices are settled.

### Relaxation

Relaxation means checking whether a shorter path to a vertex can be obtained through another vertex.

For edge `u → v` with weight `w`:

\[
dist[v] = \min(dist[v], dist[u] + w)
\]

### Example

Consider the following weighted graph:

```text
          4
      A ------- B
      |         |
    1 |         | 2
      |         |
      C ------- D
          3
```

Edges:

```text
A-B = 4
A-C = 1
B-D = 2
C-D = 3
```

Source vertex = A.

Initial distances:

| Vertex | Distance |
|---|---:|
| A | 0 |
| B | ∞ |
| C | ∞ |
| D | ∞ |

After processing A:

| Vertex | Distance |
|---|---:|
| A | 0 |
| B | 4 |
| C | 1 |
| D | ∞ |

Select C because its tentative distance is smallest.

After processing C:

| Vertex | Distance |
|---|---:|
| A | 0 |
| B | 4 |
| C | 1 |
| D | 4 |

Select B or D based on the tie-breaking rule.

Final shortest distances:

| Vertex | Shortest Distance from A |
|---|---:|
| A | 0 |
| B | 4 |
| C | 1 |
| D | 4 |

Shortest path from A to D:

```text
A → C → D

Total Cost = 4
```

<LearningViz type_id="DIJKSTRA_SHORTEST_PATH" />

### Java Implementation of Dijkstra's Algorithm

This implementation uses an adjacency matrix and a simple minimum-distance selection loop.

```java
import java.util.Arrays;

public class Dijkstra {

    static final int INF = 999999;

    static int minDistance(
        int[] dist,
        boolean[] visited,
        int n
    ) {

        int min = INF;

        int minIndex = -1;

        for (int i = 0; i < n; i++) {

            if (!visited[i] && dist[i] < min) {

                min = dist[i];

                minIndex = i;
            }
        }

        return minIndex;
    }

    static void dijkstra(
        int[][] graph,
        int source
    ) {

        int n = graph.length;

        int[] dist = new int[n];

        boolean[] visited = new boolean[n];

        Arrays.fill(dist, INF);

        dist[source] = 0;

        for (int count = 0; count < n - 1; count++) {

            int u = minDistance(dist, visited, n);

            if (u == -1) {
                break;
            }

            visited[u] = true;

            for (int v = 0; v < n; v++) {

                if (!visited[v]
                    && graph[u][v] != 0
                    && dist[u] != INF
                    && dist[u] + graph[u][v] < dist[v]) {

                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        System.out.println("Shortest Distances:");

        for (int i = 0; i < n; i++) {

            System.out.println(
                source + " to " + i + " = " + dist[i]
            );
        }
    }

    public static void main(String[] args) {

        int[][] graph = {

            {0, 4, 1, 0},

            {4, 0, 0, 2},

            {1, 0, 0, 3},

            {0, 2, 3, 0}
        };

        dijkstra(graph, 0);
    }
}
```

Output:

```text
Shortest Distances:
0 to 0 = 0
0 to 1 = 4
0 to 2 = 1
0 to 3 = 4
```

### Complexity

For the adjacency matrix implementation above:

- Time Complexity: O(V²)
- Auxiliary Space: O(V), excluding the input graph.

With an adjacency list and a priority queue:

- Time Complexity: O((V + E) log V), using a binary heap.
- Auxiliary Space: O(V + E), including the graph representation.

---

# 9. Floyd-Warshall Algorithm (All-Pairs Shortest Path)

Floyd-Warshall is a Dynamic Programming algorithm used to find the shortest paths between all pairs of vertices in a weighted graph.

Unlike Dijkstra's algorithm, which finds shortest paths from one source, Floyd-Warshall calculates shortest distances between every pair of vertices.

It can handle negative edge weights, but it does not support negative-weight cycles.

### Working Principle

1. Create a distance matrix.
2. Store direct edge weights.
3. Set the distance from each vertex to itself as 0.
4. Consider every vertex as an intermediate vertex.
5. Check whether a shorter path exists through that intermediate vertex.
6. Update the distance matrix.

### Formula

For every intermediate vertex `k`:

\[
D[i][j] =
\min(D[i][j], D[i][k] + D[k][j])
\]

Where:

- `D[i][j]` = Current shortest distance from i to j.
- `D[i][k]` = Distance from i to k.
- `D[k][j]` = Distance from k to j.

### Example

Consider:

```text
A ---- 5 ---- B
|             |
2             1
|             |
C ---- 3 ---- D
```

Floyd-Warshall checks whether travelling through an intermediate vertex provides a shorter path.

### Java Implementation

```java
public class FloydWarshall {

    static final int INF = 999999;

    static void floydWarshall(int[][] graph) {

        int n = graph.length;

        int[][] dist = new int[n][n];

        // Copy original graph
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                dist[i][j] = graph[i][j];
            }
        }

        // Consider each vertex as intermediate
        for (int k = 0; k < n; k++) {

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {

                    if (dist[i][k] != INF
                        && dist[k][j] != INF
                        && dist[i][k] + dist[k][j]
                           < dist[i][j]) {

                        dist[i][j] =
                            dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        System.out.println("Shortest Distance Matrix:");

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (dist[i][j] == INF) {

                    System.out.print("INF ");

                } else {

                    System.out.print(dist[i][j] + " ");
                }
            }

            System.out.println();
        }

        // Negative cycle detection
        for (int i = 0; i < n; i++) {

            if (dist[i][i] < 0) {

                System.out.println(
                    "Negative weight cycle detected"
                );

                return;
            }
        }
    }

    public static void main(String[] args) {

        int[][] graph = {

            {0, 5, 2, INF},

            {5, 0, INF, 1},

            {2, INF, 0, 3},

            {INF, 1, 3, 0}
        };

        floydWarshall(graph);
    }
}
```

Output:

```text
Shortest Distance Matrix:
0 5 2 5
5 0 4 1
2 4 0 3
5 1 3 0
```

### Complexity

| Complexity | Value |
|---|---|
| Time | O(V³) |
| Auxiliary Space | O(V²) |

### Applications

- All-pairs shortest paths.
- Network routing analysis.
- Finding shortest paths in dense graphs.
- Detecting negative-weight cycles.
- Transitive closure (with a Boolean variant).

---

# 10. Dijkstra vs Floyd-Warshall

| Feature | Dijkstra | Floyd-Warshall |
|---|---|---|
| Purpose | Single-source shortest path | All-pairs shortest path |
| Approach | Greedy | Dynamic Programming |
| Negative Edges | Not supported | Supported |
| Negative Cycles | Not supported | Can detect them |
| Matrix Implementation Time | O(V²) | O(V³) |
| Priority Queue Implementation | O((V + E) log V) | Not applicable |
| Space | O(V) auxiliary for matrix version | O(V²) auxiliary |
| Best Use | Single-source shortest paths with non-negative weights | Shortest paths between all vertex pairs |

### Level Setting vs Level Correcting

In the syllabus terminology:

- **Level Setting:** Dijkstra's algorithm settles vertices in increasing order of their shortest tentative distance.
- **Level Correcting:** Floyd-Warshall repeatedly improves path estimates using intermediate vertices.

---

# 11. Spanning Trees

A **Spanning Tree** is a subgraph of a connected, undirected graph that:

1. Includes all vertices.
2. Is connected.
3. Contains no cycles.

A spanning tree of a graph with `V` vertices contains exactly:

\[
V - 1
\]

edges.

### Example

Original graph:

```text
       A -------- B
       | \        |
       |  \       |
       C -------- D
```

One possible spanning tree:

```text
       A -------- B
       |
       C -------- D
```

All vertices are connected without any cycle.

### Important Properties

- Contains all vertices.
- Contains exactly V - 1 edges.
- Has no cycles.
- Removing any edge disconnects the spanning tree.
- Adding any extra edge creates a cycle.

---

# 12. Minimum Spanning Tree (MST)

A **Minimum Spanning Tree** is a spanning tree having the minimum possible total edge weight among all spanning trees of a connected, weighted, undirected graph.

### Example

Consider a weighted graph:

```text
          10
      A ------- B
      | \       |
     6|  \15    |5
      |   \     |
      C ------- D
          4
```

The goal is to connect all vertices with minimum total cost without creating cycles.

### Applications of MST

- Designing computer networks.
- Connecting cities through roads.
- Electrical power distribution.
- Water pipeline networks.
- Telecommunications infrastructure.

### MST Algorithms

1. Prim's Algorithm
2. Kruskal's Algorithm

---

# 13. Prim's Algorithm

Prim's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree of a connected, weighted, undirected graph.

It starts from any vertex and repeatedly selects the minimum-weight edge connecting a vertex already in the MST to a vertex outside the MST.

### Working Principle

1. Select any starting vertex.
2. Mark it as included in the MST.
3. Find the minimum-weight edge connecting the MST to an unvisited vertex.
4. Add that edge and vertex to the MST.
5. Repeat until all vertices are included.

### Example

Consider:

```text
          10
      A ------- B
      | \       |
     6|  \15    |5
      |   \     |
      C ------- D
          4
```

Starting vertex = A.

Possible selection:

```text
A -- C = 6

C -- D = 4

D -- B = 5
```

Minimum Spanning Tree:

```text
A --6-- C --4-- D --5-- B
```

Total weight:

\[
6 + 4 + 5 = 15
\]

### Java Implementation of Prim's Algorithm

The following implementation uses an adjacency matrix.

```java
import java.util.Arrays;

public class PrimMST {

    static final int INF = 999999;

    static int minKey(
        int[] key,
        boolean[] mstSet,
        int n
    ) {

        int min = INF;

        int minIndex = -1;

        for (int i = 0; i < n; i++) {

            if (!mstSet[i] && key[i] < min) {

                min = key[i];

                minIndex = i;
            }
        }

        return minIndex;
    }

    static void prim(int[][] graph) {

        int n = graph.length;

        int[] parent = new int[n];

        int[] key = new int[n];

        boolean[] mstSet = new boolean[n];

        Arrays.fill(key, INF);

        Arrays.fill(parent, -1);

        key[0] = 0;

        for (int count = 0; count < n; count++) {

            int u = minKey(key, mstSet, n);

            if (u == -1) {
                System.out.println(
                    "Graph is disconnected; MST does not exist."
                );
                return;
            }

            mstSet[u] = true;

            for (int v = 0; v < n; v++) {

                if (graph[u][v] != 0
                    && !mstSet[v]
                    && graph[u][v] < key[v]) {

                    parent[v] = u;

                    key[v] = graph[u][v];
                }
            }
        }

        int totalWeight = 0;

        System.out.println("Edges in MST:");

        for (int i = 1; i < n; i++) {

            System.out.println(
                parent[i] + " - " + i
                + " : " + graph[i][parent[i]]
            );

            totalWeight += graph[i][parent[i]];
        }

        System.out.println(
            "Total MST Weight: " + totalWeight
        );
    }

    public static void main(String[] args) {

        int[][] graph = {

            {0, 10, 6, 15},

            {10, 0, 0, 5},

            {6, 0, 0, 4},

            {15, 5, 4, 0}
        };

        prim(graph);
    }
}
```

Output:

```text
Edges in MST:
2 - 1 : 10
0 - 2 : 6
2 - 3 : 4

Total MST Weight: 20
```

**Note:** This output is correct for the graph represented in the code, whose edges are A-B=10, A-C=6, A-D=15, B-D=5, and C-D=4. Its MST is A-C, C-D, and D-B, with total weight 15. The printed edge-selection output above should therefore be treated as an illustration of the expected format, not the expected numerical result. The correct output for this implementation is:

```text
Edges in MST:
0 - 1 : 10
0 - 2 : 6
2 - 3 : 4

Total MST Weight: 20
```

**Correction to the example:** The code's `minKey` selection produces the edges A-C (6), C-D (4), and D-B (5), so the correct total is 15. The `parent` array output for vertex B is 3, not 0. The correct result is:

```text
Edges in MST:
3 - 1 : 5
0 - 2 : 6
2 - 3 : 4

Total MST Weight: 15
```

### Complexity

For the adjacency matrix implementation:

- Time Complexity: O(V²)
- Auxiliary Space: O(V)

With an adjacency list and priority queue:

- Time Complexity: O((V + E) log V), using a binary heap.

---

# 14. Kruskal's Algorithm

Kruskal's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree.

It sorts all edges by weight and selects the smallest edge that does not form a cycle.

It commonly uses a Disjoint Set Union (DSU), also called Union-Find.

### Working Principle

1. Sort all edges in increasing order of weight.
2. Start with an empty MST.
3. Select the smallest-weight edge.
4. Check whether adding it creates a cycle.
5. If it does not create a cycle, add it to the MST.
6. If it creates a cycle, reject it.
7. Repeat until the MST contains V - 1 edges.

### Example

Consider:

```text
          10
      A ------- B
      | \       |
     6|  \15    |5
      |   \     |
      C ------- D
          4
```

Edges sorted by weight:

| Edge | Weight |
|---|---:|
| C-D | 4 |
| B-D | 5 |
| A-C | 6 |
| A-B | 10 |
| A-D | 15 |

Select:

1. C-D = 4
2. B-D = 5
3. A-C = 6

All vertices are connected without a cycle.

MST:

```text
A --6-- C --4-- D --5-- B
```

Total weight:

\[
4 + 5 + 6 = 15
\]

### Java Implementation of Kruskal's Algorithm

```java
import java.util.*;

class Edge implements Comparable<Edge> {

    int src;
    int dest;
    int weight;

    Edge(int src, int dest, int weight) {

        this.src = src;

        this.dest = dest;

        this.weight = weight;
    }

    @Override
    public int compareTo(Edge other) {

        return Integer.compare(
            this.weight,
            other.weight
        );
    }
}

public class KruskalMST {

    static int[] parent;

    static int[] rank;

    // Find with path compression
    static int find(int x) {

        if (parent[x] != x) {

            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    // Union by rank
    static void union(int x, int y) {

        int rootX = find(x);

        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        if (rank[rootX] < rank[rootY]) {

            parent[rootX] = rootY;

        } else if (rank[rootX] > rank[rootY]) {

            parent[rootY] = rootX;

        } else {

            parent[rootY] = rootX;

            rank[rootX]++;
        }
    }

    static void kruskal(int vertices, List<Edge> edges) {

        parent = new int[vertices];

        rank = new int[vertices];

        for (int i = 0; i < vertices; i++) {

            parent[i] = i;
        }

        Collections.sort(edges);

        int totalWeight = 0;

        int edgeCount = 0;

        System.out.println("Edges in MST:");

        for (Edge edge : edges) {

            int root1 = find(edge.src);

            int root2 = find(edge.dest);

            if (root1 != root2) {

                System.out.println(
                    edge.src + " - " + edge.dest
                    + " : " + edge.weight
                );

                totalWeight += edge.weight;

                union(root1, root2);

                edgeCount++;

                if (edgeCount == vertices - 1) {
                    break;
                }
            }
        }

        if (edgeCount != vertices - 1) {

            System.out.println(
                "Graph is disconnected; no spanning tree exists."
            );

        } else {

            System.out.println(
                "Total MST Weight: " + totalWeight
            );
        }
    }

    public static void main(String[] args) {

        int vertices = 4;

        List<Edge> edges = new ArrayList<>();

        edges.add(new Edge(0, 1, 10));

        edges.add(new Edge(0, 2, 6));

        edges.add(new Edge(0, 3, 15));

        edges.add(new Edge(1, 3, 5));

        edges.add(new Edge(2, 3, 4));

        kruskal(vertices, edges);
    }
}
```

Output:

```text
Edges in MST:
2 - 3 : 4
1 - 3 : 5
0 - 2 : 6

Total MST Weight: 15
```

### Complexity

- Sorting edges: O(E log E)
- Union-Find operations: Nearly O(1) amortized per operation.
- Overall Time Complexity: O(E log E)
- Auxiliary Space: O(V), excluding the edge list.

---

# 15. Prim's vs Kruskal's Algorithm

| Feature | Prim's Algorithm | Kruskal's Algorithm |
|---|---|---|
| Approach | Greedy | Greedy |
| Starting Point | Starts from a vertex | Starts from the smallest edge |
| Selection | Minimum edge connecting MST to a new vertex | Minimum edge that does not form a cycle |
| Data Structure | Priority Queue / Matrix | Sorting + Disjoint Set |
| Cycle Handling | Avoids adding visited vertices | Uses Union-Find |
| Suitable For | Often useful for dense graphs with matrix implementation | Often useful for sparse graphs |
| Time Complexity | O(V²) with matrix | O(E log E) |
| Result | Minimum Spanning Tree | Minimum Spanning Tree |

**Important:** Both algorithms find an MST for a connected, weighted, undirected graph. For a disconnected graph, they can instead produce a minimum spanning forest.

---

# 16. Shortest Path vs Minimum Spanning Tree

These two concepts are different.

| Shortest Path | Minimum Spanning Tree |
|---|---|
| Finds the minimum-cost path between vertices. | Connects all vertices with minimum total edge weight. |
| Can be calculated from one source or all pairs. | Covers all vertices of a connected undirected graph. |
| Dijkstra and Floyd-Warshall are examples. | Prim and Kruskal are examples. |
| Does not necessarily minimize total network connection cost. | Minimizes total weight of the selected connecting edges. |

---

# 17. Complexity Summary

Let:
- V = Number of vertices
- E = Number of edges

| Algorithm / Operation | Time Complexity | Auxiliary Space |
|---|---|---|
| Adjacency Matrix Construction | O(V² + E) | O(V²) |
| Adjacency List Construction | O(V + E) | O(V + E) |
| BFS (Adjacency List) | O(V + E) | O(V) |
| DFS (Adjacency List) | O(V + E) | O(V) |
| Dijkstra (Matrix) | O(V²) | O(V) |
| Dijkstra (Priority Queue) | O((V + E) log V) | O(V + E) |
| Floyd-Warshall | O(V³) | O(V²) |
| Prim (Matrix) | O(V²) | O(V) |
| Prim (Priority Queue) | O((V + E) log V) | O(V + E) |
| Kruskal | O(E log E) | O(V), excluding edge storage |

---

# 18. Required Lab Programs

According to the ACTS syllabus, the following programs are required.

## Lab 1: Implement a Graph Using Adjacency Matrix and Traverse Using DFS

Tasks:

- Create a graph with vertices.
- Create an adjacency matrix.
- Add edges between vertices.
- Accept a starting vertex.
- Implement DFS using recursion or stack.
- Display traversal order.

## Lab 2: Implement a Graph and Perform Traversal Using Stack and Queue

Tasks:

- Create a graph using an adjacency list.
- Implement BFS using a Queue.
- Implement DFS using a Stack.
- Accept a starting vertex.
- Mark visited vertices.
- Display traversal order.

### Complete Java Lab Program

This program supports:

- Graph creation.
- Adjacency matrix representation.
- DFS using recursion.
- DFS using Stack.
- BFS using Queue.

```java
import java.util.*;

public class GraphTraversal {

    int vertices;

    int[][] graph;

    GraphTraversal(int vertices) {

        this.vertices = vertices;

        graph = new int[vertices][vertices];
    }

    // Add undirected edge
    void addEdge(int u, int v) {

        graph[u][v] = 1;

        graph[v][u] = 1;
    }

    // DFS using recursion
    void dfsRecursive(int start) {

        boolean[] visited = new boolean[vertices];

        System.out.print("Recursive DFS: ");

        dfsUtil(start, visited);

        System.out.println();
    }

    void dfsUtil(int current, boolean[] visited) {

        visited[current] = true;

        System.out.print(current + " ");

        for (int i = 0; i < vertices; i++) {

            if (graph[current][i] == 1
                && !visited[i]) {

                dfsUtil(i, visited);
            }
        }
    }

    // DFS using Stack
    void dfsStack(int start) {

        boolean[] visited = new boolean[vertices];

        Stack<Integer> stack = new Stack<>();

        stack.push(start);

        System.out.print("Stack DFS: ");

        while (!stack.isEmpty()) {

            int current = stack.pop();

            if (!visited[current]) {

                visited[current] = true;

                System.out.print(current + " ");

                // Push neighbors in reverse order
                for (int i = vertices - 1; i >= 0; i--) {

                    if (graph[current][i] == 1
                        && !visited[i]) {

                        stack.push(i);
                    }
                }
            }
        }

        System.out.println();
    }

    // BFS using Queue
    void bfs(int start) {

        boolean[] visited = new boolean[vertices];

        Queue<Integer> queue = new LinkedList<>();

        visited[start] = true;

        queue.add(start);

        System.out.print("Queue BFS: ");

        while (!queue.isEmpty()) {

            int current = queue.poll();

            System.out.print(current + " ");

            for (int i = 0; i < vertices; i++) {

                if (graph[current][i] == 1
                    && !visited[i]) {

                    visited[i] = true;

                    queue.add(i);
                }
            }
        }

        System.out.println();
    }

    // Display adjacency matrix
    void display() {

        System.out.println("Adjacency Matrix:");

        for (int i = 0; i < vertices; i++) {

            for (int j = 0; j < vertices; j++) {

                System.out.print(graph[i][j] + " ");
            }

            System.out.println();
        }
    }

    public static void main(String[] args) {

        GraphTraversal g = new GraphTraversal(6);

        g.addEdge(0, 1);

        g.addEdge(0, 2);

        g.addEdge(1, 3);

        g.addEdge(1, 4);

        g.addEdge(2, 5);

        g.display();

        g.dfsRecursive(0);

        g.dfsStack(0);

        g.bfs(0);
    }
}
```

### Expected Output

```text
Adjacency Matrix:
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 0 1
0 1 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0

Recursive DFS: 0 1 3 4 2 5
Stack DFS: 0 1 3 4 2 5
Queue BFS: 0 1 2 3 4 5
```

**Note:** These traversals start from vertex 0 and assume the graph is connected. For disconnected graphs, repeat traversal from every unvisited vertex to visit all components.

---

# 19. Important Interview Questions

**Q1. What is a graph?**

A graph is a non-linear data structure consisting of vertices and edges.

**Q2. What is a vertex?**

A vertex is a node in a graph.

**Q3. What is an edge?**

An edge is a connection between two vertices.

**Q4. What is a directed graph?**

A graph in which edges have a specific direction.

**Q5. What is an undirected graph?**

A graph in which edges do not have a direction.

**Q6. What is a weighted graph?**

A graph in which edges have associated weights or costs.

**Q7. What is an adjacency matrix?**

A two-dimensional array representing connections between vertices.

**Q8. What is an adjacency list?**

A representation where each vertex stores its neighboring vertices.

**Q9. Which data structure is used in BFS?**

Queue.

**Q10. Which data structure is used in DFS?**

Stack or recursion.

**Q11. What is the time complexity of BFS?**

O(V + E) using an adjacency list.

**Q12. What is the time complexity of DFS?**

O(V + E) using an adjacency list.

**Q13. Does BFS find the shortest path?**

Yes, for unweighted graphs, BFS finds a shortest path in terms of number of edges.

**Q14. What is Dijkstra's algorithm?**

A greedy algorithm that finds shortest paths from one source vertex to all other reachable vertices in a graph with non-negative edge weights.

**Q15. Can Dijkstra handle negative weights?**

No, the standard Dijkstra algorithm does not correctly support negative-weight edges.

**Q16. What is Floyd-Warshall?**

A Dynamic Programming algorithm that finds shortest paths between all pairs of vertices.

**Q17. What is the time complexity of Floyd-Warshall?**

O(V³).

**Q18. What is a spanning tree?**

A connected, acyclic subgraph containing all vertices of a connected undirected graph.

**Q19. How many edges does a spanning tree contain?**

V - 1 edges.

**Q20. What is a Minimum Spanning Tree?**

A spanning tree with the minimum possible total edge weight.

**Q21. What is Prim's algorithm?**

A greedy algorithm that builds an MST by repeatedly selecting the minimum edge connecting the current tree to a new vertex.

**Q22. What is Kruskal's algorithm?**

A greedy algorithm that sorts edges and selects the smallest edges that do not create cycles.

**Q23. Which data structure is used in Kruskal's algorithm?**

Disjoint Set Union (Union-Find).

**Q24. What is the difference between a shortest path and an MST?**

A shortest path minimizes the cost of a path between vertices, whereas an MST minimizes the total cost of connecting all vertices.

**Q25. What is a DAG?**

A Directed Acyclic Graph is a directed graph without any directed cycle.

---

# 20. Multiple Choice Questions (MCQs)

**Q1. A graph consists of:**

- A. Arrays and pointers
- B. Vertices and edges
- C. Stacks and queues
- D. Only nodes

**Answer:** B

**Q2. Which representation uses a two-dimensional array?**

- A. Adjacency List
- B. Adjacency Matrix
- C. Linked List
- D. Stack

**Answer:** B

**Q3. Which graph has edges with directions?**

- A. Undirected Graph
- B. Directed Graph
- C. Complete Graph
- D. Simple Graph

**Answer:** B

**Q4. Which graph contains edge weights?**

- A. Unweighted Graph
- B. Weighted Graph
- C. Acyclic Graph
- D. Simple Graph

**Answer:** B

**Q5. Which data structure is used by BFS?**

- A. Stack
- B. Queue
- C. Tree
- D. Hash Table

**Answer:** B

**Q6. Which data structure is used by iterative DFS?**

- A. Queue
- B. Stack
- C. Heap
- D. HashMap

**Answer:** B

**Q7. What is the time complexity of BFS using an adjacency list?**

- A. O(V²)
- B. O(V + E)
- C. O(E²)
- D. O(log V)

**Answer:** B

**Q8. Which representation is suitable for sparse graphs?**

- A. Adjacency Matrix
- B. Adjacency List
- C. Two-dimensional array only
- D. Stack

**Answer:** B

**Q9. Which algorithm finds shortest paths from a single source with non-negative edge weights?**

- A. Prim
- B. Kruskal
- C. Dijkstra
- D. Floyd-Warshall

**Answer:** C

**Q10. Dijkstra's algorithm is based on:**

- A. Dynamic Programming
- B. Greedy Approach
- C. Backtracking
- D. Divide and Conquer

**Answer:** B

**Q11. Which algorithm finds all-pairs shortest paths?**

- A. BFS
- B. DFS
- C. Floyd-Warshall
- D. Prim

**Answer:** C

**Q12. What is the time complexity of Floyd-Warshall?**

- A. O(V)
- B. O(V²)
- C. O(V³)
- D. O(E log V)

**Answer:** C

**Q13. Floyd-Warshall is based on:**

- A. Greedy
- B. Dynamic Programming
- C. Linear Search
- D. Recursion only

**Answer:** B

**Q14. What is a spanning tree?**

- A. A tree containing only leaf nodes
- B. A connected acyclic subgraph containing all vertices
- C. A graph containing cycles
- D. A disconnected graph

**Answer:** B

**Q15. How many edges does a spanning tree with V vertices contain?**

- A. V
- B. V + 1
- C. V - 1
- D. 2V

**Answer:** C

**Q16. Which algorithms are used to find Minimum Spanning Trees?**

- A. BFS and DFS
- B. Dijkstra and Floyd-Warshall
- C. Prim and Kruskal
- D. Merge Sort and Quick Sort

**Answer:** C

**Q17. Prim's algorithm starts with:**

- A. An edge
- B. A vertex
- C. A sorted list
- D. A queue

**Answer:** B

**Q18. Kruskal's algorithm selects edges based on:**

- A. Largest weight first
- B. Smallest weight first
- C. Random order
- D. Vertex degree only

**Answer:** B

**Q19. Which data structure helps Kruskal's algorithm detect cycles efficiently?**

- A. Queue
- B. Stack
- C. Disjoint Set Union
- D. Binary Search Tree

**Answer:** C

**Q20. Which algorithm can handle negative edge weights but not negative-weight cycles?**

- A. Dijkstra
- B. Floyd-Warshall
- C. Prim
- D. BFS

**Answer:** B

---

# 21. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Graph | Collection of vertices and edges |
| Vertex | Node |
| Edge | Connection between vertices |
| Directed Graph | Edges have direction |
| Undirected Graph | Edges have no direction |
| Weighted Graph | Edges contain weights |
| Adjacency Matrix | 2D array representation |
| Adjacency List | List of neighbors |
| BFS | Uses Queue |
| DFS | Uses Stack or Recursion |
| Dijkstra | Single-source shortest path |
| Floyd-Warshall | All-pairs shortest path |
| Spanning Tree | Connected and acyclic, includes all vertices |
| MST | Minimum total edge weight |
| Prim | Builds MST from a starting vertex |
| Kruskal | Sorts edges and avoids cycles |
| DSU | Used for cycle detection in Kruskal |
| DAG | Directed Acyclic Graph |

### Important Formulas

**Graph Representation:**

\[
G = (V,E)
\]

**Handshaking Lemma:**

\[
\sum Degree(v) = 2|E|
\]

**Complete Undirected Graph:**

\[
E = \frac{V(V-1)}{2}
\]

**Spanning Tree Edges:**

\[
E = V-1
\]

**Dijkstra Relaxation:**

\[
dist[v] = \min(dist[v], dist[u] + w)
\]

**Floyd-Warshall:**

\[
D[i][j] = \min(D[i][j],D[i][k]+D[k][j])
\]

---

# 22. Suggested GitHub Folder Structure

```text
Algorithms-and-Data-Structures/
│
├── Sessions-01-03/
│   └── README.md
│
├── Sessions-04-06-Linked-Lists/
│   └── README.md
│
├── Sessions-07-08-Recursion/
│   └── README.md
│
├── Sessions-09-11-Trees/
│   └── README.md
│
├── Sessions-12-14-Searching-Sorting/
│   └── README.md
│
├── Sessions-15-16-Hashing/
│   └── README.md
│
└── Sessions-17-19-Graphs/
    │
    ├── README.md
    │
    ├── GraphRepresentation/
    │   ├── AdjacencyMatrix.java
    │   └── AdjacencyList.java
    │
    ├── GraphTraversal/
    │   ├── BFSGraph.java
    │   ├── DFSGraph.java
    │   ├── IterativeDFS.java
    │   └── GraphTraversal.java
    │
    ├── ShortestPath/
    │   ├── Dijkstra.java
    │   └── FloydWarshall.java
    │
    └── MinimumSpanningTree/
        ├── PrimMST.java
        └── KruskalMST.java
```

---

# 23. Learning Outcomes

After completing Sessions 17, 18 & 19, students should be able to:

- Understand graphs and graph terminology.
- Identify different types of graphs.
- Represent graphs using adjacency matrices.
- Represent graphs using adjacency lists.
- Implement BFS using a Queue.
- Implement DFS using recursion and Stack.
- Understand single-source shortest-path algorithms.
- Implement Dijkstra's algorithm.
- Understand all-pairs shortest paths.
- Implement Floyd-Warshall algorithm.
- Understand spanning trees and Minimum Spanning Trees.
- Implement Prim's algorithm.
- Implement Kruskal's algorithm using Disjoint Set Union.
- Analyze the time and space complexity of graph algorithms.

---

**End of Sessions 17, 18 & 19 – Graphs and Applications**

*Course: Algorithms and Data Structures Using Java | PGCP-AC August 2026 | ACTS Pune*
