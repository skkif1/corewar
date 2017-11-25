#!bin/bash
# rm my_cor
# rm orig_cor
# ./corewar -n -dump 100 resourses/champs/ex.cor >> my_cor
# ./resourses/corewar -d 100 resourses/champs/ex.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> orig_cor
# diff my_cor orig_cor


./resourses/scenario/asm *.s

liv="live"
echo $liv" test"
rm t_files/my_live_d.txt
rm t_files/orig_live_d.txt
./corewar -n -dump 10 resourses/scenario/live_d.cor >> t_files/my_live_d.txt
./resourses/corewar -d 10 resourses/scenario/live_d.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_live_d.txt
diff t_files/my_live_d.txt t_files/orig_live_d.txt


#-------------/ ld /--------------#
echo "ld_dr test"
rm t_files/my_ld_dr.txt
rm t_files/orig_ld_dr.txt
./corewar -n -dump 10 resourses/scenario/ld_dr.cor >> t_files/my_ld_dr.txt
./resourses/corewar -d 10 resourses/scenario/ld_dr.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_ld_dr.txt
diff t_files/my_ld_dr.txt t_files/orig_ld_dr.txt

echo "ld_ir test"
rm t_files/my_ld_ir.txt
rm t_files/orig_ld_ir.txt
./corewar -n -dump 10 resourses/scenario/ld_ir.cor >> t_files/my_ld_ir.txt
./resourses/corewar -d 10 resourses/scenario/ld_ir.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_ld_ir.txt
diff t_files/my_ld_ir.txt t_files/orig_ld_ir.txt


#----------------/ st /------------------#


echo "st_rr test"
rm t_files/my_st_rr.txt
rm t_files/orig_st_rr.txt
./corewar -n -dump 10 resourses/scenario/st_rr.cor >> t_files/my_st_rr.txt
./resourses/corewar -d 10 resourses/scenario/st_rr.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_st_rr.txt
diff t_files/my_st_rr.txt t_files/orig_st_rr.txt


#--------------/ add /--------------------#

echo "add_rrr test"
rm t_files/my_add_rrr.txt
rm t_files/orig_add_rrr.txt
./corewar -n -dump 50 resourses/scenario/add_rrr.cor >> t_files/my_add_rrr.txt
./resourses/corewar -d 50 resourses/scenario/add_rrr.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_add_rrr.txt
diff t_files/my_add_rrr.txt t_files/orig_add_rrr.txt

#--------------/ sub /--------------------#

echo "sub_rrr test"
rm t_files/my_sub_rrr.txt
rm t_files/orig_sub_rrr.txt
./corewar -n -dump 50 resourses/scenario/sub_rrr.cor >> t_files/my_sub_rrr.txt
./resourses/corewar -d 50 resourses/scenario/sub_rrr.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_sub_rrr.txt
diff t_files/my_sub_rrr.txt t_files/orig_sub_rrr.txt

#--------------/ or /--------------------#

echo "or_rrr test"
rm t_files/my_or_rrr.txt
rm t_files/orig_or_rrr.txt
./corewar -n -dump 50 resourses/scenario/or_rrr.cor >> t_files/my_or_rrr.txt
./resourses/corewar -d 50 resourses/scenario/or_rrr.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_or_rrr.txt
diff t_files/my_or_rrr.txt t_files/orig_or_rrr.txt

echo "or_irr test"
rm t_files/my_or_irr.txt
rm t_files/orig_or_irr.txt
./corewar -n -dump 50 resourses/scenario/or_irr.cor >> t_files/my_or_irr.txt
./resourses/corewar -d 50 resourses/scenario/or_irr.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_or_irr.txt
diff t_files/my_or_irr.txt t_files/orig_or_irr.txt


echo "or_drr test"
rm t_files/my_or_drr.txt
rm t_files/orig_or_drr.txt
./corewar -n -dump 50 resourses/scenario/or_drr.cor >> t_files/my_or_drr.txt
./resourses/corewar -d 50 resourses/scenario/or_drr.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_or_drr.txt
diff t_files/my_or_drr.txt t_files/orig_or_drr.txt

echo "or_rir test"
rm t_files/my_or_rir.txt
rm t_files/orig_or_rir.txt
./corewar -n -dump 50 resourses/scenario/or_rir.cor >> t_files/my_or_rir.txt
./resourses/corewar -d 50 resourses/scenario/or_rir.cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> t_files/orig_or_rir.txt
diff t_files/my_or_rir.txt t_files/orig_or_rir.txt

val="or_rdr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="or_idr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="or_dir"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"

#--------------------/ zjmp /-------------------#

val="zjmp"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"

#-------------------------/ ldi /---------------------#

val="ldi_rrr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"

val="ldi_rdr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"

val="ldi_drr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"

val="ldi_ddr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"

val="ldi_idr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="ldi_irr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"

#--------------------- sti -----------------#

val="sti_rrd"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="sti_rrr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="sti_rdd"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="sti_rid"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="sti_rir"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"

val="sti_rdr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"

#----------------- lld ----------------#


val="lld_dr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="lld_ir"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


#------------------ lldi ---------------------#


val="lldi_rdr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="lldi_rrr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"



val="lldi_ddr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="lldi_drr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"


val="lldi_idr"
echo $val" test"
./resourses/scenario/asm "resourses/scenario/"$val".s"
rm "t_files/my_"$val".txt"
rm "t_files/orig_"$val".txt"
./corewar -n -dump 50 "resourses/scenario/"$val".cor" >> "t_files/my_"$val".txt"
./resourses/corewar -d 50 "resourses/scenario/"$val".cor" | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "t_files/orig_"$val".txt"
diff "t_files/my_"$val".txt" "t_files/orig_"$val".txt"
