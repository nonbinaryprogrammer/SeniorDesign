all: Report.tex Glossary.tex logo.png
	pdflatex Report.tex
	makeindex -s Report.ist -t Report.glg -o Report.gls Report.glo
	pdflatex Report.tex
	
clean:
	rm -f *.out *.glo *.log *.toc *.ist *.aux
