// cpp version
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        int res = stack2.top();
        stack2.pop();
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }

        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

//2. You don't need to do it every time. Just pop stack1 if stack2 if empty.
int pop() {
    if (stack2.empty()) {
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    int res = stack2.top();
    stack2.pop();

    return res;
}