struct Node {
    int key;
    Node* left;
    Node* right;
};

class Huffman {
public:
    Huffman(int*, int*, int);
    Node* makeTree(int*, int*, int, int, int*);
    void printText(char*);
    
    Node* root;
};

Huffman::Huffman(int* inorder, int* postorder, int size) {
    int currPos = size - 1;
    root = makeTree(inorder, postorder, 0, size - 1, &currPos);
}

Node* Huffman::makeTree(int* inorder, int* postorder, int begin, int end, int* currPosition) {
    Node* newNode = new Node;
    newNode->key = postorder[*currPosition];
    (*currPosition)--;
    if (begin == end) return newNode;
    int inorderIndex;
    for (int i = begin; i <= end; i++) {
        if (inorder[i] == newNode->key) inorderIndex = i;
    }

    newNode->right = makeTree(inorder, postorder, inorderIndex+1, end, currPosition);
    newNode->left = makeTree(inorder, postorder, begin, inorderIndex-1, currPosition);
    
    return newNode;
}

void Huffman::printText(char* message) {
    Node* currNode = root;
    int i = 0;
    
    while (message[i] != '\n') {
        if (message[i] == '0') currNode = currNode->left;
        else if (message[i] =='1') currNode = currNode->right;
        if (currNode->key < 128) {
            cout << (char) currNode->key;
            currNode = root;
        }
        i++;
    }
    cout << endl;
}

//////////////////////////////////////////////

int* getList(char* fileName, int* spot) {
    int* list = new int[300];
    int temp;
    
    ifstream inputFile;
    inputFile.open(fileName);
    
    while (inputFile >> temp) {
        list[*spot] = temp;
        (*spot)++;
    }
    inputFile.close();
    
    return list;
}
