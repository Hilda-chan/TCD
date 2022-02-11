#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int priority(char str)
{
    if(str == '(')
        return 0;
    if (str == '+' || str == '-')
        return 1;
    if (str == '*' || str == '/' )
        return 2;
    return -1;

}

void emptyStack(struct Stack* stack,char* res, char* str)
{
    while(priority(peek(stack))>= priority(*str))
    {
        *res = pop(stack);
        res++;
    }
}

void pol(char* str, char* res)
{
   struct Stack* opStack = createStack(100);
   //char* res = (char*)malloc(sizeof(char)*200);
   char poop;


    while(*str != '\0')
    {
        //printf("str = %c\n",*str);
        // If *str is a close parenthesis we pop every operand in opStack until 
        // the top of the stack is an open parenthesis
        if(*str == ')')
        {
            while((poop = peek(opStack)) != ')')
            {
                *res = pop(opStack);
                res++;
            }
        }
        // If *str is an open parenthesis we push it in stack
        else if(*str == '(' )
            push(opStack,*str);
        // If *str is a number we put it in the output
        else if(*str >= '0' && *str <= '9')
        {
            *res = *str;
            printf("res = %c\nstr = %c\n",*res,*str);
            res++;
        }
        // If *str is an operand there are plenty of option
        else
        {
            // While the priority of *str is inferior of the top of the opStack
            // we pop the opStack and the pop in the res
            emptyStack(opStack,res,str);
            push(opStack,*str);

        }
        str++;
    }
    while(opStack->top != -1)
    {
        *res = pop(opStack);
        res++;
    }
    //return res;

}


int main()
{
    char *exp = "2*3+4*(5-6)";
    char *res = (char*)malloc(sizeof(char)*500);
    pol(exp,res);
    

    printf("\n\nexp = %s\n",exp);
    printf("res = ");
    while (*res != '\0')
    {
        printf("%c",*res);
        res++;
    }
    printf("\n");



    return 0;
}
