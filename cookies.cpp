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
    new_l->next = header->next;
    header->next = new_l;
}

void free_list(ListNode *&header)
{
    ListNode *tmp = header->next;
    header->next = tmp->next;
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
    int t, l, k, x; //l = 1 = insert = 2 = eat

    cin >> t;
    ListNode *header = new ListNode(0);
    for (int i = 1; i <= t; i++)
    {
        ListNode *h = header;
        cin >> l;
        if (l == 1)
        {
            cin >> k >> x;
            if ((header->next == 0) || (k == 0))
            {
                insert(header, x);
            }
            else
            {
                for (int j = 1; j <= k; j++)
                {
                    if (h->next == 0)
                    {
                        break;
                    }
                    h = h->next;
                }
                insert(h, x);
            }
        }
        else if (l==2)
        {
            cin >> k;
            if (h->next != 0)
            {
                for (int j = 1; j < k; j++)
                {
                    if (h->next == 0)
                    {
                        break;
                    }
                    else
                    {
                        h = h->next;
                    }
                }
                if (h->next != 0)
                {
                    free_list(h);
                }
            }
        }
    }
    print_list(header->next);
}