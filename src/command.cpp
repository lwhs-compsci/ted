#include "command.h"
#include "commands.h"

namespace ted {
	size_t command_parser::parse_number(const string& str, size_t& i) {
		string s;
		while(i < str.size() && isdigit(i)) s += str[i];
		return atoll(s.c_str());
	}
	unique_ptr<text_object> command_parser::parse_text_object(const string& str, size_t& i) {
		if(isdigit(str[i])) {
			size_t o = parse_number(str, i);
			if(str[i] == ':') {
				size_t e = parse_number(str, i);
				if(e < o) throw;
				return make_unique<text_objects::line_range>(o, e-o);
			}
			return make_unique<text_objects::line>(o);
		}
		return nullptr;
	}

	unique_ptr<command> command_parser::parse(const string& str) {
		size_t i = 0;
		auto fto = parse_text_object(str, i);
		if(fto != nullptr) { return make_unique<commands::print_command>(move(fto)); }
		auto next_space = str.find_first_of(' ');
		string kwd = str.substr(i, i-next_space);
		cout << "found keyword  " << kwd << endl;
		return nullptr;
	}
}
