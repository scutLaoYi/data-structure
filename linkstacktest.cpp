#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include "tools.h"
#include "test.h"

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

    printf("LinkStack testing passed!\n");
    return ;
}

