#!/bin/sh

echo cd
echo cd bin
echo ./rshell
ls -l ; touch newFileText && exit
echo ./rshell
rm newFileText && abc || exit

