/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
*/

const int INF = 2147483647;

class MinStack {
public:
    /** initialize your data structure here. */
    class StackNode{
        public:
        int val;
        StackNode *next;
        StackNode(int x) : val(x), next(NULL) {};
        StackNode(): next(NULL) {};
    };
    
    StackNode* head;
    StackNode* min;
    
    MinStack() {
         head = new StackNode();
         min = new StackNode(INF);
    }
    
    void push(int x) {
        StackNode *tmp = new StackNode(x);
        tmp->next = head;
        head = tmp;
        
        StackNode *tmp2 = new StackNode(x);
  
        if(x<=min->val){
            tmp2->next = min;
            min = tmp2;
        }else{
            tmp2->val = min->val;
            tmp2->next = min;
            min = tmp2;
        }
    
        //cout<<min->val<<endl;
    }
    
    void pop() {
        if(head->next !=NULL){
            StackNode *tmp = head;
            head = tmp->next;
            delete tmp;
        }
        if(min->next !=NULL){
            StackNode *tmp2 = min;
            min = tmp2->next;
            delete tmp2;
        }
    }
    
    int top() {
        return (head->val);
    }
    
    int getMin() {
        return (min->val);
    }

    
    #if 0
    stack <int> Nom;
    stack <int> Min;
        
    MinStack() {
    }
    
    void push(int x) {
        Nom.push(x);
        if(Min.empty())
            Min.push(x);
        else
            Min.push(x<=Min.top()? x:Min.top());
    }
    
    void pop() {
        if(!Nom.empty()) Nom.pop();
        if(!Min.empty()) Min.pop();
    }
    
    int top() {
        return Nom.top();
    }
    
    int getMin() {
        return Min.top();
    }
    #endif
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
