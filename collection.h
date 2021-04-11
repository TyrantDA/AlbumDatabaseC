/* 
 * File:   collection.h
 * Author: jsc16gru
 *
 * Created on 01 November 2018, 14:30
 */

#ifndef COLLECTION_H
#define COLLECTION_H

#ifdef __cplusplus
extern "C" {
#endif
    
typedef struct NodeCollectionStruct
{
    Album* album;
    struct NodeCollectionStruct* next; 
}CollectionNode;  

typedef struct CollectionStruct
{
    char* name;
    CollectionNode* first;
    CollectionNode* last;
}Collection;

typedef CollectionNode* Hold;

static inline Hold AlbumListBegin(const Collection *collection)
{
    return collection->first;
}

static inline Hold AlbumListend(const Collection *collection)
{
   return NULL;
}

static inline Hold nextAlbum(const Hold h)
{
   return h->next;
}

static inline Album* hold_value(const Hold h)
{
    return h->album;
}

static inline Hold hold_set(Hold h, Album* album)
{
    h->album = album;
}

Collection* newCollection(char* n);

void addAlbum(Collection* collection, Album* album);

void listCollection_sort(Collection* collection);

void artistDurationLength(char* art,Collection* collection);

void mostTrack(Collection* collection);

void compareTracks(Collection* collection);

void printCollection(Collection* collection);

#ifdef __cplusplus
}
#endif

#endif /* COLLECTION_H */

