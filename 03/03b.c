#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main ()
{
    int count, width, position_x, position_y, i;
    int across[] = {1, 3, 5, 7, 1};
    int down[] = {1, 1, 1, 1, 2};
    long multip;
    FILE *field;
    char buffer[256];


    multip = 1;

    for(i = 0; i < sizeof(across) / sizeof(int); i ++)
    {
        count = 0;
        position_x = 0;
        position_y = 0;
        width = 0;

        field = fopen("input.txt", "r");
        if(field == NULL)
        {
            perror("open");
            exit(1);
        }
        while(fgets(buffer, sizeof(buffer), field) != NULL)
        {
            if(width == 0)
            {
                width = strlen(buffer) - 1;
                //printf("%i\n", width);
            }

            if((position_y % down[i] == 0) && (buffer[position_x] == '#'))
            {
                count ++;
            }
            
            if (position_y % down[i] == 0)
            {
                position_x = (position_x + across[i]) % width;
            }
            position_y ++;
        }

        printf("Count: %i\t%i\t%i\t%i\n", count, i, across[i], down[i]);
        multip *= count;
    }

    printf("Total: %li\n", multip);


}
