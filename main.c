
// Created on 25 October 2018, 12:25
// by 100168172

#include <stdio.h>
#include <stdlib.h>

#include "duration.h"
#include "track.h"
#include "album.h"
#include "collection.h"

void testing() {
    int hour = 2;
    int minute = 40;
    int second = 20;
    char* time = "2:21:20";
    Duration* time1 = newDurationString("00:30:00");
    Duration* time2 = newDurationString("00:00:30");
    Duration* totalduration = newDurationString("00:00:00");
    Duration* duration = newDuration(hour, minute, second);
    Duration* duration1 = newDurationString(time);
    totalduration = add(time1,time1);
    printDuration(totalduration);
    printf("\n");
    totalduration = add(time2,time2);
    printDuration(totalduration);
    printf("\n");
    printf("\n");
    printDuration(duration);
    printf("\n");
    printDuration(duration1);
    printf("\n");

    Duration* sum = add(duration, duration1);
    printDuration(sum);
    printf("\n");

    char* song = "Paduana Del Re (Anonyme)";
    char* song1 = "Mr Blue Sky";
    Track* track = newTrack(song, duration);
    Track* track1 = newTrack(song1, duration1);
    printTrack(track);
    printf("\n");

    char* artist = "me";
    char* title = "testSongs";
    Album* album = newAlbum(artist, title);
    addTrack(album, track);
    addTrack(album, track1);
    printAlbum(album);
    printf("\n");

    char* name = "myCollection";
    Collection* collection = newCollection(name);
    addAlbum(collection, album);
    addAlbum(collection, album);
    printCollection(collection);
}

int main(int argc, char** argv) {
    char line[200];
    char artist[200];
    char albumTitle[200];
    char duration[200];
    char trackTitle[200];
    char* collectionName = "MyAlbumCollection";
    Collection* collection = newCollection(collectionName);
    Track* track;
    Album* album;
    
    printf("testing \n");
    testing();
   
    FILE *input = fopen("albums.txt", "r");

    if (input == NULL) {
        printf("Error: unable to open ‘albums.txt’ in mode ’r’\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, 200, input) != NULL) {
        if (line[0] >= 48 && line[0] <= 57) {
            sscanf(line, "%s - %[^\r\n]", duration, trackTitle);
            //printf("%s / %s \n", duration, trackTitle);
            Duration* durationD = newDurationString(duration);
            track = newTrack(trackTitle,durationD);
            addTrack(album,track);
        }
        else {
            sscanf(line, "%[^:] : %[^\r\n]", artist, albumTitle);
            //printf("%s | %s \n", artist, albumTitle);
            album = newAlbum(artist,albumTitle);
            addAlbum(collection,album);
        } 
       
    }
    
    
    char* find = "Pink Floyd";
    printf("\n\n");
    printf("Printing albums.txt \n");
    printCollection(collection);
    listCollection_sort(collection);
    printf("\n\n");
    printf("Printing sorted collecting \n");
    printCollection(collection);
    printf("\n\n");
    artistDurationLength(find,collection);
    printf("\n\n\n");
    printf("The Album with the most Tracks \n");
    mostTrack(collection);
    printf("\n\n");
    compareTracks(collection);

    return EXIT_SUCCESS;
}

