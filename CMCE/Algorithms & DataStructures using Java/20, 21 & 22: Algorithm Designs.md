# Sessions 20, 21 & 22: Algorithm Design Techniques

**Course:** Algorithms and Data Structures Using Java  
**Program:** PGCP-AC – August 2026  
**Institute:** ACTS, Pune  
**Duration:** 7 Theory + 7 Lab Hours

---

# 1. Introduction to Algorithm Design

An **Algorithm** is a finite sequence of well-defined instructions used to solve a particular problem.

Algorithm design is the process of developing a logical and efficient approach to solve a computational problem.

A good algorithm should produce correct results while using minimum possible time and memory.

### Characteristics of a Good Algorithm

1. **Correctness:** Produces the expected output for valid inputs.
2. **Efficiency:** Uses less execution time and memory.
3. **Finiteness:** Terminates after a finite number of steps.
4. **Definiteness:** Every instruction should be clear and unambiguous.
5. **Input:** Accepts zero or more inputs.
6. **Output:** Produces at least one result.
7. **Scalability:** Performs well as input size increases.

### Example: Finding the Largest Element

Problem: Find the largest element in an array.

Input:

```text
10, 25, 5, 40, 15
```

Algorithm:

1. Assume the first element is the largest.
2. Compare it with every remaining element.
3. If a larger element is found, update the largest value.
4. Continue until all elements are checked.
5. Return the largest element.

Output:

```text
Largest Element = 40
```

Java Implementation:

```java
public class FindLargest {

    static int findLargest(int[] arr) {

        int max = arr[0];

        for (int i = 1; i < arr.length; i++) {

            if (arr[i] > max) {

                max = arr[i];
            }
        }

        return max;
    }

    public static void main(String[] args) {

        int[] arr = {10, 25, 5, 40, 15};

        System.out.println(findLargest(arr));
    }
}
```

Time Complexity: O(n)

Space Complexity: O(1) auxiliary space.

---

# 2. Writing Efficient Algorithms

An efficient algorithm solves a problem using minimum computational resources.

Two important resources are:

- Time: How long the algorithm takes to execute.
- Space: How much additional memory the algorithm requires.

### Techniques for Writing Efficient Algorithms

1. Choose the appropriate data structure.
2. Avoid unnecessary loops.
3. Avoid repeated calculations.
4. Use suitable searching and sorting techniques.
5. Reduce unnecessary memory allocation.
6. Use recursion carefully.
7. Apply memoization when repeated subproblems occur.
8. Select an appropriate algorithm design technique.
9. Analyze the algorithm before implementation.
10. Consider different input sizes and edge cases.

### Example: Searching an Element

Suppose an array contains 1,000,000 sorted elements.

**Approach 1: Linear Search**

Checks elements one by one.

Time Complexity: O(n)

**Approach 2: Binary Search**

Repeatedly divides the search interval into two halves.

Time Complexity: O(log n)

For large sorted arrays, Binary Search generally requires far fewer comparisons.

### Important Principle

The fastest algorithm is not always the best choice.

The selection depends on:

- Input size.
- Input characteristics.
- Available memory.
- Required accuracy.
- Implementation complexity.
- Problem constraints.

---

# 3. Algorithm Design Techniques

Algorithm Design Techniques are systematic approaches used to solve computational problems.

Different problems require different techniques.

The major techniques in this syllabus are:

1. Divide and Conquer
2. Greedy Algorithm
3. Dynamic Programming
4. Brute Force Algorithm
5. Backtracking Algorithm
6. Branch and Bound Algorithm
7. Stochastic Algorithm

### Comparison

| Technique | Main Idea | Example |
|---|---|---|
| Divide and Conquer | Divide problem into smaller subproblems | Merge Sort |
| Greedy | Select the locally best choice | Prim's Algorithm |
| Dynamic Programming | Store and reuse subproblem results | Fibonacci Memoization |
| Brute Force | Try all possible solutions or candidates | Linear Search |
| Backtracking | Explore and undo choices when invalid | N-Queens |
| Branch and Bound | Explore solutions while pruning using bounds | Travelling Salesperson Problem |
| Stochastic | Use randomness in the algorithm | Randomized Quick Sort |

---

# 4. Analysis of an Algorithm

Algorithm Analysis is the process of evaluating an algorithm's efficiency.

It helps us understand how an algorithm performs when the input size increases.

The main factors are:

- Time Complexity
- Space Complexity
- Best Case
- Average Case
- Worst Case

### Why Is Algorithm Analysis Important?

- Helps compare different algorithms.
- Helps select efficient solutions.
- Predicts performance for large inputs.
- Identifies performance bottlenecks.
- Helps optimize programs.
- Reduces unnecessary resource consumption.

---

# 5. Asymptotic Analysis

Asymptotic Analysis is a mathematical method used to describe the performance of an algorithm as input size grows.

It focuses on the growth rate rather than actual execution time.

The three major asymptotic notations are:

1. Big O – Upper Bound
2. Big Omega – Lower Bound
3. Big Theta – Tight Bound

## 5.1 Big O Notation – O

Big O describes an asymptotic upper bound on the growth of an algorithm.

It is commonly used to express worst-case time complexity.

Example:

```java
for (int i = 0; i < n; i++) {

    System.out.println(i);
}
```

The loop executes n times.

Time Complexity:

\[
O(n)
\]

## 5.2 Big Omega Notation – Ω

Big Omega describes an asymptotic lower bound on the growth of an algorithm.

For example, Linear Search has:

- Best case: Ω(1), when the element is at the first position.
- Worst case: O(n), when the element is at the last position or absent.

## 5.3 Big Theta Notation – Θ

Big Theta describes a tight asymptotic bound when upper and lower bounds have the same growth rate.

Example:

```java
for (int i = 0; i < n; i++) {

    System.out.println(i);
}
```

The loop always executes n times.

Time Complexity:

\[
\Theta(n)
\]

### Comparison

| Notation | Meaning | Description |
|---|---|---|
| O | Upper Bound | Growth does not exceed this asymptotic bound |
| Ω | Lower Bound | Growth is at least this asymptotic bound |
| Θ | Tight Bound | Upper and lower bounds match |

**Important:** Big O is not automatically the exact worst-case complexity, and Big Omega is not automatically the best-case complexity. These notations describe mathematical bounds; best, average, and worst cases describe input scenarios.

---

# 6. Common Time Complexity Classes

| Complexity | Name | Example |
|---|---|---|
| O(1) | Constant | Array element access |
| O(log n) | Logarithmic | Binary Search |
| O(n) | Linear | Linear Search |
| O(n log n) | Linearithmic | Merge Sort |
| O(n²) | Quadratic | Bubble Sort |
| O(n³) | Cubic | Basic Floyd-Warshall |
| O(2ⁿ) | Exponential | Naive recursive Fibonacci |
| O(n!) | Factorial | Generating all permutations |

### Growth Rate Visualization

```text
Input Size Increases
        |
        v
O(1)       → Almost constant
O(log n)   → Very slow growth
O(n)       → Linear growth
O(n log n) → Slightly faster than linear
O(n²)      → Quadratic growth
O(2ⁿ)      → Exponential growth
O(n!)      → Factorial growth
```

### Order of Growth

From generally more efficient to less efficient:

```text
O(1)
  <
O(log n)
  <
O(n)
  <
O(n log n)
  <
O(n²)
  <
O(n³)
  <
O(2ⁿ)
  <
O(n!)
```

This is a comparison of asymptotic growth rates for sufficiently large input sizes.

---

# 7. Rules for Calculating Time Complexity

## Rule 1: Constant Operations

```java
int a = 10;

int b = 20;

int c = a + b;
```

Time Complexity: O(1)

## Rule 2: Single Loop

```java
for (int i = 0; i < n; i++) {

    System.out.println(i);
}
```

Time Complexity: O(n)

## Rule 3: Nested Loops

```java
for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

        System.out.println(i + " " + j);
    }
}
```

Outer loop executes n times.

Inner loop executes n times for every outer iteration.

Total operations:

\[
n \times n = n^2
\]

Time Complexity: O(n²)

## Rule 4: Consecutive Loops

```java
for (int i = 0; i < n; i++) {

    System.out.println(i);
}

for (int j = 0; j < n; j++) {

    System.out.println(j);
}
```

Total operations:

\[
n+n=2n
\]

Time Complexity: O(n)

Constants are ignored in asymptotic analysis.

## Rule 5: Loop Dividing by Two

```java
int i = n;

while (i > 1) {

    i = i / 2;
}
```

Time Complexity: O(log n)

## Rule 6: Recursive Function

```java
static int factorial(int n) {

    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}
```

Time Complexity: O(n)

Auxiliary Space Complexity: O(n), due to recursive calls.

---

# 8. Time Complexity and Space Complexity

## 8.1 Time Complexity

Time Complexity measures how the number of operations performed by an algorithm grows with input size.

It does not necessarily represent the exact execution time in seconds.

Example:

```java
for (int i = 0; i < n; i++) {

    System.out.println(i);
}
```

Time Complexity: O(n)

## 8.2 Space Complexity

Space Complexity measures the memory required by an algorithm as input size increases.

It can include:

- Input storage.
- Auxiliary variables.
- Temporary data structures.
- Recursion stack.
- Dynamically allocated memory.

**Auxiliary Space** specifically refers to the extra memory used by an algorithm, excluding the input storage itself.

### Example 1: Constant Auxiliary Space

```java
static int sum(int[] arr) {

    int total = 0;

    for (int value : arr) {

        total += value;
    }

    return total;
}
```

Time Complexity: O(n)

Auxiliary Space Complexity: O(1)

The input array is not counted as auxiliary space.

### Example 2: Linear Auxiliary Space

```java
static int[] copyArray(int[] arr) {

    int[] copy = new int[arr.length];

    for (int i = 0; i < arr.length; i++) {

        copy[i] = arr[i];
    }

    return copy;
}
```

Time Complexity: O(n)

Auxiliary Space Complexity: O(n)

### Example 3: Recursive Space

```java
static int factorial(int n) {

    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}
```

Time Complexity: O(n)

Auxiliary Space Complexity: O(n)

Because each recursive call requires stack memory.

### Time vs Space Complexity

| Feature | Time Complexity | Space Complexity |
|---|---|---|
| Measures | Operations | Memory usage |
| Main Concern | Execution efficiency | Memory efficiency |
| Example | O(n) | O(n) |
| Depends On | Input size and algorithm | Input size and memory allocation |

---

# 9. Best Case, Average Case and Worst Case

Algorithm performance can vary depending on the input.

## Best Case

Minimum number of operations required for an input of a given size.

## Average Case

Expected number of operations over a specified input distribution.

## Worst Case

Maximum number of operations required for an input of a given size.

### Example: Linear Search

Array:

```text
10, 20, 30, 40, 50
```

Search element = 10:

- Found at first position.
- Best Case: O(1)

Search element = 30:

- Found after checking three elements.
- Average behavior depends on the input distribution.
- Under a uniformly random successful search position, expected comparisons are approximately (n + 1) / 2, giving Θ(n).

Search element = 50 or an absent element:

- All elements may need to be checked.
- Worst Case: O(n)

### Complexity Table

| Case | Description | Linear Search |
|---|---|---|
| Best | First position | O(1) |
| Average | Typical position | O(n) |
| Worst | Last position or absent | O(n) |

---

# 10. Divide and Conquer Algorithm

Divide and Conquer is an algorithm design technique that divides a large problem into smaller subproblems, solves them independently, and combines their results.

### Three Main Steps

1. Divide – Break the problem into smaller subproblems.
2. Conquer – Solve the subproblems recursively.
3. Combine – Combine their solutions.

### General Structure

```text
          Problem
             |
          Divide
             |
       -------------
       |           |
   Subproblem  Subproblem
       |           |
     Solve       Solve
       |           |
       -------------
             |
          Combine
             |
          Solution
```

### Examples

- Merge Sort
- Quick Sort
- Binary Search

## Example: Merge Sort

Merge Sort divides an array into two halves until each part contains one element.

Then it merges the smaller sorted parts.

Input:

```text
38, 27, 43, 3
```

Division:

```text
          38 27 43 3
           /       \
        38 27      43 3
        /  \       /  \
       38  27     43   3
```

Merging:

```text
       27 38       3 43
            \     /
          3 27 38 43
```

Output:

```text
3, 27, 38, 43
```

### Java Implementation

```java
public class MergeSort {

    static void mergeSort(int[] arr, int left, int right) {

        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }

    static void merge(
        int[] arr,
        int left,
        int mid,
        int right
    ) {

        int n1 = mid - left + 1;

        int n2 = right - mid;

        int[] L = new int[n1];

        int[] R = new int[n2];

        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }

        for (int j = 0; j < n2; j++) {
            R[j] = arr[mid + 1 + j];
        }

        int i = 0;

        int j = 0;

        int k = left;

        while (i < n1 && j < n2) {

            if (L[i] <= R[j]) {

                arr[k++] = L[i++];

            } else {

                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++];
        }

        while (j < n2) {
            arr[k++] = R[j++];
        }
    }

    public static void main(String[] args) {

        int[] arr = {38, 27, 43, 3, 9, 82, 10};

        mergeSort(arr, 0, arr.length - 1);

        for (int value : arr) {

            System.out.print(value + " ");
        }
    }
}
```

Output:

```text
3 9 10 27 38 43 82
```

### Complexity

| Case | Time Complexity |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |

Auxiliary Space: O(n)

---

# 11. Greedy Algorithm

A Greedy Algorithm makes the locally best choice at each step with the goal of finding a globally optimal solution.

It does not generally reconsider previous choices.

### Working Principle

1. Identify available choices.
2. Select the best immediate choice.
3. Check whether the choice is valid.
4. Add it to the solution.
5. Repeat until the problem is solved.

### Examples

- Activity Selection
- Fractional Knapsack
- Prim's Algorithm
- Kruskal's Algorithm
- Dijkstra's Algorithm (non-negative edge weights)

### Example: Activity Selection

Suppose activities have start and finish times:

| Activity | Start | Finish |
|---|---:|---:|
| A1 | 1 | 3 |
| A2 | 2 | 5 |
| A3 | 4 | 6 |
| A4 | 6 | 8 |
| A5 | 5 | 9 |

Goal: Select the maximum number of non-overlapping activities.

Greedy strategy:

Select the activity that finishes earliest among the available activities.

Selected activities:

```text
A1 → A3 → A4
```

### Java Implementation

```java
import java.util.Arrays;
import java.util.Comparator;

public class ActivitySelection {

    static void selectActivities(
        int[][] activities
    ) {

        Arrays.sort(
            activities,
            Comparator.comparingInt(a -> a[1])
        );

        int lastFinish = -1;

        System.out.println("Selected Activities:");

        for (int[] activity : activities) {

            int start = activity[0];

            int finish = activity[1];

            if (start >= lastFinish) {

                System.out.println(
                    start + " - " + finish
                );

                lastFinish = finish;
            }
        }
    }

    public static void main(String[] args) {

        int[][] activities = {

            {1, 3},

            {2, 5},

            {4, 6},

            {6, 8},

            {5, 9}
        };

        selectActivities(activities);
    }
}
```

Output:

```text
Selected Activities:
1 - 3
4 - 6
6 - 8
```

### Complexity

- Sorting: O(n log n)
- Selection: O(n)
- Overall: O(n log n)
- Auxiliary Space: O(1) excluding sorting implementation details and input storage.

### Advantages

- Often simple and fast.
- Can produce optimal solutions for suitable problems.
- Uses relatively little additional memory.

### Disadvantages

- A locally optimal choice does not always produce a globally optimal solution.
- Correctness requires proof that the greedy choice is safe.

---

# 12. Dynamic Programming Algorithm

Dynamic Programming (DP) is an algorithm design technique that solves problems by breaking them into overlapping subproblems and storing their results to avoid repeated calculations.

### Main Properties

1. **Overlapping Subproblems:** The same smaller problems occur repeatedly.
2. **Optimal Substructure:** An optimal solution can be constructed from optimal solutions to subproblems.

### Two Approaches

**1. Memoization – Top-Down**

- Uses recursion.
- Stores previously calculated results.
- Reuses stored results.

**2. Tabulation – Bottom-Up**

- Uses iteration.
- Solves smaller subproblems first.
- Builds the final solution step by step.

## Example: Fibonacci Using Dynamic Programming

Fibonacci Sequence:

```text
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
```

Mathematical definition:

\[
F(n) = F(n-1) + F(n-2)
\]

### Normal Recursive Approach

```java
static int fib(int n) {

    if (n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}
```

Time Complexity: O(2ⁿ) upper bound.

### Memoization Approach

```java
import java.util.HashMap;
import java.util.Map;

public class FibonacciMemo {

    static Map<Integer, Long> memo = new HashMap<>();

    static long fib(int n) {

        if (n <= 1) {
            return n;
        }

        if (memo.containsKey(n)) {
            return memo.get(n);
        }

        long result = fib(n - 1) + fib(n - 2);

        memo.put(n, result);

        return result;
    }

    public static void main(String[] args) {

        System.out.println(fib(50));
    }
}
```

Expected Time Complexity: O(n)

Auxiliary Space: O(n).

### Tabulation Approach

```java
public class FibonacciDP {

    static long fib(int n) {

        if (n <= 1) {
            return n;
        }

        long[] dp = new long[n + 1];

        dp[0] = 0;

        dp[1] = 1;

        for (int i = 2; i <= n; i++) {

            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    public static void main(String[] args) {

        System.out.println(fib(50));
    }
}
```

Time Complexity: O(n)

Auxiliary Space: O(n).

### Space-Optimized Fibonacci

Only the previous two values are required.

```java
public class FibonacciOptimized {

    static long fib(int n) {

        if (n <= 1) {
            return n;
        }

        long prev2 = 0;

        long prev1 = 1;

        for (int i = 2; i <= n; i++) {

            long current = prev1 + prev2;

            prev2 = prev1;

            prev1 = current;
        }

        return prev1;
    }

    public static void main(String[] args) {

        System.out.println(fib(50));
    }
}
```

Time Complexity: O(n)

Auxiliary Space: O(1).

**Note:** Java `long` supports Fibonacci values only through F(92). Use `BigInteger` for larger values.

### Applications of Dynamic Programming

- Fibonacci sequence
- 0/1 Knapsack
- Longest Common Subsequence
- Matrix Chain Multiplication
- Coin Change
- Floyd-Warshall Algorithm
- Shortest-path problems

---

# 13. Brute Force Algorithm

Brute Force is a straightforward algorithm design technique that tries all possible candidates or directly checks possibilities until a solution is found.

It usually does not use advanced optimization techniques.

### Working Principle

1. Generate or examine possible candidates.
2. Check whether a candidate satisfies the required condition.
3. Return a valid solution or continue searching.
4. Stop when the required result is found or all candidates are exhausted.

### Example: Linear Search

```java
public class LinearSearch {

    static int search(int[] arr, int key) {

        for (int i = 0; i < arr.length; i++) {

            if (arr[i] == key) {

                return i;
            }
        }

        return -1;
    }

    public static void main(String[] args) {

        int[] arr = {10, 20, 30, 40, 50};

        System.out.println(search(arr, 30));
    }
}
```

Output:

```text
2
```

Time Complexity:

- Best: O(1)
- Average: O(n)
- Worst: O(n)

Auxiliary Space: O(1).

### Other Examples

- Checking all pairs in an array.
- Trying all permutations.
- Simple password combination enumeration.
- Naive string matching.

### Advantages

- Simple to understand.
- Easy to implement.
- Useful for small inputs.
- Can serve as a reference solution for checking optimized algorithms.

### Disadvantages

- Can be inefficient for large inputs.
- May require exponential or factorial time.
- Often performs unnecessary work.

---

# 14. Backtracking Algorithm

Backtracking is an algorithm design technique that explores possible solutions step by step.

When a choice cannot lead to a valid solution, the algorithm reverses that choice and tries another option.

It follows the principle:

**Choose → Explore → Undo**

### Working Principle

1. Start with an empty or partial solution.
2. Select a possible choice.
3. Check whether the choice is valid.
4. If valid, continue recursively.
5. If invalid or unsuccessful, undo the choice.
6. Try another option.

### Example: N-Queens Problem

The N-Queens problem asks us to place N queens on an N × N chessboard so that no two queens attack each other.

Queens must not share:

- The same row.
- The same column.
- The same diagonal.

### Example: 4-Queens Problem

One valid arrangement:

```text
. Q . .
. . . Q
Q . . .
. . Q .
```

`Q` represents a queen.

`.` represents an empty cell.

### Java Implementation

```java
public class NQueens {

    static int N = 4;

    static boolean isSafe(
        int[][] board,
        int row,
        int col
    ) {

        // Check same column
        for (int i = 0; i < row; i++) {

            if (board[i][col] == 1) {
                return false;
            }
        }

        // Check upper-left diagonal
        for (
            int i = row - 1, j = col - 1;
            i >= 0 && j >= 0;
            i--, j--
        ) {

            if (board[i][j] == 1) {
                return false;
            }
        }

        // Check upper-right diagonal
        for (
            int i = row - 1, j = col + 1;
            i >= 0 && j < N;
            i--, j++
        ) {

            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    static boolean solve(int[][] board, int row) {

        if (row == N) {
            return true;
        }

        for (int col = 0; col < N; col++) {

            if (isSafe(board, row, col)) {

                board[row][col] = 1;

                if (solve(board, row + 1)) {
                    return true;
                }

                // Backtrack
                board[row][col] = 0;
            }
        }

        return false;
    }

    public static void main(String[] args) {

        int[][] board = new int[N][N];

        if (solve(board, 0)) {

            for (int[] row : board) {

                for (int value : row) {

                    System.out.print(
                        value == 1 ? "Q " : ". "
                    );
                }

                System.out.println();
            }

        } else {

            System.out.println("No solution found");
        }
    }
}
```

### Complexity

For the simple row-by-row implementation:

- Worst-case Time Complexity: O(N!), as an upper-bound description of the search.
- Auxiliary Space: O(N) for recursion, excluding the board; O(N²) if the board itself is counted as extra storage.

The actual running time depends on pruning and the number of valid partial arrangements explored.

### Applications

- N-Queens
- Sudoku Solver
- Maze Solving
- Graph Coloring
- Hamiltonian Cycle
- Generating combinations and permutations

---

# 15. Branch and Bound Algorithm

Branch and Bound is an algorithm design technique used for optimization problems.

It explores possible solutions by dividing the problem into branches and calculating bounds to eliminate branches that cannot improve the current best solution.

### Main Concepts

**Branching:** Dividing a problem into smaller decision paths.

**Bounding:** Calculating a bound on the best possible result from a branch.

**Pruning:** Discarding a branch that cannot improve the current best solution.

### Working Principle

1. Start with the original problem.
2. Divide it into smaller branches.
3. Calculate a bound for each branch.
4. Compare the bound with the current best solution.
5. Prune branches that cannot improve the best solution.
6. Continue exploring promising branches.
7. Return the optimal solution.

### Example: 0/1 Knapsack

Suppose a bag has a maximum capacity of 10 kg.

| Item | Weight | Value |
|---|---:|---:|
| A | 2 | 40 |
| B | 3 | 50 |
| C | 5 | 100 |
| D | 4 | 60 |

Goal: Select items without exceeding the capacity and maximize total value.

Branch and Bound explores include/exclude decisions.

```text
                Start
               /     \
          Include A  Exclude A
            /             \
        Include B       Exclude B
          /   \           /   \
         ...  ...        ...  ...
```

A branch can be pruned if its upper bound is not better than the best solution already found.

### Applications

- Travelling Salesperson Problem
- 0/1 Knapsack
- Job Assignment Problem
- Scheduling Problems
- Integer Programming

### Backtracking vs Branch and Bound

| Feature | Backtracking | Branch and Bound |
|---|---|---|
| Main Goal | Find feasible solutions | Find optimal solution |
| Pruning | Based on constraint violations or inability to complete a solution | Based on bounds on solution quality |
| Main Use | Constraint satisfaction | Optimization |
| Examples | N-Queens, Sudoku | Knapsack, TSP |
| Search | Usually depth-first | May use DFS, BFS or best-first strategies |

---

# 16. Stochastic Algorithms

A Stochastic Algorithm uses randomness or probability during its execution.

It may produce different execution paths or results for different runs, even with the same input.

Randomness can help explore large search spaces and avoid certain worst-case patterns.

### Examples

- Randomized Quick Sort
- Monte Carlo Algorithms
- Las Vegas Algorithms
- Randomized Search
- Simulated Annealing

## 16.1 Randomized Quick Sort

Quick Sort selects a pivot and partitions the array around it.

In Randomized Quick Sort, the pivot is selected randomly to reduce the chance of repeatedly getting highly unbalanced partitions for particular input arrangements.

### Java Implementation

```java
import java.util.Random;

public class RandomizedQuickSort {

    static Random random = new Random();

    static void quickSort(int[] arr, int low, int high) {

        if (low < high) {

            int pivotIndex = partition(arr, low, high);

            quickSort(arr, low, pivotIndex - 1);

            quickSort(arr, pivotIndex + 1, high);
        }
    }

    static int partition(int[] arr, int low, int high) {

        int randomIndex =
            low + random.nextInt(high - low + 1);

        swap(arr, randomIndex, high);

        int pivot = arr[high];

        int i = low - 1;

        for (int j = low; j < high; j++) {

            if (arr[j] <= pivot) {

                i++;

                swap(arr, i, j);
            }
        }

        swap(arr, i + 1, high);

        return i + 1;
    }

    static void swap(int[] arr, int i, int j) {

        int temp = arr[i];

        arr[i] = arr[j];

        arr[j] = temp;
    }

    public static void main(String[] args) {

        int[] arr = {50, 20, 40, 10, 30};

        quickSort(arr, 0, arr.length - 1);

        for (int value : arr) {

            System.out.print(value + " ");
        }
    }
}
```

Output:

```text
10 20 30 40 50
```

### Complexity

| Case | Time Complexity |
|---|---|
| Expected | O(n log n) |
| Worst | O(n²) |

Auxiliary Space:

- Expected recursion stack: O(log n).
- Worst-case recursion stack: O(n).

Randomized pivot selection reduces dependence on the original input order but does not eliminate the theoretical O(n²) worst case.

## 16.2 Monte Carlo Algorithms

Monte Carlo algorithms use randomness and have a bounded running time, but may produce an incorrect answer with a small probability.

## 16.3 Las Vegas Algorithms

Las Vegas algorithms use randomness but always produce a correct answer when they terminate. Their running time is variable.

### Monte Carlo vs Las Vegas

| Feature | Monte Carlo | Las Vegas |
|---|---|---|
| Correctness | May have a small error probability | Always correct |
| Running Time | Usually bounded | Variable |
| Randomness | Affects result accuracy | Affects execution path/time |
| Example | Randomized primality testing | Randomized Quick Sort |

---

# 17. Case Study: Choosing the Right Algorithm Design Technique

Consider a delivery company that needs to plan routes, manage deliveries, and allocate limited resources.

Different problems require different algorithm design techniques.

| Problem | Suitable Technique | Example Algorithm |
|---|---|---|
| Sort delivery records | Divide and Conquer | Merge Sort |
| Select maximum non-overlapping jobs | Greedy | Activity Selection |
| Calculate repeated route subproblems | Dynamic Programming | Floyd-Warshall |
| Find an element in a small unsorted list | Brute Force | Linear Search |
| Solve a route with constraints | Backtracking | Hamiltonian Path Search |
| Find the best route under cost limits | Branch and Bound | TSP Branch and Bound |
| Explore randomized search paths | Stochastic | Randomized Search |

### Case Study: Route Planning

Suppose a delivery company has several locations connected through roads.

Requirements:

1. Find the shortest route from the warehouse to a destination.
2. Connect all warehouses using minimum network cost.
3. Visit locations in a suitable order.
4. Store location-to-location connections efficiently.

Suitable data structures and algorithms:

| Requirement | Data Structure / Algorithm |
|---|---|
| Represent locations | Graph |
| Store connections | Adjacency List |
| Find shortest route from one source | Dijkstra |
| Find all-pairs shortest paths | Floyd-Warshall |
| Connect all locations at minimum cost | Prim / Kruskal |
| Track visited locations | Boolean Array / HashSet |
| Store route information | Queue / Priority Queue |

### Key Learning

The correct algorithm depends on the actual problem, input constraints, and optimization objective.

---

# 18. Real-World Applications of Data Structures and Algorithms

| Data Structure / Algorithm | Real-World Application |
|---|---|
| Array | Image processing, storing records |
| Linked List | Music playlists, dynamic collections |
| Stack | Browser history, function calls |
| Queue | Printer scheduling, task processing |
| Circular Queue | CPU scheduling, buffering |
| Tree | File systems, hierarchical data |
| Binary Search Tree | Ordered data storage |
| AVL Tree | Balanced searching |
| Heap | Priority scheduling |
| Hash Table | Caching, database indexing |
| Graph | Social networks, maps |
| BFS | Shortest path in unweighted networks |
| DFS | Maze solving, connectivity analysis |
| Dijkstra | GPS route calculation |
| Floyd-Warshall | All-pairs route analysis |
| Prim / Kruskal | Network infrastructure design |
| Merge Sort | Large-scale data sorting |
| Quick Sort | General-purpose sorting |
| Dynamic Programming | Resource optimization |
| Backtracking | Puzzle solving |
| Branch and Bound | Scheduling and optimization |

---

# 19. Comparison of Major Algorithm Design Techniques

| Technique | Strategy | Optimality | Common Example |
|---|---|---|---|
| Divide and Conquer | Divide, solve, combine | Depends on algorithm | Merge Sort |
| Greedy | Choose locally best option | Only for suitable problems | Prim |
| Dynamic Programming | Store subproblem results | For suitable optimal-substructure problems | Knapsack |
| Brute Force | Try possible candidates | Can find exact solution if exhaustive | Linear Search |
| Backtracking | Explore and undo choices | Can find exact solutions if search is complete | N-Queens |
| Branch and Bound | Explore and prune using bounds | Can find optimal solution with valid bounds and complete search | TSP |
| Stochastic | Use randomness | Depends on algorithm | Randomized Quick Sort |

---

# 20. Comparison of Algorithms Studied in Previous Sessions

This section is especially important for the Sessions 20–22 lab.

| Algorithm | Technique | Best Time | Average / Expected Time | Worst Time | Auxiliary Space |
|---|---|---|---|---|---|
| Linear Search | Brute Force | O(1) | O(n) | O(n) | O(1) |
| Binary Search | Divide and Conquer | O(1) | O(log n) | O(log n) | O(1) iterative |
| Bubble Sort | Comparison Based | O(n) optimized | O(n²) | O(n²) | O(1) |
| Selection Sort | Comparison Based | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | Incremental / Insertion | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | Divide and Conquer | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | Divide and Conquer | O(n log n) | O(n log n) expected | O(n²) | Expected O(log n) stack |
| Heap Sort | Heap Based | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Fibonacci Recursion | Recursion | - | Exponential | O(2ⁿ) upper bound | O(n) |
| Fibonacci Memoization | Dynamic Programming | O(n) | O(n) expected | O(n) | O(n) |
| BFS | Graph Traversal | O(V + E) | O(V + E) | O(V + E) | O(V) |
| DFS | Graph Traversal | O(V + E) | O(V + E) | O(V + E) | O(V) |
| Dijkstra | Greedy | O(V²) matrix | O((V + E) log V) with binary heap | Depends on implementation | O(V + E) with adjacency list |
| Floyd-Warshall | Dynamic Programming | O(V³) | O(V³) | O(V³) | O(V²) |
| Prim | Greedy | O(V²) matrix | O((V + E) log V) with binary heap | Depends on implementation | O(V + E) with adjacency list |
| Kruskal | Greedy | O(E log E) | O(E log E) | O(E log E) | O(V), excluding edge storage |

**Note:** Complexity depends on the specific implementation and data structure. For example, iterative Binary Search uses O(1) auxiliary space, while recursive Binary Search uses O(log n) stack space.

---

# 21. Lab: Compare Different Algorithms and Perform Analysis

The syllabus requires comparing previously programmed algorithms and analyzing their performance.

### Lab Objectives

1. Implement multiple algorithms.
2. Test them with different input sizes.
3. Measure execution time.
4. Analyze time complexity.
5. Analyze auxiliary space complexity.
6. Compare theoretical and observed performance.
7. Identify the most suitable algorithm for a particular problem.

## 21.1 Java Program: Compare Searching Algorithms

```java
import java.util.Arrays;

public class SearchingComparison {

    static int linearSearch(int[] arr, int key) {

        for (int i = 0; i < arr.length; i++) {

            if (arr[i] == key) {
                return i;
            }
        }

        return -1;
    }

    static int binarySearch(int[] arr, int key) {

        int low = 0;

        int high = arr.length - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {

                return mid;

            } else if (arr[mid] < key) {

                low = mid + 1;

            } else {

                high = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {

        int n = 1000000;

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {

            arr[i] = i + 1;
        }

        int key = n;

        long start = System.nanoTime();

        int linearResult = linearSearch(arr, key);

        long linearTime =
            System.nanoTime() - start;

        start = System.nanoTime();

        int binaryResult = binarySearch(arr, key);

        long binaryTime =
            System.nanoTime() - start;

        System.out.println(
            "Linear Search Result: " + linearResult
        );

        System.out.println(
            "Linear Search Time: " + linearTime + " ns"
        );

        System.out.println(
            "Binary Search Result: " + binaryResult
        );

        System.out.println(
            "Binary Search Time: " + binaryTime + " ns"
        );
    }
}
```

### Expected Theoretical Comparison

| Algorithm | Input Requirement | Time Complexity |
|---|---|---|
| Linear Search | Sorted or unsorted | O(n) worst case |
| Binary Search | Sorted data | O(log n) worst case |

**Observation:** Binary Search usually requires fewer comparisons for large sorted arrays. Actual execution time depends on hardware, JVM warm-up, input, and measurement conditions.

## 21.2 Java Program: Compare Sorting Algorithms

The following program compares Bubble Sort, Insertion Sort, Selection Sort, and Merge Sort.

```java
import java.util.Arrays;
import java.util.Random;

public class SortingComparison {

    static void bubbleSort(int[] arr) {

        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {

            boolean swapped = false;

            for (int j = 0; j < n - i - 1; j++) {

                if (arr[j] > arr[j + 1]) {

                    int temp = arr[j];

                    arr[j] = arr[j + 1];

                    arr[j + 1] = temp;

                    swapped = true;
                }
            }

            if (!swapped) {
                break;
            }
        }
    }

    static void insertionSort(int[] arr) {

        for (int i = 1; i < arr.length; i++) {

            int key = arr[i];

            int j = i - 1;

            while (j >= 0 && arr[j] > key) {

                arr[j + 1] = arr[j];

                j--;
            }

            arr[j + 1] = key;
        }
    }

    static void selectionSort(int[] arr) {

        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {

            int minIndex = i;

            for (int j = i + 1; j < n; j++) {

                if (arr[j] < arr[minIndex]) {

                    minIndex = j;
                }
            }

            int temp = arr[i];

            arr[i] = arr[minIndex];

            arr[minIndex] = temp;
        }
    }

    static void mergeSort(int[] arr, int left, int right) {

        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }

    static void merge(
        int[] arr,
        int left,
        int mid,
        int right
    ) {

        int[] temp = new int[right - left + 1];

        int i = left;

        int j = mid + 1;

        int k = 0;

        while (i <= mid && j <= right) {

            if (arr[i] <= arr[j]) {

                temp[k++] = arr[i++];

            } else {

                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (int x = 0; x < temp.length; x++) {

            arr[left + x] = temp[x];
        }
    }

    static void measure(
        String name,
        int[] original,
        int algorithm
    ) {

        int[] arr = Arrays.copyOf(
            original,
            original.length
        );

        long start = System.nanoTime();

        switch (algorithm) {

            case 1:
                bubbleSort(arr);
                break;

            case 2:
                insertionSort(arr);
                break;

            case 3:
                selectionSort(arr);
                break;

            case 4:
                mergeSort(arr, 0, arr.length - 1);
                break;
        }

        long end = System.nanoTime();

        System.out.println(
            name + ": " + (end - start) + " ns"
        );

        if (!isSorted(arr)) {

            System.out.println("Sorting failed!");
        }
    }

    static boolean isSorted(int[] arr) {

        for (int i = 1; i < arr.length; i++) {

            if (arr[i - 1] > arr[i]) {

                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {

        int n = 5000;

        int[] original = new int[n];

        Random random = new Random(42);

        for (int i = 0; i < n; i++) {

            original[i] = random.nextInt(100000);
        }

        measure("Bubble Sort", original, 1);

        measure("Insertion Sort", original, 2);

        measure("Selection Sort", original, 3);

        measure("Merge Sort", original, 4);
    }
}
```

### Theoretical Comparison

| Algorithm | Best | Average | Worst |
|---|---|---|---|
| Bubble Sort (optimized) | O(n) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |

### Important Experimental Notes

- Use the same input data for all algorithms.
- Give each algorithm its own copy of the original array.
- Test multiple input sizes.
- Test sorted, reverse-sorted, and random input.
- Verify that each output is sorted.
- Run multiple trials and compare average times.
- JVM warm-up and garbage collection can affect measurements.
- Use theoretical complexity to explain observed results.

**Important:** Do not compare algorithms using different input arrays or different input sizes.

---

# 22. Practical Algorithm Analysis Report Format

For your lab record, use the following structure.

### Experiment: Performance Comparison of Searching Algorithms

**Objective:** Compare Linear Search and Binary Search based on time complexity and execution time.

**Input:** Sorted integer array containing n elements.

| Input Size | Linear Search Time | Binary Search Time |
|---:|---:|---:|
| 100 | Record result | Record result |
| 1,000 | Record result | Record result |
| 10,000 | Record result | Record result |
| 100,000 | Record result | Record result |
| 1,000,000 | Record result | Record result |

**Theoretical Analysis:**

- Linear Search: O(n)
- Binary Search: O(log n)

**Conclusion:** Binary Search is generally more efficient for large sorted datasets, while Linear Search can work directly on unsorted data.

### Experiment: Performance Comparison of Sorting Algorithms

**Objective:** Compare different sorting algorithms using the same input data.

| Input Size | Bubble Sort | Insertion Sort | Selection Sort | Merge Sort |
|---:|---:|---:|---:|---:|
| 100 | Record | Record | Record | Record |
| 500 | Record | Record | Record | Record |
| 1,000 | Record | Record | Record | Record |
| 5,000 | Record | Record | Record | Record |
| 10,000 | Record | Record | Record | Record |

**Conclusion:** Merge Sort generally performs better for larger random datasets due to its O(n log n) time complexity. Simple quadratic sorting algorithms may still be suitable for small or nearly sorted inputs.

---

# 23. Important Interview Questions

**Q1. What is an algorithm?**

An algorithm is a finite sequence of well-defined instructions used to solve a problem.

**Q2. What is algorithm analysis?**

It is the process of evaluating an algorithm's time and space requirements.

**Q3. What is asymptotic analysis?**

It describes how an algorithm's resource requirements grow as input size increases.

**Q4. What is Big O notation?**

It describes an asymptotic upper bound on growth.

**Q5. What is Omega notation?**

It describes an asymptotic lower bound on growth.

**Q6. What is Theta notation?**

It describes a tight asymptotic bound.

**Q7. What is time complexity?**

It measures how the number of operations grows with input size.

**Q8. What is space complexity?**

It measures the memory required by an algorithm.

**Q9. What is auxiliary space?**

It is the extra memory used by an algorithm, excluding input storage.

**Q10. What is Divide and Conquer?**

It divides a problem into smaller subproblems, solves them, and combines their results.

**Q11. Give examples of Divide and Conquer.**

Merge Sort, Quick Sort and Binary Search.

**Q12. What is a Greedy Algorithm?**

It makes the locally best choice at each step.

**Q13. What is Dynamic Programming?**

It stores and reuses solutions to overlapping subproblems.

**Q14. What is Memoization?**

It is a top-down Dynamic Programming technique that stores previously calculated results.

**Q15. What is Tabulation?**

It is a bottom-up Dynamic Programming technique that builds solutions iteratively.

**Q16. What is Brute Force?**

It tries possible candidates directly without relying on advanced optimization.

**Q17. What is Backtracking?**

It explores choices and reverses decisions when they cannot lead to a valid solution.

**Q18. What is Branch and Bound?**

It explores solution branches and uses bounds to eliminate branches that cannot improve the current best solution.

**Q19. What is a Stochastic Algorithm?**

It uses randomness or probability during execution.

**Q20. What is the difference between Monte Carlo and Las Vegas algorithms?**

Monte Carlo algorithms may return an incorrect result with a small probability, while Las Vegas algorithms always return a correct result when they terminate.

**Q21. Which algorithm design technique is used in Merge Sort?**

Divide and Conquer.

**Q22. Which technique is used in Prim's and Kruskal's algorithms?**

Greedy.

**Q23. Which technique is used in Fibonacci Memoization?**

Dynamic Programming.

**Q24. Which technique is used in N-Queens?**

Backtracking.

**Q25. Which technique is used in Travelling Salesperson optimization using bounds?**

Branch and Bound.

---

# 24. Multiple Choice Questions (MCQs)

**Q1. What is an algorithm?**

- A. A programming language
- B. A finite sequence of instructions
- C. A database
- D. An operating system

**Answer:** B

**Q2. Which notation represents an asymptotic upper bound?**

- A. Omega
- B. Theta
- C. Big O
- D. Delta

**Answer:** C

**Q3. Which notation represents a tight asymptotic bound?**

- A. Big O
- B. Big Omega
- C. Big Theta
- D. Big Alpha

**Answer:** C

**Q4. Which complexity represents constant time?**

- A. O(n)
- B. O(1)
- C. O(n²)
- D. O(log n)

**Answer:** B

**Q5. Which algorithm has O(log n) worst-case time complexity?**

- A. Linear Search
- B. Binary Search
- C. Bubble Sort
- D. Selection Sort

**Answer:** B

**Q6. Which algorithm design technique divides a problem into smaller subproblems?**

- A. Greedy
- B. Divide and Conquer
- C. Brute Force
- D. Stochastic

**Answer:** B

**Q7. Which algorithm uses Divide and Conquer?**

- A. Merge Sort
- B. Linear Search
- C. Selection Sort
- D. Bubble Sort

**Answer:** A

**Q8. Which technique selects the locally best option?**

- A. Dynamic Programming
- B. Greedy
- C. Backtracking
- D. Brute Force

**Answer:** B

**Q9. Which algorithm design technique stores previous results?**

- A. Brute Force
- B. Dynamic Programming
- C. Selection Sort
- D. Linear Search

**Answer:** B

**Q10. Which technique uses Memoization?**

- A. Dynamic Programming
- B. Brute Force
- C. Selection Sort
- D. Linear Search

**Answer:** A

**Q11. Which technique explores a choice and undoes it when necessary?**

- A. Greedy
- B. Backtracking
- C. Divide and Conquer
- D. Stochastic

**Answer:** B

**Q12. Which problem is commonly solved using Backtracking?**

- A. N-Queens
- B. Binary Search
- C. Merge Sort
- D. Linear Search

**Answer:** A

**Q13. Which technique uses bounds to eliminate unpromising branches?**

- A. Greedy
- B. Branch and Bound
- C. Divide and Conquer
- D. Brute Force

**Answer:** B

**Q14. Which algorithm uses randomness to select a pivot?**

- A. Merge Sort
- B. Randomized Quick Sort
- C. Selection Sort
- D. Binary Search

**Answer:** B

**Q15. Which algorithm has O(n log n) time complexity in all cases?**

- A. Bubble Sort
- B. Insertion Sort
- C. Merge Sort
- D. Linear Search

**Answer:** C

**Q16. What is the worst-case time complexity of Quick Sort?**

- A. O(n)
- B. O(n log n)
- C. O(n²)
- D. O(log n)

**Answer:** C

**Q17. What is the auxiliary space complexity of iterative Binary Search?**

- A. O(n)
- B. O(log n)
- C. O(1)
- D. O(n²)

**Answer:** C

**Q18. What is the auxiliary space complexity of Merge Sort for an array implementation?**

- A. O(1)
- B. O(log n)
- C. O(n)
- D. O(n²)

**Answer:** C

**Q19. Which algorithm design technique is used by Floyd-Warshall?**

- A. Greedy
- B. Dynamic Programming
- C. Brute Force
- D. Backtracking

**Answer:** B

**Q20. Which algorithm design technique is used by Prim's algorithm?**

- A. Greedy
- B. Dynamic Programming
- C. Backtracking
- D. Brute Force

**Answer:** A

---

# 25. Quick Revision Notes

| Topic | Important Point |
|---|---|
| Algorithm | Finite sequence of instructions |
| Efficient Algorithm | Uses computational resources effectively |
| Algorithm Analysis | Evaluates time and space requirements |
| Asymptotic Analysis | Studies growth as input increases |
| Big O | Upper bound |
| Big Omega | Lower bound |
| Big Theta | Tight bound |
| Time Complexity | Growth of operations |
| Space Complexity | Growth of memory requirements |
| Auxiliary Space | Extra memory used |
| Divide and Conquer | Divide, conquer, combine |
| Greedy | Locally best choice |
| Dynamic Programming | Store and reuse results |
| Brute Force | Directly examine candidates |
| Backtracking | Choose, explore, undo |
| Branch and Bound | Branch and prune using bounds |
| Stochastic | Uses randomness |
| Memoization | Top-down DP |
| Tabulation | Bottom-up DP |
| Monte Carlo | May have a small error probability |
| Las Vegas | Correct result with variable running time |

### Important Complexity Orders

\[
O(1) < O(\log n) < O(n) < O(n\log n)
\]

\[
< O(n^2) < O(n^3) < O(2^n) < O(n!)
\]

---

# 26. Suggested GitHub Folder Structure

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
├── Sessions-17-19-Graphs/
│   └── README.md
│
└── Sessions-20-22-Algorithm-Design/
    │
    ├── README.md
    │
    ├── AsymptoticAnalysis/
    │   └── ComplexityExamples.java
    │
    ├── DivideAndConquer/
    │   ├── MergeSort.java
    │   └── QuickSort.java
    │
    ├── Greedy/
    │   └── ActivitySelection.java
    │
    ├── DynamicProgramming/
    │   ├── FibonacciMemo.java
    │   ├── FibonacciDP.java
    │   └── FibonacciOptimized.java
    │
    ├── BruteForce/
    │   └── LinearSearch.java
    │
    ├── Backtracking/
    │   └── NQueens.java
    │
    ├── BranchAndBound/
    │   └── Knapsack.java
    │
    ├── Stochastic/
    │   └── RandomizedQuickSort.java
    │
    └── AlgorithmComparison/
        ├── SearchingComparison.java
        └── SortingComparison.java
```

---

# 27. Learning Outcomes

After completing Sessions 20, 21 & 22, students should be able to:

- Understand efficient algorithm design.
- Explain different algorithm design techniques.
- Analyze algorithms using asymptotic notation.
- Calculate time complexity.
- Calculate space and auxiliary space complexity.
- Understand best, average and worst cases.
- Implement Divide and Conquer algorithms.
- Understand Greedy algorithms.
- Implement Dynamic Programming using memoization and tabulation.
- Understand Brute Force algorithms.
- Implement Backtracking algorithms.
- Understand Branch and Bound.
- Understand Stochastic algorithms.
- Identify real-world applications of algorithms and data structures.
- Compare previously implemented algorithms.
- Analyze theoretical and experimental performance.

---

**End of Sessions 20, 21 & 22 – Algorithm Design Techniques**

*Course: Algorithms and Data Structures Using Java | PGCP-AC August 2026 | ACTS Pune*
