all: ProgressUpdate.tex Glossary.tex Appendix.tex state_diagram.tex logo.png armDiagram.jpg
	pdflatex ProgressUpdate.tex
	makeindex -s ProgressUpdate.ist -t ProgressUpdate.glg -o ProgressUpdate.gls ProgressUpdate.glo
	pdflatex ProgressUpdate.tex
	
clean:
	rm -f *.out *.glo *.log *.toc *.ist *.aux
