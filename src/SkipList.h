#include "Node.h"
#include <iostream>
#include <cmath>
#include <mutex>

std::mutex mtx;

template<typename K,typename V>
class SkipList
{
public:
    SkipList(int max_level);
    ~SkipList();

    int get_rand_level();   //获取随机层级
    Node<K,V>* create_node(K k,V v,int level); //创建节点
    void clear(Node<K,V>* cur); //删除跳表链条

    bool insert_node(K k,V v);  //插入节点
    bool select_node(K k);  //查找节点
    bool delete_node(K k);  //删除节点
    void display_list(); //列出数据列表
    int size();     //获取当前节点数

private:
    int m_max_level; //最大层级
    int being_level; //当前层级
    Node<K,V>* head_ptr; //头指针
    int being_node_num; //当前节点个数
};

template<typename K,typename V>
SkipList<K,V>::SkipList(int max_level)
{
    this->m_max_level = max_level;
    this->being_level = 0;
    this->being_node_num = 0;
    K k;
    V v;
    this->head_ptr = new Node<K,V>(k,v,m_max_level);
}

template<typename K,typename V>
SkipList<K,V>::~SkipList()
{
    clear(head_ptr->forword[0]);
    delete head_ptr;
}

template<typename K ,typename V>
int SkipList<K,V>::get_rand_level()
{
    int k = 1;
    while(rand() % 2)
    {
        k++;
    }
    return k < m_max_level ? k : m_max_level ;
}

template<typename K,typename V>
Node<K,V>* SkipList<K,V>::create_node(K k,V v,int level)
{
    Node<K,V>* new_node = new Node<K,V>(k,v,level);
    return new_node;
}

template<typename K ,typename V>
bool SkipList<K,V>::insert_node(K key,V value)
{
    mtx.lock();
    Node<K,V>* current = this->head_ptr;
    
    Node<K,V>* update[m_max_level+1];
    memset(update,0,sizeof(Node<K,V>*)*(m_max_level+1));

    for(int i = being_level; i>=0 ; i--)
    {
        while(current->forword[i] != NULL && current->forword[i]->get_key() < key)
        {
            current = current->forword[i];
        }
        update[i] = current;
    }
    current = current->forword[0];
    if(current != NULL && current->get_key() == key) //已存在键为key的数据，数据插入失败
    {
        mtx.unlock();
        std::cout << "已存在键为 "<< key<<" 的数据，数据插入失败" <<std::endl;
        return false;
    }

    if(current == NULL || current->get_key() != key)
    {
        int random_level = get_rand_level();
        if(random_level > being_level)
        {
            for(int i = being_level+1; i<random_level+1; i++)
            {
                update[i]=head_ptr;
            }
            being_level = random_level;
        }

        Node<K,V>* new_node = create_node(key,value,random_level);
        for(int i = 0; i<=random_level ; i++)
        {
            new_node->forword[i] = update[i]->forword[i];
            update[i]->forword[i] = new_node;
        }
        std::cout << "数据 key: " << key << " " << "value: " << value << " " << "插入成功" << std::endl;
        being_node_num++;
    }
    mtx.unlock();
    return true;
}

template<typename K,typename V>
bool SkipList<K,V>::select_node(K key)
{
    Node<K,V>* current = head_ptr;

    for(int i = being_level; i>=0 ; i--)
    {
        while(current->forword[i] && current->forword[i]->get_key() < key)
        {
            current = current->forword[i];
        }
    }
    current = current->forword[0];
    if(current && current->get_key() == key)
    {
        std::cout << "找到键key= " << key << " 的值为: " << current->get_value() << std::endl;
        return true;
    }
    std::cout << "不存在key= " << key << " 的值" << std::endl;
    return false;
}

template<typename K,typename V>
bool SkipList<K,V>::delete_node(K key)
{
    mtx.lock();
    Node<K,V>* current = head_ptr;
    Node<K,V>* update[m_max_level+1];
    memset(update,0,sizeof(Node<K,V>*)*(m_max_level+1));

    for(int i=being_level ; i>=0 ;i--)
    {
        while(current->forword[i] && current->forword[i]->get_key() < key)
        {
            current = current->forword[i];
        }
        update[i]=current;
    }

    current = current->forword[0];
    if(current && current->get_key()==key)
    {
        for(int i=0;i<being_level;i++)
        {
            if(update[i]->forword[i]!=current)
            {
                break;
            }
            update[i]->forword[i] = current->forword[i];
        }
        while(being_level > 0 && head_ptr->forword[being_level] == 0)
        {
            being_level--;
        }
        std::cout << "成功删除key= " << key << " 的节点" << std::endl;
        delete current;
        being_node_num--;
        mtx.unlock();
        return true;
    }
    std::cout << "删除key= " << key << " 的节点失败" << std::endl;
    mtx.unlock();
    return false;
}

template<typename K,typename V>
void SkipList<K,V>::display_list()
{
    std::cout << "***SkipList数据***" << std::endl;
    Node<K,V>* temp = head_ptr->forword[0];
    while(temp)
    {
        std::cout << "层级:" << temp->m_level << " (" << temp->get_key() << "," << temp->get_value() << ");";
        temp = temp->forword[0];
    }
    std::cout << std::endl;
}

template<typename K,typename V>
int SkipList<K,V>::size()
{
    return this->being_node_num;
}

template<typename K,typename V>
void SkipList<K,V>::clear(Node<K,V>* cur)
{
    while (cur != nullptr) {
        Node<K, V>* next = cur->forword[0];
        //std::cout << "释放key为:" << cur->get_key() << " 的节点" << std::endl;
        delete cur;
        cur = next;
    }
    //std::cout << "所有节点释放结束" << std::endl;
}