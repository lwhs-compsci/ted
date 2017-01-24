#include "cmmn.h"
#include "command.h"

int main(int argc, char* argv[]) {
	ted::command_parser p;
	while(true) {
		cout << ":";
		string ln; getline(cin, ln);
		auto cmd = p.parse(ln);
		if (cmd == nullptr) {
			cout << "unknown command: " << ln << endl;
		}
		else cmd->apply(nullptr);
	}
	return 0;
}
