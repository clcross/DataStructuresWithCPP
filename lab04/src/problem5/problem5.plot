set terminal postscript color
set output "problem5/problem5Graph.ps"
set ylabel "time (seconds)"
set xlabel "size (i)"

plot [:][:] "problem5/problem5.txt" using 1:2 with line