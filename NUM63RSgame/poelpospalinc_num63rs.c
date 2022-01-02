#include "poelpospalinc_num63rs.h"
int gcd (int a, int b)
{
    int gcd = 1;
    int tmp;

    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a == 1 || b == 1)
        return 1;

    while (a != 0 && b != 0)
    {
        if (((a & 1) | (b & 1)) == 0)
        {
            gcd <<= 1;
            a >>= 1;
            b >>= 1;
            continue;
        }
        if (((a & 1) == 0) && (b & 1))
        {
            a >>= 1;
            continue;
        }
        if ((a & 1) && ((b & 1) == 0))
        {
            b >>= 1;
            continue;
        }
        if (a > b)
        {
           tmp = a;
           a = b;
           b = tmp;
        }
        tmp = a;
        a = (b - a) >> 1;
        b = tmp;
    }

    if (a == 0)
        return gcd * b;
    else
        return gcd * a;
}

int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

int numbers_game(int min, int max)
{
    int res = min;

    for (int i = min + 1; i <= max; i++)
        res = lcm(res, i);
        
    return res;
}
