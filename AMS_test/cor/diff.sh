#!bin/bash

sfile=$1

rm orig_${sfile%.*}
rm our_${sfile%.*}

./ft_asm   	$sfile 
mv ${sfile%.*}".cor" "ft_"${sfile%.*}".cor"
./asm 		$sfile 


xxd ${sfile%.*}".cor" >> orig_${sfile%.*}
xxd "ft_"${sfile%.*}".cor" >> our_${sfile%.*}

diff orig_${sfile%.*} our_${sfile%.*}