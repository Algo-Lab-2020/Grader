#include <set>
#include <iostream>
#include <cmath>

using namespace std;

set<int> number;
set<int>::iterator it;
int x, y, min = 0;

int main()
{
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        number.insert(x);
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> y;
        it = number.lower_bound(y);

        if (it == number.end())
        {
            it--;
            cout << *it << endl;
        }
        else if (it == number.begin())
        {
            cout << *it << endl;
        }
        else
        {
            int tmp = *it;
            int tmpp = tmp;
            if (tmp == y)
            {
                cout << y << endl;
            }
            else
            {
                it--;
                tmpp = *it;
                if (abs(tmp - y) >= abs(y - tmpp))
                {
                    cout << tmpp << endl;
                }
                else
                {
                    cout << tmp << endl;
                }
            }
        }
    }
}