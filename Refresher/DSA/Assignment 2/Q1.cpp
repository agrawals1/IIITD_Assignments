#include<string.h>
#include<stdlib.h>
#include <bits/stdc++.h> 
using namespace std; 

struct ip
{
    string str;
    int val;
    bool strint;
};
vector<struct ip> op_arr;
string tmp_str = "";
string cmd_str;
string ip_str;
char c;

struct Stack {
    int top;
    unsigned cap;
    char* array;
};
struct Stack *l, *r;



struct Stack* createStack(unsigned cap)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->array = (char*)malloc(stack->cap * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack)
{
     if(stack->top == stack->cap - 1)
     return true;
     return false;

}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}   

void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->top++;
    stack->array[stack->top] = item;
    printf("%c pushed to stack\n", item);
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("stack empty, cant pop");
        return -1;
    }
    int pop = stack->array[stack->top--];
    printf("%c popped from stack\n", pop);
    return pop;
}



void addText(string &text, int n) {
    int i=0;
        while(n){
            push(l, text[i]);
            i++;
            n--;
        }
    }

int deleteText(int k) {
        int cnt=0;
        while(!isEmpty(l) && k>0){
            pop(l);
            cnt++;
            k--;
        }
        return cnt;
    }    

    string ShiftHelper(){
    
    int cnt=10;
    int i=0;
    tmp_str.clear();
    while(!isEmpty(l) && cnt>0){
        char c = pop(l);
        tmp_str+= c;
        cnt--;
        i++;
    }
    reverse(tmp_str.begin(),tmp_str.end());
    int j=0;
    while(j<tmp_str.length()){
        push(l, tmp_str[j]);
        j++;
    }
    return tmp_str;
}
  string cursorLeft(int k) {
        while(!isEmpty(l) && k>0){
            char c = pop(l);
            push(r, c);
            k--;
        }
		
        return ShiftHelper();
    }

     string cursorRight(int k) {
       while(!isEmpty(r) && k>0){
            char c = pop(r);
            push(l, c);
            k--;
        }
		
        return ShiftHelper();
    }



 
    int main()
    {
        
        while(1)
        {
            struct ip temp;
            
            cout << "press y to continue, n to show results" << endl;
            cin >> c;
            if(c == 'n')
            break;
            cout << "Enter command, enter TextEditor if its the first command";
            cin >> cmd_str;          
            cout << "Enter input";
            cin >> ip_str;

                 if(cmd_str == "TextEditor")
            {
                l = createStack(100);
                r = createStack(100);
                temp.str.clear();
                temp.str = "null";
                temp.val = 0;
                temp.strint = true;
                op_arr.push_back(temp);

            }
         
            else if(cmd_str == "addText")
            {
                temp.str.clear();
                temp.str = "null";
                temp.val = 0;
                temp.strint = true;
                op_arr.push_back(temp);
                addText(ip_str, ip_str.length());
            }
            else if(cmd_str == "deleteText")
            {
                temp.str.clear();
                temp.val = stoi(ip_str);
                temp.strint = false;                
                temp.val = deleteText(temp.val);                
                op_arr.push_back(temp);
            }
             else if(cmd_str == "cursorRight")
            {
                temp.str.clear();
                temp.val = stoi(ip_str);
                temp.str = cursorRight(temp.val);
                temp.strint = true;
                op_arr.push_back(temp);
            }
             else if(cmd_str == "cursorLeft")
            {
                temp.str.clear();
                temp.val = stoi(ip_str);
                temp.str = cursorLeft(temp.val);
                temp.strint = true;
                op_arr.push_back(temp);
            }
            
        }

        for(int i=0;i<op_arr.size();i++)
        {
            if(op_arr[i].strint)
            cout << op_arr[i].str << '\n';
            else
            cout << op_arr[i].val << '\n';
        }

       
        
    }