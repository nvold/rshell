# rshell

A command shell written in C++. It can read in single commands, or multiple commands on one line.  
&&, ||, and ; are connectors for multiple commands, with # meaning everything else is a comment.

---

Known Bugs:

  * Ending a line of multiple commands ending with a connector results in a out of range error
  * Using & or | instead of && || will act as connectors when parsing the input, but not be stored as connectors, causing errors
