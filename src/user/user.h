/*
 * @author: Alaa Mohammed
 * @brief:
 * @date: 29/07/2024
 */

#ifndef CLINICMANAGEMENTSYSTEM_USER_H
#define CLINICMANAGEMENTSYSTEM_USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stdTypes.h"
#include "../PatientDataList/PatientDataList.h"
#include "../handelingInputs/HandelingInputs.h"
#include "../LinkedList/LinkedList.h"
#include "../Admin/Admin.h"

extern Node* head;
void UserMenu();
void ViewPatientRecord();
void ViewTodayReservations();
#endif //CLINICMANAGEMENTSYSTEM_USER_H
