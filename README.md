# Data Structures and Programming Methodology (DSPM) Laboratory

C++ implementations for all 20 laboratory experiments as prescribed in the **DSPM Lab Manual (2026–27)** for **Course Code: PCL03DSPM**, Department of Computer Science and Engineering, **Indian Institute of Information Technology Agartala**.

> **Note for Lab Computers:**
> **No Python, no `pip`, and no external packages are needed.**
> Every single experiment is written in **100% pure standard C++** with zero dependencies. It runs straight out of the box on standard lab environments (Dev-C++, Code::Blocks, MinGW `g++`, VS Code, or Linux terminal).

---

## ⚡ Quick Ways to Use on Lab Laptops

### Option 1: Direct 1-Click ZIP Download (No Git or CLI needed)
If the lab PC doesn't have Git:
- **Download Link**: [**Download dspm-main.zip**](https://github.com/cyugandharreddy08/dspm/archive/refs/heads/main.zip) *(Only ~50 KB!)*
- Unzip and open any `.cpp` file in **Dev-C++**, **Code::Blocks**, or your preferred editor, then click **Compile & Run (F9 / F11)**.

### Option 2: Ultra-Lightweight Git Clone (< 60 KB download)
```bash
git clone --depth 1 https://github.com/cyugandharreddy08/dspm.git
cd dspm
```

### Option 3: Download Only the Experiment You Need (Using `curl`)
You don't even need to download the full repository. Use `curl` in PowerShell or Command Prompt to grab a single file:
```bash
# Example: Download only Experiment 1
curl -O https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_01_Bubble_Sort_Linear_Binary_Search.cpp
```

---

## List of Experiments

| Exp No. | Experiment Title / Aim | Source File | Raw Download Link |
| :---: | :--- | :--- | :---: |
| **01** | Bubble Sort, Linear Search and Binary Search with execution time analysis | [`Experiment_01_Bubble_Sort_Linear_Binary_Search.cpp`](./Experiment_01_Bubble_Sort_Linear_Binary_Search.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_01_Bubble_Sort_Linear_Binary_Search.cpp) |
| **02** | Sparse Matrix Representation and Transpose using Compact Representation | [`Experiment_02_Sparse_Matrix_Representation_and_Transpose.cpp`](./Experiment_02_Sparse_Matrix_Representation_and_Transpose.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_02_Sparse_Matrix_Representation_and_Transpose.cpp) |
| **03** | Addition of two univariate polynomials using an array of structures | [`Experiment_03_Polynomial_Addition_Array_of_Structures.cpp`](./Experiment_03_Polynomial_Addition_Array_of_Structures.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_03_Polynomial_Addition_Array_of_Structures.cpp) |
| **04** | Reverse an array of integers using pointer arithmetic without direct indexing | [`Experiment_04_Reverse_Array_Pointer_Arithmetic.cpp`](./Experiment_04_Reverse_Array_Pointer_Arithmetic.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_04_Reverse_Array_Pointer_Arithmetic.cpp) |
| **05** | Menu-driven Singly Linked List (creation, insertion, deletion at beginning/pos/end, display) | [`Experiment_05_Singly_Linked_List.cpp`](./Experiment_05_Singly_Linked_List.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_05_Singly_Linked_List.cpp) |
| **06** | Doubly Linked List with insertion, deletion, and forward & reverse traversal | [`Experiment_06_Doubly_Linked_List.cpp`](./Experiment_06_Doubly_Linked_List.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_06_Doubly_Linked_List.cpp) |
| **07** | Check balanced parentheses `()`, `[]`, `{}` using Stack data structure | [`Experiment_07_Balanced_Parentheses_Stack.cpp`](./Experiment_07_Balanced_Parentheses_Stack.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_07_Balanced_Parentheses_Stack.cpp) |
| **08** | Evaluate valid single-digit postfix expression using Stack data structure | [`Experiment_08_Evaluate_Postfix_Stack.cpp`](./Experiment_08_Evaluate_Postfix_Stack.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_08_Evaluate_Postfix_Stack.cpp) |
| **09** | Linear Queue using arrays with enqueue, dequeue, queue length, and display | [`Experiment_09_Linear_Queue_Using_Array.cpp`](./Experiment_09_Linear_Queue_Using_Array.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_09_Linear_Queue_Using_Array.cpp) |
| **10** | Circular Queue using arrays with enqueue, dequeue, queue length, and wrap-around | [`Experiment_10_Circular_Queue_Using_Array.cpp`](./Experiment_10_Circular_Queue_Using_Array.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_10_Circular_Queue_Using_Array.cpp) |
| **11** | Selection Sort algorithm for sorting an array in ascending order with pass tracing | [`Experiment_11_Selection_Sort.cpp`](./Experiment_11_Selection_Sort.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_11_Selection_Sort.cpp) |
| **12** | Insertion Sort algorithm for sorting an array in ascending order with pass tracing | [`Experiment_12_Insertion_Sort.cpp`](./Experiment_12_Insertion_Sort.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_12_Insertion_Sort.cpp) |
| **13** | Merge Sort algorithm using the divide-and-conquer approach | [`Experiment_13_Merge_Sort.cpp`](./Experiment_13_Merge_Sort.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_13_Merge_Sort.cpp) |
| **14** | Quick Sort algorithm using partitioning technique | [`Experiment_14_Quick_Sort.cpp`](./Experiment_14_Quick_Sort.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_14_Quick_Sort.cpp) |
| **15** | Radix Sort algorithm for sorting non-negative integer data digit-by-digit | [`Experiment_15_Radix_Sort.cpp`](./Experiment_15_Radix_Sort.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_15_Radix_Sort.cpp) |
| **16** | Binary Search Tree (BST) node creation and deletion handling all 3 deletion cases | [`Experiment_16_BST_Creation_and_Deletion.cpp`](./Experiment_16_BST_Creation_and_Deletion.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_16_BST_Creation_and_Deletion.cpp) |
| **17** | Recursive Inorder, Preorder, and Postorder traversals of a Binary Search Tree (BST) | [`Experiment_17_BST_Recursive_Traversals.cpp`](./Experiment_17_BST_Recursive_Traversals.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_17_BST_Recursive_Traversals.cpp) |
| **18** | Breadth-First Search (BFS) traversal on graph representing college campus buildings | [`Experiment_18_Graph_BFS_College_Buildings.cpp`](./Experiment_18_Graph_BFS_College_Buildings.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_18_Graph_BFS_College_Buildings.cpp) |
| **19** | Depth-First Search (DFS) traversal on graph representing college campus buildings | [`Experiment_19_Graph_DFS_College_Buildings.cpp`](./Experiment_19_Graph_DFS_College_Buildings.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_19_Graph_DFS_College_Buildings.cpp) |
| **20** | AVL Tree implementation with insertion, balancing via rotations (LL, RR, LR, RL), inorder traversal, height | [`Experiment_20_AVL_Tree_Operations.cpp`](./Experiment_20_AVL_Tree_Operations.cpp) | [Raw Link](https://raw.githubusercontent.com/cyugandharreddy08/dspm/main/Experiment_20_AVL_Tree_Operations.cpp) |

---

## How to Compile & Run in the Lab

### 1. In IDEs (Dev-C++, Code::Blocks, Turbo C++)
1. Open the `.cpp` file directly in your IDE.
2. Hit **F9** or **F11** (**Compile & Run**).

### 2. In Terminal or Command Prompt (`g++`)
```bash
# Compile any file:
g++ Experiment_01_Bubble_Sort_Linear_Binary_Search.cpp -o exp01

# Run it:
./exp01        # On Linux / macOS
exp01.exe      # On Windows Command Prompt
```
