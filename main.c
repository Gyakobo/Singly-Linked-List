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

int SLL_empty(struct List * list) {
    return list->head == NULL;
}

int SLL_len(struct List * list) {
    struct Node * p;
    int length = 0;

    if (!SLL_empty(list))
        for (p = list->head; p != NULL; p = p->next) ++length; 
    else return 0; 
    
    return length;
}

void SLL_display(struct List * list) {
    struct Node * p;
    if (!SLL_empty(list))
        for (p = list->head; p != NULL; p = p->next) printf("val = %d\n", p->item); 
    else printf("List is empty\n");
}
 
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

void SLL_clear(struct List * list) {
    while (!SLL_empty(list))
        SLL_pop(list);
}


int main() {
    struct List list = new_list();
    SLL_push(&list, 3);
    SLL_push(&list, 2);
    SLL_push(&list, 1);
    SLL_append(&list, 4);

    SLL_clear(&list);

    SLL_display(&list);

    return 0;
}

