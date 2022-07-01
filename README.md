# Doubly Linked List

This is an implementation of the doubly linked list in C++ with extended functionality.
This list allows you to create lists of any data, even your own data structures.
A doubly linked list does not permit null elements, but can be empty.
A doubly linked list is widely used in different algorithms and for storing data.

## Features and Examples

  * Create an empty List

  ```cpp
  // Example: Create an empty List of integers with the name "list"
  LinkedList<int> list;
  ```

  * Create a List with prefilled values

  ```cpp
  // you can prefill List with any amount of values
  // Example: Create a List of strings called "list" with prefilled values ("Hello", "World")
  LinkedList<string> list({ "Hello", "World" });
  ```

  * Get the current size of the List

  ```cpp
  size_t size();
  ```

  * Get the current List state: empty or not empty

  ```cpp
  bool isEmpty();
  ```

  * Clear the List - remove all elements from the List

  ```cpp
  void clear();
  ```

  * Check whether the List contains specific value. Returns true if the value is present in the List, otherwise - false

  ```cpp
  bool contains(value);
  ```

  * Add a new value to the List

  ```cpp
  void add(value);
  ```

  * Add a new value to the specific place in the List by an index starting from 0. After insertion element will be available on that index. If the List is empty, then the value will be added to the List

  ```cpp
  void add(index, value);
  ```

  * Add new values to the List

  ```cpp
  void addAll(values);
  // Example
  list.addAll({ 'a', 'b', 'c', 'a', 'b', 's' });
  ```

  * Remove all elements with a specific value from the List. Returns true if successful or false if the value is not present in the List

  ```cpp
  bool remove(value);
  ```

  * Remove a specific element from the List by its index starting from 0. Returns the value of the removed element

  ```cpp
  Type remove(index);
  ```

  * Remove all values from the List. Returns true if all enumerated values were removed successfully; otherwise, it returns false and keeps the List untouched.

  ```cpp
  bool removeAll(values);
  // Example
  list.removeAll({ 3.14, 5.34, 7.1231 });
  ```

  * Get the value of the element from the List by its index starting from 0

  ```cpp
  Type get(index);
  ```

  * Set a new value to the element from the List by its index starting from 0. Returns the previous value of the element

  ```cpp
  Type set(index, value);
  ```

  * Find the first appearance of the value in the List. Returns index of the found element

  ```cpp
  size_t indexOf(value);
  ```

  * Find the last appearance of the value in the List. Returns index of the found element

  ```cpp
  size_t lastIndexOf(value);
  ```

  * Swap elements represented by their indexes. Returns true if indexes are correct; otherwise, it returns false

  ```cpp
  bool swap(index1, index2);
  ```

  * Sort the List in ascending order

  ```cpp
  void sort();
  ```

  * Get a specific List element by its index starting from 0. Returns element from the List

  ```cpp
  // Examples
  #include <iostream>
  std::cout << list[0];
  // or
  list[3] = 15;
  // or
  list[1] = list[5];
  ```

  * Output the List to the standard output stream

  ```cpp
  // Example
  #include <iostream>
  std::cout << list << std::endl;
  // Will output the List in the following format: [element0, element1, ..., elementN]
  ```
