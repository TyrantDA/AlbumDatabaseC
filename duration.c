#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "duration.h"

Duration* newDuration(int h, int m, int s)
{
    Duration* duration = (Duration*)malloc(sizeof(Duration));
    
    duration->hour = h;
    duration->minute = m;
    duration->second = s;
    
    return duration;
}

Duration* newDurationString(char* time)
{
    int hour;
    int minute;
    int second;
    sscanf(time, "%d:%d:%d", &hour, &minute, &second);
    Duration* duration = newDuration(hour, minute, second);
    
    return duration;
}

int getHour(Duration* duration)
{
    return duration->hour;
}

int getMinute(Duration* duration)
{
    return duration->minute;
}

int getSecond(Duration* duration)
{
    return duration->second;
}

Duration* add(Duration* first, Duration* second)
{
    int h, m, s, overflow = 0;
    
    s =getSecond(first) + getSecond(second);
    if(s > 59)
    {
        overflow = s / 60;
        s = s % 60;
    }
    
    m = (getMinute(first) + getMinute(second)) + overflow;
    overflow = 0;
    if (m > 59)
    {
        overflow = m / 60;
        m = m % 60;
    }
    
    h = (getHour(first) + getHour(second)) + overflow;
    
    Duration* duration = newDuration(h, m, s);
    
    return duration;
}

int compare(Duration* first, Duration* second)
{
    
    if(getHour(first) > getHour(second))
    {
        return 1;
    }
    else if(getHour(first) < getHour(second))
    {
        return -1;
    }
    else if(getHour(first) == getHour(second))
    {
        if(getMinute(first) > getMinute(second))
        {
            return 1;
        }
        else if(getMinute(first) < getMinute(second))
        {
            return -1;
        }
        else if(getMinute(first) == getMinute(second))
        {
            if(getSecond(first) > getSecond(second))
            {
                return 1;
            }
            else if(getSecond(first) < getSecond(second))
            {
                return -1;
            }
            else if(getSecond(first) == getSecond(second))
            {
                return 0;
            }
            
        }
    }
}

void printDuration(Duration* duration)
{
    printf("%02d:%02d:%02d", duration->hour, duration->minute, duration->second);
}

