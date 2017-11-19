#!bin/bash
# rm my_cor
# rm orig_cor
# ./corewar -n -dump 100 resourses/champs/ex.cor >> my_cor
# ./resourses/corewar -d 100 resourses/champs/ex.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> orig_cor
# diff my_cor orig_cor

rm t_files/my_live_d.txt
rm t_files/orig_live_d.txt
./corewar -n -dump 10 resourses/scenario/live_d.cor >> t_files/my_live_d.txt
./resourses/corewar -d 10 resourses/scenario/live_d.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_live_d.txt
diff t_files/my_live_d.txt t_files/orig_live_d.txt


#-------------/ ld /--------------#

rm t_files/my_ld_dr.txt
rm t_files/orig_ld_dr.txt
./corewar -n -dump 10 resourses/scenario/ld_dr.cor >> t_files/my_ld_dr.txt
./resourses/corewar -d 10 resourses/scenario/ld_dr.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_ld_dr.txt
diff t_files/my_ld_dr.txt t_files/orig_ld_dr.txt


rm t_files/my_ld_ir.txt
rm t_files/orig_ld_ir.txt
./corewar -n -dump 10 resourses/scenario/ld_ir.cor >> t_files/my_ld_ir.txt
./resourses/corewar -d 10 resourses/scenario/ld_ir.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_ld_ir.txt
diff t_files/my_ld_ir.txt t_files/orig_ld_ir.txt
