#pragma once
#include "cmmn.h"
#include "buffer.h"
#include "text_object.h"

namespace ted {
	struct command {
		unique_ptr<text_object> target;
		unique_ptr<string> payload;
		virtual void apply(buffer& buf) const = 0;
		virtual ~command() {}
	protected:
		command(unique_ptr<text_object>&& tr = nullptr, unique_ptr<string>&& pld = nullptr) : target(move(tr)), payload(move(pld)) {}
	};

	class command_parser {
		size_t parse_number(const string& str, size_t& i);
		unique_ptr<text_object> parse_text_object(const string& str, size_t& i);
	public:
		unique_ptr<command> parse(const string& str);
	};
}
