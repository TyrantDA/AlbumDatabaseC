#include <stdio.h>
#include <stdlib.h>

#include "duration.h"
#include "track.h"
#include "string.h"


Track* newTrack(char* t, Duration* d)
{
    Track* track = (Track*)malloc(sizeof(Track));
    
    track->title = (char*) malloc(sizeof(char)*strlen(t)+1);
    strcpy(track->title, t);
    track->duration = d;
   
    return track;
}

void printTrack(Track* track)
{
   printDuration(track->duration);
   printf(" - %s\n", track->title);
}

