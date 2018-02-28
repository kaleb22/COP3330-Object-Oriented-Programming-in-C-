#include "song.cpp"
#include "playlist.cpp"
#include <iostream>
#include <cctype>               // this is for toupper function

using namespace std;

void ShowMenu()
{
    cout << " *Welcome to the Playlist Manager* ";
    
    cout << "\n\n\t\t  *** Playlist Menu ***";
    cout << "\n\t A \t Add a song to the playlist";
    cout << "\n\t F \t Find a song by title or artist";
    cout << "\n\t D \t Delete a song from the playlist by title";
    cout << "\n\t S \t Show the playlist";
    cout << "\n\t C \t Category summary";
    cout << "\n\t Z \t Show the total size of the playlist";
    cout << "\n\t M \t Show this menu";
    cout << "\n\t X \t eXit playlist";
}


char GetAChar(const char* promptString)
// I got this function from the course website
{
   char response;		        	// the char to be returned
	
   cout << promptString;    		// Prompt the user
   cin >> response;		        	// Get a char,
   response = toupper(response);	// and convert it to uppercase
   cin.get();			        	// Discard newline char from input.
   return response;
}

char Legal(char c)
// I got this function from the course website and adapted it to my program
{
	return	((c == 'A') || (c == 'F') || (c == 'D') || (c == 'S') ||
			 (c == 'C') || (c == 'Z') || (c == 'M') || (c == 'X'));
}


char GetCommand()
// I got this function from the course website and adopted it to my program
{
   char cmd = GetAChar("\n\n>");	// Get a command character.
	
   while (!Legal(cmd))		// As long as it's not a legal command,
   {			        	// display menu and try again.
	cout << "\nIllegal command. Please, try again.";
	cmd = GetAChar("\n>");
   }
   return cmd;
}

int main()
{
    Playlist d;
    
    ShowMenu();                         // prints the menu for the first time
    
    char command;                       //to read the command entry by the user
    
    do
    {
        
        command = GetCommand();
        
        switch (command)
        {
            case 'A' :                          // to add a song
            {
                         
                char musicTitle[36];
                char musicArtist[21];
                Style musicCategory;
                int musicSize;
                
                char comand;
                int flag = 0;
                
                cout << "Enter title: ";
                cin.getline(musicTitle, 36);
                
                cout << "Enter artist: ";
                cin.getline(musicArtist, 21);
                
                do
                {
                    cout << "Enter category - (P)op, (R)ock, (A)lternative, (C)ountry, (H)iphop or Parod(Y): " << endl;
                    cin >> comand;
                
                    if(comand == 'P' || comand == 'p')
                    {
                        musicCategory = POP;
                        flag = 0;
                    }
                    else if(comand == 'R' || comand == 'r')
                    {
                        musicCategory = ROCK;
                        flag = 0;
                    }
                    else if(comand == 'A' || comand == 'a')
                    {
                        musicCategory = ALTERNATIVE;
                        flag = 0;
                    }
                    else if(comand == 'C' || comand == 'c')
                    {
                        musicCategory = COUNTRY;
                        flag = 0;
                    }
                    else if(comand == 'H' || comand == 'h')
                    {
                        musicCategory = HIPHOP;
                        flag = 0;
                    }
                    else if(comand == 'Y' || comand == 'y')
                    {
                        musicCategory = PARODY;
                        flag = 0;
                    }
                    else
                    {
                       cout << "\nInvalid Category entry. Please, try again." << endl;
                       flag = 1;
                        
                    }
            
                        
                } while(flag == 1);
        
                do
                {    
                    cout << "Enter size: ";
                    cin >> musicSize;
                        
                    if(musicSize < 0)
                        cout << "\nInvalid size entry. Please, try again." << endl;
                            
                } while(musicSize < 0);
                
                cout << "\n"; 
                
                d.AddSong(musicTitle, musicArtist, musicCategory, musicSize);
            }
            
            break;
            
            case 'F' :                                          // to find a song
            {
                char musicInfo[36];
                
                cout << "Please, insert the title or the artist for the search: ";
                cin.getline(musicInfo, 36);
                
                d.AdvanceSearch(musicInfo);
                
            }
            
            break;
            
            case 'D' :                                          // to delete a song
            {
                char musicTitle[36];
                
                cout << "Enter the title of the song: ";
                cin.getline(musicTitle, 36);
                
                d.DeleteSong(musicTitle);
                
            }
            break;
            
            case 'S' : d.Show();        break;              // to show a song
            
            case 'C' :                                      // to show summary by category
            {
                Style categorySummary;
                
                char comand;
                
                int flag = 0;
                
                do
                {
                    cout << "Enter category - (P)op, (R)ock, (A)lternative, (C)ountry, (H)iphop or Parod(Y): ";
                    cin >> comand;
                
                    if(comand == 'P' || comand == 'p')
                    {
                        categorySummary = POP;
                        flag = 0;
                    }
                    else if(comand == 'R' || comand == 'r')
                    {
                        categorySummary = ROCK;
                        flag = 0;
                    }
                    else if(comand == 'A' || comand == 'a')
                    {
                        categorySummary = ALTERNATIVE;
                        flag = 0;
                    }
                    else if(comand == 'C' || comand == 'c')
                    {
                        categorySummary = COUNTRY;
                        flag = 0;
                    }
                    else if(comand == 'H' || comand == 'h')
                    {
                        categorySummary = HIPHOP;
                        flag = 0;
                    }
                    else if(comand == 'Y' || comand == 'y')
                    {
                        categorySummary = PARODY;
                        flag = 0;
                    }
                    else
                    {
                       cout << "\nInvalid Category entry. Please, try again." << endl;
                       flag = 1;
                        
                    }
                } while(flag == 1);
                
                d.CategorySummary(categorySummary);
                
            }
            
            break;
            
            case 'Z' : d.SizeOf();      break;                      // to see size of the playlist in kbytes
            case 'M' : ShowMenu();      break;                      // show menu again
            case 'X' :                  break;                      // exit the program
            
        }
        
    }while (command != 'X');
    
    cout << "Bye bye!";
    
    return 0;
}