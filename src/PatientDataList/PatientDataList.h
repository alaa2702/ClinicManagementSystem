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
#include "../handelingInputs/HandlingInputs.h"
#include "../LinkedList/LinkedList.h"

/* Patient structure */
 typedef struct PatientData {
    u8 name[100];
    u16 age;
    u16 id;
    u8 gender[10];
    u8 slot[20];
}Patient;
 /* Function prototypes */
void insertPatient(Node** head);
void deletePatient(Node** head, Patient data);
void printPatient(Patient* data);
Patient* searchPatient(Node* head, Patient data);
void updatePatient(Node* head, Patient data);


#endif //CLINICMANAGEMENTSYSTEM_PATIENTDATALIST_H
