/*
 * @author: Alaa Mohammed
 * @brief: LinkedList functions prototypes
 * @date: 27/07/2024
 * */

#ifndef CLINICMANAGEMENTSYSTEM_LINKEDLIST_H
#define CLINICMANAGEMENTSYSTEM_LINKEDLIST_H
/* Includes */
#include "../PatientDataList/PatientDataList.h"
#include "../stdTypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Node structure */
typedef struct Node {
    Patient *data;
    struct Node* next;
}Node;
/* Function prototypes */
Node* createNode();
void insertAtEnd(Node** head, Patient data);
void insertAtIndex(Node** head, Patient data);
void deleteAtIndex(Node** head,Patient data);
void printList(Node* head);
Node* search(Node* head, Patient data);
void update(Node* head, Patient data);
void freeNode(Node** head);

#endif //CLINICMANAGEMENTSYSTEM_LINKEDLIST_H
