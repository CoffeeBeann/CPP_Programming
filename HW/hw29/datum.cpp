
#include "point.h"

// Function Overload Definitions
istream& operator >> (istream& is, datum& D)
{
    char c;
    return is >> c >> D.time >> c >> D.position >> c; 
}