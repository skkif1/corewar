#!bin/bash

# dump=`./corewar -v 2 slider2.cor | tail -n 4 | head -n 1 | cut -c 17-29`

# ./corewar -d $dump slider2.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba'

dump=$1

rm "ft_file.txt"
rm "file.txt"
./corewar -dump $dump "resourses/test.cor" >> "ft_file.txt"
./resourses/corewar -d $dump "resourses/test.cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "file.txt"
diff "ft_file.txt" "file.txt"

diffs=`diff "ft_file.txt" "file.txt"`


if [[ $diffs == "" ]]; then
	echo $dump
fi