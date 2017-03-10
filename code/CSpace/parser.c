int main() {
	int accuracyFactor = 10;
	int MAX_ANGLE = 365;
	int x = MAX_ANGLE/accuracyFactor;
	int a, b, c, d;

	int CSpace[37][37][37][37];

	//init C-Space with 0's
	for(a=0; a<x; a++) {
		for(b=0; b<x; b++) {
			for(c=0; c<x; c++) {
				for(d=0; d<x; d++) {
					CSpace[a][b][c][d] = 0;
				}
			}
		}
	}

}
