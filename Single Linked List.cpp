#include <iostream>
using namespace std;

typedef struct Node {
    string nama;
    int umur;
    Node *next;
}NODE;

typedef struct List {
    NODE *head;
    int juml_data_di_node;
}LIST;

LIST *create_list(){
    LIST *list;
    list = new LIST;
    list->juml_data_di_node = 0;
    list->head = NULL;
    return list;
}

void insert_front(LIST *list, string nama, int umur){
    NODE *tmp;
    tmp = new NODE;
    tmp->nama = nama;
    tmp->umur = umur;
    tmp->next = list->head;
    list->head = tmp;
    list->juml_data_di_node += 1;
}

void insert_end(LIST *list, string nama, int umur){
    if(list->juml_data_di_node == 0){
        insert_front(list, nama, umur);
    } else {
        NODE *tmp = new NODE;
        tmp->nama = nama;
        tmp->umur = umur;
        tmp->next = NULL;

        // Menemukan node teakhir
        NODE *tail = list->head;
        while(tail->next != NULL){
            tail = tail->next;
        }

        tail->next = tmp;
        list->juml_data_di_node += 1;
    }
}

void insert_posittion(LIST *list, string nama, int umur, int pos){
    if(pos == 0){
        insert_front(list, nama, umur);
    } else {
        NODE *tmp = new NODE;
        tmp->nama = nama;
        tmp->umur = umur;

        //Menemukan posisi
        NODE *tmp2 = list->head;
        for(int i = 0; i<pos-1; i++){
            tmp2 = tmp2->next;
        }
        tmp->next = tmp2->next;
        tmp2->next = tmp;

        list->juml_data_di_node += 1;
    }
}

void remove_front(LIST *list){
    NODE *tmp;
    tmp = list->head;
    list->head = tmp->next;
    free(tmp);
}

void remove_end(LIST *list){
    NODE *tmp, *tmp2;
    if(list->juml_data_di_node == 1){
        remove_front(list);
    } else {
        tmp2 = list->head;
        // Menemukan node teakhir
        while(tmp2->next->next != NULL){
            tmp2 = tmp2->next;
        }
        tmp = tmp2->next->next;
        tmp2->next = NULL;
        free(tmp);
        list->juml_data_di_node -= 1;
    }
}

void remove_position(LIST *list, int pos){
    if(pos == 0 || pos == 1){
        remove_front(list);
    } else {
        NODE *tmp, *tmp2;

        //Menemukan posisi
        tmp2 = list->head;
        for(int i = 0; i<pos-1; i++){
            tmp2 = tmp2->next;
        }
        tmp->next = tmp2->next;
        tmp2->next = tmp;
        free(tmp);

        list->juml_data_di_node -= 1;
    }
}

void destroy_list(LIST *list){
    while(list->juml_data_di_node > 0){
        remove_front(list);
    }
}

void print_list(LIST *list){
    NODE *tmp = list->head;
    cout << "List: " << endl;
    while(tmp != NULL){
        cout << "Nama: " << tmp->nama << endl;
        cout << "Umur: " << tmp->umur << endl;
        tmp = tmp->next;
    }
    cout << "\n" << endl;
}

int main(){
    LIST *list = create_list();
    insert_front(list, "Pratama", 20);
    print_list(list);
    insert_end(list, "Can", 20);
    print_list(list);
    insert_end(list, "Eli", 20);
    print_list(list);
    remove_front(list);
    print_list(list);
    //remove_end(list);
    // print_list(list);
    // destroy_list(list);
    insert_posittion(list, "Elya", 20, 1);
    print_list(list);
    remove_position(list, 1);
    print_list(list);
return 0;
}
