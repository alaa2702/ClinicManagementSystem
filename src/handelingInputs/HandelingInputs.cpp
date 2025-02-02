/*
 * @Author: Alaa Mohammed
 * @brief: Handeling Inputs functions implementation
 * @Date: 28/07/2024
 */
#include "HandelingInputs.h"

u8* StringCheck(u16 size) {
    u8* str = (u8*)malloc(size * sizeof(u8));
    u8 c;
    fflush(stdin);//clear input buffer (stdin)
    for (int i = 0; i < size; ++i) {
        c = getchar();
        if (c == '\n') {
            str[i] = '\0';
            break;
        }
        str[i] = c;
    }
    return str;

}

u16 IntCheck() {
    s16 n;
    u8 c;
    int test = scanf_s("%d%c", &n, &c);
    while (!test || n < 0 || c !=   '\n') {
        printf("invalid input\nPlease enter a positive number ");
        if(!test)
            scanf_s("%*[^\n]");//clear input buffer
        test = scanf_s("%d%c", &n, &c);
    }
    return (u16) n;
}

f32 FloatCheck(){
    f32 n;
    u8 c;
    int test = scanf_s("%f%c", &n, &c);
    while (!test || n < 0 || c != '\n') {
        printf("\ninvalid input\nEnter again\n");
        scanf_s("%*[^\n]");//clear input buffer
        test = scanf_s("%f%c", &n, &c);
    }
    return n;
}
 s16 passwordScanner() {
     u8 password[100];
     u16 i = 0;
     s16 Num = 0;
     u8 ch;

     printf("Enter password: ");
     while ((ch = _getch()) != '\r') { // '\r' is the Enter key
         if (i < sizeof(password) - 1) {
             password[i++] = ch;
             printf("*"); // Print asterisk instead of the character
         }
          // Null-terminate the string
     }
     printf("\n");
     password[i] = '\0'; // Null-terminate the string

     //check if the returned value is a number
     for (i = 0; password[i] != '\0'; i++) {
         if (!isdigit(password[i])) {
             return -1;
         }
     }
     i = 0;
     //converting the password to integer manually
     while (password[i] != '\0') {
         Num = Num * 10 + (password[i] - '0');
         i++;
     }
     return Num;

 }