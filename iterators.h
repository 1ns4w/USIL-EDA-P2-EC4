//Añadir # a ifndef por Diego Panta
#ifndef __ITERATORS_H__
#define __ITERATORS_H__

#include <iostream>
#include <vector>
#include <Container>
#include <types.h>

template <typename Iterator>
void recorrer1(Iterator begin, Iterator end, iostream &os)
{
	while (begin != end) 
  {
		os << *begin << endl;
		++begin;
	}
}

template <typename Iterator, typename OF>
void recorrer2(Iterator begin, Iterator end, OF &of)
{
	while (begin != end)
		of(*begin);
}

template <typename Iterator, typename OF, typename Extra>
void recorrer3(Iterator begin, Iterator end, OF &of, Extra &extra_param)
{
	while (begin != end)
		of(*begin, extra_param);
}

template <typename Container, typename Function>
void recorrer4(Container &container, Function &function)
{
  auto begin = container.begin();
	while (begin != container.end())
		function(*begin); //eliminado extra_param_MaizoDiego
}

void incrementar(T &val) //int cambiado por T1 - MaizoDiego
{
	val++;
}

template <typename Container>
void print(Container &container, iostream &os)
{
	auto begin = container.begin();
	while (begin != container.end())
		os << *begin << endl;
}
#endif // Agregado por Kevin De Lama
