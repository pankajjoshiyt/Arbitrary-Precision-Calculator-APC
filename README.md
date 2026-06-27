# Arbitrary-Precision-Calculator-APC
The Arbitrary Precision Calculator (APC) is designed to perform arithmetic calculations on extremely large integers that exceed the storage capacity of standard C data types.



# Arbitrary Precision Calculator (APC)

> A C-based Arbitrary Precision Calculator that performs arithmetic operations on integers of virtually unlimited size using a Doubly Linked List.

---

## 📌 Project Overview

The **Arbitrary Precision Calculator (APC)** is a data structure-based application developed in **C** that performs arithmetic operations on numbers much larger than those supported by standard C data types.

Instead of storing an entire number in primitive data types such as `int`, `long`, or `long long`, every digit of the number is stored in a **Doubly Linked List**, allowing calculations on numbers with hundreds or even thousands of digits.

This project demonstrates the implementation of arithmetic algorithms using linked lists and is useful for understanding dynamic memory management and large number manipulation.

---

## 👨‍💻 Project Information

**Project Name:** Arbitrary Precision Calculator (APC)

**Submitted By:** Pankaj Joshi

**Student ID:** 25031_001

**Language:** C

**Data Structure Used:** Doubly Linked List

---

# ✨ Features

* Supports extremely large integer calculations
* Dynamic memory allocation
* Doubly Linked List implementation
* Command Line Argument based execution
* Handles positive and negative numbers
* Removes leading zeros automatically
* Modular programming approach
* Easy to understand and extend

---

# 🚀 Supported Operations

| Operator | Operation      |
| -------- | -------------- |
| +        | Addition       |
| -        | Subtraction    |
| x / X    | Multiplication |
| /        | Division       |

---

# 📂 Project Structure

```text
APC/
│
├── main.c
├── apc.h
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── create_list.c
├── helper_functions.c
├── validation.c
├── Makefile
└── README.md
```

*(File names may vary depending on your implementation.)*

---

# ⚙️ Working Principle

1. The program accepts two operands and one operator through command-line arguments.
2. Each operand is converted into a Doubly Linked List.
3. Every node stores one decimal digit.
4. The selected arithmetic operation is performed digit by digit.
5. The resulting number is stored in another linked list.
6. Finally, the result is displayed on the terminal.

---

# 🧠 Data Structure

Each node stores one digit of the number.

```c
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;
```

Example:

Number:

```text
123456
```

Stored as:

```text
NULL <- [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [6] -> NULL
```

---

# 💻 Compilation

Using GCC:

```bash
gcc *.c -o apc.out
```

Or using Makefile:

```bash
make
```

---

# ▶️ Execution

Syntax:

```bash
./apc.out operand1 operator operand2
```

Example:

Addition

```bash
./apc.out 123456789 + 987654321
```

Subtraction

```bash
./apc.out 987654321 - 123456789
```

Multiplication

```bash
./apc.out 12345 x 54321
```

Division

```bash
./apc.out 999999999 / 9
```

Negative Numbers

```bash
./apc.out -999999 + 888888
```

---

# 📸 Sample Output

```text
=========================================
PROJECT : Arbitrary Precision Calculator
Submitted By : Pankaj Joshi
=========================================

The Addition of 123456789 and 987654321 is :
1111111110
```

---

# 🔄 Program Flow

```text
Start
   │
   ▼
Read Command Line Arguments
   │
   ▼
Validate Input
   │
   ▼
Create Linked Lists
   │
   ▼
Remove Leading Zeros
   │
   ▼
Select Operation
   │
   ├── Addition
   ├── Subtraction
   ├── Multiplication
   └── Division
   │
   ▼
Store Result in Linked List
   │
   ▼
Display Result
   │
   ▼
End
```

---

# 📚 Concepts Used

* C Programming
* Doubly Linked List
* Dynamic Memory Allocation
* Modular Programming
* Command Line Arguments
* Pointer Manipulation
* Arithmetic Algorithms
* Data Structures

---

# ⚡ Advantages

* Supports integers of virtually unlimited length.
* Not limited by built-in C data types.
* Efficient memory usage using dynamic allocation.
* Easy to maintain and extend.
* Demonstrates practical use of linked lists.

---

# 🔮 Future Improvements

* Modulus (%) operation
* Exponentiation
* Floating-point support
* Hexadecimal and Binary calculations
* Interactive menu-driven interface
* Expression parsing (e.g., `(A+B)*C`)
* Performance optimization for multiplication and division

---

# 🛠 Requirements

* GCC Compiler
* Linux / macOS / Windows (MinGW or WSL)
* C Standard Library

---

# 📖 Learning Outcomes

This project helps in understanding:

* Large number arithmetic
* Linked List operations
* Memory management
* Pointer concepts
* Command line programming
* Modular software design
* Algorithm implementation in C

---

# 👤 Author

**Pankaj Joshi**

**Student ID:** 25031_001

Embedded Systems Engineer | C Programmer | Robotics Enthusiast

---

# 📄 License

This project is intended for educational and academic purposes. Feel free to use and modify it for learning while giving appropriate credit to the original author.

---

⭐ If you found this project useful, consider giving the repository a **Star** on GitHub.
