# Doubly Linked List

This is an implementation of the doubly linked list in C++ with extended functionality.
This list allows to create lists of any data, even your own data structures.
Doubly linked list does not permit null elements, but can be empty.
Doubly linked list is widely used in different algorithms and for storing data.

## Features and Examples

  * Create empty List

  ```cpp
  // Example: Create empty List of integers with name "list"
  LinkedList<int> list;
  ```

  * Create List with prefilled values

  ```cpp
  // you can prefill List with any amount of values
  // Example: Create List of strings called "list" with prefilled values ("Hello", "World")
  LinkedList<string> list({"Hello", "World"});
  ```

  * Get current size of the List

  ```cpp
  size_t size();
  ```

  * Get current List state: empty or not empty

  ```cpp
  bool isEmpty();
  ```

  * Clear List - remove all elements from the List

  ```cpp
  void clear();
  ```

  * Check whether List contains specific value. Returns true if the value is present in the List, otherwise - false

  ```cpp
  bool contains(value);
  ```

  * Add new value to the List

  ```cpp
  void add(value);
  ```

  * Add new value to the specific place in the List by index starting from 0. After insertion element will be available on that index. If the List is empty than the value will be simply added to the List

  ```cpp
  void add(index, value);
  ```

  * Add new values to the List

  ```cpp
  void addAll(values);
  // Example
  list.addAll({'a', 'b', 'c', 'a', 'b', 's'});
  ```

  * Remove all elements with specific value from the List. Returns true if succeed, or false if the value is not present in the List

  ```cpp
  bool remove(value);
  ```

  * Remove specific element from the List by its index starting from 0. Returns the value of the removed element

  ```cpp
  Type remove(index);
  ```

  * Remove all values from the List. Returns true if all enumerated values have been removed successfully, otherwise returns false and keeps List untouched

  ```cpp
  bool removeAll(values);
  // Example
  list.removeAll({3.14, 5.34, 7.1231});
  ```

  * Get value of the element from the List by its index starting from 0

  ```cpp
  Type get(index);
  ```

  * Set new value to the element from the List by its index starting from 0. Returns previous value of the element

  ```cpp
  Type set(index, value);
  ```

  * Find first appearance of the value in the List. Returns index of found element

  ```cpp
  size_t indexOf(value);
  ```

  * Find last appearance of the value in the List. Returns index of found element

  ```cpp
  size_t lastIndexOf(value);
  ```

  * Swap elements represented by their indexes. Returns true if indexes are correct, otherwise - false

  ```cpp
  bool swap(index1, index2);
  ```

  * Sort the List ascending

  ```cpp
  void sort();
  ```
