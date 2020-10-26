#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode
{
    valueType id; //ball index insert
    ListNode *next;

    ListNode(valueType id, ListNode *next = 0)
        : id(id), next(next) {}
};

void insert(ListNode *header, valueType i)
{
    ListNode *new_l = new ListNode(i);
    header->next = new_l;
}

void free_list(ListNode *&header)
{
    ListNode *tmp = header;
    header = header->next;
    delete (tmp);
}

void print_list(ListNode *node)
{
    while (node != 0)
    {
        cout << node->id << endl;
        node = node->next;
    }
}

int main()
{
    int t, l, k, x;
    ListNode *h;

    cin >> t;
    ListNode *header = new ListNode(0);

    for (int i = 1; i <= t; i++)
    {
        cin >> l;
        h = header;
        if (l == 1)
        {
            cin >> k >> x;
            for (int j = 0; j <= k; j++)
            {
                if (h->next == 0){
                    insert(h, x);
                    break;
                } else if (j == k){
                    insert(h, x);
                } else {
                    h = h->next;
                }
            }
        }
        else if (l == 2)
        {
            if (header->next != 0)
            {
                cin >> k;
                for (int a = 1; a < k; a++)
                {
                    header = header->next;
                }
                free_list(header->next);
            }
        }
    }
    print_list(header);
}