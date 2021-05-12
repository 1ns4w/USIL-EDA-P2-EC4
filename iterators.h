//Añadir # a ifndef por Diego Panta
#ifndef __ITERATORS_H__
#define __ITERATORS_H__

#include <iostream>
#include <vector>
#include "type.h"
using namespace std;
template <typename Iterator>
void recorrer1(Iterator begin, Iterator end, ostream &os)
{
	while (begin != end) 
  {
		os << *begin << endl;
		++begin;
	}
}

template <typename Iterator, typename OF>
void recorrer2(Iterator begin, Iterator end, OF &&of)
{
	while (begin != end){
		of(*begin);
    begin++;
  }
}

template <typename Iterator, typename OF, typename Extra>
void recorrer3(Iterator begin, Iterator end, OF &&of, Extra &extra_param)
{
	while (begin != end){
		of(*begin, extra_param);
    begin++;
  }
}

template <typename Container, typename Function>
void recorrer4(Container &container, Function &function)
{
  auto begin = container.begin();
	while (begin != container.end()){
		function(*begin); //eliminado extra_param_MaizoDiego
    begin++;
  }
}

template <typename T>
void incrementar(T &val) //int cambiado por T1 - MaizoDiego
{
	val++;
}

template <typename Container>
void print(Container &container, ostream &os)
{
	auto begin = container.begin();
	for( ; begin != container.end() ; begin++ )
		os << *begin << endl;
}
#endif // Agregado por Kevin De Lama
