/*
 * @author: Alaa Mohammed
 * @brief: standard types
 * @date: 27/07/2024
 * */
#include "LinkedList.h"
#include "../PatientDataList/PatientDataList.h"
#include "../stdTypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* createNode(){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error creating a new node.\n");
        exit(0);
    }
    return newNode;
}
void insertAtEnd(Node** head, Patient data){
    Node* newNode = createNode();
    Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;

}
void insertAtIndex(Node** head, Patient data);
void deleteAtIndex(Node** head,Patient data);
void printList(Node* head);
void search(Node* head, Patient data);
void update(Node* head, Patient data);
void freeNode(Node** head);
