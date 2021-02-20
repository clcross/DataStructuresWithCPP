set terminal postscript color
set output "problem4/problem4Graph.ps"
set ylabel "time (seconds)"
set xlabel "size (i)"

plot [:][:] "problem4/problem4.txt" using 1:2 with line