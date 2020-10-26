#include <iostream>
using namespace std;

int main()
{
    int exp[1000];
    int day;
    int total = 0;

    cin >> day;
    for (int i = 0; i < day; i++){
        cin >> exp[i];
    }

    for (int j = 0; j < day; j++){
        if((j+1)%4==0){
            total += (2*exp[j]);
        }
        else {
            total += exp[j];
        }
    }
    cout << total <<endl;
}