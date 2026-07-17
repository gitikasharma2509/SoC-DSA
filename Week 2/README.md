# Week 2 (1 Jun - 7 Jun): More Data Structures

## Goals for the week

- Learn the fundamentals of stacks, queues, linked lists, trees, recursion, and graph basics.
- Understand BFS and DFS, and how they are used to traverse and explore data structures.
- Solve basic problems on these topics to strengthen your understanding.
- Participate in the competitive programming contest.

The idea is to build intuition for traversal, state exploration, and systematic problem-solving.

---

## Core Concepts & Practice

### Stacks and Queues

- **Core Concept:**

- 

### Lists and Related Structures

- **Core Concept:**

- 

### Graph Theory and Trees

- **Core Concept:** [USACO Guide to Graphs](https://usaco.guide/bronze/intro-graphs?lang=cpp)

- 

### Recursion

- **Core Concept:**

- 

### Graph Searching Algorithms

- **Core Concept:**

- [bfs](https://youtu.be/HZ5YTanv5QE?si=0FImbsVK1M10bx9M)

## Warm-up Task: Traversal Explorer

Get comfortable with implementing and visualizing basic traversals using stacks, queues, recursion, and graphs.

## Tasks

# Stack & Queue Simulation

Implement a generic last-in, first-out container backed by a `std::vector`.

## Class template

```cpp
template <typename T>
class Stack;
```

## Constructor & destructor

| Signature | Description |
|-----------|-------------|
| `Stack()` | Default-constructs an empty stack. |
| `~Stack()` | Destroys the stack and all stored elements. |

## Methods

| Signature | Description |
|-----------|-------------|
| `void push(const T& value)` | Pushes `value` onto the top of the stack. |
| `void pop()` | Removes the top element. Throws `std::underflow_error` if empty. |
| `T& top()` | Returns a reference to the top element. Throws if empty. |
| `const T& top() const` | `const`-qualified overload. |
| `bool empty() const` | Returns `true` if the stack contains no elements. |
| `std::size_t size() const` | Returns the number of elements currently stored. |

## Operator overloads

| Operator | Description |
|----------|-------------|
| `operator==(const Stack&)` | Returns `true` if both stacks contain the same elements in the same order. |
| `operator!=(const Stack&)` | Negation of `operator==`. |
| `operator<<(std::ostream&)` | Prints elements top→bottom: `[3, 2, 1]` |

## Testing

Use the provided `./test_stack` executable to validate your implementation:

```bash
./test_stack
`

<!---## Implementation hints

- Map `push` to `std::vector::push_back` and `top` to `std::vector::back`. The back of the vector is the top of the stack.
- All core operations (`push`, `pop`, `top`) are O(1) amortised.--->

## Extension

Add a `Stack(std::initializer_list<T>)` constructor so stacks can be written as:

```cpp
Stack<int> s = {1, 2, 3};
```













Implement a generic first-in, first-out container. Choose either an **array / deque** or a **linked list** as the underlying storage.

## Class template

```cpp
template <typename T>
class Queue;
```

## Constructor & destructor

| Signature | Description |
|-----------|-------------|
| `Queue()` | Default-constructs an empty queue. |
| `~Queue()` | Destroys the queue and all stored elements. |

## Methods

| Signature | Description |
|-----------|-------------|
| `void enqueue(const T& value)` | Adds `value` to the back of the queue. |
| `void dequeue()` | Removes the front element. Throws `std::underflow_error` if empty. |
| `T& front()` | Returns a reference to the front element. Throws if empty. |
| `const T& front() const` | `const`-qualified overload. |
| `T& back()` | Returns a reference to the back element. Throws if empty. |
| `const T& back() const` | `const`-qualified overload. |
| `bool empty() const` | Returns `true` if the queue contains no elements. |
| `std::size_t size() const` | Returns the number of elements currently stored. |

## Operator overloads

| Operator | Description |
|----------|-------------|
| `operator==(const Queue&)` | Returns `true` if both queues contain the same elements in the same order. |
| `operator!=(const Queue&)` | Negation of `operator==`. |
| `operator<<(std::ostream&)` | Prints elements front→back: `[1, 2, 3]` |

## Testing

Use the provided `./test_queue` executable to validate your implementation:

```bash
./test_queue
```

<!---## Implementation hints

**Array / deque variant:** use `std::deque<T>` internally — `push_back` for enqueue, `pop_front` for dequeue. Both are O(1). Using a plain `std::vector` works but makes dequeue O(n) due to element shifting.

**Linked list variant:** define a private node struct and maintain separate head and tail pointers for O(1) enqueue and dequeue:

```cpp
struct Node {
    T data;
    Node* next;
};
Node* head; // front
Node* tail; // back
```

Don't forget the Rule of Three / Five when managing raw pointers.--->

## Extension

Implement a `CircularQueue<T>` variant backed by a fixed-size array with head/tail indices and a capacity passed to the constructor:

```cpp
CircularQueue<int> q(8); // capacity of 8 elements
```

Throw `std::overflow_error` on `enqueue` when the queue is full.




### Part 2: Linked List Traversal

Create the linked list:

```
5 → 10 → 15 → 20 → NULL
```

Implement a function to:

* Traverse the list.
* Print all elements.
* Count the number of nodes.

---

### Part 3: Tree Traversals

Given the binary tree:

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

Find and verify:

* Preorder traversal
* Inorder traversal
* Postorder traversal
* Level-order traversal

---

### Part 4: DFS and BFS

Given the graph:

```
1 -- 2
|    |
3 -- 4
     |
     5
```

Starting from node `1`:

* Perform DFS.
* Perform BFS.
* Record the order in which nodes are visited.

---

### Part 5: Reflection

Answer briefly:

1. How does a stack help recursion?
2. Why does BFS use a queue?
3. When would you prefer DFS over BFS?
4. What information must be stored to avoid revisiting nodes in a graph?

## Deliverable

Submit:

* Source code for all implementations.
* Traversal outputs.
* Answers to the reflection questions.

The goal is not optimization but developing intuition for traversal, recursion, and state exploration.





# Warm-Up Task: Traversal Fundamentals

Implement the following data structures and traversal algorithms in C++.

## Stack

### Operations

Implement a stack supporting:

| Operation | Description                                |
| --------- | ------------------------------------------ |
| `push(x)` | Insert an element at the top               |
| `pop()`   | Remove and return the top element          |
| `top()`   | Return the top element without removing it |
| `empty()` | Check whether the stack is empty           |

### Testing

Execute the following sequence:

```text
push(10)
push(20)
push(30)
pop()
push(40)
pop()
```

Record the outputs and final state of the stack.

---

## Queue

### Operations

Implement a queue supporting:

| Operation    | Description                                  |
| ------------ | -------------------------------------------- |
| `enqueue(x)` | Insert an element at the rear                |
| `dequeue()`  | Remove and return the front element          |
| `front()`    | Return the front element without removing it |
| `empty()`    | Check whether the queue is empty             |

### Testing

Execute the following sequence:

```text
enqueue(10)
enqueue(20)
enqueue(30)
dequeue()
enqueue(40)
dequeue()
```

Record the outputs and final state of the queue.

---

## Linked List

### Requirements

Implement a singly linked list with:

| Method          | Description                |
| --------------- | -------------------------- |
| `insert(int x)` | Insert a node at the end   |
| `traverse()`    | Print all elements         |
| `count()`       | Return the number of nodes |

### Testing

Construct the list:

```text
5 → 10 → 15 → 20 → NULL
```

Verify traversal output and node count.

---

## Binary Tree Traversals

### Tree

```text
        1
       / \
      2   3
     / \   \
    4   5   6
```

### Methods

Implement:

| Method         | Description             |
| -------------- | ----------------------- |
| `preorder()`   | Root → Left → Right     |
| `inorder()`    | Left → Root → Right     |
| `postorder()`  | Left → Right → Root     |
| `levelOrder()` | Breadth-first traversal |

### Testing

Print the traversal order produced by each method.

---

## Graph Traversals

### Graph

```text
1 -- 2
|    |
3 -- 4
     |
     5
```

### Methods

| Method           | Description          |
| ---------------- | -------------------- |
| `DFS(int start)` | Depth-First Search   |
| `BFS(int start)` | Breadth-First Search |

### Testing

Starting from node `1`:

```cpp
DFS(1);
BFS(1);
```

Record the order in which nodes are visited.

---

## Reflection Questions

Answer the following:

1. How does recursion implicitly use a stack?
2. Why is a queue required for BFS?
3. What are the key differences between DFS and BFS?
4. Why is a visited array/set necessary in graph traversal?

---

## Validation

Compile and run your code:

```bash
g++ warmup.cpp -o warmup
./warmup
```

Verify that all traversals and operations produce the expected outputs.

### Goal

---

## Problems to Submit

- [Playlist](https://cses.fi/problemset/task/1141)
- [Sum of Two Values](https://cses.fi/problemset/task/1640)
- [Sum of Three Values](https://cses.fi/problemset/task/1641)
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/)
- [Stick Lengths](https://cses.fi/problemset/task/1074)
- [Min Max Sort](https://codeforces.com/problemset/problem/1792/C)
- [2^Sort](https://codeforces.com/problemset/problem/1692/G)
- [Longest K-good segment](https://codeforces.com/contest/616/problem/D)
- [Nested Ranges Count](https://cses.fi/problemset/task/2169)
- [Rooks Defenders](https://codeforces.com/problemset/problem/1679/C)

---

## Tasks for Competitive Programming

- Go through [C++ sort](https://www.geeksforgeeks.org/sort-c-stl/) function.
- Read Chapter 5 and Chapter 8 from this [Competitive Programmer's Handbook](https://github.com/sakshamrathi21/SOC-Conquering_Competitive_Programming/blob/main/Resources/Competitive%20Programmer_s%20Handbook.pdf?usp=sharing).
- Go through Chapters 4-5 and 8 from this [Guide to Competitive Programming](https://github.com/sakshamrathi21/SOC-Conquering_Competitive_Programming/blob/main/Resources/Guide%20to%20Competitive%20Programming.pdf?usp=sharing).
- Try solving these problems:
    - [Matryoshkas](https://codeforces.com/problemset/problem/1790/D)
    - [Playing in a casino](https://codeforces.com/problemset/problem/1808/B)
    - [Sum of four values](https://cses.fi/problemset/task/1642)
    - [Sliding Window Median](https://cses.fi/problemset/task/1076)
    - [Sliding Window Cost](https://cses.fi/problemset/task/1077)
- [Fun Problem](https://codeforces.com/contest/1764/problem/G2) (You can maybe read its tutorial for reference)

---










- Please read this [document](https://github.com/sakshamrathi21/SOC-Conquering_Competitive_Programming/blob/main/Resources/Some%20Techniques.pdf) for some common techniques.

<!---- Optional: Read Chapter-5 of this [Algorithm Design](https://github.com/sakshamrathi21/SOC-Conquering_Competitive_Programming/blob/main/Resources/Algorithm%20Design%20(J.%20Kleinberg%2C%20E.%20Tardos).pdf).---->
