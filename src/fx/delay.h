#ifndef FX_DELAY_H
#define FX_DELAY_H

#define SAMPLE_RATE 44100
#define BUFFER_SIZE (SAMPLE_RATE * 3)


struct Delay {
 	int delayLength;
 	int readIndex;
 	int writeIndex;

	double feedbackLevel;
	double delayLevel;

    float buffer[BUFFER_SIZE];
};

void initDelay(struct Delay *self);
void setFedbackLevel(struct Delay *self, float level);
void setDelayLevel(struct Delay *self, float level);
void setDelay(struct Delay *self, int delay);

float nextSample(struct Delay *self, float innputSample);

#endif