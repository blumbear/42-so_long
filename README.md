You Have to  do an .valgrindrc file and put in :

--keep-debuginfo=yes<br/>
--leak-check=full<br/>
--show-leak-kinds=all<br/>
--suppressions=mlx42.supp<br/>
