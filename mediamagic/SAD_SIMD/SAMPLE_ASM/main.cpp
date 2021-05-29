#include "iostream"
//#include "conio.h"
#include "time.h"

using namespace std;

extern "C" int sad_asm(char*, char*, int);

#define SIZE 16

int sad_c(char* src1, char* src2, int size)
{
    int ans = 0;

    for (int i = 0; i < size; i++)
        ans += (abs(src1[i] - src2[i]));

    return ans;
}

int main()
{
    char src1[SIZE];
    char src2[SIZE];

    srand((int)time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        src1[i] = rand() % 128;
        src2[i] = rand() % 128;
    }

    int ans_c = sad_c(src1, src2, SIZE);

    int ans_asm = sad_asm(src1, src2, SIZE);

    // check if SIMD asm output matches with C function or not
    if (ans_c != ans_asm)
        printf("\nError: C and ASM output mismatch!\nsad_c = %d, sad_asm = %d\n", ans_c, ans_asm);
    else
        printf("\nSuccess !!\nsad_c = %d, sad_asm = %d\n", ans_c, ans_asm);

//    _getch();
    return 0;
}
