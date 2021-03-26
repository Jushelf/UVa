#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int N, k, m;
    int left;
    int A, B;
    int numA, numB;
    const int mod = 20;
    int a[mod];

    while (scanf("%d%d%d", &N, &k, &m), N || m || k)
    {
        for (int i = 0; i < N; ++i)
        {
            a[i] = 1;
        }
        left = N;
        A = -1;
        B = N;

        while (left)
        {
            numA = 0;
            numB = 0;
            while (numA != k)
            {
                A = (A + 1) % N;
                numA += a[A];
            }

            while (numB != m)
            {
                B = (B - 1 + N) % N;
                numB += a[B];
            }

            a[A] = 0;
            a[B] = 0;

            if (A == B)
            {
                printf("%3d", A + 1);
                left--;
            }
            else
            {
                printf("%3d%3d", A + 1, B + 1);
                left -= 2;
            }

            if (left)
            {
                printf(",");
            }
            else
            {
                printf("\n");
            }
        }
    }

    return 0;
}
