/*
 * @author: Alaa Mohammed
 * @brief: LinkedList functions prototypes
 * @date: 27/07/2024
 * */

#ifndef CLINICMANAGEMENTSYSTEM_LINKEDLIST_H
#define CLINICMANAGEMENTSYSTEM_LINKEDLIST_H
/* Includes */
#include "../stdTypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../PatientDataList/PatientDataList.h"

/* Node structure */
typedef struct Node {
    struct Patient *data ;
    struct Node* next;
}Node;
/* Function prototypes */
Node* createNode();
void insertAtIndex(Node** head, struct Patient *data);
void deleteAtIndex(Node** head, struct Patient* data);
void printList(Node* head);
Node* search(Node* head, struct Patient* data);
void update(Node* head, struct Patient* data);
void freeNode(Node** head);

#endif //CLINICMANAGEMENTSYSTEM_LINKEDLIST_H
