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
typedef enum{
    Female = 0,
    Male = 1
}Gender;
typedef struct Patient{
    u8* name;
    u16 age;
    u16 id;
    Gender gender;
    u8* slot;
    u16 slotReserved;
} Patient;
 /* Function prototypes */
void insertPatient(struct Node** head);
u16 scanID(struct Node* head);
void deletePatient(struct Node** head, Patient data);
void printPatient(struct Patient* data);
bool checkForPatient(struct Node* head, u16 id);
Patient* getPatient(struct Node* head, u16 id);
void updatePatient(struct Node* head, Patient* data);
bool validateID(Node* head, u16 id);
bool repeatedID(Node *head, u16 id) ;
Gender GenderScan();
void printSlotWithID(Patient* patient);
#endif //CLINICMANAGEMENTSYSTEM_PATIENTDATALIST_H
