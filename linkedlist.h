#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "traits.h"
// #include
// #include <vector>
using namespace std;


template <typename Type>
class LinkedList
{
  private:
  typedef typename Type::T x;
  typename Type::T T;
  struct Node
  {
      x data;
      Node *m_pNext;
      Node(x &_data, Node *pNext=nullptr) 
          : data(_data), m_pNext(pNext) {}
      x  &getData()            { return data; }
      void   setData(x &_data)    { data = _data;}
      Node *&getpNext()           { return m_pNext; }
      void   setpNext(Node *pNext){ m_pNext = pNext;}
  };
  Node *m_pRoot;
  typedef Node *PNODE;
  typedef PNODE &RPNODE;
  // members here
  public:
  LinkedList<Type>() noexcept
  {
    m_pRoot=nullptr;
  }

  class iterator
  {
    friend class LinkedList;
    private:
    Node *m_actual;
    public:
    iterator begin()
    {return iterator(this->m_pRoot);}

    iterator end()
    {return iterator(nullptr);}
    
    iterator () noexcept :
      m_actual(this->m_pRoot) { }
    
    iterator(Node* pNode) noexcept :
        m_actual (pNode) { }
  
    iterator operator++()
    { if (m_actual)
      m_actual=m_actual->next;
      return *this; 
    }
    
    x &operator*() { return m_actual->data; }
    
    bool operator != (iterator &other) 
    { return m_actual != other.m_actual; }
  };
    
    x front(); // Retorna el elemento al comienzo
    x back(); // Retorna el elemento al final
    void push_front(x &elem); // Agrega un elemento al comienzo 
    void push_back(x &elem); // Agrega un elemento al final
    void pop_front(); // Remueve el elemento al comienzo pero no lo retorna
    void insert(x &elem);
    void insert2(x &elem);
    void internal_insert(RPNODE pPrev, x &elem);
    void pop_back(); // Remueve el elemento al final pero no lo retorna
    typename Type::T &operator[](size_t pos); // Retorna el elemento en la posición indicada
    bool empty(); // Retorna si la lista está vacía o no
    size_t size(); // Retorna el tamaño de la lista 
    void clear(); // Elimina todos los elementos de la lista
    void sort(); // Ordena la lista
    void reverse(); // Revierte la lista

    ostream &recorrer_imprimiendo(ostream &os);
    template <typename F>
    void recorrer(F &func); // Buscar funciones Lambda
                            // Buscar object functions
};

//forma 1
template <typename Type>
void LinkedList<Type>::insert(x &elem)
{
  Node **pPrev = &m_pRoot;
  while(*pPrev && Type::Operation(elem, (*pPrev)->getData()) )
  {   pPrev = &(*pPrev)->getpNext();  }

  Node *pNewNode=new Node(elem, *pPrev);
  *pPrev = pNewNode;
}

//forma 2
template <typename Type>
void LinkedList<Type>::insert2(x &elem)
{
  internal_insert(m_pRoot, elem);
}
//forma 2 continuidad
template <typename Type>
void LinkedList<Type>::internal_insert(RPNODE pPrev,x &elem)
{
  if(!pPrev || elem < pPrev->getData())
  {
    Node *pNewNode = new Node(elem, pPrev);
    pPrev = pNewNode;
    return;
  }
  internal_insert(pPrev->getpNext(), elem);
}

template <typename Type>
ostream &LinkedList<Type>::recorrer_imprimiendo(ostream &os)
{
  auto pNode = m_pRoot;
  while( pNode != nullptr )
  {
      os << pNode->getData() << endl;
      pNode = pNode->getpNext();
  }
  return os; 
}

template <typename Type>
template <typename F>
void LinkedList<Type>::recorrer(F &func)
{
  auto pNode = m_pRoot;
  while( pNode != nullptr )
  {
      func( pNode->getData() );
      pNode = pNode->getpNext();
  }
}
//forma 1
template <typename Type>
typename Type::T &LinkedList<Type>::operator[](size_t pos)
{
  Node **pPrev = &m_pRoot;
  for(size_t i = 0; i < pos ; i++)
    pPrev = &(*pPrev)->getpNext();
  return (*pPrev)->getData();
}

//forma 2
/*template <typename T>
T &LinkedList<T>::operator[](size_t pos)
{
  if(!pos)
    return 
  Node *pPrev = &m_pRoot;
  for(size_t i = 0; i < pos ; i++)
    pPrev = &(*pPrev)->getpNext();
  return (*pPrev)->getData();
}*/

template <typename Type>
ostream &operator<<(ostream &os, LinkedList<Type> &lista)
{
  return lista.recorrer_imprimiendo(os);
}
#endif
