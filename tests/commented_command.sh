#!/bin/sh
cd
cd bin
./rshell
ls -l #this is a comment
echo hello world ; ls -a #comment again
mkdir newDirTesting ; echo the directory should be created && ls -l #another comment
exit #Comment for exit
