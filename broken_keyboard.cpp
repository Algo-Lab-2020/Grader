#include <iostream>
#include <list>

using namespace std;

void print_list(list<char> l)
{
    list<char>::iterator iter;
    for (iter = l.begin(); iter != l.end(); iter++)
    {
        cout << *iter;
    }
    cout << endl;
}

int main()
{
    string input;
    // list<char> keyboard;
    // list<char>::iterator it;
    // it = keyboard.begin();
    while (getline(cin, input))
    {
        list<char> keyboard;
        list<char>::iterator it;
        it = keyboard.begin();
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '[')
            {
                it = keyboard.begin();
            }
            else if (input[i] == ']')
            {
                it = keyboard.end();
            }
            else
            {
                keyboard.insert(it, input[i]);
            }
        }

        print_list(keyboard);
        // keyboard.clear();
    }
}
