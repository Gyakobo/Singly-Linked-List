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

**A Singly Linked List** is a linear data structure where each element, called a node, contains two parts:

1. Data: The value stored in the node
1. Pointer (or Reference): A reference to then next node in the sequence

The first node in the list is called a head, and the last node in the list has a reference to `null`, indicating the end of the list.

## Methodology

Needless to say, each link in this singly linked list is going to be represented by a node, followed by the `class SinglyLinkedList` or `struct List` implementation:

C code
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item;
    struct Node * next;
};

struct List {
    struct Node * head;
    struct Node * tail;
};

struct List new_list() {
    struct List list = {NULL, NULL};
    return list;
}
```

Python
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
```

Before we delve into the code let's first understand the basic operations. 

1. **Insertion**

    * *At the beginning (head)*: This operation involves creating a new node and updating the head pointer to this new node.

        * Time Complexity: $O(1)$
    
    * *At the end*: This operation requires traversal to the end of the list to add the new node.

        * Time Complexity: $O(n)$, where n is the number of nodes in the list. 

    * *At a specific position*: This operation involves traversing to the desired position and inserting the new node.

        * Time Complexity: $O(n)$ in the worst case.

C code
```c
void SLL_push(struct List * list, int item) {
    struct Node * p = malloc(sizeof(struct Node));
    p->item = item;

    if (SLL_empty(list)) {
        list->head = p;        
        list->tail = p;        
    }

    else {
        p->next     = list->head;
        list->head  = p; 
    }
}

void SLL_append(struct List * list, int item) {
    struct Node * p = malloc(sizeof(struct Node));
    p->item = item;

    if (SLL_empty(list)) SLL_push(list, item);
    else {
        list->tail->next = p;
        list->tail = p;
    }
}
```

Python
```python    
def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

def insert_at_end(self, data):
    new_node = Node(data)
    if not self.head:
        self.head = new_node
        return
    last_node = self.head
    while last_node.next:
        last_node = last_node.next
    last_node.next = new_node
```

2. **Deletion**

    * *At the beginning(head)*: This operation involves updating the head pointer to the next node.
        
        * Time complexity: $O(1)$
    
    * *At the end*: This operation requires traversal to the second last node to update its reference to `null`.

        * Time complexity: $O(n)$

    * *At a specific position*: This operation involves traversal to the node just before the one to be deleted and updating its reference.
        
        * Time complexity: $O(n)$

C code
```c
int SLL_pop(struct List * list){
    struct Node * p;
    int item;

    if (!SLL_empty(list)) {
        p = list->head;
        item = p->item;

        list->head = p->next; 
        free(p);
        return item;
    }

    return -1; /* Gotto change */
}
```

Python
```python
def delete_node(self, key):
       temp = self.head

       if temp is not None:
           if temp.data == key:
               self.head = temp.next
               temp = None
               return

       while temp is not None:
           if temp.data == key:
               break
           prev = temp
           temp = temp.next

       if temp == None:
           return

       prev.next = temp.next
       temp = None
```

3. **Search**
    * Searching for an element involves traversing the list and comparing each node's data with the target value.
        * Time Complexity: $O(n)$

Python
```python
def search(self, key):
       current = self.head
       while current:
           if current.data == key:
               return True
           current = current.next
       return False
```

## Space Complexity 

The space complexity for a singly linked list is $O(n)$ because each node requires space for the data and the reference to the next node.

### Advantages of Singly Linked Lists

1. *Dynamic Size*: They can easily grow and shrink in size by allocating and deallocating memory as needed.

1. *Efficient Insertions/Deletions*: Insertions and deletions (especially at the beginning) are more efficient compared to arrays since no shifting of elements is required.

### Disadvantages of Singly Linked Lists

1. *No Direct Access*: Accessing an element by index requires traversal from the head, which can be time-consuming.

1. *Memory Overhead*: Additional memory is required for storing the reference to the next node for each element.

1. *Poor Cache Performance*: Due to non-contiguous memory allocation, linked lists may suffer from poor cache performance compared to arrays.

## License
MIT

