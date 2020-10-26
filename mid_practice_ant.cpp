#include <iostream>
using namespace std;

int main()
{
    int day;
    int ants[1000];
    int total = 0;

    cin >> day;
    for (int i = 0; i < day; i++){
        cin >> ants[i];
    }

    for (int j = 0; j < day; j++){
        if (ants[j] >= 1000){
            total += 1000;
            j ++;
        }
        else {
            total += ants[j];
        }
    }
    cout << total << endl;
}