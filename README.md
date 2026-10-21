# 🔢 Push_swap

A sorting algorithm project written in C at Codam (42 Network). The goal is to sort a sequence of integers using two stacks and a limited set of operations, minimizing the number of moves.

The project explores algorithm design, data structures, sorting complexity, and optimization under constraints.

## ⚙️ Features

- **Input validation:** Checks integer arguments, overflow, and duplicate values.
- **Stack operations:** Implements swap, push, rotate, and reverse rotate operations on two stacks.
- **Index-based sorting:** Assigns indices to values to simplify sorting.
- **Radix sort:** Uses a bitwise sorting approach to order indexed values through stack operations.
- **Small-stack optimization:** Uses dedicated sorting logic for small input sizes.
- **Memory management:** Frees allocated stack nodes and handles invalid input.

## 🛠️ Installation and Usage

**1. Compile the project**

```bash
make
```

**2. Run the sorter**

```bash
./push_swap 4 67 3 87 23
```

The program outputs the sequence of stack operations required to sort the integers in ascending order.

You can also pass a space-separated string:

```bash
./push_swap "4 67 3 87 23"
```

## 🧰 Technologies

- C
- Linked lists
- Stack data structures
- Radix sort and bitwise operations
- Algorithmic complexity and optimization
- Make
