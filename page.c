#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
int main(int argc, char * argv[])
{
    unsigned int input_addr;
    int m, n;
    //int page_size;
    char *filename;
    
    /* Parse user inputs */
    char c ;
    while((c=getopt(argc, argv, "f:m:n:")) != -1){
        switch(c){
            case 'f':
             filename = optarg;
                break;
            case 'm':
                m = atoi(optarg);
                break;
            case 'n':
                n = atoi(optarg);
                //page_size = 1 << n;
                break;
        }
    }
    
    if(m==16){
        int mask_1_pages = (-1) - ((1<<(16+n))-1);
        int mask_1_offset = (1 << (16+n)) - (1<<16);
        int mask_2_pages = (1<<16) - (1<<n);
        int mask_2_offset = (1<<n) - 1;

        char word[20];
        FILE *fp = fopen(filename, "r");
        while(fgets(word, 20, fp)){
            char *tmp = strtok(word, "\n");

            //printf("%s\n", tmp);
            input_addr = strtol(tmp, NULL, 16);

            /* Bit-wise operation */
            printf("%d %d ", (mask_1_pages&input_addr)>>(16+n), (mask_1_offset&input_addr)>>16);
            printf("%d %d\n", (mask_2_pages&input_addr)>>n, (mask_2_offset&input_addr));

            /* 數學運算 */
            /* int mask_1 = (-1) - ((1<<16)-1);
             * int mask_2 = ~mask_1;
             * int laddr_1 = (mask_1&input_addr)>>16;
             * int laddr_2 = mask_2&input_addr;
             * printf("%d %d\n", laddr_1/page_size, laddr_1%page_size);
             * printf("%d %d\n", laddr_2/page_size, laddr_2%page_size);  */
         
         //printf("======\n");
        }
    }


    return 0;
}

