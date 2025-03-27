// 4types of casting 
/*1. static casting:- simple type ,convertd from one datatype to another 
*	is considered as c type casting
*	static_cast<datatype>(value);
*	int a=(int)4.3;
*	int a=static_cast<int>(4.3);
*	double b=static_cast<double>(4.3); 
*	int i=0;
*	float f; //4bytes -32bits  ...1bit for sign , 6 bits for exponential ,23 for integral part
*	
* 
* 
*	2. Dynamic cast : 
*	dynamic_cast<data type>(...)
*	its usally used in inheritance of a class along with runtime polymorphism 
*	A:
*	virtual
* 
*	B:A
* 
*	C:
*		
*	A *p=new A;
*	
*	check if p is belongs to C ??? having thousands of lines of code then how to check ?
*	p1 belongs to C
*	p2 belongs to B
*   A *base =new A;
*	C *ptr=dynamic_cast<C*>(base); base is object of class A  
*	///ptr will become  a nullptr ,if we get nullptr then it doesnt belong to C 
*	
* 
*	B *obj=new B; --Fun1()
*	B *pp=dynamic_cast<B*>(base); //pp has memory if memory has some relation 
*								  // if pp is null then doesnt have any relation 
*	/// dynamic_cast should have virtual function because it looks for virtual table while verifying 
*	
*	3. const_cast<datatype> :
*		we have to either pass a const variable or it will return a const variabel /// rechceck this 
* 
*		void fun(const int *ptr){
*			int *x=const_cast<int*>(ptr);
*			*x=45;
*		}
*		void main()
*		{
*			int a=4;
*			fun(&a);
*			cout <<"value of a "<<a<<endl;
*		}
*		Question: how will chnage /correct the constant correction ???
*	
*		in somecase we are having not const we want to make it to be constant 
*		void fun(int *ptr){
*			int *x=const_cast<int*>(ptr);
*			*x=45; //error becuase we change non const to const 
*		}
*		void main()
*		{
*			int a=4;
*			fun(&a);
*			cout <<"value of a "<<a<<endl;
*		}
*		-----------------------------------------------------------------------------------
* 
*		void fun(const int *ptr){
*			int *x=const_cast<int*>(ptr);
*			*x=45; //no error because we are having const we changed to non const 
*		}
*		void main()
*		{
*			int a=4;
*			fun(&a);
*			cout <<"value of a "<<a<<endl;
*		}
* 
*	--------------------------------------------------------------------------------------------------------
*	class Person
*	{ virtual walk(const int* ptr);
*	}
*	class NK:public Person
*	{
*		virtual walk(int* ptr)
*		{
*			int *x =const_cast<int*> (ptr);
*			*x=45;
		}
*	}
*	void main()
*	{
*	Person *NK1=new NK;
*	int var=4;
*	NK1->walk(&var);
*	var --5;
*	}
* 
*	4.reinterpet_cast<datatype*> bit to bit conversion
*	class A{
*	public:
*	const int i;
*	};
*	class B
*	{
*		public:
*		int j;
*	}
*	A obj;
*	B *ptr=reinterpet_cast<B*>(&obj);
*	ptr->j=94;
* 
* 
*	-------------------------------------------------------------------------------------------------------------------------
*	RTTI RunTime type Identification 
* 
*	dynamic_cast we only get is it has a IS a kind of relation or not ???
*	typeid().name() 
*	void main()
*	{
*		int a;
*		float b;
*		cout<<typeid(a).name()<<typeid(b).name()<<endl;
*				int				float
*		
*	}
* 
* 
*	downcasting
*	Base
*	{
	int y;
	}
* 
*	Dervied :Base
*	{
*	
		int x;
*	}
*	instantiated the dervied ptr but you want now as BASE class 
*	Dervied *ptr=new Derived;
*	Base *p=dynamic_cast<Base*>(ptr);
*	p->y;
*	you cannot acces the x ;
*	Derived *p1=dynamic_cast<Derived*>(ptr);
*	
*	--------------------------------------------------------------------------------------------------------------------
*	class A
*	{
*		public:
*			//int i;
*			mutable int i;
*		int j;
*		void fun() const 
*		{
*			i=34; // no errorr 
*			j=45;// error 
*		}
	};
	void main()
	{
		const A obj;
		obj.i=45; ///errror but you have to change i value so then have add mutable in declaration as above 
		///then we can chnage value though its a const object
		///when we add const 
		
	}

*/
