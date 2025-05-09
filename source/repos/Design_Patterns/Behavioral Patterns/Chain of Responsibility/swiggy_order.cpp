#include<iostream>
using namespace std;
// Define the abstract base class for order handlers.
class OrderHandler
{
protected:
	OrderHandler* nextHandler;
public:
	OrderHandler(OrderHandler* nextHandler) :nextHandler(nextHandler) {}
	virtual ~OrderHandler() {} //add virtual destructor to avoid memory leak

	virtual void processOrder(const string& order) = 0;
	//add getter for nextHandler or make it public
	OrderHandler* getNextHandler() const { return nextHandler; }
};
class OrderValidationHandler :public OrderHandler
{
public:
	OrderValidationHandler(OrderHandler* nextHandler) :OrderHandler(nextHandler) {}

	void processOrder(const string& order)
	{
		cout << "Validating order: " << order << endl;
		if (nextHandler)
			nextHandler->processOrder(order);
	}
	~OrderValidationHandler()
	{
		cout << "Validation handler dtor called" << endl;
	}
};
class PaymentProcessingOrder :public OrderHandler
{
public:
	PaymentProcessingOrder(OrderHandler* nextHandler) :OrderHandler(nextHandler) {}
	void processOrder(const string& order)
	{
		cout << "Processing Payment for order: " << order << endl;
		if (nextHandler)
			nextHandler->processOrder(order);
	}
	~PaymentProcessingOrder()
	{
		cout << "PaymentProcessing Handler dtor called" << endl;
	}
};
class OrderPreparationHandler :public OrderHandler
{
public:
	OrderPreparationHandler(OrderHandler* nextHandler):OrderHandler(nextHandler){}

	void processOrder(const string& order)
	{
		cout << "Preparing order :" << order << endl;
		if (nextHandler)
			nextHandler->processOrder(order);
	}
	~OrderPreparationHandler()
	{
		cout << "Order Prepartion HAndler dtor called" << endl;
	}
};

class DeliveryAssignmentHandler:public OrderHandler
{
public:
	DeliveryAssignmentHandler(OrderHandler* nextHandler) :OrderHandler(nextHandler) {}

	void processOrder(const string& order)
	{
		cout << "Processing Order :" << order << endl;
		if (nextHandler)
			nextHandler->processOrder(order);
	}
	~DeliveryAssignmentHandler()
	{
		cout << "DeliveryAssignmentHandler dtor called" << endl;
	}
};
class OrderTrackingHandler :public OrderHandler
{
public:
	OrderTrackingHandler(OrderHandler* nextHandler) :OrderHandler(nextHandler) {}
	void processOrder(const string& order)
	{
		cout << "Tracking order: " << order << endl;
		if (nextHandler)
			nextHandler->processOrder(order);
	}
	~OrderTrackingHandler()
	{
		cout << "OrderTracking Handler dtor called" << endl;
	}
};
int main()
{
	//create a chain of Responsibility for order processing
	OrderHandler* orderProcessingChain = new OrderValidationHandler(
		new PaymentProcessingOrder(
			new OrderPreparationHandler(
				new DeliveryAssignmentHandler(
					new OrderTrackingHandler(nullptr)
				)
			)
		)
	);
	//process an order
	//Simulate an order being placed
	string order = "pizza";
	orderProcessingChain->processOrder(order);

	/*
	OrderHandler* orderTrackingHandler = new OrderTrackingHandler(nullptr);
	OrderHandler* deliveryAssignmentHandler = new DeliveryAssignmentHandler(orderTrackingHandler);
	OrderHandler* orderPreparationHandler = new OrderPreparationHandler(deliveryAssignmentHandler);
	OrderHandler* paymentProcessingHandler = new PaymentProcessingHandler(orderPreparationHandler);
	OrderHandler* orderValidationHandler = new OrderValidationHandler(paymentProcessingHandler);

	// Simulate an order being placed
	std::string order = "Burger and Fries";
	orderValidationHandler->processOrder(order);

	// Clean up by deleting all handler objects
	delete orderValidationHandler;
	delete paymentProcessingHandler;
	delete orderPreparationHandler;
	delete deliveryAssignmentHandler;
	delete orderTrackingHandler;

	//Or use shared pointers so that we don't have to handle cleanup
	*/

	/*
	//Add setters to choose successor or next handler on run-time
	//Hanlder will have setSuccessor func
		orderValidation.setSuccessor(paymentProcessing);
		paymentProcessing.setSuccessor(shipping);
	*/
	// Clean up by deleting all handler objects
	OrderHandler* currentHandler = orderProcessingChain;
	while (currentHandler != nullptr)
	{
		OrderHandler* nextHandler = currentHandler->getNextHandler();
		delete currentHandler;
		currentHandler = nextHandler;
	}
	
	return 0;
}
//output :
//Validating order : pizza
//Processing Payment for order : pizza
//Preparing order : pizza
//Processing Order : pizza
//Tracking order : pizza
//Validation handler dtor called
//PaymentProcessing Handler dtor called
//Order Prepartion HAndler dtor called
//DeliveryAssignmentHandler dtor called
//OrderTracking Handler dtor called