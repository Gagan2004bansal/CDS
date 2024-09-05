# CDS-Library 

**C Data Structures Library** is a comprehensive library for C, offering a collection of data structures, algorithms, and utilities. It simplifies the use of essential data structures, sorting algorithms, and string manipulations, allowing you to focus on developing your application.

## Key Features

- **Prebuilt Data Structures**: Includes major data structures such as Linked Lists, Stacks, Queues etc.
- **Algorithms**: Implements a range of sorting and searching algorithms like Bubble Sort, Merge Sort, Quick Sort, Linear Search, and many more.
- **Custom String Utilities**: Provides a custom `String` type with dynamic resizing and various utility functions similar to `std::string` in C++.
- **Custom Functions**: Each data structure and algorithm comes with a set of commonly used operations (e.g., insert, delete, search, traverse) tailored for ease of use.
- **Header-Only Access**: Include the relevant header files in your project to start using the data structures, algorithms, and utilities without additional setup.

## Supported Components

### Data Structures
- **String**
  <div>
    <ul>
      <li>String create();</li>
      <li>void freeS(String *str);</li>
      <li>void appendS(String *str, const char* suffix);</li>
      <li>size_t lenghtS(const String *str);</li>
      <li>const char* getS(const String *str);</li>
      <li>void readS(String *str);</li>
      <li>bool isemptyS(const String* str);</li>
      <li>void rep_substring(String *str, const char *old_sub, const char *new_sub);</li>
      <li>void reverseS(String *str);</li>
    </ul>
  </div>
- **Linked List**
  <div>
    <ul>
      <li>Node* CreateList(int data);</li>
      <li>void InsertAtHead(Node** head, int data);</li>
       <li>void InsertAtTail(Node** head, int data);</li>
       <li>void InsertAtPosition(Node** head, int data, int position);</li>
       <li>void DeleteByValue(Node** head, int data);</li>
       <li>void DeleteAtPosition(Node** head, int position);</li>
       <li>void DeleteList(Node** head);</li>
       <li>void PrintList(Node* head);</li>
       <li>int SearchList(Node* head, int data);</li>
       <li>int LengthList(Node* head);</li>
       <li>void SortList(Node** head);</li>
    </ul>
  </div>
- **Generic Stack**
  <div>
    <ul>
      <li>Stack *stackCreate(size_t element_size);</li>
      <li>void stackDelete(Stack *stack);</li>
      <li>bool stackPush(Stack *stack, const void *element);</li>
      <li>bool stackPop(Stack *stack);</li>
      <li>bool stackPeek(const Stack *stack, void *element);</li>
      <li>bool stackIsEmpty(const Stack *stack);</li>
    </ul>
  </div>
- **Generic Queue**
  <div>
    <ul>
      <li>Queue *queueCreate(size_t element_size);</li>
      <li>void queueDelete(Queue *queue);</li>
      <li>bool queueEnqueue(Queue *queue, const void *element);</li>
      <li>bool queueDequeue(Queue *queue);</li>
      <li>bool queuePeek(const Queue *queue, void *element); </li>
      <li>bool queueIsEmpty(const Queue *queue);</li>
    </ul>
  </div>


### Searching Algorithms
- Linear Search
- Binary Search

### Sorting Algorithms
- Bubble Sort
- Insertion Sort
- Selection Sort
- Merge Sort
- Quick Sort


### Usage 
- Include the necessary header files in your C code.
- Initialize and use the data structures and algorithms as needed.
- Refer to the documentation in the code comments for detailed usage instructions.