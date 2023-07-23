//There are two linked list A & B containing data 10 element. write a program to create a linked list c that contains only those element that have common in linked list A & B.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

typedef struct node* NODE;

NODE create_node();
NODE insert_front(NODE head);
NODE insert_end(NODE head);
NODE merge_lists(NODE head1, NODE head2);
NODE sum(NODE head1, NODE head2);
void display(NODE head);

int main() {
    NODE head1 = NULL;
    NODE head2 = NULL;
    NODE head3 = NULL;
    NODE head4 = NULL;
    int ch;
    while (1) {
        printf("\nMenu:\n");
        printf("1: Insert front1\t 2: Insert end1\t 3: Insert front2\t 4: Insert end2\t 5: Merge lists\t 6: Display1\t 7: Display2\t 8: Display3\t  9: Display4\t 10: Sum\t 11: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                head1 = insert_front(head1);
                break;
            case 2:
                head1 = insert_end(head1);
                break;
            case 3:
                head2 = insert_front(head2);
                break;
            case 4:
                head2 = insert_end(head2);
                break;
            case 5:
                head3 = merge_lists(head1, head2);
                break;
            case 6:
                display(head1);
                break;
            case 7:
                display(head2);
                break;
            case 8:
                display(head3);
                break;
            case 9:
                display(head4);
                break;
            case 10:
                head4 = sum(head1, head2);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

NODE create_node() {
    NODE newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &(newnode->data));
    newnode->link = NULL;
    return newnode;
}

NODE insert_front(NODE head) {
    NODE newnode = create_node();
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->link = head;
        head = newnode;
    }
    return head;
}

NODE insert_end(NODE head) {
    NODE newnode = create_node();
    if (head == NULL) {
        head = newnode;
    } else {
        NODE cur = head;
        while (cur->link != NULL) {
            cur = cur->link;
        }
        cur->link = newnode;
    }
    return head;
}

NODE merge_lists(NODE head1, NODE head2) {
    NODE cur1 = head1;
    NODE cur2 = head2;
    NODE head3 = NULL;
    NODE cur3 = NULL;

    while (cur1 != NULL) {
        cur2 = head2;
        while (cur2 != NULL) {
            if (cur1->data == cur2->data) {
                NODE newnode = create_node();
                newnode->data = cur1->data;
                if (head3 == NULL) {
                    head3 = newnode;
                    cur3 = newnode;
                } else {
                    cur3->link = newnode;
                    cur3 = cur3->link;
                }
                break;
            }
            cur2 = cur2->link;
        }
        cur1 = cur1->link;
    }

    return head3;
}

NODE sum(NODE head1, NODE head2) {
    NODE cur1 = head1;
    NODE cur2 = head2;
    NODE head4 = NULL;
    NODE cur4 = NULL;

    while (cur1 != NULL && cur2 != NULL) {
        int s = cur1->data + cur2->data;
        NODE newnode = create_node();
        newnode->data = s;
        newnode->link = NULL;

        if (head4 == NULL) {
            head4 = newnode;
            cur4 = newnode;
        } else {
            cur4->link = newnode;
            cur4 = cur4->link;
        }

        cur1 = cur1->link;
        cur2 = cur2->link;
    }

    return head4;
}

void display(NODE head) {
    if (head == NULL) {
        printf("Singly linked list is empty\n");
        return;
    }

    NODE cur = head;
    while (cur != NULL) {
        printf("%d->", cur->data);
        cur = cur->link;
    }
    printf("NULL\n");
}
