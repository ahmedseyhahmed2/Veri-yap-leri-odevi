#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertNode(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int number;

    printf("Sayilari girin (Sonlandirmak icin -1 girin):\n");

    while (1) {
        scanf("%d", &number);

        if (number == -1) {
            break;
        }

        if (number % 2 == 1) { // Tek sayilar listesinin basina ekle
            head = insertNode(head, number);
        } else { // Çift sayilar listesinin sonuna ekle
            struct Node* current = head;
            if (current == NULL) { // Liste bossa
                head = insertNode(head, number);
            } else {
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = insertNode(NULL, number);
            }
        }
    }

    printf("Siralanmis liste: ");
    printList(head);

    // Bellegi temizle
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
