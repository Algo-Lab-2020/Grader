#include <iostream>
using namespace std;

// main()
// {
//     int a, b;
//     int total = 0;
//     cin >> a >> b;

//     for (int i = a; i <= b; i++)
//     {
//         total += i;
//     }

//     cout << total << endl;
// }

int main()
{
    int p[1000];
    int n,k;
    int stock = 0;
    int m = 0;
    int sell, buy;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for (int j = 0; j < n-1; j++)
    {
        if ((p[j+1] - p[j] >= k) && (stock == 0))
        {
            stock = 1;
            buy = p[j+1];
        }
        else if ((p[j] - p[j+1] >= k) && (stock == 1))
        {
            stock = 0;
            sell = p[j+1];
            m += (sell - buy);
        }
        
    }
    // cout << "s" << sell << "b" << buy << endl;
    // // cout << buy-sell << endl;
    cout << m << endl;
}