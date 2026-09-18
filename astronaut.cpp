#include <iostream>
using namespace std;

struct Astronaut {
    int id;
    Astronaut* next;
    
    Astronaut(int i) {
        id = i;
        next = nullptr;
    }
};

int main() {
    int N, K;
    
    cout << "Masukkan jumlah astronaut: ";
    cin >> N;
    cout << "Masukkan urutan yang dieliminasi: ";
    cin >> K;

    if (N <= 0) {
        cout << "Jumlah astronaut harus lebih dari 0." << endl;
        return 0;
    }

    Astronaut* head = new Astronaut(1);
    Astronaut* current = head;
    
    for (int i = 2; i <= N; i++) {
        current->next = new Astronaut(i);
        current = current->next;
    }
    current->next = head; 
    
    Astronaut* prev = current; 
    Astronaut* curr = head;    

    cout << "\nUrutan eliminasi: ";

    
    while (curr->next != curr) {
        
        
        for (int i = 1; i < K; i++) {
            prev = curr;
            curr = curr->next;
        }

    
        int eliminated_id = curr->id;
        cout << eliminated_id << " ";

        prev->next = curr->next;
        Astronaut* temp = curr;
        curr = curr->next; 
        delete temp;       

        if (eliminated_id % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        
        if (K < 2) {
            K = 2;
        }
    }

    cout << "\nAstronaut terakhir yang bertahan: " << curr->id << endl;

    delete curr;

    return 0;
}