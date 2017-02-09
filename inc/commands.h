#pragma once
#include "command.h"

namespace ted {
	namespace commands {
		struct print_command : public command {
			print_command(unique_ptr<text_object>&& tr) : command(move(tr)) {}

			void apply(buffer& buf) const override {
				buf.all_lines_in(target.get(), [&](size_t i, buffer::const_line_t line) {
					cout << i << ": " << *line << endl;
				});
			}
		};

		struct quit_command : public command {
			quit_command() {}
			void apply(buffer& buf) const override {
				exit(0);
			}
		};
	}
}
