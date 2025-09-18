// #pragma unique
#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <string>

class PlaylistNode {
 private:
  // PlaylistNode Class memeber variables
  std::string uniqueID;
  std::string songName; 
  std::string artistName; 
  int songLength;
  PlaylistNode* nextNodePtr;

 public:
  // Default Constructor
  PlaylistNode();

  // Parameterized Constructor
  PlaylistNode(const std::string&, const std::string&, const std::string&, int);

  // Destructor
  ~PlaylistNode();

  // Copy Constructor
  PlaylistNode(const PlaylistNode&);

  // Copy Assignment Operator 
  PlaylistNode& operator=(const PlaylistNode&) = delete;
  
  //PlaylistNode Class Member Functions
  void InsertAfter(PlaylistNode*);
  void SetNext(PlaylistNode*);
  std::string GetID() const;
  std::string GetSongName() const;
  std::string GetArtistName() const;
  int GetSongLength() const;
  PlaylistNode* GetNext() const;
  void PrintPlaylistNode() const;
};

class Playlist {
 private:
 // Playlist Class member variables
  PlaylistNode* head = nullptr;
  PlaylistNode* tail = nullptr;
  std::string playlistTitle;
 public:
  // Default Constructor
  Playlist();

  // Parameterized Constructor
  Playlist(const std::string&);

  // Destructor
  ~Playlist();

  // Copy Constructor
  Playlist(const Playlist&);

  // Copy Assignment Operator
  Playlist& operator=(const Playlist&) = delete;

  // Playlist Class Member Functions
  void PrintMenu() const;
  void OutputFullPlaylist() const;
  void AddSong(const std::string&, const std::string&, const std::string&, int);
  void RemoveSong(const std::string&);
  void ChangeQueueOrder(int, int);
  void ChangePosition();
  void PrintByArtist(const std::string&) const;
  int PlaylistTimeInSec() const;
};
 
 #endif