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

void print_list(ListNode *node, int n)
{
    int a[n];
    int i = 0;
    while (node != 0)
    {   
        a[i] = node->index;
        node = node->next;
        i++;
    }
    for (int j = n-1; j >= 0; j--){
        cout << a[j] << endl;
    }
}

void insert_first(ListNode *header, valueType i,valueType c)
{
    ListNode *new_l = new ListNode(i,c);
    ListNode *tmp = header->next;
    header->next = new_l;
    new_l->next = tmp;
}

int main()
{
    int n, m;
    cin >> n >> m;

    ListNode *header = new ListNode(0, 0);

    /* input color for starter ball **/
    for (int i = 1; i <= n; i++){
        int c;
        cin >> c;
        insert_first(header, i, c);
    }

    /* input insert ball **/
    for (int j = 1; j <= m; j++){
        int insert_i, insert_c;
        cin >> insert_c >> insert_i;

    ListNode *h = header;
        while(h->next != 0){
            if (h->next->index == insert_i){
                insert_first(h, n+j, insert_c);
                break;
            }
            h = h->next;
        }
    }
    print_list(header->next, n+m);
}