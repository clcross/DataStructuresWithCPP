set terminal postscript color
set output "AVL_better.ps"
set ylabel "time (seconds)"
set xlabel "size (10000)"

plot [:][:] "datafiles/AVLTreeHeight.txt" using 1:2 with line, "datafiles/SplayTreeHeight.txt" using 1:2 with line
