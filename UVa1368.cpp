#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num, m, n;

    cin >> num;

    while (num--)
    {
        cin >> m >> n;
        vector<int> sum(n, 0);
        vector<vector<int>> distance(4, vector<int>(n, 0));
        vector<string> input(m, string(n, 'A'));
        string ans(n, 'A');

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> input[i][j];

                distance[0][j] += (input[i][j] != 'A');
                distance[1][j] += (input[i][j] != 'C');
                distance[2][j] += (input[i][j] != 'G');
                distance[3][j] += (input[i][j] != 'T');
            }
        }

        int distancesum = 0;
        vector<int> distmin(n);

        for (int i = 0; i < n; ++i)
        {
            distmin[i] = distance[0][i];

            if (distance[1][i] < distmin[i])
            {
                distmin[i] = distance[1][i];
                ans[i] = 'C';
            }

            if (distance[2][i] < distmin[i])
            {
                distmin[i] = distance[2][i];
                ans[i] = 'G';
            }

            if (distance[3][i] < distmin[i])
            {
                distmin[i] = distance[3][i];
                ans[i] = 'T';
            }

            distancesum += distmin[i];
        }

        cout << ans << endl << distancesum << endl;
    }

    return 0;
}
