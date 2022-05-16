# 439_FileManagementSystem

Our objective is to create a program to simulate a file management system. The system will be created using tree-structured directories, starting at a root directory. The root directory will contain both files and directories. Each subdirectory can also contain both files and directories. Our goal is to implement functions to: 

Add a file or directory to the current directory,
Remove a file or directory from the current directory,
Rename a file or directory,
List all files and directories in the current directory,
Navigate through directories,
and Display current directory’s name.

We will simulate a file by representing it with a string containing the name of the file. 
The directory will be simulated using a general node class with two subclasses, one for directories and one for files. The general node class will only contain the name of the file or directory and a pointer. The subclasses will contain the methods specific to the functions of either files or directories.

Running program: 
1) in 'dirTree.c', above the makeTdir struct method at the top, change the 'head' string to the desired location of the program's root directory.
2) FleManagement.c is where the program will run "gcc FileManagement.c -o FM" to initialize program and "./FM"to execute if no errors.
