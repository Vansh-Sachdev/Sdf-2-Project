#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node
{
public:
    T Data;
    Node<T> *Left, *Right;
};
template <class T>
class Tree
{
public:
    Node<T> *Root;
    Node<T> *newNode(int Data)
    {
        Node<T> *Temp = new Node<T>;

        Temp->Data = Data;
        Temp->Left = Temp->Right = NULL;

        return Temp;
    }
    Node<T> *constructTreeUtil(T pre[], int *Index, int low,
                               int high, int Size)
    {
        if (*Index >= Size || low > high)
            return NULL;

        Node<T> *Temp = newNode(pre[*Index]);
        *Index = *Index + 1;

        if (low == high)
            return Temp;

        int i;
        for (i = low; i <= high; ++i)
            if (pre[i] > Temp->Data)
                break;

        Temp->Left = constructTreeUtil(pre, Index, *Index,
                                       i - 1, Size);
        Temp->Right = constructTreeUtil(pre, Index, i, high, Size);

        return Temp;
    }
    void constructTree(T pre[], int Size)
    {
        int Index = 0;
        Root = constructTreeUtil(pre, &Index, 0, Size - 1,
                                 Size);
    }
    void PrintInoder(Node<T> *Temp)
    {
        if (Temp == NULL)
            return;
        PrintInoder(Temp->Left);
        cout << Temp->Data << " ";
        PrintInoder(Temp->Right);
    }
    void PrintPreOrder(Node<T> *Temp)
    {
        if (Temp == NULL)
            return;
        cout << Temp->Data << " ";
        PrintPreOrder(Temp->Left);
        PrintPreOrder(Temp->Right);
    }
    void PrintPostOrder(Node<T> *Temp)
    {
        if (Temp == NULL)
            return;
        PrintPostOrder(Temp->Left);
        PrintPostOrder(Temp->Right);
        cout << Temp->Data << " ";
    }
    bool PrintPath(Node<T>*Temp, int Sum)
    {
        if (Sum == 0)
        {
            return true;
        }

        if (Temp == nullptr)
        {
            return false;
        }

        bool Left = PrintPath(Temp->Left, Sum - Temp->Data);
        bool Right = PrintPath(Temp->Right, Sum - Temp->Data);

        if (Left || Right)
        {
            cout << Temp->Data << " ";
        }

        return Left || Right;
    }

    int RootToLeaf(Node<T>*Temp)
    {
        if (Temp == nullptr)
        {
            return 0;
        }

        int Left = RootToLeaf(Temp->Left);

        int Right = RootToLeaf(Temp->Right);

        return (Left > Right ? Left : Right) + Temp->Data;
    }

    void FindSumPath(Node<T>*Temp)
    {
        int Sum = RootToLeaf(Temp);
        cout << "The Maximum Sum is " << Sum << endl;
        cout << "The Maximum Sum path is ";

        PrintPath(Temp, Sum);
    }
};

int main()
{
    cout << "Enter The Size Of Array ";
    int Size;
    cin >> Size;
    int Array[Size];
    for (int i = 0; i < Size; i++)
    {
        cin >> Array[i];
    }
    // int Array[] = {1, 2, 3, 4, 5, 6, 7, 0, 8, 9, 0, 0, 0, 10, 11, 12, 13, 0, 14, 15, 0, 16, 17};
    // int Size = sizeof(Array) / sizeof(Array[0]);
    Tree<int> Tr;
    if (Size)
    {
        Tr.constructTree(Array, Size);
        Tr.FindSumPath(Tr.Root);
    }
    cout << "\n\nHie Death ";

    return 0;
}