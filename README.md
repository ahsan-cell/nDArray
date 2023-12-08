# ndArray C++ Template

The `ndArray` C++ template provides a flexible multi-dimensional array implementation. It supports arrays of one, two, three, or four dimensions and includes various functionalities such as insertion, deletion, retrieval, extension, and shrinking of arrays.

## Usage

### Initialization

```cpp
// Creating a 1D array with size 5
ndArray<int> array1D(5);

// Creating a 2D array with dimensions 3x3
ndArray<int> array2D(3, 3);

// Creating a 3D array with dimensions 2x2x3
ndArray<int> array3D(2, 2, 3);

// Creating a 4D array with dimensions 2x1x2x2
int dimensions[4] = { 2, 1, 2, 2 };
ndArray<int> array4D(dimensions, 4);
````
### Insertion
```cpp
// Inserting elements into the array
array1D.insert(42, 2);
array2D.insert(99, 1, 2);
array3D.insert(77, 0, 1, 2);
array4D.insert(123, indexes, 4); // Using indexes to insert into a 4D array
```
### Deletion
```cpp
// Deleting elements from the array
array1D.Delete(42);
array2D.Delete(1, 2);
array3D.Delete(indexes, 3); // Using indexes to delete from a 3D array
```
### Extend
```cpp
// Doubling the size of the higher dimension
array1D.Extend();
```
### Shrink
```cpp
// Halving the size of the higher dimension
array2D.Shrink();
```
### Output
```cpp
// Outputting the array
cout << array1D;
```
### Copy
```cpp
// Creating a copy of an existing array
ndArray<int> newArray(array1D);
```
### Access
```cpp
// Accessing elements using operators
int element = array2D(1, 2); // Accessing element at position (1, 2) in a 2D array
array3D(0, 1, 2) = 55; // Modifying element at position (0, 1, 2) in a 3D array
```
### Example
```cpp
int main()
{
    // Sample 3D array for testing
    int const size = 3;
    int arr1[size] = { 2, 2, 3 };
    ndArray<int> a1(arr1, size);

    // ... (Various operations on the array)

    return 0;
}
```
Feel free to explore and use this flexible ndArray template for your multi-dimensional array needs in C++.


