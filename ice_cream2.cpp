#include <iostream>
#include <queue>

using namespace std;

int m, t, n, id, flavor;
int stat[20];
queue<pair<int, int>> q;

void statistic()
{
    for (int k = 0; k < 20; k++)
    {
        cout << stat[k] << " ";
    }
    cout << endl;
}

int main()
{
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> n;
            for (int j = 1; j <= n; j++)
            {
                cin >> id >> flavor;
                q.push(make_pair(id, flavor));
            }
        }
        else if (t == 2)
        {
            cout << q.front().first << endl;
            stat[q.front().second-1] += 1;
            q.pop();
        }
    }
    cout << q.size() << endl;
    statistic();
}