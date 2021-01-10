#include <stdio.h>
#include <stdlib.h>
int
main (void)
{
    FILE *report1;
    FILE *report2;
    FILE *report3;
    char buffer1[16], buffer2[16], buffer3[16];
    int num1, num2, num3;

    report1 = fopen("input.txt", "r");
    if(report1 == NULL)
    {
        perror("fopen");
        exit(1);
    }
    
    while(fgets(buffer1, sizeof(buffer1), report1) != NULL)
    {
        num1 = atoi(buffer1);
        
        report2 = fopen("input.txt", "r");
        if(report2 == NULL)
        {
            perror("fopen");
            exit(1);
        }
        
            while(fgets(buffer2, sizeof(buffer2), report2) != NULL)
            {
                num2 = atoi(buffer2);
                
                report3 = fopen("input.txt", "r");
                if(report3 == NULL)
                {
                    perror("fopen");
                    exit(1);
                }

                while(fgets(buffer3, sizeof(buffer3), report3) != NULL)
                {
                    num3 = atoi(buffer3);
                 
                    if (num1 + num2 + num3 == 2020)
                    {
                        printf("%d\n", num1 * num2 * num3);
                    }
                }
                fclose(report3); 
            }
        fclose(report2);
    } 
    fclose(report1);
    
}
