set terminal postscript color
set output "lab12Graph.ps"
set ylabel "time (seconds)"
set xlabel "size (1000)"

plot [:][:] "dataFiles/bubble.txt" using 1:2 with line, "dataFiles/selection.txt" using 1:2 with line, "dataFiles/insertion.txt" using 1:2 with line, "dataFiles/SLLinsertion.txt" using 1:2 with line
