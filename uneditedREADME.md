## Kent-CS-33211-OS-Banker-s-Algorithm-

# Author: Cornelius Pavlic

# Spring 2024

# CS-33211 Operating Systems

# Dr. Qiang Guan

# Kent State University

**End Goal as per instructions:**

Requirements:

You are required to use C/C++ in Linux/Unix. You can consider installing virtualBox in your non-Linux environment.
Programs must succeed in compilation and execution as required (80 points)
Readme, documentation, and example are required (20 points).
 
Banker’s Algorithm for deadlock avoidance.

Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken:


Implement the Banker’s algorithm to answer the following question： Is the system in a safe state? If Yes, then what is the safe sequence?


**Steps Taken to Achieve the Goal**

The implementation is split into two major parts: collecting the data from the text file and then completing the banker's algorithm on the data. First I collect the data from the text file. it is formatted like this 
```
5  // Number of processes
3  // Number of resources 

3 3 2  // number of available resources

7 5 3  // max required resources for each process
3 2 2
9 0 2 
2 2 2
4 3 3

0 1 0  // allocated resources for each process
2 0 0
3 0 2
2 1 1 
0 0 2 
```

after parsing the data, I create the need matrix. Then loop through the processes, checking to see if they can be fufilled. If they can be I immediately add them to the path of safety, then add their resources to the available resources. And continue with the rest of the processes. 

**Running the processes:**

Once compiled, it can be run with the command ./banker and will produce the output:

```
System is in safe state safe sequence is: 
1
3
4
0
2
```

or 

```
System is not in safe state
```

