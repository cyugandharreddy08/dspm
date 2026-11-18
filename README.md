# Data Structures and Programming Methodology (DSPM) Laboratory

C++ implementations for the 20 laboratory experiments as prescribed in the **DSPM Lab Manual (2026–27)** for **Course Code: PCL03DSPM**, Department of Computer Science and Engineering, **Indian Institute of Information Technology Agartala**.

Designed for **ultra-fast cloning and minimal network bandwidth usage** (< 100 KB clone size).

---

## List of Experiments

| Exp No. | Experiment Title / Aim | Source File |
| :---: | :--- | :--- |
| **01** | Bubble Sort for sorting an array, Linear Search and Binary Search with execution time analysis | [`Experiment_01_Bubble_Sort_Linear_Binary_Search.cpp`](./Experiment_01_Bubble_Sort_Linear_Binary_Search.cpp) |
| **02** | Sparse Matrix Representation and Transpose using Compact (3-tuple) Representation | [`Experiment_02_Sparse_Matrix_Representation_and_Transpose.cpp`](./Experiment_02_Sparse_Matrix_Representation_and_Transpose.cpp) |
| **03** | Addition of two univariate polynomials using an array of structures | [`Experiment_03_Polynomial_Addition_Array_of_Structures.cpp`](./Experiment_03_Polynomial_Addition_Array_of_Structures.cpp) |
| **04** | Reverse an array of integers using pointer arithmetic without direct array indexing | [`Experiment_04_Reverse_Array_Pointer_Arithmetic.cpp`](./Experiment_04_Reverse_Array_Pointer_Arithmetic.cpp) |
| **05** | Menu-driven Singly Linked List (creation, insertion & deletion at beginning, position, and end, display) | [`Experiment_05_Singly_Linked_List.cpp`](./Experiment_05_Singly_Linked_List.cpp) |
| **06** | Doubly Linked List with insertion, deletion, and forward and reverse traversal | [`Experiment_06_Doubly_Linked_List.cpp`](./Experiment_06_Doubly_Linked_List.cpp) |
| **07** | Check balanced parentheses `()`, `[]`, `{}` using Stack data structure | [`Experiment_07_Balanced_Parentheses_Stack.cpp`](./Experiment_07_Balanced_Parentheses_Stack.cpp) |
| **08** | Evaluate valid single-digit postfix expression using Stack data structure | [`Experiment_08_Evaluate_Postfix_Stack.cpp`](./Experiment_08_Evaluate_Postfix_Stack.cpp) |
| **09** | Linear Queue using arrays with enqueue, dequeue, queue length, and display operations | [`Experiment_09_Linear_Queue_Using_Array.cpp`](./Experiment_09_Linear_Queue_Using_Array.cpp) |
| **10** | Circular Queue using arrays with enqueue, dequeue, queue length, and wrap-around handling | [`Experiment_10_Circular_Queue_Using_Array.cpp`](./Experiment_10_Circular_Queue_Using_Array.cpp) |
| **11** | Selection Sort algorithm for sorting an array in ascending order with pass-by-pass tracing | [`Experiment_11_Selection_Sort.cpp`](./Experiment_11_Selection_Sort.cpp) |
| **12** | Insertion Sort algorithm for sorting an array in ascending order with pass-by-pass tracing | [`Experiment_12_Insertion_Sort.cpp`](./Experiment_12_Insertion_Sort.cpp) |
| **13** | Merge Sort algorithm using the divide-and-conquer approach | [`Experiment_13_Merge_Sort.cpp`](./Experiment_13_Merge_Sort.cpp) |
| **14** | Quick Sort algorithm using partitioning technique | [`Experiment_14_Quick_Sort.cpp`](./Experiment_14_Quick_Sort.cpp) |
| **15** | Radix Sort algorithm for sorting non-negative integer data digit-by-digit | [`Experiment_15_Radix_Sort.cpp`](./Experiment_15_Radix_Sort.cpp) |
| **16** | Binary Search Tree (BST) node creation and deletion handling all 3 deletion cases | [`Experiment_16_BST_Creation_and_Deletion.cpp`](./Experiment_16_BST_Creation_and_Deletion.cpp) |
| **17** | Recursive Inorder, Preorder, and Postorder traversals of a Binary Search Tree (BST) | [`Experiment_17_BST_Recursive_Traversals.cpp`](./Experiment_17_BST_Recursive_Traversals.cpp) |
| **18** | Breadth-First Search (BFS) traversal on a graph representing connectivity among college buildings | [`Experiment_18_Graph_BFS_College_Buildings.cpp`](./Experiment_18_Graph_BFS_College_Buildings.cpp) |
| **19** | Depth-First Search (DFS) traversal on a graph representing connectivity among college buildings | [`Experiment_19_Graph_DFS_College_Buildings.cpp`](./Experiment_19_Graph_DFS_College_Buildings.cpp) |
| **20** | AVL Tree implementation with insertion, automatic balancing via rotations (LL, RR, LR, RL), inorder traversal, and height calculation | [`Experiment_20_AVL_Tree_Operations.cpp`](./Experiment_20_AVL_Tree_Operations.cpp) |

---

## Quick Start (Minimal Network Usage Clone)

Clone the entire repository in less than a second:

```bash
git clone https://github.com/cyugandharreddy08/dspm.git
cd dspm
```

### Shallow Clone (Even lighter bandwidth)
If you only need the latest code without commit history:
```bash
git clone --depth 1 https://github.com/cyugandharreddy08/dspm.git
```

---

## How to Compile and Run

Any modern C++ compiler (`g++`, `clang++`, or `MSVC`) supporting C++11 or higher can be used.

### Using GCC / G++ (Linux / macOS / Windows MinGW)
```bash
# Compile any experiment (e.g., Experiment 1)
g++ -std=c++17 Experiment_01_Bubble_Sort_Linear_Binary_Search.cpp -o exp01

# Run the executable
./exp01        # On Linux / macOS
.\exp01.exe    # On Windows
```

---

## Features
- **Standard C++**: Fully compatible with C++11, C++14, C++17, and C++20.
- **Tested & Verified**: All 20 files have been compiled and verified with zero errors and warnings.
- **Self-Contained**: Each experiment file includes the experiment title, aim, clean modular functions, and an interactive or menu-driven `main()` function.
- **Zero Bloat**: Repository contains only source code and documentation to ensure instant downloads even on low-speed networks.
