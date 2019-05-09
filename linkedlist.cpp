#include <iostream>
using namespace std;
/*  
・リストの最後にノードを追加する ・リスト内にノードを挿入する
・リスト内を移動する
・ノードを削除する
・リストを削除する
・参照する
head tailの内容はNULL
*/

/* Nodeクラス　かく単位ノードを持ってる。前後の枝(のアドレス)とそれ自身の値を確保している。ただそれだけ*/
class Node
{
private:
    Node *next; //単純に入れ物なので動的に確保しない。(確保すると再帰的にNodeが発散)
    Node *prev;
    double data;

public:
    Node()
    {
    }
    void setNext(Node *p)
    {
        next = p;
    }
    Node *getNext()
    {
        return next;
    }
    void setPrev(Node *p)
    {
        prev = p;
    }
    Node *getPrev()
    {
        return prev;
    }
    void setData(double c)
    {
        data = c;
    }
    double getData()
    {
        return data;
    }
};

/*ノードの関係を制御する。要は全体像を持ってる*/
class LinkedList
{
private:
    Node *head; //先頭を作る
    Node *tail; //先頭を作る
    int length; //リストごとに長さを持つ

public:
    LinkedList();
    ~LinkedList();
    void append_node(double N);
    //void delete_node();
    //void delete_node(unsigned int N);
    void print();
};

int main()
{
    LinkedList *list = new LinkedList; //動的確保
    for (int i = 10; i > 0; i--)
        list->append_node(i);
    list->print();
    delete list; //LinkedListは消えてもNodeは消えない
    return 0;
}

LinkedList::LinkedList() //this:そのクラスナイデ定義された変数
{
    head = new Node;
    tail = new Node;

    //cout << "list is created" << endl;
    this->head->setNext(this->tail);
    this->tail->setPrev(this->head);
    this->length = 0;
}

LinkedList::~LinkedList()
{
    Node *tmp = this->head;
    while (true)
    {
        Node *tmp2 = tmp;
        //このアドレスを解放
        if (tmp2 == this->tail)
        {
            break;
        }
        else
        {
            tmp = tmp->getNext();
        }
        delete tmp2;
    }
    delete tmp;
}

void LinkedList::append_node(double N)
{ //新規ノードの追加(値、前、後の設定)
    //cout <<N<< " is appended." ;
    Node *node = new Node;
    //本体処理
    node->setNext(this->tail);
    node->setPrev(this->tail->getPrev());
    //後方処理
    this->tail->setPrev(node); //こいつを忘れるな！
    //前方処理
    node->getPrev()->setNext(node); //こいつを忘れるな！
    node->setData(N);
    this->length += 1;//thisは勝手にポインタでとられている。たとえ変数でも。
}

void LinkedList::print()
{
    Node *tmp = this->head->getNext();//変数はけすがポインタは消さない。
    for (int i = 0; i < this->length; i++)
    {
        cout << "list[" << i << "]=" << tmp->getData() << endl;
        tmp = tmp->getNext();
    }
}
