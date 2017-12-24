#!/bin/sh

f=`find . -name \*.cor`

IN=$f


for i in $(echo $IN | tr " " "\n")
do
  echo $i
done
