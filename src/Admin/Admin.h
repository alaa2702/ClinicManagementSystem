/*
 * @author: Alaa Mohammed
 * @brief: standard types
 * @date: 27/07/2024
 * */
#ifndef CLINICMANAGEMENTSYSTEM_ADMIN_H
#define CLINICMANAGEMENTSYSTEM_ADMIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stdTypes.h"
#include "../PatientDataList/PatientDataList.h"

Node* head = NULL;
bool checkPasswordForAdmin(u8* password);
void AdminMenu();
void AddNewPatientRecord();
void EditPatientRecord ();
void ReserveASlotWithTheDoctor();
void CancelReservation();
Node* getHead();
#endif //CLINICMANAGEMENTSYSTEM_ADMIN_H
