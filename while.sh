#!bin/bash




# if [ $(cat res | wc -c) -eq 0 ]; then
# 		echo '\r' #OK
# 	else
# 		cat res
# fi


find . -name "*file_*" -delete

a=1

# champs/championships/2014/brandazz/Rainbow_dash.cor
# champs/championships/2014/cdivry/youforkmytralala.cor
# champs/championships/2014/clafleur/big_feet.cor
# champs/championships/2014/dcohen/loose.cor
# champs/championships/2014/ekocevar/mandragore.cor
# champs/championships/2014/esusseli/gedeon.cor
# champs/championships/2014/evlasova/terminator.cor
# champs/championships/2014/fcorre/ultimate-surrender.cor
# champs/championships/2014/gbir/_.cor
# champs/championships/2014/gjestin/salamahenagalabadoun.cor
# champs/championships/2014/gleger/Machine-gun.cor
# champs/championships/2014/gmange/corelol.cor
# champs/championships/2014/gpetrov/MarineKing.cor
# champs/championships/2014/gudepard/Kappa.cor
# champs/championships/2014/hmichals/Wall.cor
# champs/championships/2014/hmoutaou/Misaka_Mikoto.cor
# champs/championships/2014/kelickel/Varimathras.cor
# champs/championships/2014/kmonrose/justin_bee.cor
# champs/championships/2014/ldesgoui/_honeybadger.cor
# champs/championships/2014/lseguin/skynet.cor
# champs/championships/2014/lsirigna/live.cor
# champs/championships/2014/mbacoux/meowluigi.cor
# champs/championships/2014/mconraux/dubo.cor
# champs/championships/2014/rabid-on/jinx.cor
# champs/championships/2014/rmasse/THUNDER.cor
# champs/championships/2014/sbuono/Asombra.cor
# champs/championships/2014/srabah-m/littlepuppy.cor
# champs/championships/2014/tdemay/champ.cor
# champs/championships/2014/vrey/darksasuke.cor
# champs/championships/2014/ybouvet/casimir.cor

# cor=`find champs/championships -name $1".cor"`

cor="champs/championships/2014/vrey/darksasuke.cor"
while [ $a -lt 2147483647 ]
do


	my=`./corewar -dump $a $cor`
	orig=`./resourses/corewar -d $a $cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba'`

	if [ "$my" != "$orig" ]; then
		echo "Cycle " $a
		./corewar -dump $a $cor >> "ft_file_"$a".txt"
		./resourses/corewar -d $a $cor | cut -c 10-201 | sed -e :a -e '$q;N;65,$D;ba' >> "file_"$a".txt"
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