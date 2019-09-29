// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the STACKQUEUES_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// STACKQUEUES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef STACKQUEUES_EXPORTS
#define STACKQUEUES_API __declspec(dllexport)
#else
#define STACKQUEUES_API __declspec(dllimport)
#endif

#include <string>

class STACKQUEUES_API IStack {
public:
	virtual bool isEmpty() const = 0;
	virtual bool push(int val) = 0;
	virtual  int top() = 0;
	virtual bool pop() = 0;
	//If the ADT is empty throw an exception indicating this
	virtual int peek() = 0;
	virtual int length() = 0;
	virtual void empty() = 0;
	virtual int get(int n) = 0;
private:
	
};



class STACKQUEUES_API ArrayBasedStack : IStack {
public:
	ArrayBasedStack(void);
	virtual ~ArrayBasedStack();
	bool isEmpty() const override;
	bool push(int val) override;
	bool pop() override;
	int top() override;
	int length();
	void empty() override;
	int get(int n) override;
	//If the ADT is empty throw an exception indicating this
	int peek() override;
private:
	int arr[100];
	int height = 0;
};


class STACKQUEUES_API IQueue {
public:
	virtual bool isEmpty() const = 0;
	virtual bool enQueue(std::string val) = 0;
	virtual bool deQueue() = 0;
	//If the ADT is empty throw an exception indicating this
	virtual std::string peekFront() = 0;
private:

};



class STACKQUEUES_API ArrayBasedQueue : IQueue {
public:
	ArrayBasedQueue(void);
	virtual ~ArrayBasedQueue();
	bool isEmpty() const override;
	bool enQueue(std::string val) override;
	bool deQueue() override;
	//If the ADT is empty throw an exception indicating this
	std::string peekFront() override;
private:
	std::string arr[100];
	int height = 0;
};










