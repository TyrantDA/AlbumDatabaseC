/* 
 * File:   album.h
 * Author: jsc16gru
 *
 * Created on 25 October 2018, 14:29
 */

#ifndef ALBUM_H
#define ALBUM_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct NodeStruct
{
    Track* track;
    struct NodeStruct* next; 
}Node;  
    
typedef struct AlbumStruct 
{
    char* artist;
    char* title;
    Node* first;
    Node* last;
}Album;

typedef Node* Iterator;

static inline Iterator TrackListBegin(const Album *album)
{
   return album->first;
}

static inline Iterator TrackListend(const Album *ablum)
{
   return NULL;
}

static inline Iterator nextTrack(const Iterator i)
{
   return i->next;
}

static inline Track* iterator_value(const Iterator i)
{
    return i->track;
}

static inline Iterator iterator_set(Iterator i, Track* track)
{
    i->track = track;
}

Album* newAlbum(char* art,char* t);

void addTrack(Album* album, Track* track);

int list_length(Album* album);

Track* list_head(Album* album);

Track* list_tail(Album* album);

void list_sort(Album* album);

void printAlbum(Album* album);

#ifdef __cplusplus
}
#endif

#endif /* ALBUM_H */

