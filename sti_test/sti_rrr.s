.name "Mat"
.comment "Mat"


	ld r2, %100
	ld r3, %100
	sti r1, r2, r3

	ld r2, %32767
	ld r3, %100
	sti r1, r2, r3

	ld r2, %200
	ld r3, %-100
	sti r1, r2, r3

	ld r2, %-300
	ld r3, %100
	sti r1, r2, r3

	ld r2, %-200
	ld r3, %-200
	sti r1, r2, r3

	ld r2, %32769
	ld r3, %100 
	sti r1, r2, r3

	ld r2, %100
	ld r3, %32769
	sti r1, r2, r3

	ld r2, %3000
	ld r3, %3000
	sti r1, r2, r3

	ld r2, %-3000
	ld r3, %-3000
	sti r1, r2, r3

	ld r2, %32767
	ld r3, %100
	sti r1, r2, r3

	ld r2, %500000000	
	ld r3, %2000000000
	sti r1, r2, r3
