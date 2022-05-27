//structure that represents avl tree node
struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

//class that represents AVL(Self-Balanced) Tree
class avlTree {
public:
    //pointer to root of the tree
    treeNode *root;

    //method that returns height of the tree
    int height(treeNode *temp);

    //method that returns height difference
    int heightDifference(treeNode *temp);

    //method that makes right-right rotation
    treeNode *RRrotation(treeNode *parent);

    //method that makes left-left rotation
    treeNode *LLrotation(treeNode *parent);

    //method that makes left-right rotation
    treeNode *LRrotation(treeNode *parent);

    //method that makes right-left rotation
    treeNode *RLrotation(treeNode *parent);

    //method that balances tree
    treeNode *balance(treeNode *temp);

    //method that inserts value into a tree
    treeNode *insert(treeNode *root, int value);

    //prints tree into console output
    void display(treeNode *pointerToStart, int level);

    //prints elements into console output in inorder order
    void inorder(treeNode *tree);

    //prints elements into console output in preorder order
    void preorder(treeNode *tree);

    //prints elements into console output in postorder order
    void postorder(treeNode *tree);

    //method that deletes element from the tree
    treeNode *remove(treeNode *pointerToStart, int value);

    //method that finds min element in a tree
    treeNode *findMin(treeNode *tree);

    //method that finds max element in a tree
    treeNode *findMax(treeNode *tree);

    //empty constructor
    avlTree() {
        root = nullptr;
    }
};