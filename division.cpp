#include <iostream>
using namespace std;

string place(int x, int y, int x_axis, int y_axis) 
{
    if((x == x_axis) || (y == y_axis))
    {
        return "divisa";
    }
    else if (x > x_axis)
    {
        if (y > y_axis)
        {
            return "NE";
        }
        else
        {
            return "SE";
        }
    }
    else 
    {
        if(y > y_axis)
        {
            return "NO";
        }
        else
        {
            return "SO";
        }   
    } 
}

int main()
{
    int n, m, c_x, c_y, x, y;
    c_x = 0;
    c_y = 0;
    m = 0;
    cin >> n;
    while (n != 0)
    {   
        cin >> c_x >> c_y;
        for (int i = m; i < n+m; i++)
        {
            cin >> x >> y;
            cout << place(x, y, c_x, c_y) << endl;
        }
        m += n;
        cin >> n;
    }
}