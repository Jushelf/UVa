//why WA??? pass udebug
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct opration
{
    char command[5];
    int A;
    int num[15];
    int r1, c1, r2, c2;

    void initialize()
    {
        scanf("%s", command);

        if (strcmp(command, "EX") == 0)
        {
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        }
        else
        {
            scanf("%d", &A);

            for (int i = 0; i < A; ++i)
            {
                scanf("%d", &num[i]);
            }
        }
    }

    int execute(int &r, int &c)
    {
        int less = 0;

        if (strcmp(command, "EX") == 0)
        {
            if (r1 == r && c1 == c)
            {
                r = r2;
                c = c2;
            }
            else if (r2 == r && c2 == c)
            {
                r = r1;
                c = c1;
            }
        }
        else
        {
            if (strcmp(command, "DR") == 0)
            {
                for (int i = 0; i < A; ++i)
                {
                    if (num[i] < r)
                    {
                        less++;
                    }
                    else if (num[i] == r)
                    {
                        return -1;
                    }
                }

                r -= less;
            }
            else if (strcmp(command, "DC") == 0)
            {
                for (int i = 0; i < A; ++i)
                {
                    if (num[i] < c)
                    {
                        less++;
                    }
                    else if (num[i] == c)
                    {
                        return -1;
                    }
                }

                c -= less;
            }
            else if (strcmp(command, "IC") == 0)
            {
                for (int i = 0; i < A; ++i)
                {
                    if (num[i] <= c)
                    {
                        less++;
                    }
                }

                c += less;
            }
            else if (strcmp(command, "IR") == 0)
            {
                for (int i = 0; i < A; ++i)
                {
                    if (num[i] <= r)
                    {
                        less++;
                    }
                }

                r += less;
            }
        }
        return 0;
    }
};

int main()
{
    int r, c;
    int m;//m operations
    int n;//n queries
    int Spreadsheet = 1;
    int qr, qc;//query row, query column
    vector<opration> operaVec;
    int deleted;

    while (scanf("%d%d", &r, &c), r)
    {
        scanf("%d", &m);
        operaVec = vector<opration>(m);

        for (int i = 0; i < m; ++i)
        {
            operaVec[i].initialize();
        }

        if (Spreadsheet > 1)
        {
            printf("\n");
        }

        printf("Spreadsheet #%d\n", Spreadsheet);
        Spreadsheet++;

        scanf("%d", &n);

        while (n--)
        {
            scanf("%d%d", &qr, &qc);
            printf("Cell data in (%d,%d) ", qr, qc);

            for (int i = 0; i < m; ++i)
            {
                deleted = operaVec[i].execute(qr, qc);
                if (deleted)
                {
                    break;
                }
            }

            if (deleted)
            {
                printf("GONE\n");
            }
            else
            {
                printf("moved to (%d,%d)\n", qr, qc);
            }
        }
    }

    return 0;
}
