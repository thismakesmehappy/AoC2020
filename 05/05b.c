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
    struct ticket new_ticket, my_ticket;
    struct ticket all_tickets[883];
    int max_id, i, my_seat;
    int seats[3];

    max_id = -1;
    my_seat = 0;
    
    memset(all_tickets, '\0', sizeof(all_tickets));
    memset(seats, '\0', sizeof(seats));

    tickets = fopen("input.txt", "r");
    if(tickets == NULL)
    {
        perror("open");
        exit(1);
    }

    while(fgets(buffer, sizeof(buffer), tickets))
    {
        new_ticket = decipher_ticket(buffer);
        all_tickets[new_ticket.id] = new_ticket;
        //printf("%3d | %3d | %6d\n", new_ticket.row, new_ticket.column, new_ticket.id);
        if (new_ticket.id > max_id)
            max_id = new_ticket.id;
    }
    printf("Max: %i\n", max_id);
    printf("---\n");
    for(i = 0; i <= max_id; i ++)
    {
        if(all_tickets[i].row != 0)
        {
            printf("\x1B[32m");
        }
        printf("%3d %3d %3d | ", all_tickets[i].row, all_tickets[i].column, all_tickets[i].id);
        printf("\x1B[0m");
        if (i % 8 == 7)
            printf("\n");
        seats[0] = seats[1];
        seats[1] = seats[2];
        seats[2] = all_tickets[i].id;
        if((seats[0] != 0) && (seats[1] == 0) && (seats[2] != 0) && (seats[0] + 2 == seats[2]))
        {
            my_seat = seats[0] + 1;
        }
    }

    printf("\nmy seat: %i\n", my_seat);
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
