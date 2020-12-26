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

ListNode *address[2000030];

void print_list(ListNode *node)
{
    while (node != 0)
    {
        cout << node->index << endl;
        node = node->next;
    }
}


void boom(int check_index, valueType color)
{
    
}

ListNode* insert(ListNode *header, valueType i, valueType c)
{
    ListNode *new_l = new ListNode(i, c);
    ListNode *tmp = header->next;
    
    header->next = new_l;
    new_l->next = tmp;
    return new_l;
}

int main()
{
    int n, m;
    cin >> n >> m;

    ListNode *header = new ListNode(0, 0);
    address[0] = header;

    /* input color for starter ball **/
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        address[i] = insert(address[i-1], i, c);
    }

    /* input insert ball **/
    for (int j = 1; j <= m; j++)
    {
        int insert_i, insert_c;
        cin >> insert_c >> insert_i;

        ListNode *h;

        h = address[insert_i];
        address[n+j] = insert(h, n+j, insert_c);
        boom(n+j, insert_c);
    }
    print_list(header->next);
}