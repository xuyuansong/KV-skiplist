#include <cstdlib>
#include <cstring>

//节点类
template<typename K,typename V>
class Node
{
public:
    Node();
    Node(K k,V v,int level);
    ~Node();
    int m_level;        //节点层级
    Node<K,V> **forword; //指针数组，存储当前节点不同层级指向下一节点的地址

    void set_value(V v); //修改值
    K get_key();        //获取键
    V get_value();      //获取值

private:
    K key;              //键
    V value;            //值
};

template<typename K,typename V>
Node<K,V>::Node()
{
}

template<typename K,typename V>
Node<K,V>::Node(K k,V v,int level)
{
    this->key = k;
    this->value = v;
    this->m_level = level;
    this->forword = new Node<K,V>* [level+1];
    memset(forword,0,sizeof(Node<K,V>*)*(level+1)); //初始化指针数组为0
}

template<typename K,typename V>
Node<K,V>::~Node()
{
    delete[] this->forword;
}

template<typename K,typename V>
void Node<K,V>::set_value(V v)
{
    this->value = v;
}

template<typename K,typename V>
K Node<K,V>::get_key()
{
    return this->key;
}

template<typename K,typename V>
V Node<K,V>::get_value()
{
    return this->value;
}