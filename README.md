## Banker's Algorithm Implementation

### Author: Cornelius Pavlic
### Spring 2024
### CS-33211 Operating Systems
### Dr. Qiang Guan
### Kent State University

---

**End Goal as per instructions:**

Requirements:

- Use C/C++ in Linux/Unix. Consider installing virtualBox in your non-Linux environment.
- Programs must succeed in compilation and execution as required (80 points).
- Readme, documentation, and examples are required (20 points).

Banker’s Algorithm for deadlock avoidance.

Consider a system with five processes (P0 through P4) and three resources of types A, B, and C. Resource type A has 10 instances, B has 5 instances, and type C has 7 instances. Suppose at time t0, the following snapshot of the system has been taken:

Implement the Banker’s algorithm to answer the following question: Is the system in a safe state? If Yes, then what is the safe sequence?

---

**Steps Taken to Achieve the Goal**

The implementation is split into two major parts: collecting the data from the text file and then completing the Banker's algorithm on the data.

1. **Data Collection:**  
   The data is collected from a text file formatted as follows:
   ```
   5  // Number of processes
   3  // Number of resources 

   3 3 2  // Number of available resources

   7 5 3  // Max required resources for each process
   3 2 2
   9 0 2 
   2 2 2
   4 3 3

   0 1 0  // Allocated resources for each process
   2 0 0
   3 0 2
   2 1 1 
   0 0 2 
   ```

2. **Banker's Algorithm:**  
   After parsing the data, the need matrix is created. Then, loop through the processes, checking to see if they can be fulfilled. If they can be, they are immediately added to the path of safety, and their resources are added to the available resources. Continue with the rest of the processes.

---

**Running the Program:**

Once compiled, run the program with the command `./banker`. It will produce the output:

```
System is in a safe state. Safe sequence is: 
1
3
4
0
2
```

or 

```
System is not in a safe state.
```

---

*(For clarity, this README file has been edited by ChatGPT for spelling, grammar, and clarity. There is also an unedited README should you prefer that.)*