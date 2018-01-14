.name "Mat"
.comment "Mat"

	ld %100, r2
	sti r1, %100, r2

	ld %32767, r2
	sti r1, %100, r2

	ld %200, r2
	sti r1, %-100, r2

	ld %-300, r2
	sti r1, %100, r2

	ld %-200, r2
	sti r1, %-200, r2

	ld %32769, r2
	sti r1, %100, r2 

	ld %100, r2
	sti r1, %32769, r2

	ld %3000, r2
	sti r1, %3000, r2

	ld %-3000, r2
	sti r1, %-3000, r2

	ld %32767, r2
	sti r1, %100, r2

	ld %500000000, r2
	sti r1, %2000000000, r2
