#include <iostream>
using namespace std;

typedef int valueType;

struct ListNode
{
    valueType index; //ball index insert
    valueType color; //ball color
    ListNode *next;

    ListNode(valueType index, valueType color, ListNode *next = 0)
        : index(index), color(color), next(next) {}
};

// void print_list(ListNode *node, int n)
// {
//     int a[n];
//     int i = 0;
//     while (node != 0)
//     {
//         a[i] = node->index;
//         node = node->next;
//         i++;
//     }
//     for (int j = n - 1; j >= 0; j--)
//     {
//         cout << a[j] << endl;
//     }
// }

void print_list(ListNode *node)
{
    while (node != 0)
    {
        cout << node->index << endl;
        node = node->next;
    }
}

void insert_first(ListNode *header, valueType i, valueType c)
{
    ListNode *new_l = new ListNode(i, c);
    while (true)
    {
        if (header->next == 0)
        {
            header->next = new_l;
            break;
        }
        else
        {
            header = header->next;
        }
    }
}

void insert(ListNode *header, valueType i, valueType c)
{
    ListNode *new_l = new ListNode(i, c);
    ListNode *tmp = header->next;
    header->next = new_l;
    new_l->next = tmp;
}

// void free_list(ListNode *&header)
// {
//     ListNode *tmp = header;
//     header = header->next;
//     delete (tmp);
// }

// void check_for_free(ListNode *header)
// {
//     // cout << header->next->index << " next " << header->next->next->index << " next next " << endl;

//     ListNode *h;
//     if ((header->next != 0 && header->next->next != 0) && ((header->next->next->color == header->next->color) && (header->next->color == header->color)))
//     {
//         free_list(header);
//         free_list(header);
//         free_list(header);
//         h = header;
//         if (h != 0)
//         {
//             while (h->color == h->next->color)
//             {
//                 free_list(h->next);
//             }
//         }
//     }
// }

int main()
{
    int n, m;
    cin >> n >> m;

    ListNode *header = new ListNode(0, 0);

    /* input color for starter ball **/
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        insert_first(header, i, c);
    }

    /* input insert ball **/
    for (int j = 1; j <= m; j++)
    {
        int insert_i, insert_c;
        cin >> insert_c >> insert_i;

        ListNode *h = header;
        while (h->next != 0)
        {
            if (h->next->index == insert_i)
            {
                insert(h->next, n + j, insert_c);
                // check_for_free(h->next->next);
                break;
            }
            h = h->next;
        }
    }
    print_list(header->next);
}