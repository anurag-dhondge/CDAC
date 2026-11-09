# Sessions 9, 10 & 11: Trees & Applications

**Course:** Algorithms and Data Structures Using Java  
**Program:** PGCP-AC – August 2026  
**Institute:** ACTS, Pune  
**Duration:** 6 Theory + 6 Lab Hours

---

## 1. Introduction to Trees

A **Tree** is a non-linear hierarchical data structure consisting of nodes connected through edges.

Unlike arrays, stacks, and queues, which are linear data structures, trees represent hierarchical relationships.

Examples of trees in real life:

- File and folder structures
- Organization hierarchies
- Family trees
- HTML DOM structure
- Database indexing
- Decision-making systems

### Basic Tree Structure

```text
              10
             /  \
            20   30
           / \    \
          40  50   60
```

In this tree:
- 10 is the root node.
- 20 and 30 are children of 10.
- 40 and 50 are children of 20.
- 60 is a child of 30.

---

## 2. Tree Terminology

Consider the following tree:

```text
                 A
               /   \
              B     C
             / \   / \
            D   E F   G
               /
              H
```

### Important Terms

| Term | Definition | Example |
|---|---|---|
| Node | Basic element of a tree. | A, B, C |
| Root | Topmost node of a tree. | A |
| Edge | Connection between two nodes. | A-B |
| Parent | A node that has one or more children. | B is parent of D and E |
| Child | Node directly connected below another node. | D is child of B |
| Sibling | Nodes having the same parent. | B and C |
| Leaf Node | Node having no children. | D, F, G, H |
| Internal Node | Node having at least one child. | A, B, C, E |
| Degree of Node | Number of children of a node. | Degree of B = 2 |
| Degree of Tree | Maximum degree of any node in the tree. | 2 |
| Path | Sequence of connected nodes. | A → B → E → H |
| Ancestor | Parent, grandparent, etc. of a node. | A and B are ancestors of H |
| Descendant | Child, grandchild, etc. of a node. | H is a descendant of A |
| Depth | Number of edges from root to a node. | Depth of H = 3 |
| Height of Node | Number of edges on the longest downward path to a leaf. | Height of B = 2 |
| Height of Tree | Height of the root node. | 3 |

**Note:** Height and depth are measured in edges here. Some textbooks count levels or nodes instead, so always check the convention used in class.

### Important Points

- A tree with `n` nodes has exactly `n - 1` edges.
- Every node except the root has exactly one parent in a rooted tree.
- A tree does not contain cycles.
- There is exactly one path between any two nodes in a tree.

---

## 3. Tree Traversals

Tree traversal means visiting every node of a tree in a particular order.

The two major traversal categories are:

1. Breadth First Search (BFS)
2. Depth First Search (DFS)

Consider this binary tree:

```text
                 1
               /   \
              2     3
             / \   / \
            4   5 6   7
```

### A. Breadth First Search (BFS)

BFS visits nodes level by level, from left to right.

It uses a **Queue (FIFO)** data structure.

Traversal:

```text
1 → 2 → 3 → 4 → 5 → 6 → 7
```

Java implementation:

```java
import java.util.LinkedList;
import java.util.Queue;

public void bfs(Node root) {

    if (root == null) {
        return;
    }

    Queue<Node> queue = new LinkedList<>();

    queue.add(root);

    while (!queue.isEmpty()) {

        Node current = queue.poll();

        System.out.print(current.data + " ");

        if (current.left != null) {
            queue.add(current.left);
        }

        if (current.right != null) {
            queue.add(current.right);
        }
    }
}
```

### B. Depth First Search (DFS)

DFS explores one branch as deeply as possible before backtracking.

It can be implemented using recursion or an explicit stack.

DFS has three common traversal orders:

#### 1. PreOrder Traversal

Order:

**Root → Left → Right**

```text
PreOrder: 1 2 4 5 3 6 7
```

Java implementation:

```java
public void preOrder(Node root) {

    if (root == null) {
        return;
    }

    System.out.print(root.data + " ");

    preOrder(root.left);

    preOrder(root.right);
}
```

#### 2. InOrder Traversal

Order:

**Left → Root → Right**

```text
InOrder: 4 2 5 1 6 3 7
```

Java implementation:

```java
public void inOrder(Node root) {

    if (root == null) {
        return;
    }

    inOrder(root.left);

    System.out.print(root.data + " ");

    inOrder(root.right);
}
```

#### 3. PostOrder Traversal

Order:

**Left → Right → Root**

```text
PostOrder: 4 5 2 6 7 3 1
```

Java implementation:

```java
public void postOrder(Node root) {

    if (root == null) {
        return;
    }

    postOrder(root.left);

    postOrder(root.right);

    System.out.print(root.data + " ");
}
```

### Traversal Comparison

| Traversal | Visiting Order | Data Structure |
|---|---|---|
| BFS | Level by level | Queue |
| DFS | Deep first | Stack / Recursion |
| PreOrder | Root, Left, Right | Stack / Recursion |
| InOrder | Left, Root, Right | Stack / Recursion |
| PostOrder | Left, Right, Root | Stack / Recursion |

### Traversal Complexity

For a tree containing `n` nodes:

| Traversal | Time Complexity | Auxiliary Space |
|---|---|---|
| BFS | O(n) | O(w), where w is maximum width |
| PreOrder | O(n) | O(h) |
| InOrder | O(n) | O(h) |
| PostOrder | O(n) | O(h) |

Here, `h` is the height of the tree. Recursive DFS uses the call stack.

---

## 4. Binary Trees

A **Binary Tree** is a tree in which each node can have at most two children.

These children are called:
- Left Child
- Right Child

Example:

```text
             10
            /  \
           20   30
          / \
         40  50
```

### Java Node Structure

```java
class Node {

    int data;

    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
```

### Types of Binary Trees

#### 1. Full Binary Tree

A full binary tree is a binary tree in which every node has either zero or exactly two children.

```text
             10
            /  \
           20   30
          / \
         40  50
```

#### 2. Complete Binary Tree

A complete binary tree has all levels completely filled except possibly the last level.

The last level is filled from left to right without gaps.

```text
             10
            /  \
           20   30
          / \  /
         40 50 60
```

#### 3. Perfect Binary Tree

A perfect binary tree has all internal nodes with exactly two children, and all leaf nodes at the same level.

```text
             10
            /  \
           20   30
          / \   / \
         40 50 60 70
```

#### 4. Skewed Binary Tree

A skewed binary tree has nodes arranged predominantly on one side.

Left-skewed:

```text
        10
       /
      20
     /
    30
   /
  40
```

Right-skewed:

```text
  10
    \
     20
       \
        30
          \
           40
```

### Important Properties of Binary Trees

Assuming the root is at level 0:

- Maximum nodes at level `l`:

\[
2^l
\]

- Maximum nodes in a binary tree of height `h`:

\[
2^{h+1}-1
\]

- Maximum leaf nodes in a binary tree of height `h`:

\[
2^h
\]

- Minimum possible height for `n` nodes:

\[
\lceil \log_2(n+1) \rceil - 1
\]

---

## 5. Complete Binary Tree and Almost Complete Binary Tree (ACBT)

### Complete Binary Tree

A complete binary tree has:
- All levels completely filled except possibly the last level.
- Last level filled from left to right.
- No missing positions before an existing node at the last level.

### Almost Complete Binary Tree (ACBT)

An almost complete binary tree is commonly used to describe a binary tree whose last level may be partially filled, with nodes occupying the leftmost available positions.

Example:

```text
             10
            /  \
           20   30
          / \  /
         40 50 60
```

The final level is filled from left to right.

**Note:** The terms complete binary tree and almost complete binary tree are sometimes used interchangeably in teaching materials. Follow the precise definition used by your ACTS faculty.

---

## 6. Array Implementation of ACBT

An almost complete binary tree can be efficiently represented using an array.

Example tree:

```text
             10
            /  \
           20   30
          / \  /
         40 50 60
```

Array representation:

```text
Index:  0   1   2   3   4   5
Value: 10  20  30  40  50  60
```

### Index Relationships (0-Based Indexing)

For a node at index `i`:

| Relationship | Formula |
|---|---|
| Parent | `(i - 1) / 2` |
| Left Child | `2 * i + 1` |
| Right Child | `2 * i + 2` |

Integer division is used for the parent formula.

### Example

Consider:

```text
             10
            /  \
           20   30
          / \  /
         40 50 60
```

Array:

```text
[10, 20, 30, 40, 50, 60]
```

For node `20` at index 1:

- Parent index = `(1 - 1) / 2 = 0`
- Left child index = `2 * 1 + 1 = 3`
- Right child index = `2 * 1 + 2 = 4`

### Java Implementation

```java
public class ArrayBinaryTree {

    int[] tree;
    int size;

    ArrayBinaryTree(int capacity) {

        tree = new int[capacity];

        size = 0;
    }

    void insert(int data) {

        if (size == tree.length) {
            System.out.println("Tree is full");
            return;
        }

        tree[size] = data;

        size++;
    }

    void display() {

        for (int i = 0; i < size; i++) {
            System.out.print(tree[i] + " ");
        }
    }

    public static void main(String[] args) {

        ArrayBinaryTree bt = new ArrayBinaryTree(10);

        bt.insert(10);
        bt.insert(20);
        bt.insert(30);
        bt.insert(40);
        bt.insert(50);
        bt.insert(60);

        bt.display();
    }
}
```

**Output:**

```text
10 20 30 40 50 60
```

**Important:** Inserting values sequentially into an array creates an ACBT. This does not automatically create a Binary Search Tree.

### Advantages of Array Representation

- Simple implementation.
- No need to store explicit left and right references.
- Parent and child positions can be calculated easily.
- Efficient for complete or almost complete binary trees.

### Disadvantages

- Fixed-size arrays may waste memory.
- Resizing may be required.
- Not suitable for sparse or highly skewed trees.
- Inserting or deleting arbitrary nodes requires maintaining the tree's positional structure.

---

## 7. Binary Search Tree (BST)

A **Binary Search Tree** is a binary tree that follows a specific ordering property.

For every node:

- Values in the left subtree are smaller than the node's value.
- Values in the right subtree are greater than the node's value.
- Both left and right subtrees must also follow the BST property.

Example:

```text
              50
             /  \
            30   70
           / \   / \
          20 40 60 80
```

### BST Properties

1. Left child values are smaller than the parent.
2. Right child values are greater than the parent.
3. InOrder traversal produces sorted values when keys are distinct.
4. Searching, insertion, and deletion depend on tree height.

### Binary Search Tree Visualization

<LearningViz type_id="BINARY_SEARCH_TREE_INSERTION" initial_values={{"insertionSequence":"mixed"}} />

### 7.1 Create a BST

A BST is created by inserting values one by one according to the BST property.

Example insertion sequence:

```text
50, 30, 70, 20, 40, 60, 80
```

Result:

```text
              50
             /  \
            30   70
           / \   / \
          20 40 60 80
```

### 7.2 Searching in BST

Searching starts from the root.

- If the key equals the current node, the element is found.
- If the key is smaller, search the left subtree.
- If the key is greater, search the right subtree.

Java implementation:

```java
Node search(Node root, int key) {

    if (root == null || root.data == key) {
        return root;
    }

    if (key < root.data) {
        return search(root.left, key);
    }

    return search(root.right, key);
}
```

### 7.3 Insertion in BST

Java implementation:

```java
Node insert(Node root, int data) {

    if (root == null) {
        return new Node(data);
    }

    if (data < root.data) {
        root.left = insert(root.left, data);
    }
    else if (data > root.data) {
        root.right = insert(root.right, data);
    }

    return root;
}
```

This implementation ignores duplicate values.

---

## 8. Delete Operation in BST

Deletion is one of the important BST operations.

There are three main cases.

### Case 1: Delete a Leaf Node

A leaf node has no children.

Example: Delete 20.

Before:

```text
             50
            /  \
           30   70
          / \
         20 40
```

After:

```text
             50
            /  \
           30   70
            \
             40
```

Simply remove the node.

### Case 2: Delete a Node with One Child

Replace the node with its only child.

Before:

```text
             50
            /
           30
             \
              40
```

Delete 30.

After:

```text
             50
            /
           40
```

### Case 3: Delete a Node with Two Children

Replace the node with either:
- InOrder Successor: Minimum value in the right subtree.
- InOrder Predecessor: Maximum value in the left subtree.

Example: Delete 50.

Before:

```text
              50
             /  \
            30   70
           / \   / \
          20 40 60 80
```

The InOrder Successor of 50 is 60.

After:

```text
              60
             /  \
            30   70
           / \     \
          20 40     80
```

### Java Delete Implementation

```java
Node delete(Node root, int key) {

    if (root == null) {
        return null;
    }

    if (key < root.data) {

        root.left = delete(root.left, key);

    } else if (key > root.data) {

        root.right = delete(root.right, key);

    } else {

        // Case 1: No child
        if (root.left == null && root.right == null) {
            return null;
        }

        // Case 2: Only right child
        if (root.left == null) {
            return root.right;
        }

        // Case 2: Only left child
        if (root.right == null) {
            return root.left;
        }

        // Case 3: Two children
        Node successor = findMin(root.right);

        root.data = successor.data;

        root.right = delete(root.right, successor.data);
    }

    return root;
}

Node findMin(Node root) {

    while (root.left != null) {
        root = root.left;
    }

    return root;
}
```

---

## 9. Complete Java Program: Binary Search Tree

The following program implements the required lab operations:

- Create()
- BFS
- DFS
- PreOrder
- InOrder
- PostOrder
- Delete()

```java
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Node {

    int data;

    Node left;
    Node right;

    Node(int data) {

        this.data = data;

        left = null;
        right = null;
    }
}

class BinarySearchTree {

    Node root;

    // Create BST by inserting values
    void create(int data) {

        root = insert(root, data);
    }

    // Insert node
    Node insert(Node root, int data) {

        if (root == null) {
            return new Node(data);
        }

        if (data < root.data) {

            root.left = insert(root.left, data);

        } else if (data > root.data) {

            root.right = insert(root.right, data);
        }

        return root;
    }

    // BFS - Level Order Traversal
    void bfs() {

        if (root == null) {
            System.out.println("Tree is empty");
            return;
        }

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);

        while (!queue.isEmpty()) {

            Node current = queue.poll();

            System.out.print(current.data + " ");

            if (current.left != null) {
                queue.add(current.left);
            }

            if (current.right != null) {
                queue.add(current.right);
            }
        }

        System.out.println();
    }

    // DFS - PreOrder, InOrder and PostOrder
    void dfs() {

        System.out.print("PreOrder: ");
        preOrder(root);

        System.out.print("\nInOrder: ");
        inOrder(root);

        System.out.print("\nPostOrder: ");
        postOrder(root);

        System.out.println();
    }

    // PreOrder: Root Left Right
    void preOrder(Node root) {

        if (root == null) {
            return;
        }

        System.out.print(root.data + " ");

        preOrder(root.left);

        preOrder(root.right);
    }

    // InOrder: Left Root Right
    void inOrder(Node root) {

        if (root == null) {
            return;
        }

        inOrder(root.left);

        System.out.print(root.data + " ");

        inOrder(root.right);
    }

    // PostOrder: Left Right Root
    void postOrder(Node root) {

        if (root == null) {
            return;
        }

        postOrder(root.left);

        postOrder(root.right);

        System.out.print(root.data + " ");
    }

    // Delete operation
    void delete(int key) {

        root = deleteNode(root, key);
    }

    Node deleteNode(Node root, int key) {

        if (root == null) {
            return null;
        }

        if (key < root.data) {

            root.left = deleteNode(root.left, key);

        } else if (key > root.data) {

            root.right = deleteNode(root.right, key);

        } else {

            // No child
            if (root.left == null && root.right == null) {
                return null;
            }

            // One child
            if (root.left == null) {
                return root.right;
            }

            if (root.right == null) {
                return root.left;
            }

            // Two children
            Node successor = findMin(root.right);

            root.data = successor.data;

            root.right = deleteNode(root.right, successor.data);
        }

        return root;
    }

    // Find minimum node
    Node findMin(Node root) {

        while (root.left != null) {
            root = root.left;
        }

        return root;
    }
}

public class BSTDemo {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        BinarySearchTree bst = new BinarySearchTree();

        int choice;

        do {

            System.out.println("\n--- BST MENU ---");

            System.out.println("1. Create / Insert");
            System.out.println("2. BFS");
            System.out.println("3. DFS");
            System.out.println("4. PreOrder");
            System.out.println("5. InOrder");
            System.out.println("6. PostOrder");
            System.out.println("7. Delete");
            System.out.println("8. Exit");

            System.out.print("Enter choice: ");

            choice = sc.nextInt();

            switch (choice) {

                case 1:

                    System.out.print("Enter value: ");

                    bst.create(sc.nextInt());

                    break;

                case 2:

                    System.out.print("BFS: ");
                    bst.bfs();

                    break;

                case 3:

                    bst.dfs();

                    break;

                case 4:

                    System.out.print("PreOrder: ");
                    bst.preOrder(bst.root);

                    System.out.println();

                    break;

                case 5:

                    System.out.print("InOrder: ");
                    bst.inOrder(bst.root);

                    System.out.println();

                    break;

                case 6:

                    System.out.print("PostOrder: ");
                    bst.postOrder(bst.root);

                    System.out.println();

                    break;

                case 7:

                    System.out.print("Enter value to delete: ");

                    bst.delete(sc.nextInt());

                    System.out.println("Delete operation completed.");

                    break;

                case 8:

                    System.out.println("Exiting...");

                    break;

                default:

                    System.out.println("Invalid choice");
            }

        } while (choice != 8);

        sc.close();
    }
}
```

### Sample Input

Insert the following values:

```text
50
30
70
20
40
60
80
```

### Expected Traversal Output

```text
BFS:
50 30 70 20 40 60 80

PreOrder:
50 30 20 40 70 60 80

InOrder:
20 30 40 50 60 70 80

PostOrder:
20 40 30 60 80 70 50
```

**Important:** DFS is the general category of depth-first traversal. PreOrder, InOrder, and PostOrder are specific DFS traversal orders.

---

## 10. AVL Tree

An **AVL Tree** is a self-balancing Binary Search Tree.

It maintains its height balance after insertion and deletion operations.

AVL stands for Adelson-Velsky and Landis, named after its inventors.

### Balance Factor

Balance Factor (BF) is calculated as:

\[
BF = Height(LeftSubtree) - Height(RightSubtree)
\]

For an AVL tree, every node must have a balance factor of:

```text
-1, 0, +1
```

If the balance factor becomes less than -1 or greater than +1, rotations are required to restore balance.

### Example of Balanced AVL Tree

```text
             30
            /  \
           20   40
          /       \
         10        50
```

The tree is height-balanced.

### Example of Unbalanced BST

```text
       10
         \
          20
            \
             30
               \
                40
```

This tree is right-skewed.

AVL rotations are used to restore balance.

---

## 11. Types of AVL Rotations

There are four major cases.

### 1. LL Rotation (Left-Left Case)

Occurs when insertion happens in the left subtree of the left child.

Solution: Right Rotation.

Before:

```text
          30
         /
        20
       /
      10
```

After Right Rotation:

```text
          20
         /  \
        10   30
```

### 2. RR Rotation (Right-Right Case)

Occurs when insertion happens in the right subtree of the right child.

Solution: Left Rotation.

Before:

```text
      10
        \
         20
           \
            30
```

After Left Rotation:

```text
          20
         /  \
        10   30
```

### 3. LR Rotation (Left-Right Case)

Occurs when insertion happens in the right subtree of the left child.

Solution:
1. Left rotation on the left child.
2. Right rotation on the unbalanced node.

Before:

```text
          30
         /
        10
          \
           20
```

After:

```text
          20
         /  \
        10   30
```

### 4. RL Rotation (Right-Left Case)

Occurs when insertion happens in the left subtree of the right child.

Solution:
1. Right rotation on the right child.
2. Left rotation on the unbalanced node.

Before:

```text
      10
        \
         30
        /
       20
```

After:

```text
          20
         /  \
        10   30
```

### AVL Rotation Summary

| Case | Imbalance | Rotation |
|---|---|---|
| LL | Left of Left | Right Rotation |
| RR | Right of Right | Left Rotation |
| LR | Right of Left | Left Rotation, then Right Rotation |
| RL | Left of Right | Right Rotation, then Left Rotation |

### AVL Tree Complexity

| Operation | Time Complexity |
|---|---|
| Search | O(log n) |
| Insertion | O(log n) |
| Deletion | O(log n) |
| Traversal | O(n) |

AVL trees maintain logarithmic height through balancing.

---

## 12. BST vs AVL Tree

| Feature | BST | AVL Tree |
|---|---|---|
| Full Form | Binary Search Tree | Adelson-Velsky and Landis Tree |
| Structure | Binary tree with ordering property | Self-balancing BST |
| Balancing | Not guaranteed | Automatically maintained |
| Search | O(log n) average, O(n) worst | O(log n) worst |
| Insertion | O(log n) average, O(n) worst | O(log n) |
| Deletion | O(log n) average, O(n) worst | O(log n) |
| Rotations | Not required | Required when unbalanced |
| Implementation | Simpler | More complex |

---

## 13. Time Complexity Summary

Let:
- `n` = number of nodes
- `h` = height of the tree

| Operation | BST Average | BST Worst | AVL Tree |
|---|---:|---:|---:|
| Search | O(log n) | O(n) | O(log n) |
| Insert | O(log n) | O(n) | O(log n) |
| Delete | O(log n) | O(n) | O(log n) |
| Traversal | O(n) | O(n) | O(n) |

**Important:** BST average-case complexity assumes reasonably balanced tree shapes and suitable insertion patterns. A sorted insertion sequence can create a skewed BST, making its height O(n).

---

## 14. Lab Practice Checklist

### Required Lab: Binary Search Tree

- [ ] Create a BST.
- [ ] Insert multiple values.
- [ ] Implement BFS traversal.
- [ ] Implement DFS traversal.
- [ ] Implement PreOrder traversal.
- [ ] Implement InOrder traversal.
- [ ] Implement PostOrder traversal.
- [ ] Delete a leaf node.
- [ ] Delete a node with one child.
- [ ] Delete a node with two children.
- [ ] Test deletion of the root node.
- [ ] Test searching for an existing and a missing value.

### Additional Practice

- [ ] Count total nodes in a tree.
- [ ] Count leaf nodes.
- [ ] Find the height of a tree.
- [ ] Find the minimum and maximum values in a BST.
- [ ] Search an element in a BST.
- [ ] Implement an ACBT using an array.
- [ ] Implement AVL insertion and rotations.

---

## 15. Important Interview Questions

**Q1. What is a tree?**

A tree is a non-linear hierarchical data structure consisting of nodes connected by edges.

**Q2. What is the root node?**

The root is the topmost node of a tree.

**Q3. What is a leaf node?**

A leaf node is a node that does not have any children.

**Q4. What is the difference between a binary tree and a BST?**

A binary tree allows at most two children per node. A BST additionally follows an ordering rule: left values are smaller and right values are greater than the node, assuming distinct keys.

**Q5. What is tree traversal?**

Tree traversal is the process of visiting every node in a tree.

**Q6. Which data structure is used in BFS?**

Queue.

**Q7. Which data structure is used in DFS?**

Stack or recursion.

**Q8. What is InOrder traversal?**

Left → Root → Right.

**Q9. What is PreOrder traversal?**

Root → Left → Right.

**Q10. What is PostOrder traversal?**

Left → Right → Root.

**Q11. What is an ACBT?**

An almost complete binary tree is a binary tree whose last level may be partially filled from left to right.

**Q12. How is an ACBT represented using an array?**

By storing nodes level by level from left to right and using index formulas to locate parent and children.

**Q13. What is a BST?**

A BST is a binary tree where left subtree values are smaller and right subtree values are greater than the node's value.

**Q14. What is an InOrder Successor?**

The InOrder Successor is the next node in InOrder traversal. In a BST, the successor of a node with a right subtree is the minimum node in that right subtree.

**Q15. What are the three cases of BST deletion?**

1. Leaf node.
2. Node with one child.
3. Node with two children.

**Q16. What is an AVL tree?**

An AVL tree is a self-balancing Binary Search Tree.

**Q17. What is the balance factor?**

Balance Factor = Height of left subtree − Height of right subtree.

**Q18. What are the four AVL rotations?**

LL, RR, LR, and RL.

**Q19. What is the worst-case time complexity of searching in an ordinary BST?**

O(n), when the BST becomes skewed.

**Q20. What is the time complexity of traversing a tree?**

O(n), because every node is visited once.

---

## 16. Multiple Choice Questions (MCQs)

**Q1. A tree is which type of data structure?**

- A. Linear
- B. Non-linear
- C. Sequential
- D. Primitive

**Answer:** B

**Q2. Which node is the topmost node in a tree?**

- A. Leaf
- B. Child
- C. Root
- D. Parent

**Answer:** C

**Q3. A tree containing n nodes has how many edges?**

- A. n
- B. n + 1
- C. n - 1
- D. 2n

**Answer:** C

**Q4. Which traversal uses a Queue?**

- A. PreOrder
- B. InOrder
- C. PostOrder
- D. BFS

**Answer:** D

**Q5. What is the order of PreOrder traversal?**

- A. Left, Root, Right
- B. Root, Left, Right
- C. Left, Right, Root
- D. Right, Root, Left

**Answer:** B

**Q6. What is the order of InOrder traversal?**

- A. Root, Left, Right
- B. Left, Right, Root
- C. Left, Root, Right
- D. Right, Left, Root

**Answer:** C

**Q7. What is the order of PostOrder traversal?**

- A. Root, Left, Right
- B. Left, Root, Right
- C. Right, Root, Left
- D. Left, Right, Root

**Answer:** D

**Q8. Which traversal of a BST gives sorted output when keys are distinct?**

- A. PreOrder
- B. InOrder
- C. PostOrder
- D. BFS

**Answer:** B

**Q9. In a 0-based array representation of a binary tree, the left child of index i is:**

- A. 2i
- B. 2i + 1
- C. 2i + 2
- D. i / 2

**Answer:** B

**Q10. In a BST, smaller values are generally stored in the:**

- A. Right subtree
- B. Left subtree
- C. Root only
- D. Parent only

**Answer:** B

**Q11. Which traversal is used to find the InOrder Successor in a BST?**

- A. BFS
- B. InOrder
- C. PreOrder
- D. PostOrder

**Answer:** B

**Q12. What is the worst-case search complexity of an ordinary BST?**

- A. O(1)
- B. O(log n)
- C. O(n)
- D. O(n²)

**Answer:** C

**Q13. AVL tree is a:**

- A. Linear data structure
- B. Self-balancing BST
- C. Queue
- D. Stack

**Answer:** B

**Q14. Which balance factor values are allowed in an AVL tree?**

- A. 0, 1, 2
- B. -2, 0, 2
- C. -1, 0, +1
- D. 1, 2, 3

**Answer:** C

**Q15. Which rotation is used for an LL imbalance?**

- A. Left Rotation
- B. Right Rotation
- C. Double Left Rotation
- D. No Rotation

**Answer:** B

**Q16. Which rotation is used for an RR imbalance?**

- A. Left Rotation
- B. Right Rotation
- C. Double Right Rotation
- D. No Rotation

**Answer:** A

**Q17. Which rotation is used for an LR imbalance?**

- A. Only Left Rotation
- B. Only Right Rotation
- C. Left Rotation followed by Right Rotation
- D. Right Rotation followed by Left Rotation

**Answer:** C

**Q18. Which rotation is used for an RL imbalance?**

- A. Left Rotation followed by Right Rotation
- B. Right Rotation followed by Left Rotation
- C. Only Left Rotation
- D. Only Right Rotation

**Answer:** B

**Q19. What is the time complexity of traversing all nodes of a tree?**

- A. O(1)
- B. O(log n)
- C. O(n)
- D. O(n²)

**Answer:** C

**Q20. Which data structure is suitable for representing a complete binary tree efficiently?**

- A. Array
- B. Linked List only
- C. Stack
- D. Hash Table

**Answer:** A

---

## 17. Quick Revision Notes

| Topic | Key Point |
|---|---|
| Tree | Non-linear hierarchical structure |
| Root | Topmost node |
| Leaf | Node with no children |
| Edge | Connection between nodes |
| Binary Tree | At most two children |
| Full Binary Tree | Every node has 0 or 2 children |
| Complete Binary Tree | Last level filled from left to right |
| Perfect Binary Tree | All levels completely filled |
| ACBT | Almost complete binary tree |
| BFS | Level-order traversal using Queue |
| DFS | Depth-first traversal using Stack or Recursion |
| PreOrder | Root → Left → Right |
| InOrder | Left → Root → Right |
| PostOrder | Left → Right → Root |
| BST | Left values smaller, right values greater |
| AVL | Self-balancing BST |
| Balance Factor | Left height − Right height |
| LL | Right Rotation |
| RR | Left Rotation |
| LR | Left then Right Rotation |
| RL | Right then Left Rotation |

### Important Array Formulas (0-Based Indexing)

For node index `i`:

```text
Parent      = (i - 1) / 2
Left Child  = 2 * i + 1
Right Child = 2 * i + 2
```

---

## 18. Suggested GitHub Folder Structure

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
└── Sessions-09-11-Trees/
    │
    ├── README.md
    │
    ├── TreeBasics/
    │   ├── TreeTerminology.java
    │   └── TreeTraversals.java
    │
    ├── BinaryTree/
    │   └── ArrayBinaryTree.java
    │
    ├── BST/
    │   ├── BSTDemo.java
    │   ├── BSTInsertion.java
    │   ├── BSTSearch.java
    │   └── BSTDeletion.java
    │
    └── AVLTree/
        ├── AVLInsertion.java
        └── AVLRotations.java
```

---

## 19. Learning Outcomes

After completing Sessions 9, 10 & 11, students should be able to:

- Understand tree data structures and their terminology.
- Identify different types of binary trees.
- Implement BFS and DFS traversals.
- Understand PreOrder, InOrder, and PostOrder traversals.
- Represent an ACBT using an array.
- Create and implement a Binary Search Tree.
- Perform insertion, searching, and deletion in a BST.
- Understand the three cases of BST deletion.
- Understand AVL trees and balance factors.
- Explain and identify LL, RR, LR, and RL rotations.

---

**End of Sessions 9, 10 & 11 – Trees & Applications**

*Course: Algorithms and Data Structures Using Java | PGCP-AC August 2026 | ACTS Pune*
