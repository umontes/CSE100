
#include <iostream>
#include <list>

using namespace std;

//.....Lab06
//.....Hash Table with Chaining

// need to implement insert, search, and delete operations

//---------------------------------------
//INSERT FUNCTION
int Insert(list<int> *table, int size, int key){

    int position = key % size;
    table[position].push_front(key);

}
//---------------------------------------

//---------------------------------------
//SEARCH FUCNTION
int Search(list<int> *table, int size, int key){

    int position = key % size;
    list<int> x = table[position];
    list<int>::iterator it;
    int index = 0;

    if (x.empty()) {
        cout << key << ":NOT_FOUND;" << endl;
    }
    else {
        for (it = x.begin(); it != x.end(); it++){
            if (*it == key){
                cout << key << ":FOUND_AT" << position << "," << index << ";" << endl;
                return 0;
            }
            index++;
        }
        cout << key << ":NOT_FOUND;" << endl;
    }

}
//---------------------------------------

//---------------------------------------
//DELETE FUNCTION
int Delete(list<int> *table, int size, int key){
    int position = key % size;
    list<int> x = table[position];
    list<int>::iterator it;

    if (x.empty()){
        cout << key << ":DELETE_FAILED;" << endl;
    }
    else {
        for (it = x.begin(); it != x.end(); it++){
            if (*it == key){
                x.erase(it);
                table[position] = x;
                cout << key << ":DELETED;" << endl;
                return 0;
            }
        }
        cout << key << ":DELETE_FAILED;" << endl;
    }

}
//---------------------------------------

//---------------------------------------
//OUTPUT FUNCTION
int Output(list<int> *table, int size, int key){

    list<int> x;
    list<int>::iterator it;

    for (int i = 0; i < size; i++){
        x = table[i];

        if (x.empty()){
            cout << i << ":;" << endl;
        }
        else {
            cout << i << ":";
            for (it = x.begin(); it != x.end(); it++){
                cout << *it << "->";
            }
            cout << ";" << endl;
        }
    }

}
//---------------------------------------

//---------------------------------------
//MAIN FUNCTION
int main(int argc, char **argv){
    
    int size, key;
    char choice;
    list<int> *table;

    cin >> size;

    table = new list<int>[size];

    cin >> choice;
    while (choice != 'e'){

        if (choice == 'i'){
            cin >> key;
            Insert(table, size, key);
        }

        else if (choice == 'd'){
            cin >> key;
            Delete(table, size, key);
        }

        else if (choice == 's'){
            cin >> key;
            Search(table, size, key);
        }

        else if (choice == 'o'){
            Output(table, size, key);
        }

        cin >> choice;

    }

}
//---------------------------------------