#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct ticket
{
    int row;
    int column;
    int id;
};

struct ticket 
decipher_ticket(char* ticket_binary);

int
main()
{
    char buffer[512];
    FILE *tickets;
    struct ticket new_ticket;
    int max_id;

    max_id = -1;


    tickets = fopen("input.txt", "r");
    if(tickets == NULL)
    {
        perror("open");
        exit(1);
    }

    while(fgets(buffer, sizeof(buffer), tickets))
    {
        new_ticket = decipher_ticket(buffer);
        printf("%3d | %3d | %6d\n", new_ticket.row, new_ticket.column, new_ticket.id);
        if (new_ticket.id > max_id)
            max_id = new_ticket.id;
    }
    printf("Max: %i\n", max_id);

}

struct ticket
decipher_ticket(char* ticket_binary)
{
    struct ticket new_ticket;
    int low, high, mid, left, right, mid_row, i;
    low = 0;
    high = 127;
    left = 0;
    right = 7;

    for(i = 0; i < 7; i ++)
    {
        //mid = (high + low) / 2;
        if (ticket_binary[i] == 'F')
        {
            high = (high + low) / 2;
            mid = high;
        }
        else
        {
            low = (int) ceil(((float)low + (float) high) / 2);
            mid = low;
        }
    }
    new_ticket.row = mid;


    for(; i < 10; i ++)
    {
        if (ticket_binary[i] == 'L')
        {
            right = (left + right) / 2;
            mid_row = right;
        }
        else
        {
            left = (int) ceil(((float)left + (float) right) / 2);
            mid_row = left;
        }
    }
    new_ticket.column = mid_row;

    new_ticket.id = new_ticket.row * 8 + new_ticket.column;

   return new_ticket;
}
