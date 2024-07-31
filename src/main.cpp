/*
 * @author: Alaa Mohammed
 * @brief: standard types
 * @date: 27/07/2024
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdTypes.h"
#include "PatientDataList/PatientDataList.h"
#include "HandelingInputs/HandelingInputs.h"
#include "User/User.h"
#include "Admin/Admin.h"

int main() {
    // declare the choice variable
    u8 choice;
    //create a loop to keep the program running
    while (1) {
        // print the main menu
        printf("Welcome to the Clinic Management System\n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        // get the choice from the user
        choice = IntCheck();
        // check the choice
        switch (choice) {
            case 1:
                //check the password for the admin
                if(checkPasswordForAdmin()){
                    // print the admin menu
                    AdminMenu();
                }else{
                    printf("You have entered the wrong password 3 times\n");
                    // exit the program
                    exit(0);
                }
                break;
            case 2:
                // call the user menu
                UserMenu();
                break;
            case 3:
                // exit the program
                exit(0);
            default:
                // print an error message
                printf("Invalid choice\n");
        }
    }

return 0;
}