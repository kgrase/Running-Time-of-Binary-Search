## Results

| **N (Size of vector)** | **Recursive Binary Search (µs)** | **Iterative Binary Search (µs)** | **Sequential Search (µs)** |
|------------------------|----------------------------------|---------------------------------|---------------------------|
| **5000**               | 0.1889                           | 0.1039                          | 12.1305                   |
| **50000**              | 0.2347                           | 0.1221                          | 70.7516                   |
| **100000**             | 0.1226                           | 0.0848                          | 317.522                   |
| **150000**             | 0.2258                           | 0.1131                          | 71.7493                   |
| **1000000**            | 0.4135                           | 0.141                           | 1899.15                   |

### 1. **Which searching algorithm performed the best?**
**Binary Search** (both recursive and iterative) performed the best, with much faster execution times than **Sequential Search**.

### 2. **Which searching algorithm performed the worst?**
**Sequential Search** performed the worst, with execution times increasing linearly as the dataset size grew.

### 3. **What was surprising about these results?**
The small difference between **Recursive** and **Iterative Binary Search** is primarily due to the minor overhead of recursive function calls in the recursive version, though the difference is minimal.

### 4. **How do you explain these results?**
**Binary Search** is faster due to its **logarithmic complexity (O(log N))**, while **Sequential Search** has **linear complexity (O(N))**, making it slower for larger datasets.

### 5. **Sometimes the sequential search algorithm will “find” the target at a different location than the two binary search algorithms. What do you think would be causing this result?**
This happens because **Sequential Search** doesn’t require sorted data, while **Binary Search** does. If there are duplicates, Sequential Search returns the first occurrence, while Binary Search may return any occurrence, depending on the middle index chosen.

### 6. **What did you find most challenging with this program?**
The most challenging part was ensuring the correct implementation of the search algorithms and accurately measuring execution times for large datasets.

### 7. **What problems did you encounter and how did you solve them?**
The main challenge was understanding how to properly measure and compare execution times for the different algorithms.

### 8. **What did you learn from writing this program?**
I learned the efficiency of binary search over sequential search and how to measure algorithm performance.
