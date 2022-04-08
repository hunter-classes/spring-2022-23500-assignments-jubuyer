# Comparisons Between Sort Algorithms
Below is an analysis of how long different sorting algorithms take to sort a list of integers of varied sizes. At the bottom is a [chart comparison](https://github.com/hunter-classes/spring-2022-23500-assignments-jubuyer/edit/main/assignments/sorts/results.md#table-comparison) of the values. The chart shows that changing the pivot value between the same sorting algorithm did not have much effect on the time for sorting. This doesn't logically make much sense but the results proved that the in-place quicksort was much faster than it's braindead counterpart. In between each header is a further brief analysis of the results.

## Merge Sort
#### Time Complexity: O(n*log(n))
```c
./sorts -m 20 -s 1000 -a m

Starting the sort!
Algorithm: m
Time: 8
```

```c
./sorts -m 20 -s 10000 -a m
Starting the sort!
Algorithm: m
Time: 77
```

```c
./sorts -m 20 -s 100000 -a m
Starting the sort!
Algorithm: m
Time: 851
```

## Quick Sort - *Basic*
#### Time Complexity: O(n^2)
```c
./sorts -m 20 -s 1000 -a q
Starting the sort!
Algorithm: q
Time: 9
```

```c
./sorts -m 20 -s 10000 -a q
Starting the sort!
Algorithm: q
Time: 445
```

```c
./sorts -m 20 -s 100000 -a q
Starting the sort!
Algorithm: q
Time: 44781
```
This basic sort is slower than the merge sort, which makes sense considering the time complexity.

## Quick Sort - *Basic and Smart Pivot*
#### Time Complexity: O(n^2)
```c
./sorts -m 20 -s 1000 -a q
Starting the sort!
Algorithm: q
Time: 9
```

```c
./sorts -m 20 -s 10000 -a q
Starting the sort!
Algorithm: q
Time: 472
```

```c
./sorts -m 20 -s 100000 -a q
Starting the sort!
Algorithm: q
Time: 61917
```
Changing the pivot value to the median of the array/set did not make a significant difference, even though it was correctly sorting it. Surprising.

## Quick Sort - *In-Place and Basic Pivot*
#### Time Complexity: O(n*log(n))
```c
./sorts -m 20 -s 1000 -a i
Starting the sort!
Algorithm: i
Time: 1
```

```c
./sorts -m 20 -s 10000 -a i
Starting the sort!
Algorithm: i
Time: 3
```

```c
./sorts -m 20 -s 100000 -a i
Starting the sort!
Algorithm: i
Time: 26
```
Much faster than the merge sort, and when considering that it's best case is O(n), this is logical. What is surprising is that the results are similar to the smart pivot value in the same sorting algorithm.

## Quick Sort - *In-Place and Smart Pivot*
#### Time Complexity: O(n*log(n))
```c
./sorts -m 20 -s 1000 -a i
Starting the sort!
Algorithm: i
Time: 0
```

```c
./sorts -m 20 -s 10000 -a i
Starting the sort!
Algorithm: i
Time: 3
```

```c
./sorts -m 20 -s 100000 -a i
Starting the sort!
Algorithm: i
Time: 24
```
Similar results to the previous algorithm, though I thought that the difference between the two would be greater.

### Table Comparison
| Size        | Merge Sort Time | Quick Sort (Basic) Time | Quick Sort (Good Pivot) Time | In-Place Quick Sort (Basic Pivot) Time | In-Place Quick Sort (Good Pivot) Time |
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| 1,000      | 8       | 9       | 9       | 1       | 1       |
| 10,000   | 77        | 445        | 472        | 2        | 3        |
| 100,000   | 851        | 44781        | 61917        | 26        | 24        |
