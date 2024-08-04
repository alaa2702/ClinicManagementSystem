/*
 * @auther: Alaa Mohammed
 * @brief: Handeling Inputs functions prototypes
 * @date: 28/07/2024
 */

#ifndef CLINICMANAGEMENTSYSTEM_HANDELINGINPUTS_H
#define CLINICMANAGEMENTSYSTEM_HANDELINGINPUTS_H
/* Includes */
#include "../stdTypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

/* Function prototypes */
u8* StringCheck(u16 size);
u16 IntCheck();
f32 FloatCheck();
s16 passwordScanner();


#endif //CLINICMANAGEMENTSYSTEM_HANDELINGINPUTS_H
