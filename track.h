/* 
 * File:   track.h
 * Author: jsc16gru
 *
 * Created on 25 October 2018, 13:59
 */

#ifndef TRACK_H
#define TRACK_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TrackStruct 
{
    char* title;
    Duration* duration;
}Track;

Track* newTrack(char* t, Duration* d);

void printTrack(Track* track);

#ifdef __cplusplus
}
#endif

#endif /* TRACK_H */

