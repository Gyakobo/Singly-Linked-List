# Singly Linked List

![image](https://img.shields.io/badge/Python-FFD43B?style=for-the-badge&logo=python&logoColor=blue)
![image](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![image](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![image](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![image](https://img.shields.io/badge/windows%20terminal-4D4D4D?style=for-the-badge&logo=windows%20terminal&logoColor=white)

Author: [Andrew Gyakobo](https://github.com/Gyakobo)

>[!NOTE]
>Just a small personal note and a small gag per say, this program is written in clean C and has no errors or warnings. The program was run and precompiled into an `.exe` with the following bash command:

```bash
$ sudo gcc -ansi -Wpedantic -Wextra -Wall main.c -o exe
```

This project showcases and more importantly explains a simple example of Singly Linked List.

## Introduction

A Singly Linked List is a linear data structure where each element, called a node, contains two parts:

1. Data: The value stored in the node
1. Pointer (or Reference): A reference to then next node in the sequence

The first node in the list is called a head, and the last node in the list has a reference to `null`, indicating the end of the list.

## Methodology

Needless to say, each link in this singly linked list is going to be represented by a node:

C code
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item;
    struct Node * next;
};
```

Python
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
```

Before we delve into the code let's first understand the basic operations. 

1. **Insertion**

    * *At the beginning (head)*: This operation involves creating a new node and updating the head pointer to this new node.

        * Time Complexity: $O(1)$
    
    * *At the end*: This operation requires traversal to the end of the list to add the new node.

        * Time Complexity: $O(n)$, where n is the number of nodes in the list. 

    * *At a specific position*: This operation involves traversing to the desired position and inserting the new node.

        * Time Complexity: $O(n)$ in the worst case.

```python    

```

## License
MIT

