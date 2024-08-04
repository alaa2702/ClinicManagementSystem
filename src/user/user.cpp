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
    if (head == NULL){
        printf("No Patients\n");
        return;
    }
    id = scanID(head);
    Patient* patient =NULL;
    if (!checkForPatient(head, id)){
        printf("Patient not found\n");
        return;
    }
    patient =getPatient(head, id);
    printf("______patient record______\n");
    printPatient(patient);
}
void ViewTodayReservations(){
    // search for the list of patients who have a reservation
    Node* temp = head;
    printf("Today's Reservations:\n");
    if(checkIfAllSlotNotReserved()){
        printf("No reservations\n");
        return;
    }
    // loop through the list
    while (temp != NULL){
        if (temp->data->slotReserved){
            printSlotWithID(temp->data);
        }
        temp = temp->next;
    }

}