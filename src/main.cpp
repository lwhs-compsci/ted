#include "cmmn.h"
#include "command.h"

int main(int argc, char* argv[]) {
	ted::command_parser p;
	ted::buffer b;
	b.lines.push_front("hello, world!");
	b.lines.push_front("hello, ted!");
	b.lines.push_front("hello, LW!");
	b.lines.push_front("hello, Zach!");
	while(true) {
		cout << ":";
		string ln; getline(cin, ln);
		auto cmd = p.parse(ln);
		if (cmd == nullptr) {
			cout << "unknown command: " << ln << endl;
		}
		else cmd->apply(b);
	}
	return 0;
}
