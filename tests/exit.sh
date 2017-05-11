#!/bin/sh

cd
cd rshell/bin
./rshell
ls -l ; touch newFileText && exit
echo ./rshell
rm newFileText && abc || exit

