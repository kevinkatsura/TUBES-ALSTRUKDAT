#include "peta.h"

void MakePETA (MATRIKS *M, int P, int L)
{
    int i,j;
    MakeMATRIKS(L,P,M);
    for (i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++)
    {
        for (j=GetFirstIdxBrs(*M); j<=GetLastIdxBrs(*M); j++)
        {
            if (i==GetFirstIdxBrs(*M)||i==GetLastIdxBrs(*M)||j==GetFirstIdxKol(*M)||j==GetLastIdxKol(*M))
            {
                Elmt(*M,i,j) = '*';
            }
            else
            {
                Elmt(*M,i,j) = '-';
            }
            
        }
    }
}

void TulisPETA (MATRIKS M)
{
    TulisMATRIKS(M);
}