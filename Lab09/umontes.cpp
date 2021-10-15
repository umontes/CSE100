#include <iostream>
#include <queue>

using namespace std;

//.....Lab09
//.....Huffman Codes

//---------------------------------------------------
struct MinHeapNode{

    char data;
    int freq;

    MinHeapNode *left, *right;
    MinHeapNode(char data, int freq){
        left = NULL;
        right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
//---------------------------------------------------

//---------------------------------------------------
struct compare{
    bool operator()(MinHeapNode* l, MinHeapNode* r){
        return (l->freq > r->freq);
    }
};
//---------------------------------------------------

//---------------------------------------------------
int printHuffman(string final[], struct MinHeapNode* root, string str, int i){

    char letters[6];
    string code[6];
    string colon = ":";

    if (!root){
        return 0;
    }
    if (root->data != '$'){

        letters[i] = root->data;
        code[i] = str;

        for (int j = 0; j < 6; j++){
            if (letters[i] == 'A'){
                final[0] = letters[i] + colon + code[i];
            }
        }
        for (int j = 0; j < 6; j++){
            if (letters[i] == 'B'){
                final[1] = letters[i] + colon + code[i];
            }
        }
        for (int j = 0; j < 6; j++){
            if (letters[i] == 'C'){
                final[2] = letters[i] + colon + code[i];
            }
        }
        for (int j = 0; j < 6; j++){
            if (letters[i] == 'D'){
                final[3] = letters[i] + colon + code[i];
            }
        }
        for (int j = 0; j < 6; j++){
            if (letters[i] == 'E'){
                final[4] = letters[i] + colon + code[i];
            }
        }
        for (int j = 0; j < 6; j++){
            if (letters[i] == 'F'){
                final[5] = letters[i] + colon + code[i];
            }
        }

    }

    printHuffman(final, root->left, str + "0", i++);
    printHuffman(final, root->right, str + "1", i++);

}
//---------------------------------------------------

//---------------------------------------------------
int Huffman(char alpha[], int freq[], int n){

    struct MinHeapNode *left;
    struct MinHeapNode *right;
    struct MinHeapNode *top;

    priority_queue <MinHeapNode*, vector<MinHeapNode*>, compare> Q;

    for (int i = 0; i < n; i++){
        Q.push(new MinHeapNode(alpha[i], freq[i]));
    }

    for (int i = 1; i < n; i++){
        left = Q.top();
        Q.pop();

        right = Q.top();
        Q.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        Q.push(top);
    }

    string final[6];

    printHuffman(final, Q.top(), "", 0);

    for (int i = 0; i < n; i++){
        cout << final[i] << endl;
    }

}
//---------------------------------------------------

//---------------------------------------------------
int main(){

    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[sizeof(alpha)];    //there will only be 6 characters
    int n = sizeof(alpha);  //the number of characters

    for (int i = 0; i < n; i++){    //put the frequencies of each character into an array
        cin >> freq[i];
    }

    Huffman(alpha, freq, n);

}
//---------------------------------------------------