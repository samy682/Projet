#include"random.h"
#include <cmath>


double random::randomNumDouble(double borneinf, double bornesup)
{
    return (double)rand()/RAND_MAX*(abs(borneinf)+abs(bornesup))-abs(borneinf);
}


int random::randomInt(int bornInf,int bornSup)
{
    return rand()%((bornSup - bornInf) + 1) + bornInf;
}
