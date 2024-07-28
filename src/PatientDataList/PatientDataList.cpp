/*
 * @author: Alaa Mohammed
 * @brief: standard types
 * @date: 27/07/2024
 * */

#include "PatientDataList.h"

void insertPatient(Node** head){
    Patient* data = (Patient*)malloc(sizeof(Patient));
    printf("Enter Patient Name: ");
    data->name = StringCheck(100);
    printf("Enter Patient Age: ");
    data->age = IntCheck();
    printf("Enter Patient ID: ");
    data->id = IntCheck();
    printf("Enter Patient Gender: ");
    data->gender = StringCheck(10);
    data->slotReserved = false;
    data->slot = (u8*)malloc(20 * sizeof(u8));
    insertAtIndex(head, data);
}
void deletePatient(Node** head, Patient *data){
    deleteAtIndex(head, data);
}
void printPatient(Patient* data){
    printf("Patient Name: %s\n", data->name);
    printf("Patient Age: %d\n", data->age);
    printf("Patient ID: %d\n", data->id);
    printf("Patient Gender: %s\n", data->gender);
    if(data->slotReserved){
        printf("Patient Slot: Reserved\n");
        printf("Time: %s\n", data->slot);
    }
    else{
        printf("Patient Slot: Not Reserved\n");
    }
}
Patient* searchPatient(Node* head, Patient* data){
    Node* temp = search(head, data);
    if(temp == NULL){
        printf("Patient not found\n");
        return NULL;
    }
    return temp->data;
void updatePatient(Node* head, Patient data);