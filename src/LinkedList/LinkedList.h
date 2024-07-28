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
Node* createNode();// create a new node
void insertAtIndex(Node** head, struct Patient *data);// insert a new node at the end of the list
void deleteAtIndex(Node** head, struct Patient* data);// delete a node from the list
void printList(Node* head);// print the list
Node* search(Node* head, u16 id);// search for a node in the list using the patient id
void update(Node* head, struct Patient* data); // update a node in the list
u16 getLength(Node* head);// get the length of the list
#endif //CLINICMANAGEMENTSYSTEM_LINKEDLIST_H
