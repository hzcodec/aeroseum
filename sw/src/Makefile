CC     = gcc
#CFLAGS = -std=c99 -pedantic -Werror -Wall
CFLAGS = -std=c99

C_FILES = x_plane_instr_ctrl
O_FILES = convert_fp_number.o

f1: convert_fp_number.c
	$(CC) $(CFLAGS) -c convert_fp_number.c -o convert_fp_number.o
	$(CC) convert_fp_number.o x_plane_instr_ctrl.c -o x_plane_instr_ctrl

clean:
	rm -f a.out x_plane_instr_ctrl

clean_all:
	rm -f a.out $(C_FILES) $(O_FILES)






