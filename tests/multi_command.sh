#!/bin/sh
echo cd
echo cd bin
echo ./rshell
echo ls -a ; echo hello ; mkdir test
echo ls -l ; echo how are you && mkdir testDirec || echo world ; ls -l
echo echo universe ; rmdir testDirect && git status ; ls -l
echo touch newFile && echo the file has been created ; git status ; ls
echo echo will now remove the file ; rm newFile && echo file deleted ; ls -l
echo abc || echo previous command failed cause its not a command, so the or works

