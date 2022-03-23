#include <stdio.h>
#include <fx/delay.h>



static inline void limitBufferIndex(int *bufferIndex){
	if (*bufferIndex >= BUFFER_SIZE){
		*bufferIndex -= BUFFER_SIZE;
	}
}

static inline float clip(float sample){
	if (sample > 1.0){
		return 1.0;
	}

	if ( sample< -1.0){
		return -1.0;
	}

	return sample;

} 

// --- Public Delay API

void initDelay(struct Delay *self){

	int i = 0;
	for ( i = 0 ; i < BUFFER_SIZE; i++) self->buffer[i] = 0;

	self->readIndex = 0;
	self->feedbackLevel = 0.7;
	self->delayLevel = 0.9;
	setDelay(self, SAMPLE_RATE);	
}

void setFedbackLevel(struct Delay *self, float level){
	self->feedbackLevel = clip(level);
}

void setDelayLevel(struct Delay *self, float level){
	self->delayLevel = clip(level);
}

void setDelay(struct Delay *self, int delay){

	if (delay < 0 || delay >= BUFFER_SIZE){
		return;
	}

	self->writeIndex = self->readIndex + delay;

	limitBufferIndex(&self->writeIndex);
}

float nextSample(struct Delay *self, float innputSample){

	float output = self->buffer[self->readIndex];
	self->readIndex += 1;

	limitBufferIndex(&self->readIndex);

	self->buffer[self->writeIndex] = clip(innputSample + (output * self->feedbackLevel));
	self->writeIndex += 1;
	
	limitBufferIndex(&self->writeIndex);

	return clip(innputSample + output * self->delayLevel);
} 


