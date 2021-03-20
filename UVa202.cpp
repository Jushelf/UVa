#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    int integerPart;
    int repeatingCycle;
    int r;
    int start;
    vector<int> decimalPart(30000);
    vector<int> remainder(30000);

    while (scanf("%d%d", &a, &b) == 2)
    {
        integerPart = a / b;
        r = a - b * integerPart;

        bool flag = false;

        for (int i = 0; !flag; ++i)
        {
            r *= 10;
            decimalPart[i] = r / b;
            remainder[i] = r - b * decimalPart[i];

            for (int j = 0; j < i; ++j)
            {
                if ((decimalPart[j] == decimalPart[i]) && (remainder[j] == remainder[i]))
                {
                    start = j;
                    repeatingCycle = i - j;
                    flag = true;
                    break;
                }
            }

            r = remainder[i];
        }

        printf("%d/%d = %d.", a, b, integerPart);

        for (int i = 0; i < start; ++i)
        {
            printf("%d", decimalPart[i]);
        }
        printf("(");

        for (int i = 0; i < 50 && i < repeatingCycle; ++i)
        {
            printf("%d", decimalPart[start + i]);
        }

        if (repeatingCycle > 50)
        {
            printf("...");
        }

        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", repeatingCycle);
    }

    return 0;
}
