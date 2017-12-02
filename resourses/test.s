.name "Mat"
.comment "Mat
	
T_DIR	%	10
T_IND		11
T_REG	r	01
fail        00	

	1010 // a0
	1011 // b0
	1001 // 90
	1000 // 80
	1111 //	f0
	1110 // e0
	1101 // d0
	1100 // c0
	0101 // 50
	0110 // 60
	0111 // 70
	0100 // 40
	0010 // 20
	0011 // 30
	0001 // 10
	0000 / 0


	1011
	1001
	1000
	
	1110
	1101
	1100
	
	0110
	0111
	0100
	
	0010
	0011
	0001
	0000


"

gen:
	live	%1
	add	r2, r3, r2
	sub	r2, r4, r5
	and	r5, r6, r5
	zjmp	%:ok
	ld	%0, r2
ok:
	live	%1
	fork	%:no
	fork	%:gen
	ld	%0, r5
	zjmp	%:gen
	
no:
	live	%1	
	sti	r8, %:end, r2
	add	r2, r3, r2
	sub	r4, r2, r5	#r4 = r2
	zjmp	%:boucle2
	ld	%0, r5
	zjmp	%:no
	
boucle2:
	ld	%0, r2
	zjmp	%:no

end:	
