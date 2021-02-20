set terminal postscript color
set output "problem1/problem1Graph.ps"
set ylabel "time (seconds)"
set xlabel "size (i)"

plot [:][:] "problem1/problem1.txt" using 1:2 with line