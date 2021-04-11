

/* 
 * File:   duration.h
 * Author: jsc16gru
 *
 * Created on 25 October 2018, 12:30
 */

#ifndef DURATION_H
#define DURATION_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DurationStruct 
{
   int hour;
   int minute;
   int second;
} Duration;

Duration* newDuration(int h, int m, int s);

Duration* newDurationString(char* time);

int getHour(Duration* duration);

int getMinute(Duration* duration);

int getSecond(Duration* duration);

Duration* add(Duration* first, Duration* second);

int compare(Duration* first, Duration* second);

void printDuration(Duration* duration);

#ifdef __cplusplus
}
#endif

#endif /* DURATION_H */

