#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    string s, t;
    int count1[26];
    int count2[26];

    while (cin >> s >> t)
    {
        memset(count1, 0, sizeof(count1));
        memset(count2, 0, sizeof(count2));

        for (auto c : s)
        {
            count1[c - 'A']++;
        }

        for (auto c : t)
        {
            count2[c - 'A']++;
        }

        sort(count1, count1 + 26);
        sort(count2, count2 + 26);

        bool match = true;

        for (int i = 0; i < 26; ++i)
        {
            if (count1[i] != count2[i])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
