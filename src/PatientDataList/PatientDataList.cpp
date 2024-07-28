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
void deletePatient(Node** head, Patient data);
void printPatient(Patient* data);
Patient* searchPatient(Node* head, Patient data);
void updatePatient(Node* head, Patient data);