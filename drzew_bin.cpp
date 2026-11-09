#include<iostream>
#include<string>
using namespace std;


struct Element {
    int data;
    Element* left=NULL;
    Element* right=NULL;

    Element(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Tree{
    private:
        Element* root;

    public:
        Tree() : root(nullptr) {}

        void insert(int value) {
            root = insertHelper(root, value);
        }

        Element* insertHelper(Element* wezel, int value){
            if (wezel==nullptr) {
                return new Element(value);
            }

            if (value<wezel->data) {
                wezel->left = insertHelper(wezel->left, value);
            } else {
                wezel->right = insertHelper(wezel->right, value);
            }

            return wezel;
        }


        void fourLevel(){
            root=new Element(1);

            root->left=new Element(2);
            root->right=new Element(3);

            root->left->left=new Element(4);
            root->left->right=new Element(5);
            root->right->left=new Element(6);
            root->right->right=new Element(7);

            root->left->left->left=new Element(8);
            root->left->left->right=new Element(9);
            root->left->right->left=new Element(10);
            root->left->right->right=new Element(11);
            root->right->left->left=new Element(12);
            root->right->left->right=new Element(13);
            root->right->right->left=new Element(14);
            root->right->right->right=new Element(15);
        }

        void inorderTraversal() {
            inorderHelper(root);
            cout << endl;
        }

        void inorderHelper(Element* wezel){
            if (wezel != nullptr) {
                inorderHelper(wezel->left);
                cout << wezel->data << " ";
                inorderHelper(wezel->right);
            }
        }
 void displayTree() {
        displayHelper(root, "", true);
    }
    
    void displayHelper(Element* wezel, string wciecie, bool isLast) {
        if (wezel != nullptr) {
            cout << wciecie;
            
            if (isLast) {
                cout << "└── ";
                wciecie += "    ";
            } else {
                cout << "├── ";
                wciecie += "│   ";
            }
            
            cout << wezel->data << endl;
            
            if (wezel->left != nullptr || wezel->right != nullptr) {
                if (wezel->left != nullptr) {
                    displayHelper(wezel->left, wciecie, false);
                }
                
                if (wezel->right != nullptr) {
                    displayHelper(wezel->right, wciecie, true);
                }
            }
        }
    }
};

int main() {
    Tree tree;
    
   
    tree.fourLevel();
    
    cout << "Stryktura drzewa:" << endl;
    tree.displayTree();
    
    return 0;
}
