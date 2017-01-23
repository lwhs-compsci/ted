#include "cmmn.h"
#include "command.h"

int main(int argc, char* argv[]) {
	ted::command_parser p;
	while(true) {
		string ln; getline(cin, ln);
		auto cmd = p.parse(ln);	
	}
	return 0;
}
