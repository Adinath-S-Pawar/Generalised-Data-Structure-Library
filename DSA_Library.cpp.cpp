#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
//
//    Class :       QueueX
//    Description : Generic implementation of queue
//    Author :      Adinath Santosh Pawar
//
////////////////////////////////////////////////////////////////////// 
                                                                          
template<class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template<class T>
class QueueX
{
    private:
        struct Queuenode<T> *first;
        int iCount;

    public:
        QueueX();
        void Enqueue(T no);
        T Dequeue();
        void Display();
        int Count();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	QueueX
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				: NONE
//	Description:
//		This is constructor of class QueueX
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
QueueX<T> :: QueueX()
{
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Enqueue
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   entry which is to be added.
//	Description:
//		This function adds node to Queue
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void QueueX<T> :: Enqueue(T no)     //InsertLast
{
    struct Queuenode<T> *newn = NULL;
    struct Queuenode<T> * temp = NULL;

    newn = new Queuenode<T>();

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;

}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Dequeue
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE.
//	Description:
//		This function removes first node from Queue
//
//	Returns					: 
//      T
//      Data which is removed from queue
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T QueueX<T> :: Dequeue()     //DeleteFirst
{
    struct Queuenode<T> *temp = NULL;
    T value = 0;

    if(first == NULL)
    {
        cout<<"Unable to remove as Queue is empty "<<endl;
        return NULL;
    }
    else
    {
        temp = this->first;
        value = temp->data;
        first = first->next;
        delete(temp);

        iCount--;

        return value;
    }
    
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE.
//	Description:
//		This function displays data of queue
//
//	Returns					:   void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void QueueX<T> :: Display()
{
    struct Queuenode<T> * temp = this->first;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Dequeue
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE.
//	Description:
//		This function Counts number of nodes in queue
//
//	Returns					: 
//      int
//      Number of nodes in queue
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int QueueX<T> :: Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////
//
//    Class :       StackX
//    Description : Generic implementation of Stack
//    Author :      Adinath Santosh Pawar
//
////////////////////////////////////////////////////////////////////// 

template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

template<class T>
class StackX
{
    private:
        struct Stacknode<T> *first;
        int iCount;

    public:
        StackX();
        void Push(T no);
        T Pop();
        void Display();
        int Count();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	StackX
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE.
//	Description:
//		This is Constructor of class StackX
//
//	Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
StackX<T> :: StackX()
{
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Push
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T
//      Data to push in stack
//	Description:
//		Push data in stack
//
//	Returns					: 
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void StackX<T> :: Push(T no)     //InsertFirst
{
    struct Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>();

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;

}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Pop
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		Pop topmost data from stack
//
//	Returns					: 
//      T
//      Data which is removed from Stack
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T StackX<T> :: Pop()     //DeleteFirst
{
    struct Stacknode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to pop as stack is empty "<<endl;
        return NULL;
    }
    else
    {
        temp = this->first;
        value = temp->data;
        first = first->next;
        delete(temp);

        iCount--;

        return value;
    }
    

}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		Display data of stack
//
//	Returns					: 
//      void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void StackX<T> :: Display()
{
    struct Stacknode<T> * temp = this->first;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		Count number of nodes in stack
//
//	Returns					: 
//      int
//      Number of nodes in stack
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int StackX<T> :: Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////
//
//    Class :       SinglyCLL
//    Description : Generic implementation of Singly Circular LinkedList
//    Author :      Adinath Santosh Pawar
//
////////////////////////////////////////////////////////////////////// 

template<class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> * next;
};

template<class T>
class SinglyCll
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCll();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no,int pos);
        
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SinglyCll
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				: NONE
//	Description:
//		This is constructor of class SinglyCll
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyCll<T> :: SinglyCll()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
    cout<<"Inside constructor of SinglyCLL \n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				: 
//      T no
//      Holds the entry which is to be added
//	Description:
//		This function adds node at start to Singly circular linked list
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCll<T> :: InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if iCount == 0
    {
        first = newn;
        last = newn;

        last->next = first;
        
    }
    else
    {
        newn->next = first;
        first = newn;
        
        last->next = first;
        
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				: 
//      T no
//      Holds the entry which is to be added
//	Description:
//		This function adds node add end to Singly circular linked list
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCll<T> :: InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if iCount == 0
    {
        first = newn;
        last = newn;
        
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		This function deletes first node of Singly circular linked list
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCll<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete(first);

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete(last->next);

        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		This function deletes last node of Singly circular linked list
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCll<T> :: DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete(first);
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete(last);
        last = temp;
        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		This function displays node data of Singly circular linked list
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCll<T> :: Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = NULL;
    temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    } while (temp != last->next);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		This function counts nodes of Singly circular linked list
//
//	Returns					: 
//      int
//      Number of nodes in Singly circular linked list
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCll<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      int pos
//      Position at which node is to be deleted
//	Description:
//		This function deletes  node at given position of Singly circular linked list
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCll<T> :: DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position \n";
        return;
    }   

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount + 1)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;
        delete target;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:	
//      T no 
//	    Holds the entry to be added
//
//      int pos
//      Position at which node is to be inserted
//
//	Description:
//		This function inserts  node at given position of Singly circular linked list
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCll<T> :: InsertAtPos(T no,int pos)
{
    struct SinglyCLLnode<T> * temp =  NULL;
    struct SinglyCLLnode<T> * newn = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position \n";
        return;
    }   

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;
        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos-1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////
//
//    Class :       DoublyCLL
//    Description : Generic implementation of Doubly Circular LinkedList
//    Author :      Adinath Santosh Pawar
//
////////////////////////////////////////////////////////////////////// 

template<class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template<class T>
class DoublyCLL
{
    private :
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyCLL
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This is constructor of class DoublyCLL
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside Constructor "<<endl;
    first = NULL;
    last = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T no
//      Holds entry to be added
//
//	Description:
//		This function inserts node at start of  DoublyCLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T> ;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // empty LL
    {
        first = newn;
        last = newn;
    }
    else    //atleast 1 node
    {
        newn->next = first;
        first->prev = newn;
                                                                                             
        first = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T no
//      Holds entry to be added
//
//	Description:
//		This function inserts node at end of  DoublyCLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> *  newn = NULL;

    newn = new struct DoublyCLLnode<T> ;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // empty LL
    {
        first = newn;
        last = newn;
    }
    else    //atleast 1 node
    {
        last->next = newn;
        newn->prev = last;

        last = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This function displays node data of  DoublyCLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> *  temp = NULL;
    cout<<"Elements of Linked list are : \n";

    temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"Linked list is empty \n";
        return;
    }
    
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    } while (temp != first);
    cout<<endl;
    
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This function counts nodes of  DoublyCLL
//
//	Returns					: 
//      int
//      Count of nodes in DoublyCLL
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This function deletes first node  of  DoublyCLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)   // ll is empty
    {
        return;
    }
    else if(first == last)  // ll contains single node
    {
        delete(first);
        first = NULL;
        last = NULL;
    }
    else    // more than 1 node
    {
        first = first->next;
        delete(first->prev);    //delete(last->next)

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This function deletes last node  of  DoublyCLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(first == NULL && last == NULL)   // ll is empty
    {
        return;
    }
    else if(first == last)  // ll contains single node
    {
        delete(last);
        first = NULL;
        last = NULL;
    }
    else    // more than 1 node
    {
        last = last->prev;
        delete(last->next);
        
        last->next = first;
        first->prev = last;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T no
//      Holds data to add in DoublyCLL
//
//      int pos
//      position where node is to be inserted
//
//	Description:
//		This function inserts  node at given position of  DoublyCLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> *  temp = NULL;
    struct DoublyCLLnode<T> *  newn = NULL;
    int iCnt = 0;
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T> ;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
        
        iCount++;

    }

}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      int pos
//      position to delete node
//
//	Description:
//		This function deletes  node at given position of  DoublyCLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos) // without target
{
    struct DoublyCLLnode<T> *  temp = NULL;

    int iCnt = 0;
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;

        iCount--;
    }

}

//////////////////////////////////////////////////////////////////////
//
//    Class :       SinglyLL
//    Description : Generic implementation of Singly linear LinkedList
//    Author :      Adinath Santosh Pawar
//
////////////////////////////////////////////////////////////////////// 

template<class T>
struct SinglyLLnode
{
    T data;
    struct SinglyLLnode<T> *next;
};

template<class T>
class SinglyLL
{
    private:
        struct SinglyLLnode<T> * first;
        int iCount;

    public:
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);

        void Display();
        int Count();

};


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SinglyLL
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This function is constructor  of  SinglyLL
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyLL<T> :: SinglyLL()
{
    this->first = NULL;
    this->iCount = 0;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T no
//      Holds data to be inserted
//
//	Description:
//		This function inserts node at start  of  SinglyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct SinglyLLnode<T> * newn = NULL;

    newn = new SinglyLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)  
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T no
//      Holds data to be inserted
//
//	Description:
//		This function inserts node at end  of  SinglyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct SinglyLLnode<T> * newn = NULL;
    struct SinglyLLnode<T> * temp = NULL;

    newn = new  SinglyLLnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)  
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T no
//      Holds data to be inserted
//
//      int pos
//      Position at which node is to be inserted
//
//	Description:
//		This function inserts node at given position  of  SinglyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: InsertAtPos(T no,int pos)
{
    struct SinglyLLnode<T> * temp =  NULL;
    struct SinglyLLnode<T> * newn = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position \n";
        return;
    }   

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new  SinglyLLnode<T>;
        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos-1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		This function deletes node at start  of  SinglyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct SinglyLLnode<T> * temp = NULL;

    if(first == NULL)  
    {
        return;
    }
    else if( (first)->next == NULL) 
    {
        delete(first);
        first = NULL;
    }
    else 
    {
        temp = first;
        first = first->next;
        delete(temp);
    }
    iCount--;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		This function deletes node at end of SinglyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DeleteLast()
{
    struct SinglyLLnode<T> * temp = NULL;

    if(first == NULL)  
    {
        return;
    }
    else if( (first)->next == NULL) 
    {
        delete(first);
        first = NULL;
    }
    else 
    {
        temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    iCount--;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      int pos
//      position of node to be deleted
//
//	Description:
//		This function deletes node at given position of SinglyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DeleteAtPos(int pos)
{
    int i=0;
    struct SinglyLLnode<T> * temp = NULL;
    struct SinglyLLnode<T> * target = NULL;

    if( (pos < 1) || (pos > iCount))
    {
        printf("invalid position \n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1 ; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next; 
        free(target);
        iCount--;
    }

}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		This function displays node data of  SinglyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: Display()
{
    if(first == NULL)
    {
        return;
    }

    struct SinglyLLnode<T> * temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }
    cout<<"NULL \n";
}
      

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		This function counts nodes of SinglyLL
//
//	Returns					: 
//      int
//      Number of nodes
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL<T> :: Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////
//
//    Class :       DoublyLL
//    Description : Generic implementation of Doubly linear LinkedList
//    Author :      Adinath Santosh Pawar
//
////////////////////////////////////////////////////////////////////// 

template<class T>
struct DoublyLLnode
{
    T data;
    struct DoublyLLnode<T> * next;
    struct DoublyLLnode<T> * prev;
};

template<class T>
class DoublyLL
{
    private:
        struct DoublyLLnode<T> * first;
        int iCount;

    public:
        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);

        void Display();
        int Count();

};


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyLL
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//	Description:
//		This function is constructor of DoublyLL class
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
DoublyLL<T> :: DoublyLL()
{
    this->first = NULL;
    this->iCount = 0;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T no
//      Data to be inserted in DoublyLL
//
//	Description:
//		This function inserts node at start of DoublyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct DoublyLLnode<T> * newn = NULL;

    newn = new DoublyLLnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)  
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T no
//      Data to be inserted in DoublyLL
//
//	Description:
//		This function inserts node at end of DoublyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct DoublyLLnode<T> * newn = NULL;
    struct DoublyLLnode<T> * temp = NULL;

    newn = new DoublyLLnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)  
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This function counts nodes of DoublyLL
//
//	Returns					: 
//      int
//      Count of nodes of DoublyLL
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T no
//      Data to be inserted in DoublyLL
//
//      int pos
//      position to insert node
//
//	Description:
//		This function inserts node at given position of DoublyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: InsertAtPos(T no,int pos)
{
    struct DoublyLLnode<T> * temp =  NULL;
    struct DoublyLLnode<T> * newn = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position \n";
        return;
    }   

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyLLnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;                                                                                                        

        temp = first;

        for(i = 1; i < pos-1 ; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This function deletes first node of DoublyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(first == NULL)  
    {
        return;
    }
    else if( (first)->next == NULL) 
    {
        delete(first);
        first = NULL;
    }
    else 
    {
        first = first->next;
        delete(first->prev);
        first->prev = NULL;
    }
    iCount--;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This function deletes last node of DoublyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DeleteLast()
{
    struct DoublyLLnode<T> * temp = NULL;

    if(first == NULL)  
    {
        return;
    }
    else if( (first)->next == NULL) 
    {
        delete(first);
        first = NULL;
    }
    else 
    {
        temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    iCount--;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      int pos
//      position to delete node
//
//	Description:
//		This function deletes node at given position of DoublyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: DeleteAtPos(int pos)
{
    int i=0;
    struct DoublyLLnode<T> * temp = NULL;

    if( (pos < 1) || (pos > iCount))
    {
        printf("invalid position \n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1 ; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;

        iCount--;
    }

}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This function displays node data of DoublyLL
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLL<T> :: Display()
{
    if(first == NULL)
    {
        return;
    }

    struct DoublyLLnode<T> * temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=> ";
        temp = temp->next;
    }
    cout<<"NULL \n";
}

//////////////////////////////////////////////////////////////////////
//
//    Class :       BST
//    Description : Generic implementation of Binary Search Tree
//    Author :      Adinath Santosh Pawar
//
////////////////////////////////////////////////////////////////////// 

template<class T>
struct BSTnode
{
    T data;
    struct BSTnode<T> *lchild;
    struct BSTnode<T> *rchild;
};

template<class T>
class BST
{
    private:
        BSTnode<T>* root;
        int iCount;

    public:
        BST();
        void Insert(T );
        void Inorder();
        void InorderHelper(BSTnode<T> *);
        void Preorder();
        void PreorderHelper(BSTnode<T> *);
        void Postorder();
        void PostorderHelper(BSTnode<T> *);
        bool Search(T );
        int Count();
        int CountLeafNodes();
        void CountLeafNodesHelper(BSTnode<T> *, int&);
        int CountParentNodes();
        void CountParentNodesHelper(BSTnode<T> *, int&);

};


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BST
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   NONE
//
//	Description:
//		This function is constructor of class BST 
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
BST<T> :: BST()
{
    root = NULL;
    iCount = 0;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Insert
//	Function Author			:	Adinath Santosh Pawar
//	Parameters:				:   
//      T no
//      Holds data to insert in tree
//
//	Description:
//		This function inserts node in BST
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: Insert(T no)
{
    BSTnode<T> * newn = NULL;
    BSTnode<T> * temp = NULL;

    newn = new BSTnode<T>;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(root == NULL)      // bst is empty
    {
        root = newn;
        iCount++;
    }
    else        // bst contains atleast one node
    {
        temp = root;

        while(1)    
        {
            if(no == temp->data)
            {
                cout<<"Duplicate element : unable to insert \n";
                delete(newn);
                break;
            }
            else if(no > temp->data)    //rchild
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    iCount++;
                    break;
                }

                temp = temp->rchild;
            }
            else if(no < temp->data)    // lchild
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    iCount++;
                    break;
                }

                temp = temp->lchild;
            }
        }
    }

}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Inorder
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE             
//
//	Description:
//		This function Displays inorder traversal of BST
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: Inorder()
{
    InorderHelper(root);
    cout << "\n";
}

template<class T>
void BST<T> :: InorderHelper(BSTnode<T>* root)
{
    if(root != NULL)
    {
        InorderHelper(root->lchild);
        cout << root->data <<"\t";
        InorderHelper(root->rchild);
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Preorder
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE             
//
//	Description:
//		This function Displays preorder traversal of BST
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: Preorder()
{
    PreorderHelper(root);
    cout <<"\n";
}

template<class T>
void BST<T> :: PreorderHelper(BSTnode<T>* root)
{
    if(root != NULL)
    {
        cout<<root->data<<"\t";
        PreorderHelper(root->lchild);
        PreorderHelper(root->rchild);
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Postorder
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE             
//
//	Description:
//		This function Displays postorder traversal of BST
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void BST<T> :: Postorder()
{
    PostorderHelper(root);
    cout <<"\n";
}

template<class T>
void BST<T> :: PostorderHelper(BSTnode<T>* root)
{
    if(root != NULL)
    {
        PostorderHelper(root->lchild);
        PostorderHelper(root->rchild);
        cout<<root->data<<"\t";
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Search
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :        
//      T no
//      Holds data to search in tree        
//
//	Description:
//		This function search given data of BST
//
//	Returns					: 
//      bool
//      True if data is found 
//      False if data is not found
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
bool BST<T> :: Search(T no)
{
    bool bFlag = false;
    int TimeComplexity = 0;
    BSTnode<T>* first = root;

    while(first != NULL)
    {
        if(no == first->data)
        {
            bFlag = true;
            break;
        }
        else if(no > first->data)
        {
            first = first->rchild;
        }
        else if(no < first->data)
        {
            first = first->lchild;
        }
        TimeComplexity++;
    }
    cout<<"Number of search required is "<<TimeComplexity<<endl;
    return bFlag;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE             
//
//	Description:
//		This function Counts nodes of BST
//
//	Returns					: 
//      int
//      Count of nodes in BST
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int BST<T> :: Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CountLeafNodes
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE             
//
//	Description:
//		This function Counts leaf nodes of BST
//
//	Returns					: 
//      int
//      Count of leaf nodes in BST
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int BST<T>::CountLeafNodes()
{
    int iLeafCnt = 0;
    CountLeafNodesHelper(root, iLeafCnt);  
    return iLeafCnt;
}

template<class T>
void BST<T>::CountLeafNodesHelper(BSTnode<T>* root, int &iCnt) 
{
    if (root != NULL)
    {
        if (root->lchild == NULL && root->rchild == NULL)
        {
            iCnt++;
        }

        CountLeafNodesHelper(root->lchild, iCnt);
        CountLeafNodesHelper(root->rchild, iCnt);
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CountParentNodes
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE             
//
//	Description:
//		This function Counts Parent nodes of BST
//
//	Returns					: 
//      int
//      Count of Parent nodes in BST
//
///////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int BST<T> :: CountParentNodes()
{
    int iParentCnt = 0;
    CountParentNodesHelper(root, iParentCnt);  
    return iParentCnt;
}

template<class T>
void BST<T> :: CountParentNodesHelper(BSTnode<T>* root, int &iCnt)
{
    BSTnode<T> * first = root;
    if(first != NULL)
    {
        if(first->lchild != NULL || first->rchild != NULL)
        {
            iCnt++;
        }
        
        CountParentNodesHelper(first->rchild,iCnt);
        CountParentNodesHelper(first->lchild,iCnt);
    }

}

//////////////////////////////////////////////////////////////////////
//
//    Class :       Sorting 
//    Description : Generic implementation of Sorting Algorithms 
//    Author :      Adinath Santosh Pawar
//
////////////////////////////////////////////////////////////////////// 


template<typename T>
class ArrayXSort   
{
    private:
        T *Arr;
        int iSize;
        bool Sorted;   
        
    public:
        ArrayXSort(int no);
        ~ArrayXSort();
        void Accept();
        void Display();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
       
};


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	ArrayXSort
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   
//      int no
//      Size of Array             
//
//	Description:
//		This function is constructor of class ArrayXSort
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
ArrayXSort<T> :: ArrayXSort(int no)
{
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~ArrayXSort
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE           
//
//	Description:
//		This function is destructor of class ArrayXSort
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
ArrayXSort<T> :: ~ArrayXSort()
{
    delete Arr;

}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Accept
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE           
//
//	Description:
//		This function Accepts input data 
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void ArrayXSort<T> :: Accept()
{
    int i = 0;
    for(i = 0; i < iSize; i++)
    {
        cout<<"Enter the element "<<i+1<<endl;
        cin>>Arr[i];

        if( (i > 0) && (Sorted == true) )  
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE           
//
//	Description:
//		This function displays data 
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void ArrayXSort<T> :: Display()
{
    cout<<"the elements of the array are : \n";

    int i = 0;
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BubbleSort
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE           
//
//	Description:
//		This function Sorts data using Bubblesort algorithm
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void ArrayXSort<T> :: BubbleSort()
{
    int i = 0, j = 0, temp = 0;

    if(Sorted == true)
    {
        return;
    }

    for(i = 0; i < iSize; i++)      // outer loop
    {
        for(j = 0; j < iSize - 1; j++)      // inner loop
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j + 1] = temp;
            }
        }

        cout<<"data after pass "<<i+1<<endl;
        Display();
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BubbleSortEfficient
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE           
//
//	Description:
//		This function Sorts data 
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void ArrayXSort<T> :: BubbleSortEfficient()
{
    int i = 0, j = 0, temp = 0;
    bool bFlag = true;

    if(Sorted == true)
    {
        return;
    }

    for(i = 0; i < iSize && bFlag == true; i++)      
    {
        bFlag = false;
        for(j = 0; j < iSize - 1 - i; j++)     
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j + 1] = temp;

                bFlag = true;
            }
        }

        cout<<"data after pass "<<i+1<<endl;
        Display();
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SelectionSort
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE           
//
//	Description:
//		This function Sorts data using SelectionSort algorithm
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void ArrayXSort<T> :: SelectionSort()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    for (i = 0; i < iSize-1; i++)
    {
        min_index = i;
        for (j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        if(i != min_index) 
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }

    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertionSort
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE           
//
//	Description:
//		This function Sorts data using InsertionSort algorithm
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void ArrayXSort<T> :: InsertionSort()
{
    int i = 0, j = 0, selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i - 1, selected = Arr[i]; (j >=0) && (Arr[j] > selected) ; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}


//////////////////////////////////////////////////////////////////////
//
//    Class :       Searching 
//    Description : Generic implementation of Searching Algorithms 
//    Author :      Adinath Santosh Pawar
//
////////////////////////////////////////////////////////////////////// 


template <typename T>
class ArrayX    
{
    private:
        T *Arr;
        int iSize;
        bool Sorted;   

    public:
        ArrayX(int no);
        ~ArrayX();
        void Accept();
        void Display();
        bool LinearSearch(T no);       
        bool BiDirectionalSearch(T no);       
        bool BinarySearchInc(T no);
        bool BinarySearchEfficientInc(T no);
        bool CheckSortedInc();
       
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	ArrayX
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   
//      int no
//      Size of Array             
//
//	Description:
//		This function is constructor of class ArrayX
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
ArrayX<T> :: ArrayX(int no)
{
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~ArrayX
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE  
//
//	Description:
//		This function is destructor of class ArrayX
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
ArrayX<T>  :: ~ArrayX()
{
    delete Arr;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Accept
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE  
//
//	Description:
//		This function Accepts input data
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void ArrayX<T>  :: Accept()
{
    int i = 0;
    for(i = 0; i < iSize; i++)
    {
        cout<<"Enter the element "<<i+1<<endl;
        cin>>Arr[i];

        if( (i > 0) && (Sorted == true) )  
        {
            if(Arr[i] < Arr[i-1])
            {
                Sorted = false;
            }
        }
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   NONE  
//
//	Description:
//		This function Displays data
//
//	Returns					: void
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void ArrayX<T>  :: Display()
{
    cout<<"the elements of the array are : \n";

    int i = 0;
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<endl;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	LinearSearch
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   
//      T no
//      Holds data to search  
//
//	Description:
//		This function Search given data using LinearSearch Algorithm
//
//	Returns					: 
//      bool
//      True if data is present
//      False if data is not present
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool ArrayX<T>  :: LinearSearch(T no)
{
    int i = 0;
    bool bFlag = 0;

    if(Sorted == true)
    {
        cout<<"Data is sorted \n";
        return BinarySearchEfficientInc(no);
    }

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == no)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BidirectionalSearch
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   
//      T no
//      Holds data to search  
//
//	Description:
//		This function Search given data using BidirectionalSearch Algorithm
//
//	Returns					: 
//      bool
//      True if data is present
//      False if data is not present
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool ArrayX<T>  :: BiDirectionalSearch(T no)
{
    int iStart = 0, iEnd = 0;
    bool bFlag = 0;

    for(iStart = 0, iEnd = iSize-1; iStart <= iEnd; iStart++,iEnd--)
    {
        if(Arr[iSize] == no || Arr[iEnd] == no)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchInc
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   
//      T no
//      Holds data to search  
//
//	Description:
//		This function Search given data using BinarySearchInc Algorithm for data sorted
//      in incremental manner
//
//	Returns					: 
//      bool
//      True if data is present
//      False if data is not present
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool ArrayX<T>  :: BinarySearchInc(T no)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while( iStart <= iEnd)
    {
        iMid = iStart + ( (iEnd - iStart) / 2 );

        if(Arr[iMid] == no)
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])     // first half (left window)
        {
            iEnd = iMid -1 ;
        }
        else if(no > Arr[iMid])     // second half (right window)
        {
            iStart = iMid + 1;
        }
    } // end of while

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchEfficientInc
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   
//      T no
//      Holds data to search  
//
//	Description:
//		This function Search given data using BinarySearchEfficientInc Algorithm for data sorted
//      in incremental manner
//
//	Returns					: 
//      bool
//      True if data is present
//      False if data is not present
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool ArrayX<T>  :: BinarySearchEfficientInc(T no)
{
    if(Sorted == false)        
    {
        cout<<"data is not sorted \n";
        return LinearSearch(no);     
    }

    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while( iStart <= iEnd)
    {
        iMid = iStart + ( (iEnd - iStart) / 2 );

        if(Arr[iMid] == no || Arr[iStart] == no || Arr[iEnd] == no)     
        {
            bFlag = true;
            break;
        }
        else if(no < Arr[iMid])     // first half (left window)
        {
            iEnd = iMid -1 ;
        }
        else if(no > Arr[iMid])     // second half (right window)
        {
            iStart = iMid + 1;
        }
    } // end of while

    return bFlag;

}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CheckSortedInc
//	Function Author			:	Adinath Santosh Pawar
//	Parameters              :   
//      T no
//      Holds data to search  
//
//	Description:
//		This function checks if data is sorted in incremental manner
//
//	Returns					: 
//      bool
//      True if data is sorted
//      False if data is not sorted
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool ArrayX<T>  :: CheckSortedInc()
{
    bool bFlag = true;
    int i = 0;

    for(i = 0; i < iSize-1; i++ )
    {
        if(Arr[i] > Arr[i+1])  
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Entry point function
//	Function Author		:	    Adinath Santosh Pawar	
//
///////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int choice = 0;
    do
    {
        cout << "\n ============================== MAIN MENU ==============================\n";
        cout << "1 : Queue\n";
        cout << "2 : Stack\n";
        cout << "3 : Singly Circular Linked List\n";
        cout << "4 : Doubly Circular Linked List\n";
        cout << "5 : Singly Linear Linked List\n";
        cout << "6 : Doubly Linear Linked List\n";
        cout << "7 : Binary Search Tree\n";
        cout << "8 : Array with Sorting\n";
        cout << "9 : Array with Searching\n";
        cout << "0 : Exit\n";
        cout << "Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            // ---------------- Queue ----------------
            case 1:
            {
                QueueX<int> qobj;
                int qChoice = 0, iVal = 0;
                do 
                {
                    cout << "\n--- Queue Menu ---\n";
                    cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Count\n0. Back\n";
                    cin >> qChoice;
                    switch(qChoice) 
                    {
                        case 1: 
                        { 
                            cout << "Enter value: "; 
                            cin >> iVal; 
                            qobj.Enqueue(iVal); 
                            break; 
                        }
                        case 2: 
                        { 
                            cout << "Dequeued: " << qobj.Dequeue() << endl; 
                            break; 
                        }
                        case 3: 
                        { 
                            qobj.Display(); 
                            break; 
                        }
                        case 4: 
                        { 
                            cout << "Count: " << qobj.Count() << endl; 
                            break; 
                        }
                    }
                } while(qChoice != 0);
                break;
            }

            // ---------------- Stack ----------------
            case 2:
            {
                StackX<int> sobj;
                int sChoice = 0, iVal = 0;
                do 
                {
                    cout << "\n--- Stack Menu ---\n";
                    cout << "1. Push\n2. Pop\n3. Display\n4. Count\n0. Back\n";
                    cin >> sChoice;
                    switch(sChoice) 
                    {
                        case 1: 
                        { 
                            cout << "Enter value: "; 
                            cin >> iVal; 
                            sobj.Push(iVal); 
                            break; 
                        }
                        case 2: 
                        { 
                            cout << "Popped: " << sobj.Pop() << endl; 
                            break; 
                        }
                        case 3: 
                        { 
                            sobj.Display(); 
                            break; 
                        }
                        case 4: 
                        { 
                            cout << "Count: " << sobj.Count() << endl; 
                            break; 
                        }
                    }
                } while(sChoice != 0);
                break;
            }

            // ---------------- Singly Circular Linked List ----------------
            case 3:
            {
                SinglyCll<int> cll;
                int cChoice = 0, ival=0,pos=0;
                do {
                    cout << "\n--- Singly CLL Menu ---\n";
                    cout << "1. InsertFirst\n2. InsertLast\n3. InsertAtPos\n4. DeleteFirst\n5. DeleteLast\n6. DeleteAtPos\n7. Display\n8. Count\n0. Back\n";
                    cin >> cChoice;
                    switch(cChoice) 
                    {
                        case 1: 
                        { 
                            cout << "Enter value: "; 
                            cin >> ival; 
                            cll.InsertFirst(ival); 
                            break; 
                        }
                        case 2: 
                        { 
                            cout << "Enter value: "; 
                            cin >> ival; 
                            cll.InsertLast(ival); 
                            break; 
                        }
                        case 3: 
                        { 
                            cout << "Enter value & pos: "; 
                            cin >> ival >> pos; 
                            cll.InsertAtPos(ival,pos); 
                            break; 
                        }
                        case 4: 
                        { 
                            cll.DeleteFirst(); 
                            break; 
                        }
                        case 5: 
                        {
                             cll.DeleteLast(); 
                             break; 
                        }
                        case 6: 
                        { 
                            cout << "Enter pos: "; 
                            cin >> pos; 
                            cll.DeleteAtPos(pos); 
                            break; 
                        }
                        case 7: 
                        { 
                            cll.Display();
                            break; 
                        }
                        case 8: 
                        { 
                            cout << "Count: " << cll.Count() << endl; 
                            break; 
                        }
                    }
                } while(cChoice != 0);
                break;
            }

            // ---------------- Doubly Circular Linked List ----------------
            case 4:
            {
                DoublyCLL<int> dcll;
                int dChoice=0,val=0,pos=0;
                do 
                {
                    cout << "\n--- Doubly CLL Menu ---\n";
                    cout << "1. InsertFirst\n2. InsertLast\n3. InsertAtPos\n4. DeleteFirst\n5. DeleteLast\n6. DeleteAtPos\n7. Display\n8. Count\n0. Back\n";
                    cin >> dChoice;
                    switch(dChoice) 
                    {
                        case 1: 
                        {
                            cout << "Enter value: "; cin >> val; dcll.InsertFirst(val);
                            break;
                        }
                        case 2: 
                        {
                             cout << "Enter value: "; cin >> val; dcll.InsertLast(val); 
                            break; 
                        }
                        case 3: 
                        {
                             cout << "Enter value & pos: "; cin >> val >> pos; dcll.InsertAtPos(val,pos); 
                            break; 
                        }
                        case 4: 
                        {
                             dcll.DeleteFirst(); 
                            break; 
                        }
                        case 5: 
                        {
                             dcll.DeleteLast(); 
                            break; 
                        }
                        case 6: 
                        {
                             cout << "Enter pos: "; cin >> pos; dcll.DeleteAtPos(pos); 
                            break; 
                        }
                        case 7: 
                        {
                             dcll.Display(); 
                            break; 
                        }
                        case 8: 
                        {
                             cout << "Count: " << dcll.Count() << endl; 
                            break; 
                        }
                    }
                } while(dChoice != 0);
                break;
            }

            // ---------------- Singly Linear Linked List ----------------
            case 5:
            {
                SinglyLL<int> sll;
                int slChoice=0,val=0,pos=0;
                do 
                {
                    cout << "\n--- Singly LL Menu ---\n";
                    cout << "1. InsertFirst\n2. InsertLast\n3. InsertAtPos\n4. DeleteFirst\n5. DeleteLast\n6. DeleteAtPos\n7. Display\n8. Count\n0. Back\n";
                    cin >> slChoice;
                    switch(slChoice) 
                    {
                        case 1: 
                        {
                             cout << "Enter value: "; cin >> val; sll.InsertFirst(val); 
                            break;
                        }
                        case 2: 
                        {
                             cout << "Enter value: "; cin >> val; sll.InsertLast(val);
                             break;
                        }
                        case 3: 
                        {
                             cout << "Enter value & pos: "; cin >> val >> pos; sll.InsertAtPos(val,pos); 
                            break;
                        }
                        case 4: 
                        {
                             sll.DeleteFirst(); 
                            break;
                        }
                        case 5: 
                        {
                             sll.DeleteLast(); 
                            break;
                        }
                        case 6: 
                        {
                             cout << "Enter pos: "; cin >> pos; sll.DeleteAtPos(pos); 
                            break;
                        }
                        case 7: 
                        {
                             sll.Display();
                             break; 
                        }
                        case 8: 
                        {
                             cout << "Count: " << sll.Count() << endl; 
                            break;
                        }
                    }
                } while(slChoice != 0);
                break;
            }

            // ---------------- Doubly Linear Linked List ----------------
            case 6:
            {
                DoublyLL<int> dll;
                int dlChoice=0,val=0,pos=0;
                do 
                {
                    cout << "\n--- Doubly LL Menu ---\n";
                    cout << "1. InsertFirst\n2. InsertLast\n3. InsertAtPos\n4. DeleteFirst\n5. DeleteLast\n6. DeleteAtPos\n7. Display\n8. Count\n0. Back\n";
                    cin >> dlChoice;
                    switch(dlChoice) 
                    {
                        case 1: 
                        {
                             cout << "Enter value: "; cin >> val; dll.InsertFirst(val);
                             break;
                        }
                        case 2: 
                        {
                             cout << "Enter value: "; cin >> val; dll.InsertLast(val); 
                            break;
                        }
                        case 3: 
                        {
                             cout << "Enter value & pos: "; cin >> val >> pos; dll.InsertAtPos(val,pos);
                             break; 
                        }
                        case 4: 
                        { 
                            dll.DeleteFirst();
                             break;
                        }
                        case 5: 
                        {
                             dll.DeleteLast();
                             break;
                        }
                        case 6: 
                        {
                             cout << "Enter pos: "; cin >> pos; dll.DeleteAtPos(pos);
                             break;
                        }
                        case 7: 
                        {
                             dll.Display();
                             break;
                        }
                        case 8: 
                        {
                             cout << "Count: " << dll.Count() << endl;
                             break;
                        }
                    }
                } while(dlChoice != 0);
                break;
            }

            // ---------------- Binary Search Tree ----------------
            case 7:
            {
                BST<int> bobj;
                int bChoice=0,val=0;
                do 
                {
                    cout << "\n--- BST Menu ---\n";
                    cout << "1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Count\n7. CountLeafNodes\n8. CountParentNodes\n0. Back\n";
                    cin >> bChoice;
                    switch(bChoice) 
                    {
                        case 1: 
                        {
                             cout << "Enter value: "; cin >> val; bobj.Insert(val);
                             break;
                        }
                        case 2: 
                        { 
                            bobj.Inorder();
                             break;
                        }
                        case 3: 
                        { 
                            bobj.Preorder();
                             break;
                        }
                        case 4: 
                        { 
                            bobj.Postorder();
                             break;
                        }
                        case 5: 
                        { 
                            cout << "Enter value: "; 
                            cin >> val; 
                            if(bobj.Search(val)) 
                            { 
                                cout << "Found" << endl; 
                            } 
                            else 
                            { 
                                cout << "Not Found" << endl; 
                            } 
                            break; 
                        }
                        case 6: 
                        { cout << "Count: " << bobj.Count() << endl;
                             break;
                        }
                        case 7: 
                        { cout << "Leaf Nodes: " << bobj.CountLeafNodes() << endl;
                             break;
                        }
                        case 8: 
                        { cout << "Parent Nodes: " << bobj.CountParentNodes() << endl;
                             break;
                        }
                    }
                } while(bChoice != 0);
                break;
            }

            // ---------------- ArrayXSort ----------------
            case 8:
            {
                int size; 
                cout << "Enter size: "; 
                cin >> size;
                ArrayXSort<int> arr(size);
                int aChoice=0;
                do 
                {
                    cout << "\n--- ArrayXSort Menu ---\n";
                    cout << "1. Accept\n2. Display\n3. BubbleSort\n4. BubbleSortEfficient\n5. SelectionSort\n6. InsertionSort\n0. Back\n";
                    cin >> aChoice;
                    switch(aChoice) {
                        case 1: 
                        {
                             arr.Accept();
                             break;
                        }
                        case 2: 
                        {
                             arr.Display();
                             break;
                        }
                        case 3: 
                        {
                             arr.BubbleSort();
                             break;
                        }
                        case 4: 
                        {
                             arr.BubbleSortEfficient();
                             break;
                        }
                        case 5: 
                        {
                             arr.SelectionSort();
                            break;
                        }
                        case 6: 
                        {
                             arr.InsertionSort();
                             break;
                        }
                    }
                } while(aChoice != 0);
                break;
            }

            // ---------------- ArrayX ----------------
            case 9:
            {
                int size; 
                cout << "Enter size: "; 
                cin >> size;
                ArrayX<int> arr(size);
                int aChoice=0,val=0;
                do {
                    cout << "\n--- ArrayX Menu ---\n";
                    cout << "1. Accept\n2. Display\n3. LinearSearch\n4. BiDirectionalSearch\n5. BinarySearchInc\n6. BinarySearchEfficientInc\n7. CheckSortedInc\n0. Back\n";
                    cin >> aChoice;
                    switch(aChoice) {
                        case 1: 
                        {
                             arr.Accept();
                              break; 
                        }
                        case 2: 
                        {
                             arr.Display();
                              break; 
                        }
                        case 3: 
                        { 
                            cout << "Enter value: "; cin >> val; 
                            if(arr.LinearSearch(val)) 
                            { 
                                cout << "Found" << endl; 
                            } 
                            else 
                            { 
                                cout << "Not Found" << endl; 
                            } 
                            break; 
                        }
                        case 4: 
                        { 
                            cout << "Enter value: "; cin >> val; 
                            if(arr.BiDirectionalSearch(val)) 
                            { 
                                cout << "Found" << endl; 
                            } 
                            else 
                            { 
                                cout << "Not Found" << endl; 
                            } 
                            break; 
                        }
                        case 5: 
                        { 
                            cout << "Enter value: "; cin >> val; 
                            if(arr.BinarySearchInc(val)) 
                            { 
                                cout << "Found" << endl; 
                            } 
                            else 
                            { 
                                cout << "Not Found" << endl; 
                            } 
                            break; 
                        }
                        case 6: 
                        { 
                            cout << "Enter value: "; cin >> val; 
                            if(arr.BinarySearchEfficientInc(val)) 
                            { 
                                cout << "Found" << endl; 
                            } 
                            else 
                            { 
                                cout << "Not Found" << endl; 
                            } 
                            break; 
                        }
                        case 7: 
                        { 
                            if(arr.CheckSortedInc()) 
                            { 
                                cout << "Sorted" << endl; 
                            } 
                            else 
                            { 
                                cout << "Not Sorted" << endl; 
                            } 
                            break; 
                        }
                    }
                } while(aChoice != 0);
                break;
            }
        }

    } while(choice != 0);

    cout << "\nThank you for using Data Structure Application!\n";

    return 0;
}
