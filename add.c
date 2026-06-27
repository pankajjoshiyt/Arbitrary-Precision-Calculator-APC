#include "apc.h"

// Function to add two numbers stored in doubly linked lists
void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1 = tail1;   // Pointer to traverse first number from last digit
    node *temp2 = tail2;   // Pointer to traverse second number from last digit
    int carry = 0;         // Variable to store carry

    // Loop until both lists are completely traversed
    while (temp1 != NULL || temp2 != NULL)
    {
        int digit1 = 0;    // Store digit from first list
        int digit2 = 0;    // Store digit from second list

        // Get digit from first list if available
        if (temp1 != NULL)
        {
            digit1 = temp1->data;
            temp1 = temp1->prev;   // Move to previous node
        }

        // Get digit from second list if available
        if (temp2 != NULL)
        {
            digit2 = temp2->data;
            temp2 = temp2->prev;   // Move to previous node
        }

        // Calculate sum of digits and carry
        int sum = digit1 + digit2 + carry;

        // Insert result digit at the beginning of result list
        insert_first(headR, tailR, sum % 10);

        // Update carry
        carry = sum / 10;
    }

    // If carry remains after finishing addition
    if (carry == 1)
    {
        insert_first(headR, tailR, carry);  // Insert carry in result list
    }
}