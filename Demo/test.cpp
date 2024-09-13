
#include "test.h" 

istream& operator >> (istream& is, point& p)
{
  char c;
  return is >> c >> p.x >> c >> p.y >> c;
} 

ostream& operator << (ostream& os, point p)
{
  return os << '(' << p.x << ',' << p.y << ')';
}

point operator + (point a, point b)
{
  point S = {a.x + b.x, a.y + b.y};
  return S;
}

point operator / (point P, double z)
{
  point Q = {P.x / z, P.y / z};
  return Q;
}