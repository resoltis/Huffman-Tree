#include <iostream>
#include <fstream>

using namespace std;

#include "decode.cpp"

int main(int argc, char* argv[]) {
    int size = 0;
    
    //  get traversal lists
    int* inorder = getList(argv[1], &size);
    size = 0;
    int* postorder = getList(argv[2], &size);
    
    //  create tree
    Huffman tree(inorder, postorder, size);
    
    //  get the coded message
    char* message = new char[300];
    ifstream inputFile;
    inputFile.open(argv[3]);
    char letter;
    int i = 0;
    while (inputFile >> letter) {
        message[i] = letter;
        i++;
    }
    
    //   print decoded message
    tree.printText(message);
    
    return 0;
}
