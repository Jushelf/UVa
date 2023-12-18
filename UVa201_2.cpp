//
// Created by 15566 on 2023/12/18.
//
#include <iostream>
#include <cstring>

using namespace std;

bool H[11][11], V[11][11];
int HLen[11][11], VLen[11][11];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    char type;
    int x, y;

    int problem_index = 0;
    while (cin >> n)
    {
        memset(H, 0, sizeof (H));
        memset(V, 0, sizeof (V));
        memset(HLen, 0, sizeof (HLen));
        memset(VLen, 0, sizeof (VLen));
        problem_index++;
        if (problem_index > 1)
        {
            cout << endl << "**********************************\n\n";
        }
        cout << "Problem #" << problem_index << "\n\n";
        cin >> m;
        while (m--)
        {
            cin >> type >> x >> y;
            if (type == 'H')
            {
                H[x][y] = true;
            }
            else
            {
                V[y][x] = true;
            }
        }

        int square_num[10] = {0};
        int maxLen;
        for (int i = n; i >= 1; --i)
        {
            for (int j = n; j >= 1 ; --j)
            {
                if (H[i][j])
                {
                    HLen[i][j] = HLen[i][j+1] + 1;
                }

                if (V[i][j])
                {
                    VLen[i][j] = VLen[i+1][j] + 1;
                }

                maxLen = min(HLen[i][j], VLen[i][j]);

                for (int k = 1; k <= maxLen; ++k)
                {
                    square_num[k] += (HLen[i+k][j] >= k) && (VLen[i][j+k] >= k);
                }
            }
        }

        bool has_square = false;
        for (int i = 1; i <= n; ++i)
        {
            if (square_num[i] > 0)
            {
                has_square = true;
                cout << square_num[i] << " square (s) of size " << i << "\n";
            }
        }

        if (!has_square)
        {
            cout << "No completed squares can be found.\n";
        }
    }

    return 0;
}
