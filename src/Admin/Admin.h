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

bool checkPasswordForAdmin();
void AdminMenu();
void AddNewPatientRecord();
void EditPatientRecord ();
void ReserveASlotWithTheDoctor();
bool checkIfAllSlotReserved();
bool checkIfAllSlotNotReserved();
void CancelReservation();
void setSlotAvailable(u16 slot);

#endif //CLINICMANAGEMENTSYSTEM_ADMIN_H
