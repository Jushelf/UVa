#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int r, c, index = 1;
    vector<vector<pair<char, int>>> puzzle(12, vector<pair<char, int>>(12));

    while (scanf("%d%d", &r, &c) == 2)
    {
        int start = 1;
        for (int j = 0; j <= c + 1; ++j)
        {
            puzzle[0][j].first = '*';
            puzzle[0][j].second = start;
        }

        for (int i = 1; i <= r; ++i)
        {
            puzzle[i][0].first = '*';
            puzzle[i][0].second = start;
            for (int j = 1; j <= c; ++j)
            {
                //scanf("%c", &puzzle[i][j].first);
                cin >> puzzle[i][j].first;
                puzzle[i][j].second = start;

                if (puzzle[i][j].first != '*' && (puzzle[i - 1][j].first == '*' || puzzle[i][j - 1].first == '*'))
                {
                    start++;
                }
            }
            puzzle[i][c + 1].first = '*';
            puzzle[i][c + 1].second = start;
        }

        for (int j = 0; j <= c + 1; ++j)
        {
            puzzle[r + 1][j].first = '*';
            puzzle[r + 1][j].second = start;
        }

        if (index != 1)
        {
            printf("\n");
        }
        printf("puzzle #%d:\n", index);
        index++;

        printf("Across\n");
        for (int i = 1; i <= r; ++i)
        {
            for (int j = 1; j <= c; ++j)
            {
                if (puzzle[i][j].first != '*' && puzzle[i][j - 1].first == '*')
                {
                    printf("%3d.", puzzle[i][j].second);

                    for (int k = 0; puzzle[i][j + k].first != '*'; ++k)
                    {
                        putchar(puzzle[i][j + k].first);
                    }
                    printf("\n");
                }
            }
        }

        printf("Down\n");
        for (int i = 1; i <= r; ++i)
        {
            for (int j = 1; j <= c; ++j)
            {
                if (puzzle[i][j].first != '*' && puzzle[i - 1][j].first == '*')
                {
                    printf("%3d.", puzzle[i][j].second);

                    for (int k = 0; puzzle[i + k][j].first != '*'; ++k)
                    {
                        putchar(puzzle[i + k][j].first);
                    }
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
