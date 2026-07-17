
# Week 1 (25 May - 31 May): Core Data Structures

## Goals for the week

- First, get a hang of coding by doing the warm-up task.
- Learn about time complexity, timing your code, and some core data structures that have been listed below.
- Solve some basic problems on these topics.
- Participate in the competitive programming contest.

The idea is to learn how to think through implementation cleanly.

---

## Warm-up Task

Implement a `Vec3` class in C++ with the following specification.

### Constructor

```cpp
Vec3(float x, float y, float z)
```

### Operator Overloads

| Operator | Description |
|----------|-------------|
| `operator+(const Vec3&)` | Component-wise addition |
| `operator-(const Vec3&)` | Component-wise subtraction |
| `operator*(float)` | Scalar multiplication |
| `operator/(float)` | Scalar division |
| `operator-()` *(unary)* | Negate all components |
| `operator[](int i)` | Index `x`/`y`/`z` by `0`/`1`/`2` |

### Methods

| Method | Description |
|--------|-------------|
| `length()` | Returns the Euclidean magnitude |
| `unit()` | Returns the normalised direction vector |
| `dot(const Vec3& other)` | Returns the scalar dot product |
| `cross(const Vec3& other)` | Returns the perpendicular `Vec3` |
| `reflect(const Vec3& normal)` | Reflects the vector about a surface normal |
| `refract(const Vec3& normal, float refractive_index)` | Refracts the vector using Snell's law |

### Testing

Use the provided `./test` executable to validate your implementation:

```bash
./test
```

---

## Core Concepts & Practice

### Complexity analysis

- **Core Concept:** [USACO Guide to Asymptitic Notation](https://usaco.guide/bronze/time-comp?lang=cpp)

- **Additional Videos:**
  - [Harvard CS50 - Asymptotic Notation (video)](https://www.youtube.com/watch?v=iOq5kSKqeR4)
  - [Skiena (video)](https://www.youtube.com/watch?v=z1mkCe3kVUA)

### Arrays and Vectors

- **Core Concept:** [USACO Guide to Arrays](https://usaco.guide/bronze/intro-ds?lang=cpp#arrays)
  
- **Additional Videos:**
  - [Harvard CS50 - Arrays (video)](https://www.youtube.com/watch?v=tI_tIZFyKBw&t=3009s)
  - [Dynamic Arrays (video)](https://www.coursera.org/lecture/data-structures/dynamic-arrays-EwbnV)
 
- **Practice Problems:**
  - [Leetcode - Two Sum](https://leetcode.com/problems/two-sum/description/)
  - [Leetcode - Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

### Strings and Hashing basics

- **Core Concept:** [USACO Guide to Hashing](https://usaco.guide/gold/hashing?lang=cpp)

- **Additional Reading:** [String Hashing](https://cp-algorithms.com/string/string-hashing.html)
  
- **Additional Videos:**
  - [Strings, Hashing, KMP, Z Algorithm (video)](https://youtu.be/6t_1eRO-Cqo?si=EIOVeWaIwiGy0iCv)
  - [USACO Guide to Hash Maps](https://usaco.guide/gold/hashmaps?lang=cpp)
 
- **Practice Problems:**
  - [Leetcode - Keyboard Row](https://leetcode.com/problems/keyboard-row/description/?envType=problem-list-v2&envId=hash-table)
  - [Leetcode - Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=problem-list-v2&envId=string)

### Sorting fundamentals

- **Core Concept:** [USACO Guide to Sorting](https://usaco.guide/bronze/intro-sorting?lang=cpp)
  
- **Additional Videos:**
  - [MIT/OCW - Sets and Sorting](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/lecture-3-sets-and-sorting/)
  - [Sorting Algorithms Explained Visually (video)](https://youtu.be/RfXt_qHDEPw?si=6PuXKn1Ny02V9lM2)
  - [Sorting Algorithms Easily Explained (video)](https://www.youtube.com/watch?v=rbbTd-gkajw)
 
- **Practice Problems:**
  - [CSES - Distinct Numbers](https://cses.fi/problemset/task/1621)
  - [CSES - Collecting Numbers](https://cses.fi/problemset/task/2216)

---

## Basic Problems to Submit (We will discuss some interesting solutions if time permits)

- ### Questions to be submitted:
    1. [Missing Number](https://cses.fi/problemset/task/1083) (w1\_q1.cpp)
    1. [Repetitions](https://cses.fi/problemset/task/1069) (w1\_q2.cpp)
    1. [Coins](https://codeforces.com/problemset/problem/1814/A) (w1\_q3.cpp)
    1. [Lucky Numbers](https://codeforces.com/problemset/problem/1808/A) (w1\_q4.cpp)
    1. [Weird Algorithm](https://cses.fi/problemset/task/1068) (w1\_q5.cpp)

- ### Questions for your practice:
    1. [Increasing Array](https://cses.fi/problemset/task/1094)
    1. [Towers of Hanoi](https://cses.fi/problemset/task/2165)
    1. [Coin Piles](https://cses.fi/problemset/task/1754)
    1. [Walking Master](https://codeforces.com/problemset/problem/1806/A)
    1. [Two Knights](https://cses.fi/problemset/task/1072)
 
---

## Tasks for Competitive Programming

- Complete reading the first 4 chapters from [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf).
- Create your accounts on [CSES](https://cses.fi/), [Codeforces](https://codeforces.com/), [Codechef](https://www.codechef.com/) and [Leetcode](https://leetcode.com/).
- If you wish to study any of the data structures in detail, then please use this [link](https://www.cse.iitb.ac.in/~akg/courses/2024-ds/). But I believe you will be able to pick up all the data structures knowledge as you will move forward. So, no need to memorize stuff, you will be able to learn through practice.
- Go through your CS101 slides or the link for basic algorithms such as [binary search](https://cp-algorithms.com/num_methods/binary_search.html), and sorting algorithms.
- Then read this [document](https://github.com/adityasanapala/SoC-DSA/blob/main/Resources/templates.pdf) thoroughly. If you have any questions on this document, please feel free to ask in the group. 
- You need to submit only the first set of the following questions in your corresponding folder. Also, your code should pass all the testcases present on either CSES or Codeforces.

---
      
- All those who are new to CP, this week is going to be a bit heavy. Feel free to ask us for more time. But make sure that you complete all the questions honestly, else this project won’t be able to help you much.

## Problem-solving habits

- Read the problem carefully before coding. Understand the input, output, and constraints.
- Start with a brute force solution. Optimize only after understanding the brute force.
- Practice regularly instead of solving many problems at once.
- Re-solve old problems to improve memory.
- Learn from mistakes and missed edge cases.
- Always think about time and space complexity.
- Avoid memorizing solutions blindly.

---
