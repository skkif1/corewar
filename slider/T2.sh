#!bin/bash

# dump=`./corewar -v 2 slider2.cor | tail -n 4 | head -n 1 | cut -c 17-29`

# ./corewar -d $dump slider2.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba'

dump=11000

rm "ft_file.txt"
rm "file.txt"
./ft_corewar -dump $dump "slider2.cor" >> "ft_file.txt"
./corewar -d $dump "slider2.cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "file.txt"
diff "ft_file.txt" "file.txt"



if [[ diff "ft_file.txt" "file.txt" == "" ]]; then
	echo null
fi