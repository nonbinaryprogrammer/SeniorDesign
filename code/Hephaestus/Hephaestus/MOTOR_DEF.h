#define MOTOR_ELB 0
#define MOTOR_SHOULD 1
#define MOTOR_PAN 2
#define MOTOR_DECK_ARM 3
#define MOTOR_CAMERA 4
#define MOTOR_DECK_PLATE 5

#define POWER_OFF 0
#define POWER_ON 1

#define CLOCKWISE 0 
#define COUNTER_CLOCKWISE 1

#define SPEED 80

#define STEPS_PER_ROTATION 1600

#define DEGREES_PER_STEP .225

#define DEGREES_TO_STEPS(degrees) ((degrees) / DEGREES_PER_STEP)

