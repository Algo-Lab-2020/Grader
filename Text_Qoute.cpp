#include <iostream>

using namespace std;

char *write_chars(char *dest, const char *st)
{
    while (*st != '\0')
    {
        *dest = *st;
        st += 1;
        dest += 1;
    }
    return dest;
}

void text(char *src, char *dest)
{
    int time = 1;
    while (*src != '\0')
    {
        if (*src == '\"' && time == 1)
        {
            dest = write_chars(dest, "``");
            time = 2;
        }
        else if (*src == '\"' && time == 2)
        {
            dest = write_chars(dest, "''");
            time = 1;
        }

        else
        {
            *dest = *src;
            dest += 1;
        }
        src += 1;
    }
}

int main()
{
    char st[1000];
    char out[1000];

    cin.getline(st, 1000);
    text(st, out);

    cout << out << endl;
}