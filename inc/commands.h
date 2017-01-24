#pragma once
#include "command.h"

namespace ted {
	namespace commands {
		struct print_command : public command {
			print_command(unique_ptr<text_object>&& tr) : command(move(tr)) {}

			void apply(shared_ptr<buffer> buf) const override {
			}
		};

		struct quit_command : public command {
			quit_command() {}
			void apply(shared_ptr<buffer> buf) const override {
				exit(0);
			}
		};
	}
}
