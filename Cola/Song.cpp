#include "Song.h"
Song::Song(string name_,string interpreter_,string album_, float time_){
	name=name_;
	interpreter=interpreter_;
	album=album_;
	time=time_;
}
Song::Song(){
	name="";
	interpreter="";
	album="";
	time=0;
}
string Song::toString(){
	stringstream s;
	s<<"........................................."<<endl;
	s<<"Name:        "<<name<<endl;
	s<<"Interpreter: "<<interpreter<<endl;
	s<<"Album:       "<<album<<endl;
	s<<"Time:        "<<time<<endl;

	return s.str();
}
string Song::get_name(){
	return name;
}
string Song::get_interpreter(){
	return interpreter;
}
string Song::get_album(){
	return album;
}
float Song::get_time(){
	return time;
}
		
