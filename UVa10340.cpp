#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;

    while (cin >> s >> t)
    {
        int match = 0;
        for(auto c : t)
        {
            if (c == s[match])
            {
                match++;
            }
        }

        if (match == s.size())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
