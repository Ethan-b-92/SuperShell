# SuperShell
 Expanding normal shell functions in UNIX CentOS 7

New commands:
- runC: receives file name and location of a .C file, compiles, and runs it. (deletes any files creates in the proccess)
- lockCMD: receives a name of a shell command and a string password. locks the command, meaning any future uses will require the stated password.
- unlockCMD: receives a name of a shell command and a string password. unlocks commands that has been locked.
- concatFiles: receives 2 file paths and a string name. Creates a new file with said name and contents of both said files. (if a file with a said name exists, writes over it)
- distABC: receives a string of a text file name. prints to screen a distribution of letters in the file by precentage(not case sensitive). (letters that dont exist in the file don't show in the distribution)
- uppercase: receives a text file name and a new string. creates a new text file with the given string as the name and the text of the given text file, where all the lowercase letters are changed to uppgercase letters. (if a file with a said name exists, writes over it)
- lowercase: receives a text file name and a new string. creates a new text file with the given string as the name and the text of the given text file, where all the uppercase letters are changed to lowercase letters. (if a file with a said name exists, writes over it)
- randomfiles: receives an ineteger 'x' and a string filename. creates a file and writes x random letters to it(uppercase or lowercase)(if a file with a said name exists, writes over it)
- putLetter: receives a char, an integer 'x' and string filename. writes to the end of the given file the given char x times.(writes over any existing file with said name and creates a new file if a file with said name doesn't exist)
- byebye: exits the SuperShell and returns to the original shell.

* SuperShell runs any existing original Shell commands too.
