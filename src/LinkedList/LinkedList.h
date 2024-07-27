/*
 * @author: Alaa Mohammed
 * @brief: standard types
 * @date: 27/07/2024
 * */

#ifndef CLINICMANAGEMENTSYSTEM_LINKEDLIST_H
#define CLINICMANAGEMENTSYSTEM_LINKEDLIST_H
#include "../PatientDataList/PatientDataList.h"
#include "../stdTypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    Patient data;
    struct Node* next;
}Node;
Node* createNode();
void insertAtEnd(Node** head, Patient data);
void insertAtIndex(Node** head, Patient data);
void deleteAtIndex(Node** head,Patient data);
void printList(Node* head);
void search(Node* head, Patient data);
void update(Node* head, Patient data);
void freeNode(Node** head);

#endif //CLINICMANAGEMENTSYSTEM_LINKEDLIST_H
