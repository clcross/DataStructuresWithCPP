all:
	gnuplot problem1/problem1.plot
	gnuplot problem2/problem2.plot
	gnuplot problem3/problem3.plot
	gnuplot problem4/problem4.plot
	gnuplot problem5/problem5.plot
	ps2pdf problem1/problem1Graph.ps
	ps2pdf problem2/problem2Graph.ps
	ps2pdf problem3/problem3Graph.ps
	ps2pdf problem4/problem4Graph.ps
	ps2pdf problem5/problem5Graph.ps
	evince problem1Graph.pdf
	evince problem2Graph.pdf
	evince problem3Graph.pdf
	evince problem4Graph.pdf
	evince problem5Graph.pdf

clean:
	rm -rf problem1/*.ps problem1/*.pdf | rm -rf *.ps *.pdf
	rm -rf problem2/*.ps problem2/*.pdf | rm -rf *.ps *.pdf
	rm -rf problem3/*.ps problem3/*.pdf | rm -rf *.ps *.pdf
	rm -rf problem4/*.ps problem4/*.pdf | rm -rf *.ps *.pdf
	rm -rf problem5/*.ps problem5/*.pdf | rm -rf *.ps *.pdf