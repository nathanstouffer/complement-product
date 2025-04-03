# complement-product

This is a little repo that solves a problem at multiple levels

## Level 1

As input, we are given a array of numbers $[ v_0, v_1, v_2, ..., v_{n-1} ]$.
For output, we expect an array of dimension $n$ where the $i^{th}$ element in the output array is $\prod_{i=0}^{n-1} v_i$.

Solve this problem with an algorithm that runs in $O(n^2)$ time.

## Level 2

Solve [Level 1](#level-1) with an algorithm that runs in $O(n)$ time.

## Level 3

This level replaces the array of numbers with an array of matrices (with fixed dimensions $d\ x\ d$).
For the case where all the matrices in the array are invertible, produce an algorithm that runs in $O(n)$.
The case where there is at least one non-invertible matrix can be solved by an algorithm that runs in $O(n^2)$ time.