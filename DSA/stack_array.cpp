#include <iostream>
using namespace std;

class stack
{
   public:
   int top;
   int *arr;
   int size;

   stack()
   {
      size = 1000;
      arr = new int[size];
      top = -1;
   }

   stack(int size)
   {
      this -> size = size;
      arr = new int[this -> size];
      top = -1;
   }

   void push(int data)
   {
      if(top == size - 1)
      {
         cout << "Stack Overflow!!" << endl;
      }
      else
      {
         top++;
         arr[top] = data;
      }
   }

   void pop()
   {
      if(top == -1)
      {
         cout << "Stack is empty!!" << endl;
      }
      else
      {
         top--;
      }
   }

   void display()
   {
      if(top == -1)
      {
         cout << "Stack is empty!!" << endl;
      }
      else
      {
         cout << "Stack: " << endl;
         for(int i = top; i > -1; i--)
         {
            cout << arr[i] << " ";
         }
         cout << endl;
      }
   }
};

int main()
{
   stack st(3);
   st.push(1);
   st.display();
   st.push(2);
   st.push(3);
   st.push(4);
   st.display();
   st.pop();
   st.display();
   st.pop();
   st.display();
   st.pop();
   st.display();
   st.pop();
   return 0;
}