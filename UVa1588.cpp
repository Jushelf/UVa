#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    unsigned long long ans;

    while (cin >> s >> t)
    {
        if(s.size() < t.size())
        {
            string temp = s;
            s = t;
            t = temp;
        }

        bool match = false;
        for (int i = 0; i < s.size() - t.size(); ++i)
        {
            match = true;
            for (int j = 0; j < t.size(); ++j)
            {
                if (t[j] == '2' && s[i + j] == '2')
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                cout << s.size() << endl;
                break;
            }
        }

        if (match)
        {
            continue;
        }

        ans = s.size() + t.size();

        for (int i = 0; i < t.size(); ++i)
        {
            match = true;
            for (int j = 0; j < t.size() - i; ++j)
            {
                if (t[i + j] == '2' && s[j] == '2')
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                ans = i + s.size();
                break;
            }
        }

        for (int i = 0; i < t.size(); ++i)
        {
            match = true;
            for (int j = 0; j < t.size() - i; ++j)
            {
                if (t[j] == '2' && s[s.size() - t.size() + i + j] == '2')
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                if ((i + s.size()) < ans)
                {
                    ans = i + s.size();
                }
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
