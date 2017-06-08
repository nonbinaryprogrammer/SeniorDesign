all: Report.tex Glossary.tex logo.png OrigTechRevDoc.tex OrigReqDoc.tex OrigDesignDoc.tex ProjectDocs.tex OtherDocs.tex LearnTech.tex FallBlogs.tex WinterBlogs.tex SpringBlogs.tex EssentialCode.tex WWL_Helena.tex WWL_Amber.tex WWL_Michael.tex
	pdflatex Report.tex
	makeindex -s Report.ist -t Report.glg -o Report.gls Report.glo
	pdflatex Report.tex
	
clean:
	rm -f *.out *.glo *.log *.toc *.ist *.aux
