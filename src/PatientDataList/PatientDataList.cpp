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
    data->id = scanID(*head);
    while (repeatedID(*head, data->id)){
        data->id = scanID(*head);
    }
    printf("Enter Patient Gender: ");
    data->gender = GenderScan();
    data->slotReserved = 0;
    data->slot = (u8*)malloc(20 * sizeof(u8));
    printf(":");
    insertAtIndex(head, data);
    printf("Patient added successfully\n");
}


u16  scanID(Node* head){
    u16 id;
    printf("Enter Patient ID (no 1->10): ");
    id = IntCheck();
    while (!validateID(head, id)){
        id = IntCheck();
    }
    return id;
}
bool validateID(Node* head, u16 id){
    if(id < 1 || id > 10){
        printf("Please enter a valid ID: ");
        return false;
    }
    return true;
}
bool repeatedID(Node* head, u16 id){
    if(checkForPatient(head, id)){
        printf("Please enter a unique ID\n ");
        return true;
    }
    return false;
}
void deletePatient(Node** head, Patient *data){
    deleteAtIndex(head, data);
}
void printPatient(Patient* data){
    printf("Patient Name: %s\n", data->name);
    printf("Patient Age: %d\n", data->age);
    printf("Patient ID: %d\n", data->id);
    printf("Patient Gender:");
    if(data->gender==Female) {
        printf("Female\n");
    }
    else{
        printf("Male\n");
    }
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
void printSlotWithID(Patient* patient) {
    printf("Patient Slot: %s\t", patient->slot);
    printf("ID: %d\n", patient->id);
}
Gender GenderScan() {
    u8 choice = 0;
    printf("1. Female\n");
    printf("2. Male\n");
    choice = IntCheck();
    while (choice < 1 || choice > 2) {
        printf("Please enter a valid choice: ");
        choice = IntCheck();
    }
    if (choice == 1) {
        return Female;
    } else if (choice == 2) {
        return Male;
    }
}
