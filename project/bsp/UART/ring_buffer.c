#include "ring_buffer.h"

unsigned int ring_buffer_write(ring_buffer* buff, char c)
{
	buff->buffer[buff->head] = c;
	buff->head = (buff->head + 1) % sizeof(buff->buffer);
	return !(buff->head == buff->tail);
}

char ring_buffer_read(ring_buffer* buff) 
{
	char c;
	if(buff->head == buff->tail)
		return (char)RING_BUFFER_EMPTY;
	
	c = buff->buffer[buff->tail];
	buff->tail = (buff->tail + 1) % sizeof(buff->buffer);
	return c;
}

unsigned int ring_buffer_available(ring_buffer* buff)
{
	return buff->head - buff->tail;
}
	