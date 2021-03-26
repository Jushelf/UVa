#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int n;
    string s, t;
    const string result[] = {"You win.", "You lose.", "You chickened out."};
    int status;
    int count[26];
    int error;
    int number;

    while (scanf("%d", &n), n > 0)
    {
        cin >> s >> t;

        status = 2;
        memset(count, 0, sizeof(count));
        error = 0;
        number = 0;

        for (auto c : s)
        {
            if (count[c - 'a'] == 0)
            {
                count[c - 'a'] = 1;
                number++;
            }
        }

        for (auto c : t)
        {
            if (count[c - 'a'] == 0)
            {
                error++;

                if (error == 7)
                {
                    status = 1;
                    break;
                }
            }
            else if (count[c - 'a'] == 1)
            {
                number--;

                if (number == 0)
                {
                    status = 0;
                    break;
                }
            }

            count[c - 'a'] = -1;
        }

        cout << "Round " << n << endl << result[status] << endl;
    }

    return 0;
}
