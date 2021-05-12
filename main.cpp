#include <iostream>
#include <vector>
#include "linkedlist.h" //eliminado Linked-MaizoDiego
//#include "iterators.h"
#include "type.h"
#include "myof.h"
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
	while (begin != end)
	{ of(*begin);
    begin++;
  }
}

template <typename Iterator, typename OF, typename Extra>
void recorrer3(Iterator begin, Iterator end, OF &&of, Extra &extra_param) 
{
	for ( ; begin != end ; begin++)
		of(*begin, extra_param);
}

template <typename Container, typename Function>
void recorrer4(Container &container, Function &&function)
{ 
  auto begin = container.begin();
  auto end = container.end();
	while (begin != end)
	{	function(*begin); //eliminado extra_param_MaizoDiego
    begin++;
  }
}

template <typename Container>
void print(Container &container, ostream &os)
{
	vector<T1>::iterator begin = container.begin();
	for( ; begin != container.end() ; begin++ )
		os << *begin << endl;
}

template <typename T>
void incrementar(T &val) //int cambiado por T1 - Kevin De Lama
{
	val++;
}


int vectores()
{
	// cambio de int por T1 - Diego Panta
	vector<T1> vx;

  	// cambio de int por T1 - Diego Panta
	for (T1 i = 0; i < 10; i++)
		vx.push_back(i * i);
  cout<<"=========A=========="<<endl;

	// cambio de int por T1 - Diego Panta
	vector<T1>::iterator iter1 = vx.begin();
	for (; iter1 != vx.end(); iter1++)
		cout << *iter1 << endl;
  cout<<"=========B=========="<<endl;

	auto iter2 = vx.begin();
	for (; iter2 != vx.end(); iter2++)
		cout << *iter2 << endl;
  cout<<"=========C=========="<<endl;

	for (auto &v : vx) //int cambiado a T1 - Kevin De Lama
		cout << v++ << endl;
  cout<<"========D==========="<<endl;

	recorrer1(vx.begin(), vx.end(), cout);
  cout << "Check #0\n";
  recorrer1(vx.rbegin(), vx.rend(), cout);
  cout << "Check #1\n";
	recorrer1(vx.begin() + 2, vx.end() - 1, cout);
  cout << "Check #2\n";
  
	MyOF<T1> myof;
	recorrer2(vx.begin(), vx.end(), incrementar<T1>);
  print(vx, cout);//agregado print_MaizoDiego
  cout << "Check #3\n";
	recorrer2(vx.begin(), vx.end(), myof); // Optimizar para no sacar una copia sin afectar las otras llamadas
  print(vx, cout);//agregado print_MaizoDiego
  cout << "Check #4\n";

  // Aqui agregar una funcion lambda
  auto x=[](int &v){ cout << v <<endl; };//se volvio una variable a la lambda_MaizoDiego
  recorrer2(vx.begin(), vx.end(), [](int &v){ cout << v <<endl; }); 
  cout << "Check #5\n";
  print(vx, cout);//agregado print_MaizoDiego
  cout << "Check #6\n";
  auto y=[](int &v){ v+= 5; };//se volvio una variable a la lambda_MaizoDiego
  recorrer2(vx.begin(), vx.end(), [](int &v){ v+= 3; }); 
  print(vx, cout);//agregado print_MaizoDiego
  cout << "Check #7\n";

  recorrer3(vx.begin(), vx.end(), MyOF<T1>(), cout);
  cout << "Check #10\n";
  print(vx, cout);//agregado print_MaizoDiego
  cout << "Check #50\n";

  recorrer4(vx, incrementar<T1>);
  print(vx,cout);
  cout << "Check #60\n";
  int w = 7;
  recorrer4(vx, [w](int &v){ v++; cout << v <<"-" << w << "\n"; });
  cout << "Check #65\n";
  print(vx,cout); //agregado por kevin de lama
  cout << "Check #70\n";
	// Añadir return 0 - buena practica Diego Panta

	return 0;
}

//IMPRIMIENDO DATOS DE LIST1
void listas_demo()
{
  LinkedList<Integer> list1;
  LinkedList<Float> list2;
  
    for (T1 q=0; q < 20; q++)
    list1.insert2(q);
    cout<<list1<<endl;      
}

int main()
{
  //vectores();
  listas_demo();
  return 0;
}
