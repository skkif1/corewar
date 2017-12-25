dump=25000

rm "ft_file.txt"
rm "file.txt"
./corewar -dump $dump "resourses/test.cor" >> "ft_file.txt"
./resourses/corewar -d $dump "resourses/test.cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "file.txt"
diff "ft_file.txt" "file.txt"