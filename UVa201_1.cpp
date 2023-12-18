#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 10;

struct PairIntHash {
    std::size_t operator()(const pair<int, int>& p) const {
        return p.first * N + p.second;
    }
};

bool check_square (int row, int col, int size, const unordered_set<pair<int, int>,
        PairIntHash> &hSet, const unordered_set<pair<int, int>, PairIntHash> &vSet)
{
    for (int i = 0; i < size; ++i)
    {
        if (hSet.find(make_pair(row, col+i)) == hSet.end()
        || hSet.find(make_pair(row+size, col+i)) == hSet.end()
        || vSet.find(make_pair(col, row+i)) == vSet.end()
        || vSet.find(make_pair(col+size, row+i)) == vSet.end())
        {
            return false;
        }
    }

    return true;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    char type;
    int row, col;
    unordered_set<pair<int, int>, PairIntHash> hSet, vSet;
    int problem_index = 0;
    while (cin >> n)
    {
        problem_index++;
        if (problem_index > 1)
        {
            cout << endl << "**********************************" << endl << endl;
        }
        cout << "Problem #" << problem_index << endl << endl;
        vSet.clear();
        hSet.clear();
        cin >> m;
        while (m--)
        {
            cin >> type >> row >> col;
            if (type == 'H')
            {
                hSet.emplace(row, col);
            }
            else
            {
                vSet.emplace(row, col);
            }
        }
        bool has_square = false;
        int square_num;
        for (int size = 1; size <= n; ++size)
        {
            square_num = 0;

            for (int i = 1; i <= n - size; ++i)
            {
                for (int j = 1; j <= n - size; ++j)
                {
                    square_num += check_square(i, j, size, hSet, vSet);
                }
            }

            if (square_num > 0)
            {
                has_square = true;
                cout << square_num << " square (s) of size " << size << endl;
            }
        }

        if (!has_square)
        {
            cout << "No completed squares can be found." << endl;
        }
    }

    return 0;
}
