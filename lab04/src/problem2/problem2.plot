set terminal postscript color
set output "problem2/problem2Graph.ps"
set ylabel "time (seconds)"
set xlabel "size (i)"

plot [:][:] "problem2/problem2.txt" using 1:2 with line