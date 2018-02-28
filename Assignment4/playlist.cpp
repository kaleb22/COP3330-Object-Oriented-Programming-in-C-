// Name: Kaleb Dalla Pria       Section: 10         Recitation Class: Tu - 3:30pm to 4:50pm

// This file contains the definitions for all the functions that are written in the class Song.

#include <iostream>
#include "playlist.h"

Playlist::Playlist()
{
    maxSize = 5;
    currentSize = 0;
    songList = new Song[maxSize];

}

Playlist::~Playlist()
{
    delete [] songList;

}

void Playlist::Grow()
{
    int i;
    
    maxSize = currentSize + 5;
    Song* newList = new Song[maxSize];          // dealocate a new array
    
    for(i = 0; i < currentSize; i++)            
        newList[i] = songList[i];               // copy one array to another
        
    delete [] songList;                         // delete the old array
    songList = newList;                         // points the pointer to the new array
    
    cout << "Array being resized to " << maxSize << " allocated slots" << "\n";
    
}

void Playlist::Shrink()
{
    int i;
    
    maxSize = maxSize - 5;
    Song* newList = new Song[maxSize];      // dealocate the new array
    
    for(i = 0; i < currentSize; i++)        
        newList[i] = songList[i];           // copy one array to another
        
    delete [] songList;                     // delete the old array
    songList = newList;                     // points the pointer to the new array
    
    cout << "Array being resized to " << maxSize << " allocated slots" << "\n";    
}

void Playlist::AddSong(const char* mt, const char* ma, Style mc, int ms)
{
    
    
    if(currentSize == maxSize)              // if array is full, grow before insert new data
        Grow();
        
    songList[currentSize++].Set(mt, ma, mc, ms);        // makes the insertion into the array
    
}

void Playlist::Show() const
{
    if(currentSize > 0)
    {
        cout << "*Title*" << "                            " << "*Artist*" << "            " << "*Category*" << "      " << "*Size (MB)*" << "\n\n";
        
        int i;
        double totalSize = 0;
        
        for(i = 0; i < currentSize; i++)
        {
            cout << songList[i];
            cout << "\n";
            
            totalSize += songList[i].GetSize();
        }
        
        cout << "\nNumber of songs: " << currentSize << "\n";
        
        totalSize = totalSize / 1000.0;
        
    // capture current output stream settings
       int oldprecision = cout.precision();
       char oldfill = cout.fill();
       ios_base::fmtflags oldflags = cout.flags();
    
    // do my output changes
       cout.setf(ios::left);
       cout << setprecision(1);
       cout << fixed;
       
       cout << "Current playlist size (MB): " << totalSize;
       
    // PUT THINGS BACK THE WAY THEY WERE WHEN I FOUND THEM
       cout.precision(oldprecision);	// restore old precision setting
       cout.fill(oldfill);			// restore old fill char setting
       cout.flags(oldflags);		// restore all prior format flags
    }
    else
    {
        cout << "\tThere is no songs in the playlist!\n";
        cout << "\nNumber of songs: " << currentSize << "\n";
        cout << "Current playlist size: 0.0";
    }
   
}

void Playlist::SizeOf() const
{
    int i;
    int totalSize = 0;
    
    for(i = 0; i < currentSize; i++)
        totalSize += songList[i].GetSize();
        
    cout << "The total size of the playlist is: " << totalSize << " kilobytes";
    
}

int Playlist::FindTitle(const char* mt) const
{
    int i;
    
    for(i = 0; i < currentSize; i++)
        if(strcmp(songList[i].GetTitle(), mt) == 0)
            return i;
            
    return -1;
}

void Playlist::DeleteSong(const char* mt)
{

    int checkSize = maxSize - currentSize;
    
    if(checkSize > 5)                        // if there is more than 5 places "empty", shrink the array
        Shrink();    

    int j = FindTitle(mt);
    
    if(j == -1)
        cout << "There is no song with this title: " << mt << "\n";
    else
    {
        for(int i = j + 1; i < currentSize; i++)       
            songList[i - 1] = songList[i];           // shifts one position down each element of the array;
            
        currentSize--;                              // decrease current size by one
        
        cout << "Song removed.\n";
            
    }

}

void Playlist::AdvanceSearch(const char* mi) const
{
    int j = FindTitle(mi);                              // verify if the the user sent an artist or a title
    
    int count = 0;
       
    if(j == -1)                                         // look for the same artist
    {
        for(int i = 0; i < currentSize; i++)
            if(strcmp(songList[i].GetArtist(), mi) == 0)
                count += 1;
    }

    
    if(j >= 0)
    {
        cout << "*Title*" << "                            " << "*Artist*" << "            " << "*Category*" << "      " << "*Size (MB)*" << "\n\n";
        cout << songList[j];
    }
    else if(count > 0)
    {
        cout << "*Title*" << "                            " << "*Artist*" << "            " << "*Category*" << "      " << "*Size (MB)*" << "\n\n";
        
        for(int k = 0; k < currentSize; k++)
            if(strcmp(songList[k].GetArtist(), mi) == 0)
            {
                cout << songList[k];                    // print the same artist songs
                cout << "\n";
            }
    }
    else
    {
        cout << "\nThere is no song that matchs your title or artist. Try again.\n";
    }
    
}

void Playlist::CategorySummary(Style c)
{
    
    int totalQuant = 0;
    double totalSize = 0;
    
    cout << "\n*Title*" << "                            " << "*Artist*" << "            " << "*Category*" << "      " << "*Size (MB)*" << "\n\n";
    
    for(int i = 0; i < currentSize; i++)
        if(songList[i].GetCategory() == c)              //if there is category equals the entry of the user
        {
            cout << songList[i];                        // print the song for that category
            cout << "\n";
            
            totalQuant += 1;
            totalSize += songList[i].GetSize();
        }
    
    cout << "\nTotal quantity of songs: " << totalQuant << "\n";
    
        totalSize = totalSize / 1000.0;
        
        // capture current output stream settings
       int oldprecision = cout.precision();
       char oldfill = cout.fill();
       ios_base::fmtflags oldflags = cout.flags();
    
       // do my output changes
       cout.setf(ios::left);
       cout << setprecision(1);
       cout << fixed;
       
       cout << "Current playlist size (MB): " << totalSize;
       
        // PUT THINGS BACK THE WAY THEY WERE WHEN I FOUND THEM
       cout.precision(oldprecision);	// restore old precision setting
       cout.fill(oldfill);			// restore old fill char setting
       cout.flags(oldflags);		// restore all prior format flags
    
}