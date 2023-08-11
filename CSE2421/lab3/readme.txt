/*Naishal Patel*/

Part 1:

Q1: How do the elements of your file system structure differ from the nodes of the linked
structures we discussed in class?

The file structure do not have a parent node or child node. The directory structure had arra of directory and have a parent node. Yet, they are much different from linked structures we discussed in class

Q2: You may have to print that you are at the root directory with no children. How will you
convey to the user that there is a directory here with no children, rather than simply printing nothing?

I’ll print the name of the root and print nothing below it to convey that there is no children.

Q3: Do you think “terse” insertion and deletion functions (similar to what we discussed in class) are possible with this lab?

It is possible with this lab.

Part 2:

Q1: What extra commands did you choose to implement? Why?

I chose to implement:
fedit: to edit the content of the file.
Blank: to clear the content of the file.
search : to see if any file with that name exist in the system.


Q2: Did you use any other data structures to help with the extra commands? Why or why not?

No, because it was build on top of the structures that already exists.

Q3: What was the motivation for displaying the directory structure in the way that you did?

The motivation was the ladder structure to symbolise the hierarchy of the files.

Part 3:

Q1: Provide a full set of instructions for how to run your program at the top of your readme
(after your name).

Steps:
Enter “make  lab3” in commandline.
Then enter “lab3”
Then write commands like you enter in command line.
Write help for documentation.

Q2: How did you handle the case where the provided directory had more than 64 items in it?
There are two counters for files and directory. If the sum of those goes above 64 then it wont allow to make file or directory and will print out the message.

Q3: Please include a set of Linux commands to create a test directory for the above
Functionality.

“mkdir dir1”, 64 times.
Or 
“file file1”, 64 times
Or 
“mkdir dir1”, 32 times.
And 
“file file1”, 32 times


Q4: How did you handle the case where the command line argument provided wasn’t a valid directory? Should such cases be your responsibility to handle? Why or why not?

It will print out invalid argument. It is my responsibility to handle.

