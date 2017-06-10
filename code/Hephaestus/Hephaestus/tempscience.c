
		//change 1
		//MN+/-1
		if(M1_POS < 36 && cspace[M1_POS+1][M2_POS][M3_POS][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
		} else if(M1_POS > 0 && cspace[M1_POS-1][M2_POS][M3_POS][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS - 1;
		} else if(M2_POS < 36 && cspace[M1_POS][M2_POS+1][M3_POS][M4_POS] == path_step + 1) {
			M2_NXT = M2_POS + 1;
		} else if(M2_POS > 0 && cspace[M1_POS][M2_POS-1][M3_POS][M4_POS] == path_step + 1) {
			M2_NXT = M2_POS - 1;
		} else if(M3_POS < 36 && cspace[M1_POS][M2_POS][M3_POS+1][M4_POS] == path_step + 1) {
			M3_NXT = M3_POS + 1;
		} else if(M3_POS > 0 && cspace[M1_POS][M2_POS][M3_POS-1][M4_POS] == path_step + 1) {
			M3_NXT = M3_POS - 1;
		} else if(M4_POS < 36 && cspace[M1_POS][M2_POS][M3_POS][M4_POS+1] == path_step + 1) {
			M4_NXT = M4_POS + 1;
		} else if(M4_POS > 0 && cspace[M1_POS][M2_POS][M3_POS][M4_POS-1] == path_step + 1) {
			M4_NXT = M4_POS - 1;

		//change 2
		//M1+1, MN+/-1
		} else if(M1_POS < 36 && M2_POS < 36 && cspace[M1_POS+1][M2_POS+1][M3_POS][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
		} else if(M1_POS < 36 && M2_POS > 0 && cspace[M1_POS+1][M2_POS-1][M3_POS][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS - 1;
		} else if(M1_POS < 36 && M3_POS < 36 && cspace[M1_POS+1][M2_POS][M3_POS+1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M3_NXT = M3_POS + 1;
		} else if(M1_POS < 36 && M3_POS > 0 && cspace[M1_POS+1][M2_POS][M3_POS-1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M3_NXT = M3_POS - 1;
		} else if(M1_POS < 36 && M4_POS < 36 && cspace[M1_POS+1][M2_POS][M3_POS][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS < 36 && M4_POS > 0 && cspace[M1_POS+1][M2_POS][M3_POS][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M4_NXT = M4_POS - 1;
		//M1-1, MN+/-1
		} else if(M1_POS > 0 && M2_POS < 36 && cspace[M1_POS+1][M2_POS+1][M3_POS][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
		} else if(M1_POS > 0 && M2_POS > 0 && cspace[M1_POS+1][M2_POS-1][M3_POS][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS - 1;
		} else if(M1_POS > 0 && M3_POS < 36 && cspace[M1_POS+1][M2_POS][M3_POS+1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M3_NXT = M3_POS + 1;
		} else if(M1_POS > 0 && M3_POS > 0 && cspace[M1_POS+1][M2_POS][M3_POS-1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M3_NXT = M3_POS - 1;
		} else if(M1_POS > 0 && M4_POS < 36 && cspace[M1_POS+1][M2_POS][M3_POS][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS > 0 && M4_POS > 0 && cspace[M1_POS+1][M2_POS][M3_POS][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M4_NXT = M4_POS - 1;
		//M2+1, MN+/-1
		} else if(M2_POS < 36 && M3_POS < 36 && cspace[M1_POS][M2_POS+1][M3_POS+1][M4_POS] == path_step + 1) {
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS + 1;
		} else if(M2_POS < 36 && M3_POS > 0 && cspace[M1_POS][M2_POS+1][M3_POS-1][M4_POS] == path_step + 1) {
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS - 1;
		} else if(M2_POS < 36 && M4_POS < 36 && cspace[M1_POS][M2_POS+1][M3_POS][M4_POS+1] == path_step + 1) {
			M2_NXT = M2_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M2_POS < 36 && M4_POS > 0 && cspace[M1_POS][M2_POS+1][M3_POS][M4_POS-1] == path_step + 1) {
			M2_NXT = M2_POS + 1;
			M4_NXT = M4_POS - 1;
		//M2-1, MN+/-1
		} else if(M2_POS > 0 && M3_POS < 36 && cspace[M1_POS][M2_POS-1][M3_POS+1][M4_POS] == path_step + 1) {
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS + 1;
		} else if(M2_POS > 0 && M3_POS > 0 && cspace[M1_POS][M2_POS-1][M3_POS-1][M4_POS] == path_step + 1) {
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS - 1;
		} else if(M2_POS > 0 && M4_POS < 36 && cspace[M1_POS][M2_POS-1][M3_POS][M4_POS+1] == path_step + 1) {
			M2_NXT = M2_POS - 1;
			M4_NXT = M4_POS + 1;
		} else if(M2_POS > 0 && M4_POS > 0 && cspace[M1_POS][M2_POS-1][M3_POS][M4_POS-1] == path_step + 1) {
			M2_NXT = M2_POS - 1;
			M4_NXT = M4_POS - 1;
		//M3+1, MN+/-1
		} else if(M3_POS < 36 && M4_POS < 36 && cspace[M1_POS][M2_POS][M3_POS+1][M4_POS+1] == path_step + 1) {
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M3_POS < 36 && M4_POS > 0 && cspace[M1_POS][M2_POS][M3_POS+1][M4_POS-1] == path_step + 1) {
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS - 1;
		//M3-1, M4+/-1
		} else if(M3_POS > 0 && M4_POS < 36 && cspace[M1_POS][M2_POS][M3_POS+1][M4_POS-1] == path_step + 1) {
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS + 1;
		} else if(M3_POS > 0 && M4_POS > 0 && cspace[M1_POS][M2_POS][M3_POS-1][M4_POS-1] == path_step + 1) {
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS - 1;

		//change 3
		//M1+1, M2+/-1, M3+/-1
		} else if(M1_POS < 36 && M2_POS < 36 && M3_POS < 36 && cspace[M1_POS+1][M2_POS+1][M3_POS+1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS + 1;
		} else if(M1_POS < 36 && M2_POS < 36 && M3_POS > 0 && cspace[M1_POS+1][M2_POS+1][M3_POS-1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS - 1;
		} else if(M1_POS < 36 && M2_POS > 0 && M3_POS < 36 && cspace[M1_POS+1][M2_POS-1][M3_POS+1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS + 1;
		} else if(M1_POS < 36 && M2_POS > 0 && M3_POS > 0 && cspace[M1_POS+1][M2_POS-1][M3_POS-1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS - 1;
		//M1+1, M2+/-1, M4+/-1
		} else if(M1_POS < 36 && M2_POS < 36 && M4_POS < 36 && cspace[M1_POS+1][M2_POS+1][M3_POS][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS < 36 && M2_POS < 36 && M4_POS > 0 && cspace[M1_POS+1][M2_POS+1][M3_POS][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
			M4_NXT = M4_POS - 1;
		} else if(M1_POS < 36 && M2_POS > 0 && M4_POS < 36 && cspace[M1_POS+1][M2_POS-1][M4_POS][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS < 36 && M2_POS > 0 && M4_POS > 0 && cspace[M1_POS+1][M2_POS-1][M3_POS][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
			M4_NXT = M4_POS - 1;
		//M1+1, M3+/-1, M4+/-1
		} else if(M1_POS < 36 && M3_POS < 36 && M4_POS < 36 && cspace[M1_POS+1][M2_POS][M3_POS+1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS < 36 && M3_POS < 36 && M4_POS > 0 && cspace[M1_POS+1][M2_POS][M3_POS+1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS - 1;
		} else if(M1_POS < 36 && M3_POS > 0 && M4_POS < 36 && cspace[M1_POS+1][M2_POS][M3_POS-1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS < 36 && M3_POS > 0 && M4_POS > 0 && cspace[M1_POS+1][M2_POS][M3_POS-1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS - 1;
		//M1-1, M2+/-1, M3+/-1
		} else if(M1_POS > 0 && M2_POS < 36 && M3_POS < 36 && cspace[M1_POS-1][M2_POS+1][M3_POS+1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS + 1;
		} else if(M1_POS > 0 && M2_POS < 36 && M3_POS > 0 && cspace[M1_POS-1][M2_POS+1][M3_POS-1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS - 1;
		} else if(M1_POS > 0 && M2_POS > 0 && M3_POS < 36 && cspace[M1_POS-1][M2_POS-1][M3_POS+1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS + 1;
		} else if(M1_POS > 0 && M2_POS > 0 && M3_POS > 0 && cspace[M1_POS-1][M2_POS-1][M3_POS-1][M4_POS] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS - 1;
		//M1-1, M2+/-1, M4+/-1
		} else if(M1_POS > 0 && M2_POS < 36 && M4_POS < 36 && cspace[M1_POS-1][M2_POS+1][M3_POS][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS > 0 && M2_POS < 36 && M4_POS > 0 && cspace[M1_POS-1][M2_POS+1][M3_POS][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS + 1;
			M4_NXT = M4_POS - 1;
		} else if(M1_POS > 0 && M2_POS > 0 && M4_POS < 36 && cspace[M1_POS-1][M2_POS-1][M4_POS][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS > 0 && M2_POS > 0 && M4_POS > 0 && cspace[M1_POS-1][M2_POS-1][M3_POS][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS + 1;
			M4_NXT = M4_POS - 1;
		//M1-1, M3+/-1, M4+/-1
		} else if(M1_POS > 0 && M3_POS < 36 && M4_POS < 36 && cspace[M1_POS-1][M2_POS][M3_POS+1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS > 0 && M3_POS < 36 && M4_POS > 0 && cspace[M1_POS-1][M2_POS][M3_POS+1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS - 1;
		} else if(M1_POS > 0 && M3_POS > 0 && M4_POS < 36 && cspace[M1_POS-1][M2_POS][M3_POS-1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS > 0 && M3_POS > 0 && M4_POS > 0 && cspace[M1_POS-1][M2_POS][M3_POS-1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS - 1;
		//M2+1, M3+/-1, M4+/-1 
		} else if(M2_POS < 36 && M3_POS < 36 && M4_POS < 36 && cspace[M1_POS][M2_POS+1][M3_POS+1][M4_POS+1] == path_step + 1) {
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M2_POS < 36 && M3_POS < 36 && M4_POS > 0 && cspace[M1_POS][M2_POS+1][M3_POS+1][M4_POS-1] == path_step + 1) {
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS - 1;
		} else if(M2_POS < 36 && M3_POS > 0 && M4_POS < 36 && cspace[M1_POS][M2_POS+1][M3_POS-1][M4_POS+1] == path_step + 1) {
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS + 1;
		} else if(M2_POS < 36 && M3_POS > 0 && M4_POS > 0 && cspace[M1_POS][M2_POS+1][M3_POS-1][M4_POS-1] == path_step + 1) {
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS - 1;
		//M2-1, M3+/-1, M4+/-1 
		} else if(M2_POS > 0 && M3_POS < 36 && M4_POS < 36 && cspace[M1_POS][M2_POS-1][M3_POS+1][M4_POS+1] == path_step + 1) {
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M2_POS > 0 && M3_POS < 36 && M4_POS > 0 && cspace[M1_POS][M2_POS-1][M3_POS+1][M4_POS-1] == path_step + 1) {
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS - 1;
		} else if(M2_POS > 0 && M3_POS > 0 && M4_POS < 36 && cspace[M1_POS][M2_POS-1][M3_POS-1][M4_POS+1] == path_step + 1) {
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS + 1;
		} else if(M2_POS > 0 && M3_POS > 0 && M4_POS > 0 && cspace[M1_POS][M2_POS-1][M3_POS-1][M4_POS-1] == path_step + 1) {
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS - 1;

		//change 4
		//(M1-2)+1, (M3-4)+/-1
		} else if(M1_POS < 36 && M2_POS < 36 && M3_POS < 36 && M4_POS < 36 && cspace[M1_POS+1][M2_POS+1][M3_POS+1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS < 36 && M2_POS < 36 && M3_POS < 36 && M4_POS > 0 && cspace[M1_POS+1][M2_POS+1][M3_POS+1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS - 1;
		} else if(M1_POS < 36 && M2_POS < 36 && M3_POS > 0 && M4_POS < 36 && cspace[M1_POS+1][M2_POS+1][M3_POS-1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS < 36 && M2_POS < 36 && M3_POS > 0 && M4_POS > 0 && cspace[M1_POS+1][M2_POS+1][M3_POS-1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS - 1;
		//M1+1, M2-1, (M3-4)+/-1
		} else if(M1_POS < 36 && M2_POS > 0 && M3_POS < 36 && M4_POS < 36 && cspace[M1_POS+1][M2_POS-1][M3_POS+1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS < 36 && M2_POS > 0 && M3_POS < 36 && M4_POS > 0 && cspace[M1_POS+1][M2_POS-1][M3_POS+1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS - 1;
		} else if(M1_POS < 36 && M2_POS > 0 && M3_POS > 0 && M4_POS < 36 && cspace[M1_POS+1][M2_POS-1][M3_POS-1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS < 36 && M2_POS > 0 && M3_POS > 0 && M4_POS > 0 && cspace[M1_POS+1][M2_POS-1][M3_POS-1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS + 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS - 1;
		//M1-1, M2+1, (M3-4)+/-1
		} else if(M1_POS > 0 && M2_POS < 36 && M3_POS < 36 && M4_POS < 36 && cspace[M1_POS-1][M2_POS+1][M3_POS+1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS > 0 && M2_POS < 36 && M3_POS < 36 && M4_POS > 0 && cspace[M1_POS-1][M2_POS+1][M3_POS+1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS - 1;
		} else if(M1_POS > 0 && M2_POS < 36 && M3_POS > 0 && M4_POS < 36 && cspace[M1_POS-1][M2_POS+1][M3_POS-1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS > 0 && M2_POS < 36 && M3_POS > 0 && M4_POS > 0 && cspace[M1_POS-1][M2_POS+1][M3_POS-1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS + 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS - 1;
		//M1+1, M2-1, (M3-4)+/-1
		} else if(M1_POS > 0 && M2_POS > 0 && M3_POS < 36 && M4_POS < 36 && cspace[M1_POS-1][M2_POS-1][M3_POS+1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS > 0 && M2_POS > 0 && M3_POS < 36 && M4_POS > 0 && cspace[M1_POS-1][M2_POS-1][M3_POS+1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS + 1;
			M4_NXT = M4_POS - 1;
		} else if(M1_POS > 0 && M2_POS > 0 && M3_POS > 0 && M4_POS < 36 && cspace[M1_POS-1][M2_POS-1][M3_POS-1][M4_POS+1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS + 1;
		} else if(M1_POS > 0 && M2_POS > 0 && M3_POS > 0 && M4_POS > 0 && cspace[M1_POS-1][M2_POS-1][M3_POS-1][M4_POS-1] == path_step + 1) {
			M1_NXT = M1_POS - 1;
			M2_NXT = M2_POS - 1;
			M3_NXT = M3_POS - 1;
			M4_NXT = M4_POS - 1;
		} else {
			//end of path reached
			//TODO send telemetry code
			return 0;
		}

