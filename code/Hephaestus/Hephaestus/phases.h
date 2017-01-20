/*
 * phases.h
 *
 * Created: 1/20/2017 3:36:58 PM
 *  Author: Michael Humphrey
 */ 


#ifndef PHASES_H_
#define PHASES_H_

int idle(void);			// Phase 1
int observation(void);	// Phase 2
int science(void);		// Phase 3
int off(void);			// Phase 4
int safety(void);		// Phase 5

#endif /* PHASES_H_ */