# rshell

A command shell written in C++. It can read in single commands, or multiple commands on one line.  
&&, ||, and ; are connectors for multiple commands.

For &&, the command after && will run only if the command before it sucessfully ran.

For ||, the command after || will run only if the command before it did not successfully run.

The next command after ; will always run.

Anything after # is considered a comment, and will not be ran.

The command test can be used to check if a file or directory exist, and if it is a file or a directory. If using the -e flag, it will return true if the file/directory exists. If using the -f flag, it will return true if it exists and is a file. If using the -d flag, it will return true if it exists and is a directory.

The syntax for the test command is "test -e PATH" or "[ -e PATH ]"

Parentheses can be used to control the precedence of the commands.

---

Known Bugs:

  * Ending or starting a line with a connector will result in an out of range error.
  * Using & or | instead of && or || will act as connectors when parsing the input, but not be stored as connectors, causing errors.
  * The Precedence operator only works if the entered command starts with a parentheses. Starting with a command outside the parentheses causes errors.
       
       For example, "(ls) && echo a" works, but "ls && (echo a)" will not.
  * Semicolons do not work with commands including precedence operators
