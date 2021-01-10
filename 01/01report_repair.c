#include <stdio.h>
#include <stdlib.h>
int
main (void)
{
    FILE *report;
    FILE *other_report;
    char buffer[16], other_buffer[16];
    int num1, num2;

    report = fopen("input.txt", "r");
    if(report == NULL)
    {
        perror("fopen");
        exit(1);
    }
    
    while(fgets(buffer, sizeof(buffer), report) != NULL)
    {
        other_report = fopen("input.txt", "r");
        if(other_report == NULL)
        {
            perror("fopen");
            exit(1);
        }
        
        num1 = atoi(buffer);
            while(fgets(other_buffer, sizeof(buffer), other_report) != NULL)
            {
              num2 = atoi(other_buffer);

              if (num1 + num2 == 2020)
              {
                printf("%d\n", num1 * num2);
              }
            
            }
        fclose(other_report);
    } 
    fclose(report);
    
}
