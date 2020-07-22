#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){

        if(argc != 3){
                printf("Usage : %s <filename1> <filename2>\n", argv[0]);
                return 0;
        }
        FILE *fp1, *fp2;
        uint32_t n1, n2;

        fp1 = fopen(argv[1], "rb");
        fp2 = fopen(argv[2], "rb");

        fread(&n1, 1, 4, fp1);
        fread(&n2, 1, 4, fp2);
        n1 = ntohl(n1);
        n2 = ntohl(n2);

        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1+n2, n1+n2);


        fclose(fp2);
        fclose(fp1);

        return 0;
}
