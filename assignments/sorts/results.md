# Comparisons Between Sort Algorithms

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

## Quick Sort - *Basic and Smart Pivot*
#### Time Complexity: O(n*log(n))
```c

```
## Quick Sort - *In-Place and Basic Pivot*
#### Time Complexity: O(n*log(n))
```c

```
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
