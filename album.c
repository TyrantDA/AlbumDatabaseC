#include <stdio.h>
#include <stdlib.h>

#include "duration.h"
#include "track.h"
#include "album.h"
#include "string.h"


Album* newAlbum(char* art,char* t)
{
    Album* album = (Album*)malloc(sizeof(Album));
    
    if (album == NULL)
   {
      fprintf(stderr, "Error: Unable to allocate memory in list_new()\n");
      
      exit(EXIT_FAILURE);
   }
    
    
    album->artist = (char*) malloc(sizeof(char)*strlen(art));
    strcpy(album->artist, art);
    album->title = (char*) malloc(sizeof(char)*strlen(t));
    strcpy(album->title, t);
    album->first = NULL;
    album->last = NULL;
}

void addTrack(Album* album, Track* t)
{
    Node* node = (Node*)malloc(sizeof(Node));
    
    if (node == NULL)
    {
      fprintf(stderr, "Error: Unable to allocate memory in list_add()\n");
      
      exit(EXIT_FAILURE);
    }
    
    node->track = t;
    node->next = NULL;
    
   if (album->last == NULL)
   {
      album->first = album->last = node;
   }
   else
   {
      album->last = album->last->next = node;  
   }
}

int list_length(Album* album)
{
   int length = 0;
    
   for (Node* node = album->first; node != NULL; node = node->next)
   {
       length++;
   }
    
   return length;
}

Track* list_head(Album* album)
{
   if (album->first == NULL)
   {
      fprintf(stderr, "Error: attempt to return the head of an empty list.");

      exit(EXIT_FAILURE);
   }
   
   Track* value = album->first->track;
   
   Node *node = album->first;
   
   if (album->first == album->last)
   {
      album->first = album->last = NULL;    
   }
   else
   {
      album->first = album->first->next;    
   }
   
   free(node);
   
   return value;
}

Track* list_tail(Album* album)
{
   if (album->first == NULL)
   {
      fprintf(stderr, "Error: attempt to return the tail of an empty list.");

      exit(EXIT_FAILURE);       
   }
   
   Track* track = album->last->track;
   
   Node* tail = album->last;
   
   if (album->first == album->last)
   {
       album->first = album->last = NULL;
   }
   else
   {
       Node* node;
       
      for (node = album->first; node->next != tail; node = node->next);
      
      album->last       = node;
      album->last->next = NULL;
   }
   
   free(tail);
   
   return track;
}

void list_sort(Album* album)
{
   if (album->first != album->last)   // list contains two or more items
   {
      int sorted;
      
      do
      {
         sorted = 1; 
         
         for (Node* node=album->first; node->next!=NULL; node=node->next)
         {
            if (node->track > node->next->track)
            {
               Track* temp       = node->track;
               node->track       = node->next->track;
               node->next->track = temp;
               sorted            = 0;
            }
         }
      }
      while (!sorted);
   }
}

void printAlbum(Album* album)
{
    printf("%s: %s\n", album->artist, album->title);
    
    for (Node *node = album->first; node != NULL; node = node->next)
    {
        printTrack(node->track);
    }
   
   
}

