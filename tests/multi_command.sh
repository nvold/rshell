#!/bin/sh
cd
cd rshell/bin
./rshell
ls -a ; echo hello ; mkdir test
els -l ; echo how are you && mkdir testDirect || echo world ; ls -l
echo universe ; rmdir testDirect && git status ; ls -l
touch newFile && echo the file has been created ; git status ; ls
echo will now remove the file ; rm newFile && echo file deleted ; ls -l
abc || echo previous command failed cause its not a command, so the or works
rmdir test

