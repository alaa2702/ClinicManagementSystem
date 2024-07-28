/*
 * @author: Alaa Mohammed
 * @brief: standard types
 * @date: 27/07/2024
 * */

#include "Admin.h"

void ReserveASlotWithTheDoctor(Node* head){
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
    temp = search(head, data);
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
