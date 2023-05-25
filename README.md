# push_swap

## Description

push_swap is a 42-school project where the aim is to implement a sorting algorithm to sort a set of numbers in a stack using operations such as sa, sb, pa, pb, ra, rb, rra, rrb, rr, rrr.
To achieve full marks the sorting needs to be well optimized and sort 100 and 500 numbers with as few instructions as possible.

## Algorithm Used

My push_swap program utilizes radix sort (a non-comparative sorting algorithm) for sorting numbers more than 5. Radix sort sorts the elements by processing individual digits or groups of digits. It is not the best in terms of instructions efficiency for this project however.

## Steps taken in the project

- Error checking on the arguments
- Creation of stack_a as a doubly circular linked list and then duplicate checking
- Use of quicksort to determine the order of numbers in stack_a
- Application of radix sort to either rotate or push nodes from stack_a to stack_b

## Installation && Usage

1. Clone the repository:
git clone https://github.com/taanviir/push-swap.git

2. Change into the project directory:
cd push_swap

3. Compile the program:
make

4. Run the push_swap executable:

`./push_swap 2 3 1 4 ...` 
or `./push_swap "2 3 1 4 ..."` 
or `./push_swap 2 3 1 "4 6 5" ...` 
