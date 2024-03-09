You Have to  do an .valgrindrc file and put in :

--keep-debuginfo=yes
--leak-check=full
--show-leak-kinds=all
--suppressions=mlx42.supp
