#!/bin/bash
g++ -Wall -g -pedantic "$1"/main.cpp -o "$1"/a.out || exit 1
for i in $(ls "$1"/sample | grep _in.txt)
do
    diff -u "$1"/sample/"$(echo "$i" | sed "s/in/ref/")" <("$1"/a.out < "$1"/sample/"$i") || cat "$1"/sample/"$i" && printf "\n"
done