#include <iostream>
using namespace std;

int main()
{
    int n;
    int tank = 0;
    int water[1000], buckets[5] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> water[i];
    }

    for (int a = 0; a < n; a++)
    {
        int index_min = 0;
        int min = buckets[0];
        for (int k = 0; k < 5; k++)
        {   
            if (min > buckets[k])
            {
                index_min = k;
                min = buckets[k];
            }
        }
        if (buckets[index_min] + water[a] >= 1000)
        {
            tank += 1000;
            buckets[index_min] = 0;
        }
        else
        {
            buckets[index_min] += water[a];
        }
        
    }
    cout << tank << endl;
}