/*
 * @author: Alaa Mohammed
 * @brief: standard types
 * @date: 27/07/2024
 * */

#include "Admin.h"
bool checkPasswordForAdmin() {
    s16 password = passwordScanner();
    u16 correctPassword = 1234;
    for (u16 i = 0; i < 3; i++) {
        if (password == -1) {
            printf("Password digits must be numbers\n");
            password = passwordScanner();
        } else if (password == correctPassword) {
            return true;
        } else {
            printf("Wrong password, try again\n");
            password = passwordScanner();
        }
    }
    return false;
}

void AdminMenu(){
    u16 choice = 0;
    while(true){
        printf("1- Add New Patient Record\n");
        printf("2- Edit Patient Record\n");
        printf("3- Reserve A Slot With The Doctor\n");
        printf("4- Cancel Reservation\n");
        printf("5- Back\n");
        printf("Please enter your choice: ");
        choice = IntCheck();
        switch(choice){
            case 1:
                AddNewPatientRecord();
                break;
            case 2:
                EditPatientRecord();
                break;
            case 3:
                ReserveASlotWithTheDoctor();
                break;
            case 4:
                CancelReservation();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
void AddNewPatientRecord(){
    //check if the list is full
    if(getLength(head) == 10){
        printf("The list is full\n");
        return;
    }
    // Add new patient record
    insertPatient(&head);
}
void EditPatientRecord (){
    u16 id;
    Patient* data = NULL;
    if(head == NULL) {
        printf("No Patients\n");
        return;
    }
    printf("Enter Patient ID: ");
    id = IntCheck();
    while(id < 1 || id > 10){
        printf("Please enter a valid ID: ");
        id = IntCheck();
    }
    if(checkForPatient(head, id)) {
        data = getPatient(head, id);
        printPatient(data);
        printf("Enter new Patient Name: ");
        data->name = StringCheck(100);
        printf("Enter new Patient Age: ");
        data->age = IntCheck();
        printf("Enter new Patient gender: ");
        data->gender = StringCheck(10);
        updatePatient(head, data);
    }
    else{
        printf("Patient not found\n");
    }
}
void ReserveASlotWithTheDoctor(){
    Node* temp = NULL;
    Patient* data;
    int slot;
    static char* SlotOptions[] = {"2:00 PM to 2:30 PM", "2:30 PM to 3:00 PM", "3:00 PM to 3:30 PM", "4:00 PM to 4:30 PM", "4:30 PM to 5:00 PM"};
    for(u16 i = 0; i < 5; i++){
        printf(" %d- %s\n", i+1, SlotOptions[i]);
    }

    printf(" Please enter the slot number: ");
    scanf("%d", &slot);
    scanf("%d", &data->id);
    temp = search(head, data->id);
    switch(slot){
        case 1:
            strcpy((char*)(data->slot), "2:00 PM to 2:30 PM");
            SlotOptions[slot-1] = (char*) "Reserved";
            break;
        case 2:
            strcpy((char*)(data->slot), "2:30 PM to 3:00 PM");
            SlotOptions[slot-1] = (char*) "Reserved";
            break;
        case 3:
            strcpy((char*)(data->slot), "3:00 PM to 3:30 PM");
            SlotOptions[slot-1] = (char*) "Reserved";

            break;
        case 4:
            strcpy((char*)(data->slot), "4:00 PM to 4:30 PM");
            SlotOptions[slot-1] = (char*) "Reserved";

            break;
        case 5:
            strcpy((char*)(data->slot), "4:30 PM to 5:00 PM");
            SlotOptions[slot-1] = (char*) "Reserved";

            break;
        default:
            printf(" Invalid slot\n");
            break;
    }

}


void CancelReservation(){
    u16 id;
    Patient* data = NULL;
    if(head == NULL) {
        printf("No Patients\n");
        return;
    }
    printf("Enter Patient ID: ");
    id = IntCheck();
    while(id < 1 || id > 10){
        printf("Please enter a valid ID: ");
        id = IntCheck();
    }
    if(checkForPatient(head, id)) {
        data = getPatient(head, id);
        if(data->slotReserved){
            data->slotReserved = false;
            strcpy((char*)(data->slot), "Not Reserved");
        }
        else{
            printf("Slot is not reserved\n");
        }
    }
    else{
        printf("Patient not found\n");
    }
}
Node* getHead(){
    return head;
}
