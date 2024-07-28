/*
 * @author: Alaa Mohammed
 * @brief: standard types
 * @date: 27/07/2024
 * */
/* Includes */
#include "LinkedList.h"
#include "../PatientDataList/PatientDataList.h"
#include "../stdTypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Linked List functions implementation*/
// Create a new node
Node* createNode(){
    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){// Check if memory allocation failed
        printf("Error creating a new node.\n");
        exit(0);
    }
    return newNode;
}
// Insert a new node at the end of the list
void insertAtEnd(Node** head, Patient* data){
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
// Insert a new node at the given Patient data
void insertAtIndex(Node** head, Patient* data){
    u16 index = data->id;
    Node* newNode = createNode();
    Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    for (u16 i = 0; i < index; i++){
        last = last->next;
    }
    newNode->next = last->next;
    last->next = newNode;

}
// Delete a node at the given Patient data
void deleteAtIndex(Node** head,Patient* data){
    u16 index = data->id;
    Node* temp = *head;
    Node* prev = NULL;
    if(temp != NULL && temp->data->id == index){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data->id != index){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}
// Print the list
void printList(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        printPatient(temp->data);
        temp = temp->next;
    }
}

// Search for a node with the given ID
Node* search(Node* head, u16 id){
    Node* current = head;
    while(current != NULL){
        if(current->data->id == id){
            return current;
        }
        current = current->next;
    }
    return NULL;

}

// Update a node with the given Patient data
void update(Node* head, Patient* data){
    search(head, data->id)->data = data;

}
// Get the length of the list
u16 getLength(Node* head){
    u16 count = 0;
    Node* current = head;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}