#include <iostream>
using namespace std;

struct node {
    string name;
    bool likes_vanilla;
    bool likes_butterscotch;
    node* next;
};

void add_node(node** head, string name, bool likes_vanilla, bool likes_butterscotch) {
    node* new_node = new node;
    new_node->name = name;
    new_node->likes_vanilla = likes_vanilla;
    new_node->likes_butterscotch = likes_butterscotch;
    new_node->next = *head;
    *head = new_node;
}

void print_list(node* head) {
    while (head != NULL) {
        cout << head->name << " ";
        head = head->next;
    }
    cout << endl;
}

void compute_sets(node* head) {
    node* vanilla_or_butterscotch = NULL;
    node* vanilla_and_butterscotch = NULL;
    int neither_vanilla_nor_butterscotch = 0;

    while (head != NULL) {
        if (head->likes_vanilla || head->likes_butterscotch) {
            add_node(&vanilla_or_butterscotch, head->name, head->likes_vanilla, head->likes_butterscotch);
        }
        if (head->likes_vanilla && head->likes_butterscotch) {
            add_node(&vanilla_and_butterscotch, head->name, head->likes_vanilla, head->likes_butterscotch);
        }
        if (!head->likes_vanilla && !head->likes_butterscotch) {
            neither_vanilla_nor_butterscotch++;
        }
        head = head->next;
    }

    cout << "Set of students who like either vanilla or butterscotch or both: ";
    print_list(vanilla_or_butterscotch);

    cout << "Set of students who like both vanilla and butterscotch: ";
    print_list(vanilla_and_butterscotch);

    cout << "Number of students who like neither vanilla nor butterscotch: " << neither_vanilla_nor_butterscotch << endl;
}

int main() {
    node* head = NULL;

    add_node(&head, "Alice", true, false);
    add_node(&head, "Bob", true, true);
    add_node(&head, "Charlie", false, true);
    add_node(&head, "Dave", false, false);

    compute_sets(head);

    return 0;
}
