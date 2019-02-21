#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
int main(int argc, char * argv[])
{
    unsigned int input_addr;
    int m, n, number_of_pages, page_size;
    
    /* Parse user inputs */
    char c ;
    while((c=getopt(argc, argv, "i:m:n:")) != -1){
        switch(c){
            case 'i':
             input_addr = (unsigned int)strtol(optarg, NULL, 16);;
                break;
            case 'm':
                m = atoi(optarg);
                break;
            case 'n':
                n = atoi(optarg);
                number_of_pages = 1 << n;
                page_size = 1 << (m-n);
                break;
        }
    }

    char *real_addr = (char *) malloc( 32 * sizeof(char));
    for(int i = 0;i<26;i++){
        real_addr[i] = (char)(i+65);
    }
    real_addr[27]=',';
    real_addr[28]='!';
    real_addr[29]='@';
    real_addr[30]='#';
    real_addr[31]='$';
    

    int *page_table = (int *) malloc( page_size * sizeof(int));
    for(int i=0;i<number_of_pages;i++){
        page_table[i] = i;
    }
    printf("%d\n", input_addr);
    int mask_1 = (-1) - ((1<<16)-1);
    int mask_2 = ~mask_1;
    printf("%x %x\n", mask_1, mask_2);

    int laddr_1 = (input_addr&mask_1)>>16;
    int laddr_2 = input_addr&mask_2;
    printf("%d %d\n", laddr_1, laddr_2);


    return 0;
}
