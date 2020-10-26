#include <iostream>

using namespace std;

typedef int valueType;

struct IceCream
{
    valueType id; //ball index insert
    IceCream *next;

    IceCream(valueType id, IceCream *next = 0)
        : id(id), next(next) {}
};

void insert(IceCream *header, valueType i)
{
    IceCream *new_l = new IceCream(i);
    header->next = new_l;
}

void free_list(IceCream *&header)
{
    IceCream *tmp = header;
    header = header->next;
    delete (tmp);
}

int count(IceCream *header)
{
    int count = 0;
    while (header->next != 0)
    {
        count ++;
        header = header->next;
    }
    return count;
}

int main()
{
    int m, n, t, id;

    IceCream *header = new IceCream(0);
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> t;
        if(t == 1){
            IceCream *h = header;
            while (h->next != 0)
            {
                h = h->next;
            }
            
            cin >> n;
            for (int j = 1; j <= n; j++){
                cin >> id;
                insert(h, id);
                h = h->next;
            }
        }
        else if (t == 2)
        {
            cout << header->next->id << endl;
            free_list(header->next);
        }
        
    }
    cout << count(header) << endl;
}