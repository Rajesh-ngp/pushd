##PUSHD
pushd: pushd [+N | -N | dir]
    Add directories to stack.
    
    Adds a directory to the top of the directory stack, or rotates
    the stack, making the new top of the stack the current working
    directory.  With no arguments, exchanges the top two directories.

    
    Arguments:
      +N	Rotates the stack so that the Nth directory (counting
    		from the left of the list shown by `dirs', starting with
    		zero) is at the top.
    
      -N	Rotates the stack so that the Nth directory (counting
    		from the right of the list shown by `dirs', starting with
    		zero) is at the top.
    
      dir	Adds DIR to the directory stack at the top, making it the
    		new current working directory.
    
    The `dirs' builtin displays the directory stack.
    
    Exit Status:
    Returns success unless an invalid argument is supplied or the directory
    change fails.

##POPD
popd: popd [+N | -N]
    Remove directories from stack.
    
    Removes entries from the directory stack.  With no arguments, removes
    the top directory from the stack, and changes to the new top directory.

    
    Arguments:
      +N	Removes the Nth entry counting from the left of the list
    		shown by `dirs', starting with zero.  For example: `popd +0'
    		removes the first directory, `popd +1' the second.
    
      -N	Removes the Nth entry counting from the right of the list
    		shown by `dirs', starting with zero.  For example: `popd -0'
    		removes the last directory, `popd -1' the next to last.
    
    The `dirs' builtin displays the directory stack.
    
    Exit Status:
    Returns success unless an invalid argument is supplied or the directory
    change fails.

##DIRS
dirs: dirs
    Display directory stack.
    
    Display the list of currently remembered directories.  Directories
    find their way onto the list with the `pushd' command; you can get
    back up through the list with the `popd' command.
    

The Program cmc.c Accepts the above Operations mentioned with description:
1. pushd
2. popd
3. dirs
   
##Arguments the commands Accepts
Pushd:
   [+N | -N | dir]![Screenshot from 2024-08-07 23-21-31]

Popd:
   [+N | -N]
Dirs:
    no Arguments

Note:
dir - path for the directory can be either the relative and absolute path
N - The value of N ranges from 1 to 9 

##Sample run of above Program
![Screenshot from 2024-08-07 23-21-31](https://github.com/user-attachments/assets/93a908fb-8712-44d2-a3b9-185abab66df3)
![Screenshot from 2024-08-07 23-24-39](https://github.com/user-attachments/assets/5a9bf5a2-443a-4369-9b68-07ba8850a654)
![Screenshot from 2024-08-07 23-24-49](https://github.com/user-attachments/assets/0d52c370-f878-4c95-a52e-7afcf5b114c6)
