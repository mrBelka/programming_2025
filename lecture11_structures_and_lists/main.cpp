#include <iostream>
#include <forward_list>
#include <list>

struct Node {
    int data;
    Node* next;
};

Node* MAKE(int value) {
    Node* p = new Node;
    p->data = value;  // -> <=> *.
    return p;
}

void ADD(Node* head, int value) {
    Node* p = MAKE(value);
    p->next = head->next;
    head->next = p;
}

void ADD_BACK(Node* head, int value) {
    // 1. дойти до последнего элемента
    // 2. как в ADD(последнего элемента)
}

void PRINT(Node* head) {
    Node* p = head->next;
    while(p!=nullptr) {
        std::cout << p->data << std::endl;
        p = p->next;
    }
}

void DELETE_ODD(Node* head) {
    Node* p = head;
    while(p->next != nullptr) {
        if (p->next->data % 2 == 1) {
            Node* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        }
        else {
            p = p->next;
        }
    }
}

void CLEAR(Node* head) {
    Node* p = head;
    while(p->next != nullptr) {
        Node* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
    }
}

void DUPLICATE_EVEN(Node* head) {
    Node* p = head->next;
    while(p != nullptr) {
        if (p->data % 2 == 0) {
            ADD(p, p->data);
            p = p->next;
        }
        p = p->next;
    }
}

int main() {
    Node head;
    head.next = nullptr;

    ADD(&head, 1);
    ADD(&head, 2);
    ADD(&head, 3);
    ADD(&head, 4);
    ADD(&head, 5);
    PRINT(&head);
    DUPLICATE_EVEN(&head);
    DELETE_ODD(&head);
    PRINT(&head);

    CLEAR(&head);


    //Node p;
    //p.c = 97;
    //p.x = 100;

    //std::cout << sizeof(Node);

    /*// Удаление и дублирование

    // Сложность алгоритма - это зависимость кол-ва операций от входных данных
    int n;
    std::cin >> n;
    int arr[100];
    // n = 10 -> O(n) = 10
    // n = 100 -> O(n) = 100
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Удаление
    // 1 2 3 4 5
    int i = 0;
    int j = 0;
    while(i<n) {
        if(arr[i] % 2 == 0) {
            arr[j] = arr[i];
            j++;
        }
        i++;
    }
    n = j;

    // Дублирование (O(n^2))
    // 1 2 3 4 5
    for(int i=0;i<n;i++) {
        if(arr[i] % 2 == 1) {
            for(int j = n-1; j >= i; j--)
                arr[j+1] = arr[j];
            i++;
            n++;
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << arr[i];
    }


    // тета(n*n), O(n*n)
    for(int i=0;i<n-1;i++) // n-1
        for(int j=i+1;j<n;j++) // n/2
            if(arr[i] < arr[j]) // 5
                std::swap(arr[i], arr[j]); // 10

    for(int d = 2; d <= sqrt(x); d++) // O(sqrt(n))
        if(x % 2 == 0) {

        }

    // O(n^2)
    // n = 1000
    // M = 100'000'000 оп/сек
    // T1 = 1/100 сек
    // n = 1'000'000
    // T2 = 10'000 сек

    // O(n*log(n))
    // n = 1'000'000
    // T1 = 0.16 сек*/
    return 0;
}