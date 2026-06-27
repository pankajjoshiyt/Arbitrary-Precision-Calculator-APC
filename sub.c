#include "apc.h"

// Function to subtract two numbers stored in linked lists
void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow_flag = 0;           // Flag to indicate borrow
    node *temp1 = tail1;           // Pointer for first number (larger number)
    node *temp2 = tail2;           // Pointer for second number

    // Traverse first number from last digit
    while (temp1 != NULL)
    {
        int digit1 = temp1->data;  // Current digit of first number
        int digit2 = 0;            // Current digit of second number

        temp1 = temp1->prev;       // Move to previous digit

        // If second number still has digits
        if (temp2 != NULL)
        {
            digit2 = temp2->data;
            temp2 = temp2->prev;   // Move to previous digit
        }

        // Apply borrow from previous step
        if (borrow_flag)
        {
            digit1 -= 1;
            borrow_flag = 0;
        }

        // If digit1 is smaller than digit2, borrow from next digit
        if (digit1 < digit2)
        {
            digit1 += 10;
            borrow_flag = 1;
        }

        int sub = digit1 - digit2;   // Perform subtraction

        // Insert result digit at beginning of result list
        insert_first(headR, tailR, sub);
    }

    // Remove leading zeros from result
    remove_pre_zeros(headR);

    // If result becomes empty, store 0
    if (*headR == NULL)
        insert_first(headR, tailR, 0);
}