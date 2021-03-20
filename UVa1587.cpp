#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void exchange(int & w, int & h)
{
    if (w < h)
    {
        int t = w;
        w = h;
        h = t;
    }
}

struct cmpFunctor
{
    inline bool operator() (const pair<int, int> & T1, const pair<int, int> & T2)
    {
        if (T1.first != T2.first)
        {
            return T1.first < T2.first;
        }
        return T1.second <= T2.second;
    }
};

int main()
{
    vector<pair<int, int>> box(6);

    int w, h;
    while (cin >> w >> h)
    {
        exchange(w, h);
        box[0].first = w;
        box[0].second = h;

        for (int i = 1; i < 6; ++i)
        {
            cin >> w >> h;
            exchange(w, h);
            box[i].first = w;
            box[i].second = h;
        }

        sort(box.begin(), box.end(), cmpFunctor());

        if (box[0].first == box[1].first
        && box[0].first == box[4].second
        && box[0].first == box[5].second
        && box[0].second == box[1].second
        && box[0].second == box[2].second
        && box[0].second == box[3].second
        && box[2].first == box[3].first
        && box[2].first == box[4].first
        && box[2].first == box[5].first)
        {
            cout << "POSSIBLE" << endl;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    
    return 0;
}
