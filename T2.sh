#!bin/bash

dump=`./resourses/corewar -v 2 champs/ex.cor | tail -n 3 | head -n 1 | cut -c 17-20`

./resourses/corewar -d $dump champs/ex.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba'









val="lldi_ddr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"