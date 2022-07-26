#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

int add_num(FILE* f1, FILE* f2)
{
    uint32_t num1 = 0;
    uint32_t num2 = 0;

    fread(&num1, sizeof(uint32_t), 1, f1);
    fread(&num2, sizeof(uint32_t), 1, f2);

    int bnum1 = htonl(num1);
    int bnum2 = htonl(num2);
    //출력 형식 : 1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)
    int add_res = bnum1 + bnum2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", bnum1, bnum1, bnum2, bnum2, add_res, add_res);

    return add_res;
}

int main(int argc, char* argv[])
{

    if(argc < 2){
        printf("[!]required at least 2 arguments\n");
        exit(1);
    }
    
    FILE* fp = fopen(argv[1], "rb");
    FILE* fp2 = fopen(argv[2], "rb");

    add_num(fp, fp2);

    fclose(fp2);
    fclose(fp);
   return 0;
}
