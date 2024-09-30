#include<iostream>
#include<queue>
using namespace std;
class MyStack{
	private:
		queue<int>q1,q2;
		public:
			MyStack(){
				//constructor initializes empty queues
			}
			//push element x to the top of the stack.
			void push(int x){
				//push to q2
				q2.push(x);
				//move all elements from q1 to q2
				while(!q1.empty()){
					q2.push(q1.front());
					q1.pop();
				}
				//swap the names from q1 and q2
				swap(q1,q2);
			}
			//removes the element on the top of thevstack and returns it.
			int pop(){
				int topElement=q1.front();
				q1.pop();
				return topElement;
			}
			//get the top element
			int top(){
				return q1.front();
			}
			//returns whether the stack is empty.
			bool empty(){
				return q1.empty();
			}
};
int main(){
	MyStack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<"Top element:"<<s.top()<<endl;
	cout<<"Popped element:"<<s.pop()<<endl;
	cout<<"Top element:"<<s.top()<<endl;
	s.push(40);
	cout<<"Top element after pushing 40:"<<s.top()<<endl;
	cout<<"Popped element:"<<s.pop()<<endl;
	cout<<"popped element:"<<s.pop()<<endl;
	cout<<"Stack empty:"<<s.empty()<<endl;
	s.pop();
	cout<<"Stack empty after popping all elements:"<<s.empty()<<endl;
	return 0;
}