/*
 * @author: Alaa Mohammed
 * @brief: Patient Data List functions prototypes
 * @date: 27/07/2024
 * */
#ifndef CLINICMANAGEMENTSYSTEM_PATIENTDATALIST_H
#define CLINICMANAGEMENTSYSTEM_PATIENTDATALIST_H
/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stdTypes.h"
#include "../handelingInputs/HandelingInputs.h"
#include "../LinkedList/LinkedList.h"

/* Patient structure */
typedef struct Patient{
    u8* name;
    u16 age;
    u16 id;
    u8* gender;
    u8* slot;
    bool slotReserved;
} Patient;
 /* Function prototypes */
void insertPatient(struct Node** head);
void deletePatient(struct Node** head, Patient data);
void printPatient(struct Patient* data);
Patient* searchPatient(struct Node* head, Patient* data);
void updatePatient(struct Node* head, Patient* data);


#endif //CLINICMANAGEMENTSYSTEM_PATIENTDATALIST_H
