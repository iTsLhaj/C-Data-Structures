#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int stack[512];
int sp;

void _init(void){
    memset(&stack, 0, sizeof(stack));
    sp = 0;
}

void _push(int value)
{
    stack[sp] = value;
    sp += 1;
}

int _pop()
{
    sp -= 1;
    return stack[sp];
}

int main( int argc, char** argv )
{

    _init();

    _push(42);
    _push(48);
    _push(41);
    _push(96);

    printf("%i\n", _pop());
    printf("%i\n", _pop());

    return 0;
}