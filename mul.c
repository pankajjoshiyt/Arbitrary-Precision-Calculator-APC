#include "apc.h"

// Function to perform multiplication of two numbers stored in linked lists
void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1 = tail1;   // Pointer for first number (moves from last digit)
    node *temp2 = tail2;   // Pointer for second number
    int carry = 0, count = 0;   // carry for multiplication, count for position shift

    node *headR2 = NULL, *tailR2 = NULL;  // Temporary result list for each row
    node *headAR = NULL, *tailAR = NULL;  // List to store addition result

    // Traverse second number (like manual multiplication)
    while(temp2 != NULL)
    {
        // Insert zeros for place value (shift left)
        for(int i = 0; i < count; i++)
        {
            insert_first(&headR2, &tailR2, 0);
        }

        // Multiply each digit of first number with current digit of second number
        while(temp1 != NULL)
        {
            int mul = temp1->data * temp2->data + carry;

            // For first row directly store in result list
            if(count == 0)
            {
                insert_first(headR, tailR, mul % 10);
            }
            else
            {
                insert_first(&headR2, &tailR2, mul % 10);
            }

            carry = mul / 10;  // Update carry
            temp1 = temp1->prev;

            // If end of first number reached
            if(temp1 == NULL)
            {
                if(count == 0)
                {
                    insert_first(headR, tailR, carry);
                }
                else
                {
                    insert_first(&headR2, &tailR2, carry);
                }
                carry = 0;
            }
        }

        // Add temporary result with main result
        if(headR2 != NULL)
        {
            addition(*tailR, tailR2, &headAR, &tailAR);

            // Delete old result
            delete_list(headR, tailR);

            // Update result with addition output
            *headR = headAR;
            *tailR = tailAR;

            headAR = NULL;
            tailAR = NULL;
        }

        // Delete temporary list
        delete_list(&headR2, &tailR2);

        // Reset pointers for next iteration
        temp1 = tail1;
        temp2 = temp2->prev;

        count++;   // Increase shift position
    }
}