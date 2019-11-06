// PQueueDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "PQueueDLL.h"


// This is an example of an exported variable
PQUEUEDLL_API int nPQueueDLL=0;

// This is an example of an exported function.
PQUEUEDLL_API int fnPQueueDLL(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CPQueueDLL::CPQueueDLL()
{
    return;
}
