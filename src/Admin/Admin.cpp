/*
 * @author: Alaa Mohammed
 * @brief: standard types
 * @date: 27/07/2024
 * */

#include "Admin.h"
Node *head = NULL;
u16 slotSize = 5;
char* SlotOptions[] = {(char*)"2:00 PM to 2:30 PM", (char*)"2:30 PM to 3:00 PM", (char*)"3:00 PM to 3:30 PM", (char*)"4:00 PM to 4:30 PM", (char*)"4:30 PM to 5:00 PM"};
bool checkPasswordForAdmin() {
    s16 password = 0;
    u16 correctPassword = 1234;
    for (u16 i = 0; i < 3; i++) {
        printf("You have %d tries left\n", 3 - i);
        password = passwordScanner();
        if (password == -1) {
            printf("Password digits must be numbers\n");
        } else if (password == correctPassword) {
            return true;
        } else {
            printf("Wrong password, try again\n");
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
    id = scanID(head);
    if(checkForPatient(head, id)) {
        data = getPatient(head, id);
        printPatient(data);
        printf("Enter new Patient Name: ");
        data->name = StringCheck(100);
        printf("Enter new Patient Age: ");
        data->age = IntCheck();
        printf("Enter new Patient gender: ");
        data->gender = GenderScan();
        updatePatient(head, data);
    }
    else{
        printf("Patient not found\n");
    }
}
void ReserveASlotWithTheDoctor(){
    Node* node = NULL;
    Patient* data = NULL;
    u16 id = 0;
    u16 slot = 0;
    //check if all slots are reserved or not
    if(checkIfAllSlotReserved()){
        printf("All slots are reserved\n");
        return;
    }
    //print the available slots
    for(u16 i = 0; i < slotSize; i++){
        printf(" %d- %s\n", i+1, SlotOptions[i]);
    }

    printf(" Please enter the slot number: ");
    slot = IntCheck();
    //check if the slot is in the range 1->5
    while(slot < 1 || slot > slotSize){
        printf("Please enter a valid slot number: ");
        slot = IntCheck();
    }
    //check if the slot is reserved or not
    if( strcmp(SlotOptions[slot-1],(char*)"Not Available") == 0){
        printf("Slot is already reserved\n");
        return;
    }
    //get the patient ID
    id = scanID(head);
    //search for the patient
    node = search(head, id);
    //check if the patient is found
    if(!checkForPatient(head, id)){
        printf("Patient not found\n");
        return;
    }
    //get the patient data
    data = node->data;
    //check if the slot is reserved
    if(data->slotReserved){
        printf("Patient already has a reservation\n");
        return;
    }
    //reserve the slot
    for(u16 i = 0; i < slotSize; i++){
        if(i == slot-1) {
            //reserve the slot for the patient
            strcpy((char *) (data->slot), (const char *)SlotOptions[i]);
            //set the slot reserved flag
            data->slotReserved = slot;
            printf("Slot reserved successfully\n");
            //set the slot to not available
            SlotOptions[i] = (char*)"Not Available";
        }
    }


}
bool checkIfAllSlotReserved(){
    for(u16 i = 0; i < slotSize; i++){
        if(strcmp(SlotOptions[i], (char*)"Not Available") != 0){ //check if the slot is not reserved
            return false;
        }
    }
    return true;

}
bool checkIfAllSlotNotReserved(){
    for(u16 i = 0; i < slotSize; i++){
        if(strcmp(SlotOptions[i], (char*)"Not Available") == 0){ //check if the slot is reserved
            return false;
        }
    }
    return true;

}
void CancelReservation(){
    u16 id;
    Patient* data = NULL;
    //check if the list is empty
    if(head == NULL) {
        printf("No Patients\n");
        return;
    }
    //check if all slots are not reserved
    if(checkIfAllSlotNotReserved()){
        printf("All slots are not reserved\n");
        return;
    }
    //get the patient ID
    id = scanID(head);
    if(checkForPatient(head, id)) {
        data = getPatient(head, id);

        if(data->slotReserved){
            setSlotAvailable(data->slotReserved);
            printf("Reservation canceled successfully\n");
            data->slotReserved = 0;
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
void setSlotAvailable(u16 slot){
    switch (slot) {
        case 1:
            SlotOptions[0] = (char*)"2:00 PM to 2:30 PM";
            break;
        case 2:
            SlotOptions[1] = (char*)"2:30 PM to 3:00 PM";
            break;
        case 3:
            SlotOptions[2] = (char*)"3:00 PM to 3:30 PM";
            break;
        case 4:
            SlotOptions[3] = (char*)"4:00 PM to 4:30 PM";
            break;
        case 5:
            SlotOptions[4] = (char*)"4:30 PM to 5:00 PM";
            break;
        default:
            break;

    }


}
