#include "apc.h"

int main(int argc, char *argv[])
{

    printf("================================================\n");
    printf("PROJECT : Arbitrary Precision Calculator (APC)\n");
    printf("        Submitted By : Pankaj Joshi\n");
    printf("====================+===========================\n\n");

    node *head1 = NULL, *tail1 = NULL;
    node *head2 = NULL, *tail2 = NULL;
    node *headR = NULL, *tailR = NULL;

    if (cla_validation(argc, argv) == FAILURE)
        return 0;

    int sign1 = 1, sign2 = 1;

    if (argv[1][0] == '-')
        sign1 = -1;
    if (argv[3][0] == '-')
        sign2 = -1;

    create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    char oper = argv[2][0];
    int cmp = compare_list(head1, head2);

    switch (oper)
    {
    case '+':
    {
        if (sign1 == sign2)
        {
            addition(tail1, tail2, &headR, &tailR);

            printf("The Addition of %s and %s is :", argv[1], argv[3]);

            if (sign1 == -1)
                printf("-");

            print_list(headR);
        }
        else
        {
            if (cmp == OPERAND1)
            {
                subtraction(tail1, tail2, &headR, &tailR);

                printf("The Addition of %s and %s is :", argv[1], argv[3]);

                if (sign1 == -1)
                    printf("-");

                print_list(headR);
            }
            else if (cmp == OPERAND2)
            {
                subtraction(tail2, tail1, &headR, &tailR);

                printf("The Addition of %s and %s is :", argv[1], argv[3]);

                if (sign2 == -1)
                    printf("-");

                print_list(headR);
            }
            else
            {
                printf("The Addition of %s and %s is :0\n", argv[1], argv[3]);
            }
        }
    }
    break;

    case '-':
    {
        sign2 = -sign2;

        if (sign1 == sign2)
        {
            addition(tail1, tail2, &headR, &tailR);

            printf("The Subtraction of %s and %s is :", argv[1], argv[3]);

            if (sign1 == -1)
                printf("-");

            print_list(headR);
        }
        else
        {
            if (cmp == OPERAND1)
            {
                subtraction(tail1, tail2, &headR, &tailR);

                printf("The Subtraction of %s and %s is :", argv[1], argv[3]);

                if (sign1 == -1)
                    printf("-");

                print_list(headR);
            }
            else if (cmp == OPERAND2)
            {
                subtraction(tail2, tail1, &headR, &tailR);

                printf("The Subtraction of %s and %s is :", argv[1], argv[3]);

                if (sign2 == -1)
                    printf("-");

                print_list(headR);
            }
            else
            {
                printf("The Subtraction of %s and %s is :0\n", argv[1], argv[3]);
            }
        }
    }
    break;

    case 'x':
    case 'X':
    {
        multiplication(tail1, tail2, &headR, &tailR);
        remove_pre_zeros(&headR);

        printf("The Multiplication of %s and %s is :", argv[1], argv[3]);

        if (sign1 != sign2)
            printf("-");

        print_list(headR);
    }
    break;

    case '/':
    {
        division(head1, tail1, head2, tail2, &headR, &tailR);

        printf("The Division of %s and %s is :", argv[1], argv[3]);

        if (sign1 != sign2)
            printf("-");

        print_list(headR);
    }
    break;
    }

    return 0;
}