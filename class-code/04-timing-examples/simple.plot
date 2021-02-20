set terminal postscript color
set output "test.ps"
set ylabel "time (seconds)"
set xlabel "size (i)"

plot [:][:] "sums-test.txt" using 1:2 with line
