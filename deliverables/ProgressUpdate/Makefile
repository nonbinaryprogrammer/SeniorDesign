all: ProgressUpdate.tex Glossary.tex state_diagram.tex logo.png armDiagram.jpg Helena.tex michael-progress-update.tex retrospective.tex AmberProgressUpdate.tex
	pdflatex ProgressUpdate.tex
	makeindex -s ProgressUpdate.ist -t ProgressUpdate.glg -o ProgressUpdate.gls ProgressUpdate.glo
	pdflatex ProgressUpdate.tex
	
clean:
	rm -f *.out *.glo *.log *.toc *.ist *.aux
