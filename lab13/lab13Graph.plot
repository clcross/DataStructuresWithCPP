set terminal postscript color
set output "lab13Graph.ps"
set ylabel "time (seconds)"
set xlabel "size (1000)"

plot [:][:] "dataFiles/quick.txt" using 1:2 with line, "dataFiles/merge.txt" using 1:2 with line, "dataFiles/SLLMerge.txt" using 1:2 with line
