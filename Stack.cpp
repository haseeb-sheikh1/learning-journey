#include<iostream>
using namespace std;
// IMPLEMENTING STACK USING ARRAY
class Stack {
		int arr[100];
		int top;

	public:
		Stack() {
			top = -1;
		}

		void push(int value) {
			if(top == 99) {
				return;
			}
			arr[++top]=value;
		}
		void pop() {
			if(top == -1) {
				return;
			}
			top--;
		}
		int peek() {
			if(top == -1) {
				return -1;
			}
			return arr[top];
		}
};
int main() {

	Stack S;
	S.push(12);
	cout << S.peek();
	return 0;
}

//  IMPLEMENTING STACK USING A LINKED LIST
#include<iostream>
using namespace std;
class Node {
	public:
		int data;
		Node* next;
};
class Stack {
		Node* top;
	public:
		Stack() {
			top=nullptr;
		}
		void push(int value) {

			Node* temp = new Node();
			temp->data = value;
			temp->next = top;
			top = temp;

		}
		void pop() {
			if (top == nullptr) {
				return;
			}
			Node* temp = top;
			top = top->next;
			delete temp;
		}
		int peek() {
			if (top == nullptr) {
				return -1;
			}
			return top->data;
		}
};
int main() {
	Stack S;
	S.push(12);
	S.push(13);
	cout << S.peek();

	return 0;
}