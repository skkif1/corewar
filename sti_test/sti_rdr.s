.name "Mat"
.comment "Mat"

	ld	r2, %100
	sti r1, %100, r2

	ld	r2, 
	sti r1, %100, %32767

	ld	r2, %200
	sti r1, %-100, r2

	ld	r2, %-300
	sti r1, %100, r2

	ld	r2, %-200
	sti r1, %-200, r2

	ld	r2, %32769
	sti r1, %100, r2 

	ld	r2, %100
	sti r1, %32769, r2

	ld	r2, %3000
	sti r1, %3000, r2

	ld	r2, %-3000
	sti r1, %-3000, r2

	ld	r2, %32767
	sti r1, %100, r2

	ld	r2, %500000000	
	sti r1, %2000000000, r2
