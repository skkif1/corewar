#!/bin/sh

f=`find . -name \*.cor`

IN=$f


for i in $(echo $IN | tr " " "\n")
do
  dump=`./corewar -v 2 $i | tail -n 3 | head -n 1 | cut -c 17-20`
  ./corewar -d $dump $i | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba'
done
