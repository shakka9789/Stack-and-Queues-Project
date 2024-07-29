# Linked List Stack and Queue Project

This C++ project implements a stack and a queue using a singly linked list. The stack supports standard operations such as push and pop, while the queue supports enqueue and dequeue operations. Both data structures are manipulated based on commands read from an input file.

## Overview

- **listNode**: Represents a node in the linked list.
- **LLStack**: Implements a stack data structure using linked list nodes.
- **LLQueue**: Implements a queue data structure using linked list nodes.
- **main**: The entry point of the program that reads commands from an input file and performs operations on the stack and queue.

## Classes

### `listNode`

- **Purpose**: Represents a node in the linked list.
- **Members**:
  - `string data`: Stores the data for the node.
  - `listNode* next`: Pointer to the next node in the list.
- **Methods**:
  - `printNode(listNode* n, ofstream& outFile)`: Prints the details of the node to the specified output file.

### `LLStack`

- **Purpose**: Implements a stack using a linked list.
- **Members**:
  - `listNode* Top`: Pointer to the top of the stack.
- **Methods**:
  - `push(listNode* newNode)`: Pushes a new node onto the stack.
  - `isEmpty()`: Checks if the stack is empty.
  - `pop(ofstream& outFile)`: Removes the top node from the stack.
  - `buildStack(LLStack& S, ifstream& inFile, ofstream& outFile)`: Builds the stack based on commands from the input file.
  - `printStack(ofstream& outFile)`: Prints the entire stack to the output file.

### `LLQueue`

- **Purpose**: Implements a queue using a linked list.
- **Members**:
  - `listNode* head`: Pointer to the front of the queue.
  - `listNode* tail`: Pointer to the end of the queue.
- **Methods**:
  - `insertQ(listNode* newNode)`: Inserts a new node at the end of the queue.
  - `deleteQ(ofstream& outFile)`: Removes the front node from the queue.
  - `isEmpty()`: Checks if the queue is empty.
  - `buildQueue(LLQueue& Q, ifstream& inFile, ofstream& outFile)`: Builds the queue based on commands from the input file.
  - `printQueue(ofstream& outFile)`: Prints the entire queue to the output file.

## How to Use

### Prerequisites

- **Compiler**: g++ (GNU C++ compiler)
- **Input File**: A text file containing commands for stack and queue operations(inputFile.txt).

### Build and Run

1. **Create Input File**:
   - Prepare an input file (e.g., `input.txt`) with commands for the stack and queue. The format for commands is:
     - `+ data`: Add `data` to the stack or queue.
     - `- data`: Remove `data` from the stack or queue.
     - `? data`: (Not used in the provided code but could be for additional operations).

   Example `inputFile.txt`:
