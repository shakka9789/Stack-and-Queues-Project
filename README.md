# Stack-and-Queues-Project
Project: Linked-list implementation of Stack and Queue. The operations include insertion, deletion, and print. 

The input file contains a list of pair {<op, data>} where op is either + or -, where + means insert, - means delete, and data is a character string. For example, + Tom, means insert Tom, - Tom means delete Tom. However, the data will not be used after the delete operation.
Your program will construct a stack, then, a queue, all in linked list implementations. Reading from the input pairs, your program will perform operations, given by the pairs, on the Stack. Then, reading the same input pairs, your program will perform operations on a queue.
**************************************
Language: C++
************************************** 
Input (use argv[1]): a text file contain a list of pair {<op, data>}, one pair per text line, where op is either - or +. - means delete, + means insert and data is a character string.
For example,

\+ Tom

\+ Adam

\+ Sean

\+ Michael

-Tom

-Tim
********************************
Outputs: There will be two output files.
********************************
outFile1 (use argv[2]): for stack outputs.
outFile2 (use argv[3]): for queue outputs.