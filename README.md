 Replicate a stl libray in c

We have a map , set and vector implementation in C.

Detailed List of APIs and its time complexity will be soon be uploaded.

***VECTOR***
implemented using doubly-linked-list

vec* var=NULL;
1.push_front(&var,int data) : it pushes data in front of the list,its time complexity is O(1),&var is the pointer to vec* variable into which you would like to perform the operation and data is the value you will push.
2.push_back(&var,int data) : it pushes data into the end of the list,parameter description is same as push_front() method,time O(1).
3.insert(&var,vec* pos,int data) : it inserts the data after the pointer pos,time O(1).
4.erase(&var,&vec* pos) : it erases the data which the pos variable points to,time O(1),be sure to pass the address of the of pointer you want to remove.
5.find(&var,int data) : it finds if a data is present in the list or not,if present it will return the pointer to that node and if not found it will return NULL.
6.reverse(&var) : it returns a pointer of vec* type with reverse digits while keeping the main vec* variable the same,time O(N)
7.clean(&var) : it deletes the entire list and returns the initailize the vec* var to NULL.


***SET***
implemented in AVL tree everythings takes O(log N) time.

tree* var=NULL;
1.add(&var,data) : it adds value to the set in sorted order,time O(logN)
2.eraseT(&var,int data) : it removes data from the set,O(logN)
3.search(var,int data) : if data is present it returns a pointer to that pos(tree*) and if not NULL is returned,time O(logN)
4.Itr(var) : it returns a pointer of type vec* this will contain the value of the set in sorted order.
5.destroy(&var) : it deletes the whole tree and make the var points to NULL


***map***
implemented using AVL tree

its method is same as of set but very little difference check the main.c to look into its APIs


***Memory leak check errors is performed by valgrind***

***Caution it is only tested by me so it might happen your program will crash..Please free to report any issues***
 
***These library are only defined for integer type value.Keeping this in mind the code is written in the manner that you can modify the its type and a have any primitive datatype you want***
