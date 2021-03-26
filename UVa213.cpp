#include <iostream>
#include <string>

using namespace std;

int readnum(int len)
{
    char c;
    int v = 0;
    int w = 1 << (len - 1);

    while (len--)
    {
        while (c = getchar(), c == '\n')
            ;

        v += w * (c - '0');
        w /= 2;
    }

    return v;
}

int main()
{
    const int index[] = {0, 1, 4, 11, 26, 57, 120};
    const int end[] = {1, 3, 7, 15, 31, 63, 127};

    string header;
    int len;
    int v;

    while (getline(cin, header))
    {
        while (len = readnum(3), len)
        {
            while (v = readnum(len), v != end[len - 1])
            {
                putchar(header[index[len - 1] + v]);
            }
        }
        getchar();//need to modify
        putchar('\n');
    }

    return 0;
}
