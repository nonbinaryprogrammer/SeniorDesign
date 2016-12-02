all: PrelimDesignDoc.tex Glossary.tex Appendix.tex state_diagram.tex logo.png armDiagram.jpg
	pdflatex PrelimDesignDoc.tex
	makeindex -s PrelimDesignDoc.ist -t PrelimDesignDoc.glg -o PrelimDesignDoc.gls PrelimDesignDoc.glo
	pdflatex PrelimDesignDoc.tex
	
clean:
	rm -f *.out *.glo *.log *.toc *.ist *.aux
