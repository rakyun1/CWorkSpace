#ifndef KARPRABIN_H
#define KARPRABIN_H

#include <math.h>

int KarpRabin(char* Text, int TextSize, int Start, char* Pattern, int PatternSize);

int Hash(char* String, int Size);
int ReHash(char* String, int Start, int Size, int HashPrev, int Coefficient);


#endif