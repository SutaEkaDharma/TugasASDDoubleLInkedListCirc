#include <stdio.h>
#include <stdlib.h>

// Definisi struktur node
typedef struct Node *Node;
struct Node {
    int data;
    Node prev, next;
};

Node first = NULL, last = NULL; // Variabel global untuk node pertama dan terakhir

// Fungsi untuk membuat node baru
Node createNode(int data) {
    Node newNode = (Node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = newNode;
    return newNode;
}

// Fungsi untuk menyisipkan node di akhir list
void insertLast(int data) {
    Node newNode = createNode(data);

    if (first == NULL) {
        first = last = newNode;
    } else {
        newNode->prev = last;
        last->next = newNode;
        newNode->next = first;
        first->prev = newNode;
        last = newNode;
    }
}

// Fungsi untuk menampilkan list
void printList() {
    if (first == NULL) {
        printf("[]\n\n");
    } else {
        Node temp = first;
        do {
            printf("Address: %p, Data: %d\n", (void*)temp, temp->data);
            temp = temp->next;
        } while (temp != first);
        printf("\n\n");
    }
}

void swap(Node a, Node b) {
  Node aPrev = a->prev;
  Node aNext = a->next;
  Node bPrev = b->prev;
  Node bNext = b->next;

  a->next = bNext;
  a->prev = b;
  b->next = a;
  b->prev = aPrev;
  aPrev->next = b;
  bNext->prev = a;

  // tukar list pertama
  if (a == first) first = b;
  else if (b == first) first = a;

  // tukar list terakhir
  if (a == last) last = b;
  else if (b == last) last = a;
}

void sortList() {
  if (first == NULL || first == first->next) return;

  int repeat;
  Node node;

  do {
    repeat = 0;
    node = first;

    while (node->next != first) {
      if (node->data > node->next->data) {
       
        swap(node, node->next);
       
        repeat = 1;
      } else {
       
        node = node->next;
      }
    }
  } while (repeat);
}

int main() {
    int total, nilai;

    printf("Masukkan Total: ");
    scanf("%d", &total);

    printf("Masukkan Nilai: ");
    for (int i = 0; i < total; i++){
        scanf("%d", &nilai);
        insertLast(nilai);
    }

    printf("List sebelum pengurutan:\n");
    printList();

    sortList();

    printf("List setelah pengurutan:\n");
    printList();
    
    return 0;
}