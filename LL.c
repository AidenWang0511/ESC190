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

void LL_insert(LL *my_list, int new_elem, int index)
{
    // TODO
    //insert new_elem at index index in linked list my_list

    node *n = (node*)malloc(sizeof(node));
    n->data = new_elem;

    if(index < 0 || index >= my_list->size){
        printf("insert: Index out of bound!!!!!!\n");
        return;
    }else if(index == 0){
        n->next = my_list->head;
        my_list->head = n;
    }else{
        node *prev = my_list->head;
        for(int i=0; i<index-1; i++){
            prev = prev->next;
        }
        n->next = prev->next;
        prev->next = n;
    }
    my_list->size++;
}

void LL_delete(LL *my_list, int index)
{
    // TODO
    // Delete element at index index in linked list my_list

    node *n_delete;

    if(index < 0 || index >= my_list->size){
        printf("remove: Index out of bound!!!!!!\n");
        return;
    }else if(index == 0){
        n_delete = my_list->head;
        my_list->head = n_delete->next;
    }else{
        node *prev = my_list->head;
        for(int i=0; i<index-1; i++){
            prev = prev->next;
        }
        n_delete = prev->next;
        prev->next = prev->next->next;
    }
    
    free(n_delete);
    my_list->size--;

}

void LL_free_all(LL *my_list)
{
    // TODO
    // Free all memory allocated for linked list my_list,
    // including all the nodes
    node *cur = my_list->head, *nxt;

    while(cur != NULL){
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }

    my_list->head = NULL;
    my_list->size = 0;
    //not sure if it's the above one or below
    //free(my_list);
}

int LL_get_rec_helper(node *cur, int index){
    if(index == 0){
        return cur->data;
    }else{
        return LL_get_rec_helper(cur->next, index-1);
    }
}

int LL_get_rec(LL *my_list, int index)
{
    // TODO
    // Return the element at index index in linked list my_list
    // Use recursion. you must not use for, while, or do-while loops
    // You should use a helper function
    if(index < 0 || index >= my_list->size){
        printf("remove: Index out of bound!!!!!!\n");
        return -1;
    }else{
        return LL_get_rec_helper(my_list->head, index);
    }

}

typedef struct ArrayList{
    int *data;
    int size;
    int capacity;
} ArrayList;

void create_AL_from_data(ArrayList **p_AL, int *data_arr, int size)
{
    // TODO
    *p_AL = (p_AL*)malloc(sizeof(ArrayList));
    (*p_AL)->size, (*p_AL->capacity) = size;
    (*p_AL)->data = (int*)malloc(sizeof(int)*size);
    for(int i=0; i<size; i++){
        (*p_AL)->data[i] = data_arr[i];
    }

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

    printf("Test for LL_insert:\n");
    LL_insert(my_list, 7, 2);
    cur = my_list->head;
    while(cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }

    printf("Test for LL_delete:\n");
    LL_delete(my_list, my_list->size - 1);
    cur = my_list->head;
    while(cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }

    printf("Test for LL_get_rec:\n");
    printf("value at index 2: %d\n", LL_get_rec(my_list, 2));

    printf("Test for LL_free_all:\n");
    LL_free_all(my_list);
    cur = my_list->head;
    while(cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    
    return 0;
}