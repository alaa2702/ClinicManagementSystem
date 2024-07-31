//
// Created by Alaa on 29/07/2024.
//

#include "user.h"


void UserMenu(){
    u8 choice;
    while (1){
        printf("1. View Patient Record\n");
        printf("2. View Today Reservations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        choice = IntCheck();
        switch (choice){
            case 1:
                ViewPatientRecord();
                break;
            case 2:
                ViewTodayReservations();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}
void ViewPatientRecord(){
    u16 id;
    printf("Enter the name of the patient ID: ");
    id = IntCheck();
    Node* patient = search(head, id);
    if (patient == NULL){
        printf("Patient not found\n");
        return;
    }
    printf("Patient data:\n");
    printPatient(patient->data);
}
void ViewTodayReservations(){
    // search for the list of patients who have a reservation
    Node* temp = head;
    while (temp != NULL){
        if (temp->data->slotReserved == 1){
            printSlotWithID(temp->data);
        }
        temp = temp->next;
    }
}