# Sessions 12, 13 & 14: Searching and Sorting Algorithms

**Course:** Algorithms and Data Structures Using Java  
**Program:** PGCP-AC – August 2026  
**Institute:** ACTS, Pune  
**Duration:** 6 Theory + 6 Lab Hours

---

# 1. Introduction to Searching

Searching is the process of finding a particular element (key) from a collection of data.

The main objective of searching is to determine:

- Whether an element exists in the collection.
- The position or index of the required element.
- How efficiently the element can be found.

### Example

Consider an array:

```java
int[] arr = {10, 20, 30, 40, 50};
```

Search for `30`.

**Output:**
```text
Element found at index 2
```

### Objectives of Searching

1. Find a required element in a collection.
2. Identify the position of an element.
3. Reduce the number of comparisons.
4. Improve searching efficiency.
5. Apply suitable searching techniques based on the data.

### Types of Searching

1. Sequential Search (Linear Search)
2. Binary Search

---

# 2. Sequential Search (Linear Search)

Sequential Search is a searching technique in which each element is checked one by one until the required element is found or the entire collection is traversed.

It works on both sorted and unsorted arrays.

### Example

Array:

```text
[10, 20, 30, 40, 50]
```

Search key = `40`

### Step-by-Step Execution

```text
Step 1: Compare 40 with 10 → Not Found

Step 2: Compare 40 with 20 → Not Found

Step 3: Compare 40 with 30 → Not Found

Step 4: Compare 40 with 40 → Found
```

<LearningViz type_id="BINARY_SEARCH" initial_values={{"target":40}} />

### Java Implementation

```java
public class SequentialSearch {

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

        int key = 40;

        int result = search(arr, key);

        if (result == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println(
                "Element found at index " + result
            );
        }
    }
}
```

**Output:**
```text
Element found at index 3
```

### Analysis of Sequential Search

The number of comparisons depends on the position of the element.

| Case | Condition | Time Complexity |
|---|---|---|
| Best Case | Element found at first position | O(1) |
| Average Case | Element found around the middle | O(n) |
| Worst Case | Element at last position or not found | O(n) |

**Space Complexity:** O(1)

### Advantages

- Simple to understand and implement.
- Works on sorted and unsorted data.
- Does not require additional memory.
- Suitable for small datasets.

### Disadvantages

- Slow for large datasets.
- May require checking every element.
- Less efficient than Binary Search for sorted data.

---

# 3. Binary Search

Binary Search is an efficient searching algorithm that repeatedly divides a sorted collection into two halves.

It compares the search key with the middle element.

**Important:** Binary Search requires the input array to be sorted.

### Working Principle

1. Find the middle element.
2. Compare the middle element with the search key.
3. If both are equal, the element is found.
4. If the key is smaller, search the left half.
5. If the key is greater, search the right half.
6. Repeat until the element is found or the search range becomes empty.

### Example

Sorted array:

```text
[10, 20, 30, 40, 50, 60, 70]
```

Search key = `60`

### Step-by-Step Execution

**Step 1:**

```text
10  20  30  40  50  60  70
            ↑
          Middle = 40
```

Since `60 > 40`, search the right half.

**Step 2:**

```text
50  60  70
    ↑
  Middle = 60
```

Since `60 == 60`, the element is found.

### Java Implementation (Iterative)

```java
public class BinarySearch {

    static int search(int[] arr, int key) {

        int low = 0;

        int high = arr.length - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {

                return mid;

            } else if (key < arr[mid]) {

                high = mid - 1;

            } else {

                low = mid + 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {

        int[] arr = {10, 20, 30, 40, 50, 60, 70};

        int key = 60;

        int result = search(arr, key);

        if (result == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println(
                "Element found at index " + result
            );
        }
    }
}
```

**Output:**
```text
Element found at index 5
```

### Binary Search Using Recursion

```java
public class RecursiveBinarySearch {

    static int search(int[] arr, int low,
                      int high, int key) {

        if (low > high) {
            return -1;
        }

        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (key < arr[mid]) {
            return search(arr, low, mid - 1, key);
        }

        return search(arr, mid + 1, high, key);
    }

    public static void main(String[] args) {

        int[] arr = {10, 20, 30, 40, 50, 60, 70};

        int key = 50;

        int result = search(
            arr, 0, arr.length - 1, key
        );

        System.out.println("Index: " + result);
    }
}
```

### Analysis of Binary Search

At each step, Binary Search reduces the search space to half.

Recurrence relation:

\[
T(n) = T(n/2) + O(1)
\]

| Case | Time Complexity |
|---|---|
| Best Case | O(1) |
| Average Case | O(log n) |
| Worst Case | O(log n) |

Space Complexity:

- Iterative Binary Search: O(1)
- Recursive Binary Search: O(log n)

### Advantages

- Very efficient for large sorted datasets.
- Requires fewer comparisons than Sequential Search.
- Time complexity is O(log n).

### Disadvantages

- Requires sorted data.
- Sorting may add extra cost if data is initially unsorted.
- Array-based Binary Search is not efficient on linked lists because accessing the middle element is not constant time.

---

# 4. Sequential Search vs Binary Search

| Feature | Sequential Search | Binary Search |
|---|---|---|
| Searching Method | Checks one by one | Divides search space into halves |
| Sorted Data Required | No | Yes |
| Best Case | O(1) | O(1) |
| Average Case | O(n) | O(log n) |
| Worst Case | O(n) | O(log n) |
| Space (Iterative) | O(1) | O(1) |
| Implementation | Simple | Comparatively complex |
| Suitable For | Small or unsorted data | Large sorted data |

---

# 5. Introduction to Sorting

Sorting is the process of arranging data in a particular order.

Common sorting orders:

- Ascending Order: Smallest to largest.
- Descending Order: Largest to smallest.

### Example

Unsorted array:

```text
[50, 20, 40, 10, 30]
```

Ascending order:

```text
[10, 20, 30, 40, 50]
```

Descending order:

```text
[50, 40, 30, 20, 10]
```

### Objectives of Sorting

1. Organize data systematically.
2. Make searching easier.
3. Improve data processing.
4. Simplify data analysis.
5. Support efficient algorithms such as Binary Search.

### Sorting Algorithms Covered

1. Selection Sort
2. Insertion Sort
3. Bubble Sort
4. Heap Sort
5. Merge Sort
6. Quick Sort

---

# 6. Selection Sort

Selection Sort repeatedly finds the smallest element from the unsorted portion and places it at the beginning.

### Working Principle

1. Assume the first element is the minimum.
2. Search for the smallest element in the remaining array.
3. Swap it with the first unsorted element.
4. Move to the next position.
5. Repeat until the array is sorted.

### Example

Unsorted array:

```text
[64, 25, 12, 22, 11]
```

**Pass 1:** Find minimum = 11

```text
[11, 25, 12, 22, 64]
```

**Pass 2:** Find minimum = 12

```text
[11, 12, 25, 22, 64]
```

**Pass 3:** Find minimum = 22

```text
[11, 12, 22, 25, 64]
```

**Pass 4:** Find minimum = 25

```text
[11, 12, 22, 25, 64]
```

Sorted array:

```text
[11, 12, 22, 25, 64]
```

<LearningViz type_id="SELECTION_SORT" initial_values={{"order":"6,3,8,2,7,1,5,4"}} />

### Java Implementation

```java
public class SelectionSort {

    static void sort(int[] arr) {

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

    public static void main(String[] args) {

        int[] arr = {64, 25, 12, 22, 11};

        sort(arr);

        for (int x : arr) {
            System.out.print(x + " ");
        }
    }
}
```

**Complexity:**

| Case | Time |
|---|---|
| Best | O(n²) |
| Average | O(n²) |
| Worst | O(n²) |

- Auxiliary Space: O(1)
- Stable: No, in its standard swapping implementation.
- In-place: Yes.

---

# 7. Insertion Sort

Insertion Sort builds a sorted portion of the array one element at a time.

Each new element is inserted into its correct position within the already sorted portion.

It works similarly to arranging playing cards in your hand.

### Working Principle

1. Assume the first element is already sorted.
2. Select the next element as the key.
3. Compare the key with elements in the sorted portion.
4. Shift larger elements one position to the right.
5. Insert the key into its correct position.
6. Repeat until all elements are sorted.

### Example

Unsorted array:

```text
[5, 3, 4, 1, 2]
```

**Pass 1:** Key = 3

```text
[3, 5, 4, 1, 2]
```

**Pass 2:** Key = 4

```text
[3, 4, 5, 1, 2]
```

**Pass 3:** Key = 1

```text
[1, 3, 4, 5, 2]
```

**Pass 4:** Key = 2

```text
[1, 2, 3, 4, 5]
```

<LearningViz type_id="INSERTION_SORT" />

### Java Implementation

```java
public class InsertionSort {

    static void sort(int[] arr) {

        int n = arr.length;

        for (int i = 1; i < n; i++) {

            int key = arr[i];

            int j = i - 1;

            while (j >= 0 && arr[j] > key) {

                arr[j + 1] = arr[j];

                j--;
            }

            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {

        int[] arr = {5, 3, 4, 1, 2};

        sort(arr);

        for (int x : arr) {
            System.out.print(x + " ");
        }
    }
}
```

**Output:**
```text
1 2 3 4 5
```

### Complexity Analysis

| Case | Time |
|---|---|
| Best | O(n) |
| Average | O(n²) |
| Worst | O(n²) |

- Auxiliary Space: O(1)
- Stable: Yes
- In-place: Yes
- Adaptive: Yes (performs well on nearly sorted data).

---

# 8. Bubble Sort

Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.

After every pass, the largest unsorted element moves to its correct position at the end.

### Working Principle

1. Compare adjacent elements.
2. Swap if the left element is greater than the right element.
3. Continue until the end of the array.
4. Repeat for the remaining unsorted portion.
5. Stop when the array is sorted.

### Example

Unsorted array:

```text
[5, 1, 4, 2, 8]
```

**Pass 1:**

```text
5 and 1 → Swap
[1, 5, 4, 2, 8]

5 and 4 → Swap
[1, 4, 5, 2, 8]

5 and 2 → Swap
[1, 4, 2, 5, 8]

5 and 8 → No Swap
[1, 4, 2, 5, 8]
```

**Pass 2:**

```text
[1, 4, 2, 5, 8]
[1, 2, 4, 5, 8]
```

Final sorted array:

```text
[1, 2, 4, 5, 8]
```

<LearningViz type_id="BUBBLE_SORT" initial_values={{"initialOrder":"mixed"}} />

### Java Implementation

```java
public class BubbleSort {

    static void sort(int[] arr) {

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

    public static void main(String[] args) {

        int[] arr = {5, 1, 4, 2, 8};

        sort(arr);

        for (int x : arr) {
            System.out.print(x + " ");
        }
    }
}
```

### Complexity Analysis

| Case | Time |
|---|---|
| Best | O(n), with swap flag optimization |
| Average | O(n²) |
| Worst | O(n²) |

- Auxiliary Space: O(1)
- Stable: Yes
- In-place: Yes

---

# 9. Heap Sort

Heap Sort is a comparison-based sorting algorithm that uses a Binary Heap data structure.

A heap is a complete binary tree that follows a heap property.

### Types of Heap

**1. Max Heap**

Every parent node is greater than or equal to its children.

```text
             50
            /  \
           30   40
          / \
         10 20
```

**2. Min Heap**

Every parent node is smaller than or equal to its children.

```text
             10
            /  \
           20   30
          / \
         40 50
```

### Heap Sort Working Principle (Ascending Order)

1. Build a Max Heap.
2. Swap the root (maximum element) with the last element.
3. Reduce the heap size.
4. Restore the Max Heap property using heapify.
5. Repeat until the heap is sorted.

### Java Implementation

```java
public class HeapSort {

    static void heapify(int[] arr, int n, int i) {

        int largest = i;

        int left = 2 * i + 1;

        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {

            int temp = arr[i];

            arr[i] = arr[largest];

            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }

    static void sort(int[] arr) {

        int n = arr.length;

        // Build Max Heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Extract maximum elements
        for (int i = n - 1; i > 0; i--) {

            int temp = arr[0];

            arr[0] = arr[i];

            arr[i] = temp;

            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {

        int[] arr = {12, 11, 13, 5, 6, 7};

        sort(arr);

        for (int x : arr) {
            System.out.print(x + " ");
        }
    }
}
```

**Output:**
```text
5 6 7 11 12 13
```

### Complexity Analysis

| Case | Time |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |

- Auxiliary Space: O(1) for the iterative heapify implementation; the recursive version above uses O(log n) stack space in the worst case.
- Stable: No
- In-place: Yes, apart from implementation call-stack usage.

---

# 10. Merge Sort

Merge Sort is a Divide and Conquer sorting algorithm.

It divides the array into smaller subarrays, sorts them individually, and merges them to create a sorted array.

### Working Principle

1. Divide the array into two halves.
2. Recursively divide each half.
3. Continue until each subarray contains one element.
4. Merge the smaller sorted arrays.
5. Continue merging until the complete array is sorted.

### Example

Unsorted array:

```text
[38, 27, 43, 3]
```

**Step 1: Divide**

```text
       [38, 27, 43, 3]
          /       \
      [38, 27]  [43, 3]
```

**Step 2: Divide Further**

```text
[38] [27] [43] [3]
```

**Step 3: Merge**

```text
[27, 38]  [3, 43]
```

**Step 4: Final Merge**

```text
[3, 27, 38, 43]
```

<LearningViz type_id="MERGE_SORT" />

### Java Implementation

```java
public class MergeSort {

    static void merge(int[] arr, int left,
                      int mid, int right) {

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

        int i = 0, j = 0, k = left;

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

    static void sort(int[] arr, int left, int right) {

        if (left < right) {

            int mid = left + (right - left) / 2;

            sort(arr, left, mid);

            sort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    public static void main(String[] args) {

        int[] arr = {38, 27, 43, 3, 9, 82, 10};

        sort(arr, 0, arr.length - 1);

        for (int x : arr) {
            System.out.print(x + " ");
        }
    }
}
```

### Complexity Analysis

| Case | Time |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |

- Auxiliary Space: O(n) for arrays and O(log n) recursion stack.
- Stable: Yes, with the implementation shown.
- In-place: No, in the usual array implementation.

---

# 11. Quick Sort

Quick Sort is a Divide and Conquer sorting algorithm.

It selects an element called a **Pivot** and partitions the array into two parts:

- Elements smaller than or equal to the pivot.
- Elements greater than the pivot.

It then recursively sorts both partitions.

### Working Principle

1. Select a pivot element.
2. Partition the array around the pivot.
3. Place the pivot in its correct sorted position.
4. Apply Quick Sort to the left partition.
5. Apply Quick Sort to the right partition.
6. Continue until all partitions contain at most one element.

### Example

Unsorted array:

```text
[10, 7, 8, 9, 1, 5]
```

Choose pivot = 5.

After partitioning:

```text
[1, 5, 8, 9, 10, 7]
```

The pivot 5 is now in its correct sorted position.

Next, sort the left and right partitions recursively.

Final sorted array:

```text
[1, 5, 7, 8, 9, 10]
```

<LearningViz type_id="QUICKSORT" />

### Java Implementation (Lomuto Partition Scheme)

```java
public class QuickSort {

    static int partition(int[] arr, int low, int high) {

        int pivot = arr[high];

        int i = low - 1;

        for (int j = low; j < high; j++) {

            if (arr[j] <= pivot) {

                i++;

                int temp = arr[i];

                arr[i] = arr[j];

                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];

        arr[i + 1] = arr[high];

        arr[high] = temp;

        return i + 1;
    }

    static void sort(int[] arr, int low, int high) {

        if (low < high) {

            int pivotIndex = partition(arr, low, high);

            sort(arr, low, pivotIndex - 1);

            sort(arr, pivotIndex + 1, high);
        }
    }

    public static void main(String[] args) {

        int[] arr = {10, 7, 8, 9, 1, 5};

        sort(arr, 0, arr.length - 1);

        for (int x : arr) {
            System.out.print(x + " ");
        }
    }
}
```

**Output:**
```text
1 5 7 8 9 10
```

### Complexity Analysis

| Case | Time |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n²) |

- Auxiliary Space: O(log n) average recursion stack; O(n) worst-case recursion stack.
- Stable: No, in the implementation shown.
- In-place: Yes, apart from recursion stack usage.

**Important:** Choosing the last element as pivot can produce poor partitions for already sorted or reverse-sorted arrays. Randomized or median-based pivot selection can reduce the likelihood of this worst case.

---

# 12. Comparison of Sorting Algorithms

### Time Complexity Comparison

| Sorting Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |
| Bubble Sort (Optimized) | O(n) | O(n²) | O(n²) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |

### Space Complexity Comparison

| Sorting Algorithm | Auxiliary Space |
|---|---|
| Selection Sort | O(1) |
| Insertion Sort | O(1) |
| Bubble Sort | O(1) |
| Heap Sort | O(1) with iterative heapify |
| Merge Sort | O(n) |
| Quick Sort | O(log n) average; O(n) worst |

### Stability and In-Place Comparison

| Algorithm | Stable? | In-Place? |
|---|---|---|
| Selection Sort | No (standard version) | Yes |
| Insertion Sort | Yes | Yes |
| Bubble Sort | Yes | Yes |
| Heap Sort | No | Yes |
| Merge Sort | Yes (standard merge implementation) | No (standard array implementation) |
| Quick Sort | No (standard in-place version) | Yes (apart from recursion stack) |

---

# 13. Which Sorting Algorithm Should We Use?

| Situation | Suitable Algorithm |
|---|---|
| Small dataset | Insertion Sort |
| Nearly sorted dataset | Insertion Sort |
| Simple educational implementation | Bubble Sort |
| Minimum number of swaps is important | Selection Sort |
| Guaranteed O(n log n) time and low auxiliary array space | Heap Sort |
| Stable sorting with guaranteed O(n log n) time | Merge Sort |
| Fast average-case in-memory sorting | Quick Sort |

---

# 14. Required Lab Programs

According to the ACTS syllabus, the following programs are required.

### Lab 1: Sequential Search

- [ ] Create an integer array.
- [ ] Accept a search element.
- [ ] Compare the key with each array element.
- [ ] Display the index if found.
- [ ] Display a not-found message otherwise.

### Lab 2: Binary Search

- [ ] Create a sorted integer array.
- [ ] Accept a search element.
- [ ] Initialize `low` and `high`.
- [ ] Calculate the middle index.
- [ ] Compare the key with the middle element.
- [ ] Update the search range.
- [ ] Display the result.

### Lab 3: Insertion Sort

- [ ] Create an unsorted array.
- [ ] Select the key element.
- [ ] Shift larger elements to the right.
- [ ] Insert the key in the correct position.
- [ ] Display the sorted array.

### Lab 4: Quick Sort

- [ ] Create an unsorted array.
- [ ] Select a pivot.
- [ ] Partition the array.
- [ ] Recursively sort the left partition.
- [ ] Recursively sort the right partition.
- [ ] Display the sorted array.

---

# 15. Important Interview Questions

**Q1. What is searching?**

Searching is the process of finding a particular element in a collection of data.

**Q2. What is Sequential Search?**

Sequential Search checks each element one by one until the key is found or all elements are checked.

**Q3. Does Sequential Search require sorted data?**

No. It works with both sorted and unsorted data.

**Q4. What is the worst-case time complexity of Sequential Search?**

O(n).

**Q5. What is Binary Search?**

Binary Search repeatedly divides a sorted array into two halves to find an element.

**Q6. Is sorting required for Binary Search?**

Yes, the input must be sorted.

**Q7. What is the worst-case time complexity of Binary Search?**

O(log n).

**Q8. What is the difference between Linear Search and Binary Search?**

Linear Search checks elements one by one, whereas Binary Search repeatedly reduces the search space by half.

**Q9. What is sorting?**

Sorting is arranging data in ascending or descending order.

**Q10. What is Selection Sort?**

Selection Sort repeatedly selects the minimum element from the unsorted portion and places it in its correct position.

**Q11. What is Insertion Sort?**

Insertion Sort builds a sorted portion by inserting each new element into its correct position.

**Q12. What is Bubble Sort?**

Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.

**Q13. What is Heap Sort?**

Heap Sort uses a Binary Heap to repeatedly extract the maximum or minimum element and sort the array.

**Q14. What is Merge Sort?**

Merge Sort divides the array into smaller parts, sorts them recursively, and merges them.

**Q15. What is Quick Sort?**

Quick Sort selects a pivot, partitions the array, and recursively sorts the partitions.

**Q16. What is a pivot in Quick Sort?**

A pivot is the selected element used to partition the array.

**Q17. Which sorting algorithm uses Divide and Conquer?**

Merge Sort and Quick Sort.

**Q18. Which sorting algorithm has O(n) best-case time complexity among the basic algorithms covered?**

Insertion Sort and optimized Bubble Sort.

**Q19. Which sorting algorithms have O(n log n) worst-case time complexity?**

Heap Sort and Merge Sort.

**Q20. Which sorting algorithm has O(n²) worst-case complexity due to poor pivot selection?**

Quick Sort.

---

# 16. Multiple Choice Questions (MCQs)

**Q1. Which searching technique checks elements one by one?**

- A. Binary Search
- B. Sequential Search
- C. Quick Sort
- D. Merge Sort

**Answer:** B

**Q2. Sequential Search works on:**

- A. Only sorted arrays
- B. Only unsorted arrays
- C. Both sorted and unsorted arrays
- D. Only linked lists

**Answer:** C

**Q3. What is the worst-case time complexity of Sequential Search?**

- A. O(1)
- B. O(log n)
- C. O(n)
- D. O(n²)

**Answer:** C

**Q4. Binary Search requires:**

- A. Unsorted data
- B. Sorted data
- C. A stack
- D. A queue

**Answer:** B

**Q5. What is the worst-case complexity of Binary Search?**

- A. O(n)
- B. O(log n)
- C. O(n²)
- D. O(1)

**Answer:** B

**Q6. Which algorithm repeatedly selects the minimum element?**

- A. Bubble Sort
- B. Selection Sort
- C. Quick Sort
- D. Merge Sort

**Answer:** B

**Q7. Which sorting algorithm works like arranging playing cards?**

- A. Insertion Sort
- B. Heap Sort
- C. Selection Sort
- D. Quick Sort

**Answer:** A

**Q8. Which sorting algorithm compares adjacent elements?**

- A. Merge Sort
- B. Quick Sort
- C. Bubble Sort
- D. Heap Sort

**Answer:** C

**Q9. Which algorithm uses a Binary Heap?**

- A. Insertion Sort
- B. Heap Sort
- C. Bubble Sort
- D. Selection Sort

**Answer:** B

**Q10. Which sorting algorithm follows Divide and Conquer?**

- A. Bubble Sort
- B. Selection Sort
- C. Merge Sort
- D. Insertion Sort

**Answer:** C

**Q11. Which sorting algorithm uses a pivot?**

- A. Merge Sort
- B. Quick Sort
- C. Heap Sort
- D. Bubble Sort

**Answer:** B

**Q12. What is the worst-case time complexity of Quick Sort?**

- A. O(n)
- B. O(log n)
- C. O(n log n)
- D. O(n²)

**Answer:** D

**Q13. Which algorithm has O(n log n) worst-case time complexity?**

- A. Bubble Sort
- B. Insertion Sort
- C. Heap Sort
- D. Selection Sort

**Answer:** C

**Q14. Which sorting algorithm is stable and has O(n log n) worst-case time complexity in its standard implementation?**

- A. Quick Sort
- B. Merge Sort
- C. Heap Sort
- D. Selection Sort

**Answer:** B

**Q15. Which sorting algorithm is generally suitable for nearly sorted data?**

- A. Insertion Sort
- B. Heap Sort
- C. Selection Sort
- D. Quick Sort

**Answer:** A

**Q16. Which algorithm has O(1) auxiliary space in its standard implementation?**

- A. Merge Sort
- B. Insertion Sort
- C. Recursive Quick Sort
- D. Recursive Binary Search

**Answer:** B

**Q17. What is the best-case time complexity of optimized Bubble Sort?**

- A. O(n²)
- B. O(log n)
- C. O(n)
- D. O(n log n)

**Answer:** C

**Q18. Which sorting algorithm generally requires O(n) additional array space?**

- A. Insertion Sort
- B. Bubble Sort
- C. Merge Sort
- D. Selection Sort

**Answer:** C

**Q19. Which searching algorithm is more suitable for a large sorted array?**

- A. Sequential Search
- B. Binary Search
- C. Bubble Sort
- D. Selection Sort

**Answer:** B

**Q20. Which algorithm repeatedly divides the search space into half?**

- A. Sequential Search
- B. Binary Search
- C. Insertion Sort
- D. Heap Sort

**Answer:** B

---

# 17. Quick Revision Notes

| Algorithm | Main Concept | Worst-Case Time |
|---|---|---|
| Sequential Search | Check elements one by one | O(n) |
| Binary Search | Divide search space into half | O(log n) |
| Selection Sort | Select minimum element | O(n²) |
| Insertion Sort | Insert key in sorted portion | O(n²) |
| Bubble Sort | Swap adjacent elements | O(n²) |
| Heap Sort | Use Binary Heap | O(n log n) |
| Merge Sort | Divide and Merge | O(n log n) |
| Quick Sort | Pivot and Partition | O(n²) |

### Important Concepts

- Searching means finding an element.
- Sorting means arranging elements.
- Binary Search requires sorted data.
- Selection Sort selects the minimum element.
- Insertion Sort inserts an element into the sorted portion.
- Bubble Sort compares adjacent elements.
- Heap Sort uses a Binary Heap.
- Merge Sort uses Divide and Conquer.
- Quick Sort uses a pivot and partitioning.
- Stability means preserving the relative order of equal-key elements.
- In-place sorting uses very little additional storage.

---

# 18. Suggested GitHub Folder Structure

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
└── Sessions-12-14-Searching-Sorting/
    │
    ├── README.md
    │
    ├── Searching/
    │   ├── SequentialSearch.java
    │   ├── BinarySearch.java
    │   └── RecursiveBinarySearch.java
    │
    └── Sorting/
        ├── SelectionSort.java
        ├── InsertionSort.java
        ├── BubbleSort.java
        ├── HeapSort.java
        ├── MergeSort.java
        └── QuickSort.java
```

---

# 19. Learning Outcomes

After completing Sessions 12, 13 & 14, students should be able to:

- Understand the objectives of searching.
- Implement Sequential Search.
- Analyze Sequential Search complexity.
- Implement iterative and recursive Binary Search.
- Analyze Binary Search complexity.
- Understand the concept of sorting.
- Implement Selection Sort, Insertion Sort and Bubble Sort.
- Understand Heap Sort, Merge Sort and Quick Sort.
- Compare different sorting algorithms.
- Analyze best-case, average-case and worst-case complexity.
- Implement searching and sorting programs using Java.

---

**End of Sessions 12, 13 & 14 – Searching and Sorting Algorithms**

*Course: Algorithms and Data Structures Using Java | PGCP-AC August 2026 | ACTS Pune*
