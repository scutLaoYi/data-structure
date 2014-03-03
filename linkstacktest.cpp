#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include "tools.h"
#include "test.h"

#define BUF_SIZE 100

void balanceparentheses();
void nextgreaterelement();

void functions()
{
    balanceparentheses();
    nextgreaterelement();
}

void linkstacktest()
{
    const int STACK_SIZE = 20;

    printf("LinkStack testing...\n");
    printf("Pushing...\n");
    LinkStack<int> *stack = new LinkStack<int>();
    assert(stack->isempty());

    int bufint;
    int testarray[STACK_SIZE];
    for(int i = 0; i < STACK_SIZE; ++i)
    {
        bufint = get_random_int();
        stack->push(bufint);
        testarray[i] = bufint;
        printf("%d\t", bufint);
    }
    printf("\n");
    assert(!stack->isempty());

    printf("Poping...\n");
    for(int i = STACK_SIZE-1; i != -1; --i)
    {
        assert(stack->peek(bufint));
        printf("%d\t", bufint);
        assert(bufint == testarray[i]);
        assert(stack->pop());
    }
    assert(stack->isempty());
    printf("\n");

    delete stack;

    printf("Testing stack functions...\n");
    functions();
    printf("LinkStack testing passed!\n");
    return ;
}

bool mapchar(char left, char right)
{
    switch(left)
    {
        case '(':return right==')';
        case '[':return right==']';
        case '{':return right=='}';
        default: assert(false);
    }
    return false;
}

void balanceparentheses()
{
    char buf[BUF_SIZE];
    printf("input some expressions to check balance parentheses:\n");
    printf("one line for each expressions and ends with a single 'e'.\n");
    while(true)
    {
        scanf("%s", buf);
        if(buf[0] == 'e')
            break;

        LinkStack<char> *stack = 
            new LinkStack<char>();

        bool check(true);
        for(int i = 0; i < strlen(buf); ++i)
        {
            if(buf[i] == '{' ||
                    buf[i] == '[' ||
                    buf[i] == '(')
                stack->push(buf[i]);
            else
            {
                char current;
                check = stack->peek(current);
                if(!check)
                    break;
                else
                    stack->pop();
                if(!mapchar(current, buf[i]))
                {
                    check = false;
                    break;
                }
            }
        }
        if(!stack->isempty())
            check = false;

        printf("The expression '%s' ", buf);
        if(check)
            printf("is balance!\n");
        else
            printf("isn't balance!\n");
        delete stack;
    }
    return ;
}

void nextgreaterelement()
{
    printf("Input the positive int array with elements to list the next greater elements.\n");
    printf("End with a '-1'.\n");

    int buf[100];
    int size(0);

    while(true)
    {
        scanf("%d", &buf[size]);
        if(buf[size] == -1)
            break;
        ++size;
    }

    printf("Data:");
    for(int i = 0; i < size; ++i)
        printf("%d ", buf[i]);
    printf("\n");

    LinkStack<int> *stack = new LinkStack<int>();
    int ptr(1);
    stack->push(buf[0]);

    int curelement;
    while(ptr < size)
    {
        while(stack->peek(curelement))
        {
            if(curelement >= buf[ptr])
                break;
            stack->pop();
            printf("%d -> %d\n", curelement, buf[ptr]);
        }
        stack->push(buf[ptr]);
        ++ptr;
    }

    delete stack;
    return;
}



