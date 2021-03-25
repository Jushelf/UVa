#include <cstdio>
#include <cmath>

int main()
{
    const double epsilon = 1E-5;
    double A[15][40];
    int B[15][40];
    double Ain;
    int Bin;

    for (int M = 0; M < 10; ++M)
    {
        for (int E = 1; E < 31; ++E)
        {
            double temp = log10(1 - pow(2, -1 - M)) + ((1 << E) - 1) * log10(2);
            B[M][E] = int(temp);
            A[M][E] = pow(10, temp - B[M][E]);
        }
    }

    while (scanf("%17lfe%d", &Ain, &Bin), Ain)
    {
        while (Ain < 1)
        {
            Ain *= 10;
            Bin--;
        }

        bool find = false;

        for (int M = 0; M < 10 && !find; ++M)
        {
            for (int E = 1; E < 31; ++E)
            {
                if (Bin == B[M][E] && fabs(Ain - A[M][E]) < epsilon)
                {
                    printf("%d %d\n", M, E);
                    find = true;
                    break;
                }
            }
        }
    }

    return 0;
}
