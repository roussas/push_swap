*This project has been created as part of the 42 curriculum by yaozhou, kpagkalo.*

# Push_swap

## Description

Push_swap is a sorting algorithm project from the 42 curriculum. The objective is to sort a set of unique integers using two stacks, **A** and **B**, and a restricted set of operations.

The challenge is not simply to sort the numbers, but to find an efficient sequence of operations while respecting the limitations of the available instructions.

The program starts with all integers in stack A, while stack B is initially empty. It must produce a sequence of operations that leaves all integers sorted in ascending order in stack A, with stack B empty.

This implementation includes four sorting strategies with different algorithmic approaches:

- **Simple:** Insertion-based sorting, O(n²).
- **Medium:** Range/chunk-based sorting, O(n√n).
- **Complex:** Binary Radix Sort, O(n log n).
- **Adaptive:** Selects a strategy according to the initial disorder percentage.

An optional `--bench` flag provides information about the input disorder, selected strategy, operation count, and individual operation frequencies.

## Instructions

### Compilation

Compile the project using the provided Makefile:

```bash
make
```

This generates the `push_swap` executable.

Other available Makefile commands:

```bash
make clean
make fclean
make re
```

### Execution

Run the program by providing a sequence of unique integers:

```bash
./push_swap 4 67 3 87 23
```

The program prints the operations required to sort the stack.

### Sorting strategies

Select a specific algorithm using one of the following flags:

```bash
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

Without a strategy flag, the program uses its default strategy.

### Benchmark mode

Add `--bench` to display performance information:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Benchmark information is written to **stderr**, while sorting operations remain on **stdout**. This allows the operations to be redirected or piped into a checker without mixing them with benchmark output.

For example:

```bash
./push_swap --bench --adaptive 4 67 3 87 23 > operations.txt 2> benchmark.txt
```

### Checking the result

Use the 42 checker to verify the generated sequence:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

A successful result should display:

```text
OK
```

## Available Operations

The program uses the following instructions:

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the top element of B onto A |
| `pb` | Push the top element of A onto B |
| `ra` | Rotate stack A upwards |
| `rb` | Rotate stack B upwards |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A |
| `rrb` | Reverse rotate stack B |
| `rrr` | Perform `rra` and `rrb` simultaneously |

## Algorithm Design

The project implements three distinct sorting approaches and an adaptive selection mechanism. Each approach explores a different balance between operation count, algorithmic complexity, and suitability for different input characteristics.

### 1. Simple — Insertion-based sorting — O(n²)

The Simple strategy uses an insertion-based approach.

It progressively positions elements in their correct relative order, using stack operations such as rotations and pushes to move elements into their required positions.

The approach is particularly suitable for small or relatively ordered inputs because it can take advantage of elements that are already close to their final positions.

Its main disadvantage is that the number of comparisons and repositioning operations can grow quadratically as the input size increases.

**Complexity:**

- Time: O(n²) upper bound.
- Space: O(n) for stack storage and the associated data structures.

**Why use it?**

- Straightforward sorting logic.
- Effective for small inputs.
- Can take advantage of relatively low disorder.
- Provides a useful baseline for comparing the other strategies.

### 2. Medium — Range/Chunk-based sorting — O(n√n)

The Medium strategy uses a chunk-based approach.

Instead of processing the entire stack as one collection, the algorithm divides the input into smaller groups. The number of chunks is related to the square root of the input size.

The general process is:

1. Divide the available ranks into approximately √n chunks.
2. Move elements belonging to the current chunk from A to B.
3. Use rotations to position elements efficiently during the transfer.
4. Continue until the elements have been transferred.
5. Reconstruct stack A by retrieving elements from B in the required order.

By dividing the input into smaller groups, the algorithm reduces the amount of searching and repositioning required compared with a straightforward quadratic approach.

The number of chunks and the movement of elements are designed to balance the cost of transferring elements between the two stacks.

**Complexity:**

- Time: O(n√n) upper bound for the implemented chunk-based approach.
- Space: O(n) for stack storage and auxiliary data structures.

**Why use it?**

- Reduces operation growth compared with the Simple strategy.
- Uses chunks to organize elements during transfers.
- Provides a balance between implementation complexity and sorting efficiency.
- Offers an alternative when the input is neither particularly ordered nor highly disordered.

### 3. Complex — Binary Radix Sort — O(n log n)

The Complex strategy uses **binary Radix Sort**.

Radix Sort processes integers by examining their binary representation rather than directly comparing every element with every other element.

To support negative and positive integers, the values are first normalized into ranks representing their relative order.

The algorithm then processes the bits of these ranks, starting with the least significant bit.

For each bit position:

1. Inspect the elements in stack A.
2. If the current bit is 0, push the element to B.
3. If the current bit is 1, rotate A.
4. Once all elements have been processed, move the elements from B back to A.
5. Repeat for the next bit.

After processing all necessary bits, the elements are sorted.

Since the normalized ranks range from 0 to n-1, approximately log₂(n) bit positions are required. Each pass processes all n elements, resulting in O(n log n) complexity.

**Complexity:**

- Time: O(n log n) upper bound.
- Space: O(n) for stack storage and rank normalization.

**Why use it?**

- Avoids the quadratic growth of comparison-based approaches.
- Provides predictable performance for large inputs.
- Does not depend on the initial disorder to guarantee its sorting complexity.
- Is particularly suitable for larger inputs, such as the 500-element evaluation.

### 4. Adaptive strategy

The Adaptive strategy combines the advantages of the three sorting approaches.

Rather than applying the same algorithm to every input, it evaluates the initial disorder percentage and selects an appropriate sorting strategy.

The selection thresholds are:

| Disorder percentage | Selected strategy | Complexity |
|---|---|---|
| Below 20% | Simple | O(n²) |
| 20% to below 50% | Medium | O(n√n) |
| 50% or higher | Complex | O(n log n) |

#### Rationale behind the thresholds

The thresholds are heuristic choices designed to balance sorting efficiency and operation count.

**Low disorder — Below 20%**

When the input is already relatively ordered, an insertion-based approach can take advantage of the existing order. Applying a more complex strategy may introduce unnecessary operations.

**Medium disorder — 20% to below 50%**

When the input has a moderate level of disorder, the chunk-based approach offers a compromise. Dividing the elements into ranges helps organize the transfers between stacks without relying on the initial order being particularly favorable.

**High disorder — 50% or higher**

When the input is highly disordered, the initial arrangement provides less advantage to an insertion-based approach. Binary Radix Sort offers predictable performance because its number of passes depends on the number of bits required to represent the ranks, rather than the initial order.

The 20% and 50% boundaries are practical heuristic thresholds used to divide the three operating regimes. They are not universal mathematical breakpoints; their purpose is to provide a consistent selection rule between the implemented algorithms.

**Complexity:**

- Sorting phase: Depends on the selected strategy.
- Worst-case sorting upper bound: O(n²), because the Simple strategy is selected for low-disorder inputs.
- Space: O(n) for stack storage and auxiliary data structures.

The adaptive strategy therefore trades a potentially higher worst-case complexity for the ability to choose an approach suited to the initial arrangement.

## Benchmarking and Disorder Calculation

The optional `--bench` mode provides additional information about the sorting process.

One of its main measurements is **disorder**, calculated using the inversion count.

An inversion is a pair of elements where an earlier element is greater than a later element.

For an input containing n elements, the maximum possible number of inversions is:

\[
\frac{n(n-1)}{2}
\]

The disorder percentage is calculated as:

\[
\text{Disorder} =
\frac{\text{Number of inversions}}
{\frac{n(n-1)}{2}}
\times 100
\]

For example:

```text
Input:  1 2 3 4 5
Disorder: 0.00%

Input:  5 4 3 2 1
Disorder: 100.00%
```

The inversion count is calculated by comparing pairs of elements. This requires O(n²) time and O(1) additional space for the counting process.

The benchmark also reports:

- Selected sorting strategy.
- Algorithmic complexity.
- Total number of operations.
- Individual operation counts, including swaps, pushes, rotations, and reverse rotations.

Benchmark information is printed to stderr so that the generated instructions remain clean on stdout.

**Note:** The complexity figures in the algorithm sections describe the respective sorting strategies. The disorder calculation is a separate preprocessing step and has its own O(n²) time complexity.

## Testing

The project was tested using a combination of manual, automated, and memory-checking tests.

Testing included:

- Empty input, single-element inputs, and already sorted sequences.
- Reverse-sorted inputs and small permutations.
- Negative numbers and integer boundaries.
- Duplicate values, invalid arguments, and integer overflow.
- All four sorting strategies.
- Randomized inputs containing 100 and 500 elements.
- Validation of generated operations using the 42 checker.
- Memory leak and invalid memory access checks using Valgrind.
- Benchmark calculations and stdout/stderr separation.

## Resources

The following resources were useful for understanding the algorithms and concepts involved in this project.

### Documentation and references

- [42 Network](https://42.fr/) — 42 curriculum and project requirements.
- [Push_swap algorithm explanation (YouTube)](https://www.youtube.com/watch?v=OaG81sDEpVk&t=1058s) — Explanation of Push_swap, its complexity, and different approaches.
- [GeeksforGeeks — Radix Sort](https://www.geeksforgeeks.org/dsa/radix-sort/) — Explanation of Radix Sort.
- [GeeksforGeeks — Insertion Sort](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/) — Reference for insertion-based sorting.
- [42 Cursus Guide — Push_swap](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap) — Additional explanations and insights into Push_swap.
- [Understanding Sorting Algorithms](https://medium.com/jl-codes/understanding-sorting-algorithms-af6222995c8) — Overview of sorting algorithms and their different approaches.
- [Turk Algorithm Explained](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0) — Additional Push_swap algorithm explanations.

### AI Usage

AI tools were used as learning assistance and development resources throughout the project.

Their use included:

- Explaining sorting algorithms, data structures, and algorithmic complexity.
- Discussing possible approaches for improving the number of operations.
- Helping investigate bugs and understand compilation errors.
- Reviewing code snippets and identifying potential memory-management problems.
- Suggesting edge cases and testing scenarios.
- Assisting with the creation of additional test commands and test scripts.
- Explaining benchmark calculations and helping verify their results.

The implementation, algorithm selection, integration, testing, and final technical decisions were carried out by the project authors. AI-generated suggestions were treated as guidance and evaluated against the project requirements.

## Contributions

This project was developed collaboratively by **kpagkalo** and **yaozhou**.

The contributions were divided as follows:

### kpagkalo

- Error handling.
- Ranker implementation.
- Complex sorting algorithm (Binary Radix Sort).
- Entire `Stack/` folder and its stack-related functionality.

### yaozhou

- Entire `Bench/` folder and benchmark functionality.
- `parse_arg_extra` and `parse_args`.
- Medium sorting algorithm (Range/Chunk-based).
- `sort` implementation.

### Joint contributions

The following components were developed collaboratively:

- The main `push_swap`.
- Insertion-based sorting functionality.
- `atoi` implementation.
- General utility functions.
- Disorder calculation.

Both authors contributed to the overall design, integration, testing, and completion of the project.

---

**Authors:** kpagkalo and yaozhou

**Project:** 42 — Push_swap