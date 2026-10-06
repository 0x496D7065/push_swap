*This project has been created as part of the 42 curriculum*

# push_swap

## Description

push_swap is an algorithmic project: sort a stack of integers using a second stack and a limited set of operations, in as few moves as possible. The program reads a list of integers and prints the sequence of operations that sorts them in ascending order.

## Rules

- There are two stacks, **a** and **b**. Stack **a** starts with the given integers (no duplicates), and stack **b** starts empty.
- The goal is to sort **a** in ascending order, with the smallest number on top.
- Only the following operations are allowed:

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | Swap the top two elements of a / b / both |
| `pa` / `pb` | Push the top element of b onto a / of a onto b |
| `ra` / `rb` / `rr` | Rotate a / b / both up (the first element becomes the last) |
| `rra` / `rrb` / `rrr` | Reverse rotate a / b / both (the last element becomes the first) |

## Instructions

### Build

```bash
make          # builds the push_swap executable
make clean    # removes object files
make fclean   # removes object files and the executable
make re       # rebuilds everything
```

### Run

```bash
./push_swap 3 2 1 0
```

The program prints one operation per line. Invalid input (non-integers, duplicates, values outside the `int` range) prints `Error` on the standard error output.

### Check the result

You can verify the output and count the operations:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l                # number of operations
./push_swap $ARG | ./checker_Mac $ARG   # prints OK or KO
```

`checker_Mac` is the checker provided by 42 for macOS.

## Algorithm

This is using the Turk algorithm.
Basically the first two A nodes are pushed into B. Every A nodes gets assigned a target node from B, which is the closest smallest number. Then the cost to push each A node on top of it's targeted B node is calculated to
find the cheapest to push. This part is repeated until there is only 3 nodes left in stack A. Sort the last 3 until the bigger is at the bottom.

It is then gonna repeat the same process but looking for the closest bigger node to B from A and finds the cheapest by checking if the targeted node is above or below the median.
When there is no more nodes in stack B, it simply rotates or reverse rotates until the smallest number is at the very top depending on it's position compared to the median.

## Project structure

```
.
├── Makefile
├── checker_Mac    # 42's checker binary (macOS)
├── includes/      # header files
└── srcs/          # source files
```

## Resources

- The 42 push_swap subject PDF
- Articles and visualizers for sorting algorithms on stacks
