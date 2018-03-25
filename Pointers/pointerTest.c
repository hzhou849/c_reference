#include <stdio.h>

struct MCS_RECORD {
    int x;
    float y;
};

void Register_masker() {
    int number;
    int
}

int main () 
{


    struct MCS_RECORD mcs;
    struct MCS_RECORD *pmcs;

    //assign the pointer variable pmcs with addressof 'mcs'
    pmcs = &mcs;

    mcs.x = 5;
    (&mcs)->y = 14.3;
    printf ("mcs.x: %i    &mcs-y: %.02f\n", mcs.x, (&mcs)->y);
    
    //here using pointers to assing x y values instead of direct call.
    pmcs->x = 6;
    pmcs->y = 22.4;
    printf("pmcs->x: %x  pmcs->y: %02f\n", pmcs->x, pmcs->y);
     printf ("mcs.x: %i    &mcs-y: %.02f\n", mcs.x, (&mcs)->y);
    return 0;
}