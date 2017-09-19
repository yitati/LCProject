/*
 * VirtualTable.cpp
 *
 *  Created on: Sep 16, 2017
 *      Author: JoanneY1
 */

/*
 * Mutiple Inheritance:
 * If a derived class has 3 base classes
 */

#include <iostream>

using namespace std;

/*
 * Question 1: Given the following code, what is the output of Global1(d)?
 */
class Base1
{
public:
	virtual int virt1()
	{
		cout << "Base vir1" << endl;
		return 100;
	}
	int data1;
};

class Derived1 : public Base1
{
public:
	int virt1()
	{
		cout << "Derived1 vir1 "<<endl;
		return 150;
	}

	int derivedData;
};

int Global1(Base1 * b1)
{
	return b1->virt1();
}

///////////////////////////////////////////////////////////////////////////////

/*
 * Question 2: Given following code, what is the output?
 */

class Base2
{
public:
	virtual int virt2()
	{
		cout << "Base vir2 "<< endl;
		return 200;
	}
	int data2;
};

class MultiDerived: public Base1, public Base2
{
public:
	virtual int virt1()
	{
		cout << "MultiDerived virt1" << endl;
		return 150;
	}

	virtual int virt2()
	{
		cout << "MultiDerived virt2" << endl;
		return 250;
	}

	int derivedData;
};

int Global2(Base2 * bptr)
{
	return bptr->virt2();
}

/*
func global1(Base1* bptr)
{
	cout << "global1 ptr is "<< bptr << endl;
	return (func)*(int *)*(int *)bptr;
}

func global2(Base2* bptr)
{
	cout << "global2 ptr is "<< bptr << endl;
	return (func)*(int *)*(int *)bptr;
}
*/

/*
 * Updated
 */
class MultiDerivedUpdated: public Base1, public Base2
{
public:
	MultiDerivedUpdated(int d):derivedData(d){}

	virtual int virt1()
	{
		cout << "MultiDerivedUpdated virt1" << endl;
		return 150;
	}

	virtual int virt2()
	{
		cout << "MultiDerivedUpdated virt2" << endl;
		return derivedData;
	}

	int derivedData;
};

int Global2Updated(Base2 * bptr)
{
	return bptr->virt2();
}

int main()
{
	Derived1 * d = new Derived1;
	cout << d->virt1() << endl;   // output 150
	cout << Global1(d) << endl;   // output 150

	 MultiDerived * md = new MultiDerived;

	 cout << md->virt1() << endl;
	 cout << Global1(md) << endl;
	 cout << md->virt2() << endl;
	 cout << Global2(md) << endl;

	 MultiDerivedUpdated* mdupdate = new MultiDerivedUpdated(122);
	 cout << Global2Updated(mdupdate) << endl;
}
/*
Derived1 vir1
global1 ptr is 0x4131e48
Derived1 vir1

Derived2 virt1
global1 ptr is 0x4131ad8
Derived2 virt1

Derived2 virt2
global2 ptr is 0x4131ae0
Derived2 virt2

So multiple derived object memory layout should be like this (from low address to high address) -

vptr1
base1 data
vptr2
base2 data
md data1
md data2

 */

/*
 * Q: What is the memory layout of Base1, Derived1, Base2, MultiDerived2?
 * 	- the number of virtual pointer is the same with the number of base class.
 * 	  Each virtual pointer points to a data table which maps all virtual functions defined in this
 * 	  base class. And the overriden functions in derived class will override the virtual function
 * 	  in base class.
 *
 * 	  Base1 memory layout
 * 	  vptr1 -------------> vtable: B1::vir1()
 * 	  data1
 *
 * 	  Derived1 memory layout
 * 	  vptr1 -------------> vtable: D1::vir1()
 * 	  B1: data1
 * 	  derivedData
 *
 * 	  Base2 memory layout
 * 	  vptr2 -------------> vtable: B2::virt2();
 * 	  B2: data2
 *
 * 	  MultiDerived memory layout
 * 	  vptr1 -------------> vtable1: D::virt1()
 * 	  B1: data1
 * 	  vptr2 ------------------------------------> vtable2: D::virt2()
 * 	  B2: data2
 * 	  derived data
 *
 * Q: Why we want to use virtual table?
 * 	-  For example, if we have a funtion that will take or use a base pointer or reference. At compile time we only
 * 	know that it points to a base object. However at runtime, the code could be calling the derived function.
 * 	At compile time,the compiler can't know which code is going to be executed.
 * 	Virtual table is basically a table of function pointers. With virtual table we can do run time polymophism.
 * 	Each object that has virtual functions has a "v-table pointer" that points to the virtual table for objects
 * 	of its type.
 *
 * Q: Why don't we use function pointers instead?
 * 	- Conceptually, it is very same thing.
 * 	The virtual method table is nothing than a list of function pointers. it is not integrated in the object itself
 * 	because it is static for the class of the object, so it can be shared among instances of the same class, which
 * 	saves computation power during initializtion and memory during the objects whole lifetime.
 *
 * Q: Why we put virtual pointer at the first entry?
 * 	- It's rather efficient and convient. Suppose you need to call a virtual function for a given object.
 * 	You have a pointer to that object and the virtual function index. You need to somehow find which function
 * 	should be called with that index and for this object. Okay, you simply access the first sizeof(void*) bytes
 * 	behind the pointer and find where the vtable resides, then access the necessary element of vtable to fetch
 * 	the function address.
 * 	You could store a separate map of "vtable for each object" or something but if you decide that you want
 * 	to store the vptr inside the object then it's only logical to use the first bytes, not the last bytes or
 * 	any other place because with this approach you know where to find the vptr once you have a pointer to the
 * 	object, no extra data required.
 *
 * Q: What if we switch the derivedData with base data?
 *  - It will change the offset of the member data. If we are using a base class pointer, in my implementation
 *  it should point to the vptr of the derived class. But to access the base data, it need to know not only the
 *  size of the base class itself, but also the member data of the derived class.
 *
 * Q: When the virtual table is being build? Compile time or run time?
 * 	- At compile time. Every class will have one (or more) virtual table. And based on if the function is overriding,
 * 	we can map the function in v table.
 *
 * Q: Why we need two vptr for the MultiDerived class?
 *  - It keeps the same layout with the base class virtual table. So the bahavior of base class pointer is the same
 *  when invoking a function.
 *
 * Q: If we need to return data member, how to change the above code?
 * 	- see code above
 *
 * Q: If we have defined another virtual function foo() in base 1, what is the memory layout of MultiDerived?
 * 	vptr1 --------------------> vtable1: D::virt1()
 * 	B1: data1                            B::foo()
 * 	vptr2 -------------------------------------------------> vtable2: D::virt2()
 * 	B2: data2
 * 	derived data
 */



