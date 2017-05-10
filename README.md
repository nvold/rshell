# rshell

A command shell written in C++. It can read in single commands, or multiple commands on one line.  
&&, ||, and ; are connectors for multiple commands.

For &&, the command after && will run only if the command before it sucessfully ran.

For ||, the command after || will run only if the command before it did not successfully run.

The next command after ; wil always run.

Anything after # is considered a comment, and will not be ran.

---

Known Bugs:

  * Ending a line of multiple commands with a connector results in a out of range error.
  * Using & or | instead of && or || will act as connectors when parsing the input, but not be stored as connectors, causing errors.
  * Starting a line of commands with a connector will result in an error.
