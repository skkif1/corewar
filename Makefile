
all	:
		make -C asmblr/
		make -C vm/
		mv asmblr/asm ./asm
		mv vm/corewar ./corewar

clean	:
		make clean -C asmblr/
		make clean -C vm/


fclean	:
		make fclean -C asmblr/
		make fclean -C vm/
		rm asm
		rm corewar

re	:	fclean	all
