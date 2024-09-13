
#include "point.h"

istream& operator >> (istream& is, hhmmss& T)
{
    char c;
    return is >> c >> T.h >> c >> T.m >> c >> T.s >> c;
}

bool operator<(hhmmss a, hhmmss b)
{
    int at = a.h*3600 + a.m*60 + a.s;
    int bt = b.h*3600 + b.m*60 + b.s;
    return at < bt; 
}
