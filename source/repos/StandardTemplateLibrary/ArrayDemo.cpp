//#include<iostream> 
//class Array
//{
//public:
//	Array(int size)
//	{
//		m_Data = (int*)alloca(size);
//	}
//private:
//	int* m_Data;
//
//};
//int main()
//{
//	int size = 5;
//	//int array[size]; give error becuase
//	int array[5]; //allocated on stack 
//	///size==5 should be mentioned at compile time becausee it gets allocated in stack whereas heap it gets allcated in runtime
//	// so with *ptr we can allcoated dynamicaly size mentioning is not neccessary 
//	
//	int* heapArray = new int[size];
//}