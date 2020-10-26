#include <set>
#include <iostream>

using namespace std;

int main()
{
    int n, m, total;
    int cd;
    total = 0;
    set<int> n_cd;
    set<int> m_cd;
    // std::set<int>::iterator it;

    cin >> n >> m;
    while (n != 0 && m != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> cd;
            n_cd.insert(cd);
        }
        for (int j = 1; j <= m; j++)
        {
            cin >> cd;
            // m_cd.insert(cd);
            if (n_cd.find(cd)!=n_cd.end()){
                total += 1;
            };
        }
    //     for (auto k = n_cd.begin(); k != n_cd.end(); k++)
    // {
    //     for (auto l = m_cd.begin(); l != m_cd.end(); l++)
    //     {
    //         if (*k == *l)
    //         {
    //             total += 1;
    //         }
    //     }
    // }
    cout << total << endl;

    total = 0;
    n_cd.clear();
    m_cd.clear();

    cin >> n >> m;
    }
}