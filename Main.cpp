#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class listNode { //Node class 
  public:
    string data;
    listNode* next;

    listNode(string d) { //constructor
      data = d;
      next = NULL;
    }

    void printNode(listNode* n, ofstream& outFile) { //method to print nodes details
      if(n->next == NULL){
      outFile << "(" + n->data + ", null) -> ";
      }else{
    outFile << "(" + n->data + ", " + n->next->data + ") -> ";
        }
  }

};

class LLStack {	//linkedlist stack
  public:
    listNode* Top = NULL;
    LLStack(){
      Top = new listNode("dummy");	//"dummy" node for Top of stack
    }

    void push(listNode* newNode){	//push method
      newNode->next = Top;
      Top = newNode;
    }


    bool isEmpty() {	//check if stack is empty
      if (Top->next == NULL){
        return true;
      }
      return false;
    }

    listNode* pop(ofstream& outFile) {	//delete top of stack
      if (!isEmpty()) {
        listNode* temp = Top;
        Top = Top->next;
        return temp;

      } else {
        outFile<<"stack is empty"<<endl;
        return NULL;
      }
    }

    void buildStack(LLStack& S, ifstream& inFile, ofstream& outFile) {	//read data from inputfile method

        string op, data;
        while (inFile >> op >> data)
        {
          if (op == "+") {
            listNode * newNode = new listNode(data);
            S.push(newNode);
            outFile<< op << " "<< data <<" added to stack"<<endl;
          }else if (op == "-"){
            S.pop(outFile);
            outFile<<op<< " "<<data<<" removed from stack"<<endl;
          } else {
            outFile<<" Error "<<endl;
          }
          outFile<<"Top -> ";
          S.printStack(outFile);
          outFile<<"null"<<endl;
        }


    }

    void printStack(ofstream& outFile){		//print entire stack
        listNode* temp = Top;
        while (temp->next != NULL)
        {
          temp->printNode(temp,outFile);
          temp = temp->next;
        }


    }

};


class LLQueue{		//linked list queue
  public:
  listNode* head;
  listNode* tail;
  LLQueue() {
    listNode* dummy = new listNode("dummy");
    head = dummy;
    tail = dummy;
  }


    void insertQ(listNode* newNode) {		//insertion method
    tail->next = newNode;
    tail = newNode;
    }


    listNode* deleteQ(ofstream& outFile) {		//delete method
      if (!isEmpty()) {
        listNode* temp = head->next->next;
          head->next = temp;
      } else {

        cout<< "Queue is empty"<<"\n";
      }
      return head;
    }

    bool isEmpty() {		//check if empty
      if (head == tail ) {
        return true;
      }
      return false;
    }



    void buildQueue(LLQueue& Q, ifstream& inFile, ofstream& outFile) {		//read data from input file and builds the queue
        string op, data;
        while (inFile >> op >> data)
        {
          if (op == "+") {
            outFile<< op << " "<< data <<" Insert "<<endl;
            listNode* newNode = new listNode(data);
            Q.insertQ(newNode);
          }else if (op == "-"){
            outFile<< op << " "<< data <<" Delete "<<endl;
            Q.deleteQ(outFile);
          } else {
            outFile<<" Error "<<endl;
          }
          outFile<<"Head -> ";
          Q.printQueue(outFile);
          outFile<<" null"<<endl;
          outFile<<"Tail -> ("<< tail->data << ", null)"<<endl;
        }


    }



    void printQueue(ofstream& outFile) {		//prints queue
      if (isEmpty()){
        outFile<<"queue is empty";
      }else {
        listNode* temp = head;

        while (temp->next != NULL)
        {
          temp->printNode(temp,outFile);
          temp= temp->next;
        }
      }
    }


};




int main(int argc, const char* argv[]) {

  ifstream inFile;
  ofstream outFile1, outFile2;

  inFile.open(argv[1]);	//need 3 args input output1 and output2
  outFile1.open(argv[2]);
  outFile2.open(argv[3]);

  LLStack S;
  S.buildStack(S,inFile,outFile1);

  inFile.close();
  inFile.open(argv[1]);

  LLQueue Q;
  Q.buildQueue(Q,inFile,outFile2);

  inFile.close();

  return 0;
};