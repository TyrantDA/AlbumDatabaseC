#include <stdio.h>
#include <stdlib.h>

#include "duration.h"
#include "track.h"
#include "album.h"
#include "collection.h"
#include "string.h"

Collection* newCollection(char* n)
{
    Collection* collection = (Collection*)malloc(sizeof(Collection));
    
    if (collection == NULL)
    {
      fprintf(stderr, "Error: Unable to allocate memory in list_new()\n");
      
      exit(EXIT_FAILURE);
    }
     
    collection->name = n;
    collection->first = NULL;
    collection->last = NULL;
}

void addAlbum(Collection* collection, Album* a)
{
    CollectionNode* node = (CollectionNode*)malloc(sizeof(CollectionNode));
    
    if (node == NULL)
    {
      fprintf(stderr, "Error: Unable to allocate memory in list_add()\n");
      
      exit(EXIT_FAILURE);
    }
    
    node->album = a;
    node->next = NULL;
    
    if (collection->last == NULL)
   {
      collection->first = collection->last = node;
   }
   else
   {
      collection->last = collection->last->next = node;  
   }
}

void listCollection_sort(Collection* collection)
{
   if (collection->first != collection->last)   // list contains two or more items
   {
      int sorted;
      
      do
      {
         sorted = 1; 
         
         for (CollectionNode *node = collection->first; node->next != NULL; node=node->next)
         {
            int compare = strcmp(node->album->artist,node->next->album->artist);
            if (compare > 0)
            {
               Album* temp       = node->album;
               node->album       = node->next->album;
               node->next->album = temp;
               sorted            = 0;
            }
            else if (compare == 0)
            {
                compare = strcmp(node->album->title,node->next->album->title);
                if(compare > 0)
                {
                    Album* temp       = node->album;
                    node->album       = node->next->album;
                    node->next->album = temp;
                    sorted            = 0;
                }
            }
         }
      }
      while (!sorted);
   }
}

void artistDurationLength(char* art,Collection* collection)
{
    Duration* durationTotal = newDurationString("00:00:00");
            
    for (CollectionNode *node = collection->first; node != NULL; node=node->next)
    {
        if (strstr(node->album->artist, art) != NULL)
        {
            for(Node *nod = node->album->first; nod != NULL; nod = nod->next)
            {
               durationTotal =  add(nod->track->duration,durationTotal);
            }
        }
    }
    printf("Total Duration of %s album: ", art);
    printDuration(durationTotal);
}

void mostTrack(Collection* collection)
{
     int trackInAlbum = 0;
     int temp = 0;
     Album* hold;
     
    for (CollectionNode *node = collection->first; node != NULL; node=node->next)
    {
        for(Node *nod = node->album->first; nod != NULL; nod = nod->next)
            {
                temp++;
            }
        if (temp > trackInAlbum)
        {
            trackInAlbum = temp;
            hold = node->album;
        }
        temp = 0;
    }
    
     printAlbum(hold);
}

void compareTracks(Collection* collection)
{
    
    Duration* time = newDurationString("00:00:00");
    char* song = "Test";
    Track* longersTrack = newTrack(song, time);
    
    for (CollectionNode *node = collection->first; node != NULL; node=node->next)
    {
        for(Node *nod = node->album->first; nod != NULL; nod = nod->next)
        {
             int comp = compare(nod->track->duration,longersTrack->duration);
             if(comp == 1)
             {
                 longersTrack = nod->track;
             }
        }
    }
     printf("The longer Track is: ");
    printTrack(longersTrack);
    
    
    
    
}

void printCollection(Collection* collection)
{
    printf("%s\n", collection->name);
    
    for (CollectionNode *node = collection->first; node != NULL; node = node->next)
    {
        printAlbum(node->album);
    }
   
   
}
