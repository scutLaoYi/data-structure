#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

struct Node
{
    int pre;
    int nex;
};
Node node[100];
int n;

void init()
{
    //init the 0 to n-1 node
    for(int i = 0; i < n; ++i)
    {
        node[i].pre = i+n;
        node[i].nex = -1;
    }
    //init the base
    //set them as the bottom of pile
    //and point to the initial node
    for(int i = n; i < 2*n; ++i)
    {
        node[i].nex = i-n;
        node[i].pre = -1;
    }
    return;
}

//find the top node of a block
int top(int ind)
{
    while(node[ind].nex != -1)
        ind = node[ind].nex;
    return ind;
}

//connect two node
void connect(int down, int up)
{
    node[down].nex = up;
    if(up != -1)
        node[up].pre = down;
    return;
}

//return the blocks above block with index:ind
void returnAbove(int ind)
{
    int curNex = node[ind].nex;
    int ptr = curNex;

    //make the initial one be the end of stack
    node[ind].nex = -1;

    while(ptr != -1)
    {
        //record the nex block to process
        curNex = node[ptr].nex;

        //make the current one into its initial position
        connect(ptr, node[n+ptr].nex);
        connect(ptr+n, ptr);

        //get the next one to process
        ptr = curNex;
    }
    return;
}

void output()
{
    for(int i = n; i < 2*n; ++i)
    {
        printf("%d:", i-n);
        int ind = node[i].nex;
        while(ind != -1)
        {
            printf(" %d", ind);
            ind = node[ind].nex;
        }
        printf("\n");
    }
    return;
}



int main(int argc, char *argv[])
{
#ifdef DEBUG
    printf("debuging!\n");
#endif
    scanf("%d", &n);
    init();

    char commandBuf[10];
    char posBuf[10];
    int ind1, ind2;
    while(true)
    {
        scanf("%s", commandBuf);
        if(commandBuf[0] == 'q')
            break;
        scanf("%d %s %d", &ind1, posBuf, &ind2);
#ifdef DEBUG
        printf("command:%s %d %s %d\n", commandBuf, ind1, posBuf, ind2);
#endif
        int top1 = top(ind1);
        int top2 = top(ind2);
        if(top1 == top2)
            continue;
        if(commandBuf[0] == 'm')
        {
            connect(node[ind1].pre, -1);
            if(posBuf[1] == 'n')
            {
                returnAbove(ind1);
                returnAbove(ind2);

                connect(ind2, ind1);
            }
            else
            {
                returnAbove(ind1);
                connect(top2, ind1);
            }
        }
        else
        {
            connect(node[ind1].pre, -1);
            if(posBuf[1] == 'n')
            {
                returnAbove(ind2);
                connect(ind2, ind1);
            }
            else
            {
                connect(top2, ind1);
            }
        }
#ifdef DEBUG
        output();
#endif
    }
    output();

    return 0;
}
