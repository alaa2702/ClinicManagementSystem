/*
 * @author: Alaa Mohammed
 * @brief: standard types
 * @date: 27/07/2024
 * */
#ifndef CLINICMANAGEMENTSYSTEM_PATIENTDATALIST_H
#define CLINICMANAGEMENTSYSTEM_PATIENTDATALIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stdTypes.h"

 typedef struct PatientData {
    u8 name[100];
    u16 age;
    u16 id;
    u8 gender[10];
}Patient;

#endif //CLINICMANAGEMENTSYSTEM_PATIENTDATALIST_H
