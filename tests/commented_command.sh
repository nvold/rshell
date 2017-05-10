#!/bin/sh
echo cd
echo cd bin
echo ./rshell
ls -l #this is a comment
echo hello world ; ls -a #comment again
mkdir newDirTesting ; echo the directory should be created && ls -l #another comment
rmdir newDirTesting #getting rid of the test directory
exit #Comment for exit
