#include "Playlist.h"

#include <iostream>
#include <string>

// Default Constructor - updates the member variables type string to "none", type int to 0, and pointers to 0 in the case that any of the arguments aren't passed in the function call
PlaylistNode::PlaylistNode(): uniqueID("none") , songName("none"), artistName("none"), songLength(0), nextNodePtr(0){}

// Parameterized Constructor - the four values must be provided in the argument of the function call to work
PlaylistNode::PlaylistNode(const std::string& uUniqueID, const std::string& uSongName, const std::string& uArtistName, int uSongLength){
  uniqueID = uUniqueID;
  songName = uSongName;
  artistName = uArtistName;
  songLength = uSongLength;
  nextNodePtr = nullptr;
}

// Destructor 
PlaylistNode::~PlaylistNode(){}

// Copy Constructor - copies the values from the original node to the new node
PlaylistNode::PlaylistNode(const PlaylistNode& cpy){
  uniqueID = cpy.uniqueID;
  songName = cpy.songName;
  artistName = cpy.artistName;
  songLength = cpy.songLength;
  nextNodePtr = nullptr;
}

// PlaylistNode Member Functions

// Inserts the node before the next node after the implict parameter (node) by setting its nextPtr to the node after
// Then uses setNext to set itself after the implict parameter (node) in the list
void PlaylistNode::InsertAfter(PlaylistNode* insertNode){
  PlaylistNode *afterInsertNode = nextNodePtr;
  insertNode -> nextNodePtr = afterInsertNode;
  SetNext(insertNode);
}

// Sets the next pointer of the implicit parameter to the node passed in
void PlaylistNode::SetNext(PlaylistNode* nextNode){
  nextNodePtr = nextNode;
}

// Returns ID data member of the node
std::string PlaylistNode::GetID() const{
  return uniqueID;
}

// Returns songName of the node
std::string PlaylistNode::GetSongName() const{
  return songName;
}

// Returns artistName saved in the node
std::string PlaylistNode::GetArtistName() const{
  return artistName;
}

// Returns song length of the node
int PlaylistNode::GetSongLength() const{
  return songLength;
}

// Returns the node the implict parameter (node) is pointing to
PlaylistNode* PlaylistNode::GetNext() const{
  return nextNodePtr;
}

//Prints out the values of all member variables
void PlaylistNode::PrintPlaylistNode() const{
  std::cout << "Unique ID: " << uniqueID << std::endl;
  std::cout << "Song Name: " << songName << std::endl;
  std::cout << "Artist Name: " << artistName << std::endl;
  std::cout << "Song Length (in seconds): " << songLength << std::endl;
  std::cout << std::endl;
}


// Default Constructor for Playlist Class -> if no title provided in argument then sets title to "none" 
Playlist::Playlist(): playlistTitle("none"){};

// Parameterized Constructor sets the user input passed in to the data held in the title member variable
Playlist::Playlist(const std::string& title){
  playlistTitle = title;
}

// Destructor - removes all the nodes in the linked list
Playlist::~Playlist(){
  PlaylistNode* currNode = head;
  PlaylistNode* nextNode = nullptr;
  
  // Continues to delete nodes until no nodes left
  while(currNode != nullptr){ 
    nextNode = currNode -> GetNext();
    delete currNode;
    currNode = nextNode;
  }
  // Set head + tail to nullptr to ensure no dangling pointers
  head = nullptr;
  tail = nullptr;
}

// Copy Constructor
Playlist::Playlist(const Playlist& cpy){
  head = nullptr;
  tail = nullptr; 
  PlaylistNode* cpyNode = cpy.head; // Sets cpyNode to the head to make it easier to traverse and copy the nodes
  // Keeps copying nodes until there are no more nodes to copy
  while(cpyNode != nullptr){
    PlaylistNode* newNode = new PlaylistNode(cpyNode -> GetID(), cpyNode -> GetSongName(), cpyNode -> GetArtistName(), cpyNode -> GetSongLength());
    // Edge case where if there are no node yet, then head and tail will both point to the new node
    if (head == nullptr){
      head = newNode;
      tail = newNode;
    }
    // Otherwise node will be added to the end of the list
    else {
      tail -> SetNext(newNode);
      tail = newNode;
    }
    cpyNode = cpyNode -> GetNext(); // Moves to next node that needs to be copied
  }
}

// Playlist Member Functions

// Prints out the options the user has to modify their playlist
void Playlist::PrintMenu() const{
  std::cout << playlistTitle << " PLAYLIST MENU" << std::endl;
  std::cout << "a - Add song" << std::endl;
  std::cout << "d - Remove song" << std::endl;
  std::cout << "c - Change position of song" << std::endl;
  std::cout << "s - Output songs by specific artist" << std::endl;
  std::cout << "t - Output total time of playlist (in seconds)" << std::endl;
  std::cout << "o - Output full playlist" << std::endl;
  std::cout << "q - Quit" << std::endl << std::endl;
  std::cout << "Choose an option:" << std::endl;
}

// Outputs the full playlist created by the user
void Playlist::OutputFullPlaylist() const{
  std::cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << std::endl;
  
  // Checks if there are any nodes created in the playlist, if not -> prints the playlist is empty
  if (head == nullptr){
    std::cout << "Playlist is empty" << std::endl;
    std::cout << std::endl;
  }

  // Otherwise traverses through linked list and prints out all of the values saved in the node
  else{
    PlaylistNode *node = head;
    int nodeTracker = 1;
    
    // Traverses only if the current node is not nullptr
    while (node != nullptr){
      std::cout << nodeTracker << "." << std::endl; 
      node -> PrintPlaylistNode();
      node = node -> GetNext(); // Changes the node to the next to continue traversing
      nodeTracker++; // Records how many nodes have been traversed to number them in the output
    }
  }
}

// Adds a new song to the playlist after the tail node if the playlist already contains a node
void Playlist::AddSong(const std::string& uUniqueID, const std::string &uSongName, const std::string &uArtistName, int uSongLength){
    PlaylistNode *addNode = new PlaylistNode(uUniqueID, uSongName, uArtistName, uSongLength); // Creates a new node based on user input

    // If head == nullptr, the playlist is empty. Adding a node makes it the only node -> head & tail point to it 
    if (head == nullptr){
      head = addNode;
      tail = addNode;
    }
    // Otherwise add the node to the end of the list and set the tail to the node
    else{
      tail -> InsertAfter(addNode);
      tail = addNode;
    }
}

void Playlist::RemoveSong(const std::string& uniqueID){
  // If head == nullptr, there are no songs in playlist -> nothing to remove
  if (head == nullptr){
    std::cout << "Song with unique ID " << uniqueID << " not found!" << std::endl;
    return;
  }

  PlaylistNode *prevNode = nullptr;
  PlaylistNode *currNode = head;

  // Traverses through linked list while currNode != nullptr and its ID doesn't match with the user input
  // After loop ends, if match is found -> function continues. If not -> return nullptr
  while (currNode && currNode -> GetID() != uniqueID){
    prevNode = currNode;
    currNode = currNode -> GetNext();
  }

  // After traversing if currNode == nullptr then the node containing uniqueID is not part of the list
  // Prints out whether on not the node with the uniqueID was found and remvoed in each of the conditionals
  if (currNode != nullptr){
    // Edge cases if the currNode is the first or last node in the linked list
    if (currNode == head){
      head = head -> GetNext();
      std::cout << '"' << currNode -> GetSongName() << '"' << " removed." << std::endl;
      delete currNode;
      return;
    }
    else if (currNode == tail){
      tail = prevNode;
      std::cout << '"' << currNode -> GetSongName() << '"' << " removed." << std::endl;
      delete currNode;
      return;
    }
    // After printing node's status, node is deleted
    // If currNode is in the middle of the list -> connect the prevNode with the node after the currNode
    else{
      PlaylistNode* saveNextNode = currNode -> GetNext();
      prevNode -> SetNext(saveNextNode);
      std::cout << '"' << currNode -> GetSongName() << '"' << " removed." << std::endl;
      delete currNode;
      return;
    }
  }
  std::cout << "Song with unique ID " << uniqueID << " not found!" << std::endl; // If node could not be found with matching ID
}

void Playlist::ChangeQueueOrder(int initialPos, int finalPos){
  // If either of these conditions is true (no songs, only one song, no postion change), there is no need to change the order of the queue
  if (head == nullptr || head == tail || initialPos == finalPos){  
    return;
  }

  PlaylistNode* prevNode = nullptr;
  PlaylistNode* currNode = head;
  int nodeTracker = 1;
  
  // Traverses list until the initial position entered is reached on the linked list
  // Sets currNode to the node in the position + increments the traversal tracker
  while (currNode && nodeTracker < initialPos){
    prevNode = currNode;
    currNode = currNode -> GetNext();
    nodeTracker++;
  }
  
  // If the  initial position is larger than the positions available in the list -> don't know which node to switch 
  if (currNode == nullptr){
    std::cout << "Invalid current position" << std::endl;
    return;
  }

  // If the node is the head of the list, head must become the next node so that the currNode can be moved
  if (currNode == head){
    head = currNode -> GetNext();
  }
  // Sets the prevNode to point to the node after currNode to bridge the gap from moving currNode 
  else{
    PlaylistNode* saveNextNode = currNode -> GetNext();
    prevNode -> SetNext(saveNextNode);

    // In the case currNode is the last node in the list, make tail the prevNode
    if (currNode == tail){
      tail = prevNode;
    }
  }

  // If the final position entered is smaller or equal to 1, move the currNode to the front of the list
  if (finalPos <= 1){
    PlaylistNode* firstNode = head;
    currNode -> SetNext(firstNode);
    head = currNode;
    return;
  }

  // Extra set of nodes to keep track of the values near the insert location 
  PlaylistNode* nodeBeforeInsert = nullptr;
  PlaylistNode* nodeAfterInsert = head;
  nodeTracker = 1;

  // Traverses to the final position
  // Uses tracker to count up to the position
  while (nodeAfterInsert && nodeTracker < finalPos){
    nodeBeforeInsert = nodeAfterInsert;
    nodeAfterInsert = nodeAfterInsert -> GetNext();
    nodeTracker++;
  }

  // If the node being moved is going to be inserted at the end, currNode must become the tail
  if (nodeAfterInsert == nullptr){
    PlaylistNode* lastNode = tail;
    lastNode -> SetNext(currNode);
    currNode = tail;
    currNode->SetNext(nullptr);
  }
  // Inserted node is place between the nodes that traversed to the final position
  else{
    currNode -> SetNext(nodeAfterInsert);
    nodeBeforeInsert -> SetNext(currNode);
  }
  std::cout << '"' << currNode -> GetSongName()  << '"' << " moved to position" << finalPos << std::endl; // Prints out the name of the song that was moved at the end of the function
}

// Prints all songs by the same artist
void Playlist::PrintByArtist(const std::string &artist) const{
  // If no songs in playlist, return nothing
  if (head == nullptr){
    return; 
  } 

  PlaylistNode* currNode = head;
  int nodeTracker = 1;

  // Traverses through the linked list
  while (currNode){
    // If the artist name stored by the node matched the artist passed in, prints out the node
    if (currNode -> GetArtistName() == artist){
      std::cout << nodeTracker << "." << std::endl; 
      currNode -> PrintPlaylistNode();
    }
    nodeTracker++; // increments to print number them sequentially
    currNode = currNode -> GetNext();
  }
}

// Adds up the time of each song and return the total time
int Playlist::PlaylistTimeInSec() const{

  int totalPlayTime = 0;
  PlaylistNode* currNode = head; // set to head for easy traversal
  // Traverses until the end of the list
  while (currNode){
    totalPlayTime += currNode -> GetSongLength(); // Adds the length of every song in sec
    currNode = currNode -> GetNext();
  }
  return totalPlayTime;
}