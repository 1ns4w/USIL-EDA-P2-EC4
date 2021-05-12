#include <iostream>
#include <vector>
#include "linkedlist.h" //eliminado Linked-MaizoDiego
#include "iterators.h"
#include "type.h"
#include "myof.h"

using namespace std;

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
  recorrer2(vx.begin(), vx.end(), x); 
  cout << "Check #5\n";
  print(vx, cout);//agregado print_MaizoDiego
  cout << "Check #6\n";
  auto y=[](int &v){ v+= 3; };//se volvio una variable a la lambda_MaizoDiego
  recorrer2(vx.begin(), vx.end(), y); 
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
  auto z = [w](int &v){ v++; cout << v <<"-" << w << "\n"; };
  recorrer4(vx, z);
  cout << "Check #65\n";
  print(vx,cout); //agregado por kevin de lama
  cout << "Check #70\n";
	// Añadir return 0 - buena practica Diego Panta

	return 0;
}

void listas_demo()
{
  LinkedList<Integer> list1;
  LinkedList<Float> list2;

  cout<<"push_back"<<endl;
  //Insertar valores para list1
  for(int i = 0; i<10; i++){
    list1.push_back(i);
  }
  list1.recorrer_imprimiendo(cout);

  cout<<"push_front"<<endl;
  for(float f = 0; f<5; f+=0.5){
    list2.push_front(f);
  }
  list2.recorrer_imprimiendo(cout);
  
}

int main()
{
  //vectores();
  listas_demo();
  return 0;
}
