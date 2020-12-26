#include <iostream>

using namespace std;

string st;

int main()
{
    bool change = true;
    while(getline(cin, st)){
        for (int i = 0; i < st.size(); i++)
        {
            if (st[i] == '\"')
            {
                if (change){
                cout << "``";
                change = false;
                }
                else if (!change)
                {
                    cout << "''";
                    change = true;
                }
            }
            else
            {
                cout << st[i];
            }
        }
        cout << endl;
    }
}