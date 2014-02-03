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
        if(scanf("%s %d %s %d", commandBuf, &ind1, posBuf, &ind2) < 4)
            break;
#ifdef DEBUG
        printf("command:%s %d %s %d\n", commandBuf, ind1, posBuf, ind2);
#endif
        if(commandBuf[0] == 'm')
        {
            connect(node[ind1].pre, node[ind1].nex);
            if(posBuf[1] == 'n')
            {
                connect(ind1, node[ind2].nex);
                connect(ind2, ind1);
            }
            else
            {
                connect(ind1, -1);
                connect(top(ind2), ind1);
            }
        }
        else
        {
            connect(node[ind1].pre, -1);
            if(posBuf[1] == 'n')
            {
                connect(top(ind1), node[ind2].nex);
                connect(ind2, ind1);
            }
            else
            {
                connect(top(ind2), ind1);
            }
        }
    }

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

    return 0;
}
