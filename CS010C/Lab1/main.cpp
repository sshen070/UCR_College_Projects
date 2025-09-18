#include <iostream>
#include <limits>
#include <string>

#include "Playlist.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::numeric_limits;
using std::string;
using std::streamsize;

void PrintMenu(const string& title) {
  cout << title << endl;
}

int main() {
  string title;
  string command;

  // Prompt for and read the title for the playlist (may contain spaces)
  cout << "Enter playlist's title:" << endl;
  cout << endl;
  getline(cin, title);

  // Build a playlist object with this title
  Playlist playlist(title);

    // Read the next "token".  Will stop on EOF or a q
  playlist.PrintMenu();
  while (cin >> command && command != "q") {
    // ignore characters until we get to a newline or end-of-file
  cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if (command == "a") { // Adds new song to Playlist
      string uniqueID, songName, artistName;
      int songLength;

      cout << "ADD SONG" << endl;

      cout << "Enter song's unique ID:" << endl;
      getline(cin, uniqueID);

      cout << "Enter song's name:" << endl;
      getline(cin, songName);

      cout << "Enter artist's name:" << endl;
      getline(cin, artistName);

      cout << "Enter song's length (in seconds):" << endl;
      cin >> songLength;
      cout << endl;

      cin.ignore(numeric_limits<streamsize>::max(),'\n');

      playlist.AddSong(uniqueID, songName, artistName, songLength);
    }

    else if (command == "d") { // Removes song from Playlist
      string uniqueID;
      
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      getline(cin, uniqueID);

      playlist.RemoveSong(uniqueID);
      cout << endl;
    }

    else if (command == "c") { // Changes position of song in Playlist
      int userCurrVal, userNewVal = 0;

      cout << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:" << endl;
      cin >> userCurrVal;
      cout << endl;

      cout << "Enter new position for song:" << endl;
      cin >> userCurrVal;
      cout << endl;
      playlist.ChangeQueueOrder(userCurrVal, userNewVal);
      cout << endl;
    }

    else if (command == "s") { // Outputs songs by Specific Artist
        string artist;

        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl;
        getline(cin, artist);

        cout << endl;
        playlist.PrintByArtist(artist);
    }

    else if (command == "t") { // Outputs total time in playlist (in seconds)
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      cout << "Total time: " << playlist.PlaylistTimeInSec() << " seconds" << endl;
      cout << endl;
    }

    else if (command == "o") { // Outputs full playlist
      playlist.OutputFullPlaylist();
    }

    // Repeat the menu and wait for another command
    playlist.PrintMenu();
  }

  return 0;
}
