/*
================================================================================================================

Author:     kgrase
Email:      kg73499@email.vccs.edu
Title:      Analyze Running Time of Binary Search
Objective:  To analyze the running time for the recursive and iterative versions of the binary search algorithm.

================================================================================================================
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>

/*
    Performs a recursive binary search on a sorted vector.

    vec:            The sorted vector of integers to search within.
    target:         The integer value to search for in the vector.
    left_index:     The starting index for the current search range.
    right_index:    The ending index for the current search range.

    Returns:
        The index of the target if found.
        -1 if the target is not in the vector.
 */
int recursiveBinarySearch(const std::vector<int>& vec, int target, int left_index, int right_index) {
    // Base case: If left index exceeds right, target is not found
    if (left_index > right_index) { 
        return -1; // Target not found
    }

    // Find the middle index
    int middle_index = left_index + (right_index - left_index) / 2;

    // Check if the target is at the middle
    if (vec[middle_index] == target) {
        return middle_index; // Target found at index mid
    }
    // If the target is smaller than middle index element, search in the left half
    else if (target < vec[middle_index]) {
        return recursiveBinarySearch(vec, target, left_index, middle_index - 1);
    }
    // If the target is larger than middle element, search in the right half
    else {
        return recursiveBinarySearch(vec, target, middle_index + 1, right_index);
    }
}

/*
    Performs an iterative binary search on a sorted vector.
 
    vec:     The sorted vector of integers to search within.
    target:  The integer value to search for in the vector.

    Returns:
        The index of the target if found.
        -1 if the target is not in the vector.
*/
int nonRecursiveBinarySearch(const std::vector<int>& vec, int target) {
    int left_index  = 0;
    int right_index = vec.size() - 1;

    while (left_index <= right_index) {
        int middle_index = left_index + (right_index - left_index) / 2;

        // Check if the target is at the middle
        if (vec[middle_index] == target) {
            return middle_index; // Target found at index mid
        }
        // If target is smaller than mid element, search the left half
        else if (target < vec[middle_index]) {
            right_index = middle_index - 1;
        }
        // If target is larger than mid element, search the right half
        else {
            left_index = middle_index + 1;
        }
    }

    return -1; // Target not found
}

/*
    Performs a sequential search on a vector.

    vec:    The vector of integers to search within.
    target: The integer value to search for in the vector.
    Returns:
        The index of the target if found
        -1 if the target is not in the vector.
 */
int sequentialSearch(const std::vector<int>& vec, int target) {
    // Loop through each element in the vector
    for (int i = 0; i < vec.size(); ++i) {
        // Check if the current element matches the target
        if (vec[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Target not found in the vector
}

int main(void) {
    std::srand(std::time(0)); // Seed the random number generator

    // Create a vector and fill it with random numbers between 1 and 100
    std::vector<int> vec;
    int vec_length = 50;  // Set the vector size to 20

    for (int i = 0; i < vec_length; ++i) {
        int number = std::rand() % 100 + 1;  // Get a random number in the range 1-100
        vec.push_back(number);
    }

    // Sort the vector in ascending order
    std::sort(vec.begin(), vec.end());

    // Contents of vector
    std::cout << "Contents of vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Generate a random target value between 1 and 100
    int target = std::rand() % 100 + 1;
    
    // Recursive Binary Search
    std::cout << "Recursive Binary Search" << std::endl;
    int index = recursiveBinarySearch(vec, target, 0, vec.size() - 1);
    if (index != -1)
        std::cout << target << " found at index: " << index << std::endl;
    else
        std::cout << target << " was not found, return value is: " << index << std::endl;
    std::cout << std::endl;

    // Iterative Binary Search
    std::cout << "Iterative Binary Search" << std::endl;
    index = nonRecursiveBinarySearch(vec, target);
    if (index != -1)
        std::cout << target << " found at index: " << index << std::endl;
    else
        std::cout << target << " was not found, return value is: " << index << std::endl;
    std::cout << std::endl;

    // // Sequential Search
    std::cout << "Sequential Search" << std::endl;
    index = sequentialSearch(vec, target);
    if (index != -1)
        std::cout << target << " found at index: " << index << std::endl;
    else
        std::cout << target << " was not found, return value is: " << index << std::endl;
    std::cout << std::endl;

    return 0;
}
