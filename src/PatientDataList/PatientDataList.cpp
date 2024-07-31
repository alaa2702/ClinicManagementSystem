/*
 * @author: Alaa Mohammed
 * @brief: Patient Data List functions implementation
 * @date: 27/07/2024
 * */

#include "PatientDataList.h"

void insertPatient(Node** head){
    Patient* data = (Patient*)malloc(sizeof(Patient));
    printf("Enter Patient Name: ");
    data->name = StringCheck(100);
    printf("Enter Patient Age: ");
    data->age = IntCheck();
    checkID(*head, data);
    printf("Enter Patient Gender: ");
    data->gender = StringCheck(10);
    data->slotReserved = false;
    data->slot = (u8*)malloc(20 * sizeof(u8));
    insertAtIndex(head, data);
}
void checkID(Node* head, Patient* data){
    printf("Enter Patient ID (no 1->10): ");
    data->id = IntCheck();
    while (!validateID(head, data->id)){
        data->id = IntCheck();
    }
}
bool validateID(Node* head, u16 id){
    if(id < 1 || id > 10){
        printf("Please enter a valid ID: ");
        return false;
    } else if(checkForPatient(head, id)){
        printf("Please enter a unique ID: ");
        return false;
    }
    return true;
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
bool checkForPatient(Node* head, u16 id){
    Node* temp = search(head, id);
    if(temp == NULL){
        return false;
    }
    return true;
}
Patient* getPatient(Node* head, u16 id){
    Node* temp = search(head, id);
    return temp->data;
}
void updatePatient(Node* head, Patient* data){

       update(head, data);
}
void printSlotWithID(Patient* patient){
    printf("Patient Slot: %s\t", patient->slot);
    printf("ID: %d\n", patient->id);
}