/* Amber Horvath
 * retract.h contains the code that controls the extension and retraction of the deck plate holding the arm
 * These methods should be used at beginning of deployment, and end of deployment, but may need to be used in the case of
 * the arm getting stuck in a bad position and needing to be retracted.
 */

// retracts the deck plate the arm is on
void retract();

// extends the deck plate the arm is on
void extend();