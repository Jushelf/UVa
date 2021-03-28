#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct cell
{
    cell()
    {
        r = 0;
        c = 0;
    }

    cell(int R, int C)
    {
        r = R;
        c = C;
    }

    int r, c;
};

vector<vector<cell>> sheet;

void executeCommand(char * command, int num)
{
    if (strcmp(command, "DR") == 0)
    {
        sheet.erase(begin(sheet) + num - 1);
    }
    else if (strcmp(command, "DC") == 0)
    {
        for (auto &row : sheet)
        {
            row.erase(begin(row) + num - 1);
        }
    }
    else if (strcmp(command, "IC") == 0)
    {
        for (auto &row : sheet)
        {
            row.insert(begin(row) + num - 1, cell());
        }
    }
    else if (strcmp(command, "IR") == 0)
    {
        sheet.insert(begin(sheet) + num - 1, vector<cell>(sheet[0].size()));
    }
}

int main()
{
    int r, c;
    int m;//m operations
    int n;//n queries
    int Spreadsheet = 1;

    char command[5];
    int A;
    cell cell1, cell2, temp;
    int num;
    bool find = false;

    vector<int> numVec;

    while (scanf("%d%d", &r, &c), r)
    {
        sheet.clear();

        for (int i = 0; i < r; ++i)
        {
            sheet.emplace_back(vector<cell>());
            for (int j = 0; j < c; ++j)
            {
                sheet[i].push_back(cell(i + 1, j + 1));
            }
        }

        scanf("%d", &m);

        while (m--)
        {
            scanf("%s", command);

            if (strcmp(command, "EX") == 0)
            {
                scanf("%d%d%d%d", &cell1.r, &cell1.c, &cell2.r, &cell2.c);

                temp = sheet[cell1.r - 1][cell1.c - 1];
                sheet[cell1.r - 1][cell1.c - 1] = sheet[cell2.r - 1][cell2.c - 1];
                sheet[cell2.r - 1][cell2.c - 1] = temp;
            }
            else
            {
                scanf("%d", &A);

                numVec.clear();
                while (A--)
                {
                    scanf("%d", &num);
                    numVec.push_back(num);
                }

                sort(numVec.begin(), numVec.end());

                for (int i = numVec.size() - 1; i >= 0 ; --i)
                {
                    executeCommand(command, numVec[i]);
                }
            }
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
            scanf("%d%d", &temp.r, &temp.c);
            find = false;

            printf("Cell data in (%d,%d) ", temp.r, temp.c);

            for (int i = 0; i < sheet.size() && !find; ++i)
            {
                for (int j = 0; j < sheet[i].size() && !find; ++j)
                {
                    if (sheet[i][j].r == temp.r && sheet[i][j].c == temp.c)
                    {
                        find = true;
                        printf("moved to (%d,%d)\n", i + 1, j + 1);
                    }
                }
            }

            if (!find)
            {
                printf("GONE\n");
            }
        }
    }

    return 0;
}
