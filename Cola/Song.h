#ifndef SONG_H
#define SONG_H
#include <sstream>
#include <iostream>
using namespace std;
class Song
{
	private:
		string name;
	    string interpreter;
	    string album;
	    float time;
	public:
		Song();
		Song(string, string, string, float);
		string toString();
		string get_name();
		string get_interpreter();
		string get_album();
		float get_time();
		
};

#endif
