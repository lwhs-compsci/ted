#pragma once
#include "cmmn.h"
#include "buffer.h"
#include "text_object.h"

namespace ted {
	struct command {
		unique_ptr<text_object> target;
		unique_ptr<string> payload;
		virtual void apply(shared_ptr<buffer> buf) const;
		virtual ~command() {}
	};

	struct command_parser {
		unique_ptr<command> parse(const string& str);
	};
}
