#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
} node;


typedef struct LL{
    node *head;
    int size;
} LL;


void create_node(node **p_n, int data)
{
    *p_n = (node*)malloc(sizeof(node));
    (*p_n)->next = NULL;
    (*p_n)->data = data;
}

// created a linked list that looks like data[0]->data[1]->data[2]->...->data[size-1]
void create_LL_from_data(LL **p_LL, int *data_arr, int size)
{
    (*p_LL) = (LL*)malloc(sizeof(LL));
    (*p_LL)->size = 0;
    node *cur = NULL;
    for(int i = 0; i < size; i++){
        node *n;
        create_node(&n, data_arr[i]); // n is a pointer to a node with data = data[i], next = NULL
        if(cur == NULL){
            (*p_LL)->head = n;
        }
        else{
            cur->next = n;
        }
        cur = n;
        (*p_LL)->size++;
    }
}


void LL_append(LL *my_list, int new_elem)
{
    node *cur = my_list->head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    node *n;
    create_node(&n, new_elem);
    cur->next = n;
    my_list->size++;
}

//insert new_elem at index index in linked list my_list
void LL_insert(LL *my_list, int new_elem, int index)
{
   
}

void LL_delete(LL *my_list, int index)
{
    // TODO
    // Delete element at index index in linked list my_list
}

void LL_free_all(LL *my_list)
{
    // TODO
    // Free all memory allocated for linked list my_list,
    // including all the nodes
}


int LL_get_rec(LL *my_list, int index)
{
    // TODO
    // Return the element at index index in linked list my_list
    // Use recursion. you must not use for, while, or do-while loops
    // You should use a helper function
}

typedef struct ArrayList{
    int *data;
    int size;
    int capacity;
} ArrayList;

void create_AL_from_data(ArrayList **p_AL, int *data_arr, int size)
{
    // TODO
}

void AL_append(ArrayList *my_list, int new_elem)
{
    // TODO
}

void AL_insert(ArrayList *my_list, int new_elem, int index)
{
    // TODO
}

void AL_delete(ArrayList *my_list, int index)
{
    // TODO
}

void AL_free(ArrayList *my_list)
{
    // TODO
}


int main()
{
    int data_arr[] = {1, 2, 3, 4, 5};
    LL *my_list;
    create_LL_from_data(&my_list, data_arr, 5);
    LL_append(my_list, 6);
    node *cur = my_list->head;
    while(cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    return 0;
}