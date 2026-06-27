#include "apc.h"

void division(node *head1, node *tail1,node *head2, node *tail2,node **headR, node **tailR)
{
    node *head_OPR1 = NULL;
    node *tail_OPR1 = NULL;

    node *temp = head1;

    /* Division by zero */
    if (head2 == NULL || (head2->data == 0 && head2->next == NULL))
    {
        printf("Error: Division by zero\n");
        return;
    }

    /* If dividend < divisor */
    if (compare_list(head1, head2) == OPERAND2)
    {
        insert_first(headR, tailR, 0);
        return;
    }

    while (temp != NULL)
    {
        /* Bring down next digit */
        insert_last(&head_OPR1, &tail_OPR1, temp->data);
        temp = temp->next;

        remove_pre_zeros(&head_OPR1);

        int count = 0;

        /* Subtract until smaller */
        while (compare_list(head_OPR1, head2) != OPERAND2)
        {
            node *head_SR = NULL;
            node *tail_SR = NULL;

            subtraction(tail_OPR1, tail2, &head_SR, &tail_SR);

            delete_list(&head_OPR1, &tail_OPR1);

            head_OPR1 = head_SR;
            tail_OPR1 = tail_SR;

            count++;
        }

        insert_last(headR, tailR, count);
    }

    remove_pre_zeros(headR);

    if (*headR == NULL)
        insert_first(headR, tailR, 0);

    delete_list(&head_OPR1, &tail_OPR1);
}