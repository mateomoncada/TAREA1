#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node {
    void * data;
    struct Node * next;
    struct Node * prev;
} Node;

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List * list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    return list;
}

void * firstList(List * list) {
    if (list->head == NULL) return NULL;
    list->current = list->head;
    return list->current->data;
}

void * nextList(List * list) {
    if (list->current == NULL || list->current->next == NULL) return NULL;
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
    if (list->tail == NULL) return NULL;
    list->current = list->tail;
    return list->current->data;
}

void * prevList(List * list) {
    if (list->current == NULL || list->current->prev == NULL) return NULL;
    list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
    Node * newNode = createNode(data);
    newNode->next = list->head;

    if (list->head != NULL)
        list->head->prev = newNode;
    else
        list->tail = newNode;

    list->head = newNode;
}

void pushBack(List * list, void * data) {
    if (list->tail == NULL) {
        pushFront(list, data);
        return;
    }

    list->current = list->tail;
    pushCurrent(list, data);
}

void pushCurrent(List * list, void * data) {
    if (list->current == NULL) return;

    Node * newNode = createNode(data);
    newNode->prev = list->current;
    newNode->next = list->current->next;

    if (list->current->next != NULL)
        list->current->next->prev = newNode;
    else
        list->tail = newNode;

    list->current->next = newNode;
}

void * popFront(List * list) {
    if (list->head == NULL) return NULL;
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    if (list->tail == NULL) return NULL;
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    if (list->current == NULL) return NULL;

    Node * toDelete = list->current;
    void * data = toDelete->data;

    if (toDelete->prev != NULL)
        toDelete->prev->next = toDelete->next;
    else
        list->head = toDelete->next;

    if (toDelete->next != NULL)
        toDelete->next->prev = toDelete->prev;
    else
        list->tail = toDelete->prev;

    list->current = toDelete->next;
    free(toDelete);

    return data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
