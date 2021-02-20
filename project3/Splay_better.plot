set terminal postscript color
set output "Splay_better.ps"
set ylabel "time (seconds)"
set xlabel "size (10000)"

plot [:][0:0.00018] "datafiles/AVLTreeInsert.txt" using 1:2 with line, "datafiles/SplayTreeInsert.txt" using 1:2 with line
