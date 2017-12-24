dump=11000

rm "ft_file.txt"
rm "file.txt"
./corewar -dump $dump "resources/test.cor" >> "ft_file.txt"
./resources/corewar -d $dump "resources/test.cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "file.txt"
diff "ft_file.txt" "file.txt"