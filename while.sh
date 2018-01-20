#!bin/bash




# if [ $(cat res | wc -c) -eq 0 ]; then
# 		echo '\r' #OK
# 	else
# 		cat res
# fi


# find . -name "*file_*" -delete

a=2640

# cor=`find champs/championships -name $1".cor"`

cor="resourses/test.cor"
while [ $a -lt 200000 ]
do


	my=`./corewar -dump $a $cor`
	orig=`./resourses/corewar -d $a $cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba'`

	if [ "$my" != "$orig" ]; then
		echo "Cycle " $a
		./corewar -dump $a $cor >> "ft_file_"$a".txt"
		./resourses/corewar -d $a $cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "file_"$a".txt"
		break
	fi

	# if [ $(cat res | wc -c) -eq 0 ]; then
	# 	echo '\r' #OK
	# else
	# 	cat res
	# 	#break
	# fi
	# rm res
	a=`expr $a + 1`
done		