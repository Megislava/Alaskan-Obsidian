#!/bin/bash
g++ -Wall -g -pedantic "$1"/task01.cpp -o "$1"/a.out || exit 1
for i in $(ls "$1"/data01 | grep _in.txt)
do
    diff -u "$1"/data01/"$(echo "$i" | sed "s/in/ref/")" <("$1"/a.out < "$1"/data01/"$i") || cat "$1"/data01/"$i" && printf "\n"
done