CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall

X_FILES = x_plane_instr_ctrl
C_FILES = x_plane_instr_ctrl.c
O_FILES = convert_fp_number.o

f1: convert_fp_number.c
	$(CC) $(CFLAGS) -c convert_fp_number.c -o convert_fp_number.o
	$(CC) $(O_FILES) $(C_FILES) -o x_plane_instr_ctrl

clean:
	rm -f a.out x_plane_instr_ctrl

clean_all:
	rm -f a.out $(X_FILES) $(O_FILES)






