#pragma once
#include "cmmn.h"

namespace ted {
	struct buffer {
		string path;
		list<string> lines; //this is preliminary, there may be a better data structure
		list<string>::iterator current_line;

		buffer();
		buffer(const string& path);

		void write();

		
	};
}
