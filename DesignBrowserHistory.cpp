struct Node {
  
  Node* prev = nullptr;
  Node* next = nullptr;
 
  const string url;
  Node(const string& url) : url(url) {}
};

// A class to represent a browser history
class BrowserHistory {
 public:
  
  BrowserHistory(string homepage) {
    
    curr = new Node(homepage);
  }

  
  void visit(string url) {
    curr->next = new Node(url);
   
    curr->next->prev = curr;
   
    curr = curr->next;
  }

  
  string back(int steps) {
   
    while (curr->prev && steps-- > 0) {
     
      curr = curr->prev;
    }
    
    return curr->url;
  }

  
  string forward(int steps) {
    
    while (curr->next && steps-- > 0) {
      
      curr = curr->next;
    }
    
    return curr->url;
  }

 private:
  // The current node in the history
  Node* curr = nullptr;
};