// Name: Kaleb Dalla Pria       Section: 10         Recitation Class: Tu - 3:30pm to 4:50pm

/* This class is called Playlist and this is a embedded class often known as a "has-a" relantionship
 * because the class Playlist has an array of Song object as it member data. Also, this class simulates
 * a Playlist environment where you can add songs to it, delete songs, do search, etc.
 */

#include "song.h"

class Playlist
{
    
    public:
        
        Playlist();                                                             //default constructor to initialize member data
        ~Playlist();                                                            // default destroctor to clean the memory allocation for the array
        
        void AddSong(const char* mt, const char* ma, Style mc, int ms);         // this function add a song to the playlist
        void Show() const;                                                      // show all the playlist songs
        
        void SizeOf() const;                                                    // this function show the size of the playlist in kbytes
        
        void DeleteSong(const char* mt);                                        // this function delete a song from the playlist
        void AdvanceSearch(const char* mi) const;                               // this function makes a search into the playlist by title and artist and show the result
        
        void CategorySummary(Style c);                                          // this function also makes a search into the playlist by category and show the result
    
    
    
    private:
    
        int maxSize,                                        // max size of the array
            currentSize;                                    // current size of the array
        Song* songList;                                     // pointer to create the dynamic array
        void Grow();                                        // grows the array
        void Shrink();                                      // shrinks the array
        int FindTitle(const char* name) const;               // search for a spefic title into the array
};