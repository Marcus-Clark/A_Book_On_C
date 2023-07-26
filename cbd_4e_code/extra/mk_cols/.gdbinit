echo \n
echo \n
echo Hello from .gdbinit\n
pwd
# br translate_letter_grades.c: prn_trans_info
br main.c: main
# br main.c: 29
r -1 /export/local/c/sys/mk_cols/t
