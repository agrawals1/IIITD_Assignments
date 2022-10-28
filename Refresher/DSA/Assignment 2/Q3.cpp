#include <iostream>
#include <iterator>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

struct op
{
    string _str;
    int _int;
    bool strint;
};
vector<op> output;
int cmd_cnt = 0;


class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};

int main()
{
    string cmd;
    
        printf("enter command LRUCache to initialise");
        cin >> cmd;
        if(cmd == "LRUCache")
        {
            cmd_cnt++;            
            struct op temp;
            int cap;
            temp._int = 0;
            temp._str = "null";
            temp.strint = true;
            output.push_back(temp);
            printf("enter cache capacity");
            cin >> cap;
            LRUCache cache = LRUCache(cap);

            while(1)
            {
            char opt;
            printf("continue y abort n");
            cin >> opt;
            if(opt == 'n')
            break;
            int  _key, _val;
            
            
            printf("enter command");
            cin >> cmd;
            if(cmd == "put")
        {
            cmd_cnt++;
            temp._str = "null";
            temp._int = 0;
            temp.strint = true;
            output.push_back(temp);
            printf("enter key");
            cin >> _key;
            printf("enter value");
            cin >> _val;
            cache.put(_key, _val);        
        }
        else if (cmd == "get")
        {
            cmd_cnt++;
            printf("enter key");
            cin >> _key;
            int x = cache.get(_key);
            temp._str = "null";
            temp._int = x;
            temp.strint = false;
            output.push_back(temp);
        }
        

        }
        
        }
        else
        {
            printf("enter first command as LRUCache");
            exit;
        }
        
         
    
    for(int i=0;i<cmd_cnt;i++)
    {
        if(output[i].strint)
        std::cout << output[i]._str << "\n";
        else
        std::cout << output[i]._int << "\n";
    }
}