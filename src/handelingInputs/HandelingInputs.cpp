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
    scanf_s("%s%c", str, size, &c);

    return str;

}
u16 IntCheck() {
    u16 n;
    u8 c;
    int test = scanf_s("%d%c", &n, &c);
    while (!test || n < 0 || c !=   '\n') {
        printf("\ninvalid input\nEnter again\n");
        scanf_s("%*[^\n]");//clear input buffer
        test = scanf_s("%d%c", &n, &c);
    }
    return n;
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