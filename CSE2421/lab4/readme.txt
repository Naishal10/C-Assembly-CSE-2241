#Naishal Patel

Part 1:

Q1: What very cool word with Latin roots that starts with a P are we implementing here?

    Profiling

Q2: What are at least one advantage and disadvantage of each implementation?

For Linked Structure:
    The advantage is Dynamic Size.
    The disadvantage is It takes a long time to get data from the middle.
For Array Structure:
    The advantage is faster access time is the index is known.
    The disadvantage is fixed memory size.

Q3: Prior to doing any timing testing, which approach do you think will be faster?

I think the Array structure will be faster. 

Q4: When implementing this, why were void pointers used?

So that any type of data could be stored and fetched.

Part 2:

Q1: It’s possible that the CPU time that we calculate from the above method isn’t actually
completely correct. Why is that?
In the StackTest() function, calculate the clock time used for each and print it to the console at the end of the execution of the function.

It could be possible. Maybe because we are running on the server then it the load is high on the server then the time might take longer then the idle server.

Q2: What is an obvious (but rather silly) way to reduce the CPU time?

The obvious way is you run operations with small amount of data.

Q3: Given your answer to Q2, is CPU time in a vacuum (that is, without any additional context) a good measure of the performance of a program? Why or why not?

Nope, because that is not practical for large data models.

Q4: After seeing the results for the test you wrote, which one was faster? Was it the one you predicted? Was there a stark difference in runtime? Why or why not?
Recompile your source files without the -g flag. Take note of the size of the executables, you’ll need them for Q7. Consider adding targets to your makefile to allow you to compile with
different amounts of optimization!

Yes, it was the one I predicted. It was an Array structure for Stack. It took half the time to execute than the linked data structure. Because arrays have faster data access time.

Q5: Recompile your source files again, but this time without the -g flag and with the -O flag. Rerun them. What happened to the execution times? Why?

The execution time decreases as the -O flag is used for optimization.

Q6: Recompile your source files one more time, but this time without the -g flag and with the -O3 flag. Rerun them. What happened to the execution times? Why?

Recompiling with the -O3 flag applies aggressive optimizations so it take seven less time.

Q7: Compare the file size of the executables created from Q6 against what you created
between Q4 and Q5. Is there a difference? Should we expect there to be?

Yes, there is a difference and yes we should expect it to be.
 
Q8: You may not have noticed, but the compilation time for your programs increased when you increased the amount that the compiler optimized. Why would this increase in compilation time happen?

Higher optimization settings require the compiler to undertake additional work in analyzing and modifying the code for improved efficiency, which lengthens the compilation process.

Q9: This is a critical thinking question. Look up all the variants of the -O flag. Why do we have so many different optimization flags?

Depending on the project and system needs, various optimization flags balance compilation time, performance, and code size.



Part 3:

Q1: Did you spot anything weird about any of your gprof outputs? If so, what were they and why do you think that weirdness occurred? (The answer to this question could also safely be no.)

No

Q2: What functions ended up taking up the most time in each of your implementations?

The most amount was taken by popStack1,  enqueueQueue2, pushStack2, and enqueueQueue1.


Q3: Do you think there is anything you could do to shrink the time spent in each of those
functions? If so, what? (The answer to this question could also safely be no.)

I don’t think so.

Q4: Think back to your answer to Q2 from Part 2. Does profiling suffer from the same sort of shortcomings that timing suffers from? Because of your answer to Q4, it’s often a good idea to profile more than once. The -s flag with gprof can aid in this.

Yes, it could. Because profiling could have some overhead of it own. 


Q5: Read through the manual page for gprof. Pick out any flag you think sounds
interesting/useful and describe why you think it sounds interesting or useful. When submitting this lab, please include all c files used to produce your executables, any test files and gprof output files you used, your makefile, and your readme.

-l flag. This is line-by-line profiling. With this, you can know which line of your code is taking so long to execute.



