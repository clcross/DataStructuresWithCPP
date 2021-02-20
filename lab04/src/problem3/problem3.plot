set terminal postscript color
set output "problem3/problem3Graph.ps"
set ylabel "time (seconds)"
set xlabel "size (i)"

plot [:][:] "problem3/problem3.txt" using 1:2 with line