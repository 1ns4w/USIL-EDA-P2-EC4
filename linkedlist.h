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
  typename Type::T T;
  struct Node
  {
      T data;
      Node *m_pNext;
      Node(T &_data, Node *pNext=nullptr) 
          : data(_data), m_pNext(pNext) {}
      typename Type::T  &getData()            { return data; }
      void   setData(T &_data)    { data = _data;}
      Node *&getpNext()           { return m_pNext; }
      void   setpNext(Node *pNext){ m_pNext = pNext;}
  };
  Node *m_pRoot = nullptr;
  typedef Node *PNODE;
  typedef PNODE &RPNODE;

  class iterator
  {
    public:
    iterator operator++();
    T &operator*();
    bool operator != (iterator &other);
  };
  
  // members here
  public:
    T front(); // Retorna el elemento al comienzo
    T back(); // Retorna el elemento al final
    void push_front(T &elem); // Agrega un elemento al comienzo 
    void push_back(T &elem); // Agrega un elemento al final
    void pop_front(); // Remueve el elemento al comienzo pero no lo retorna
    void insert(T &elem);
    void insert2(T &elem);
    void internal_insert(RPNODE pPrev, T &elem);
    void pop_back(); // Remueve el elemento al final pero no lo retorna
    T &operator[](size_t pos); // Retorna el elemento en la posición indicada
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
void LinkedList<Type>::insert(T &elem)
{
  Node **pPrev = &m_pRoot;
  while(*pPrev && Type::Operation(elem, (*pPrev)->getData()) )
  {   pPrev = &(*pPrev)->getpNext();  }

  Node *pNewNode=new Node(elem, *pPrev);
  *pPrev = pNewNode;
}

//forma 2
template <typename Type>
void LinkedList<Type>::insert2(T &elem)
{
  internal_insert(m_pRoot, elem);
}

//forma 2 continuidad
template <typename Type>
void LinkedList<Type>::internal_insert(RPNODE pPrev, T &elem)
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
void &LinkedList<Type>::recorrer(F &func)
{
  auto pNode = m_pRoot;
  while( pNode != nullptr )
  {
      func( pNode->getData() );
      pNode = pNode->getpNext();
  }
  return os; 
}
//forma 1
template <typename Type>
Type::T &LinkedList<Type>::operator[](size_t pos)
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
  return lista.recorrer(os);
}
#endif