#pragma once
#include "cmmn.h"
#include "text_object.h"

namespace ted {
	struct buffer {
		string path;
		typedef string line_data_t;
		list<line_data_t> lines; //this is preliminary, there may be a better data structure
		typedef list<line_data_t>::iterator line_t;
		typedef list<line_data_t>::const_iterator const_line_t;
		line_t current_line;

		buffer() : current_line(lines.begin()) {}
		buffer(const string& path);

		void all_lines_in(text_object* tr, function<void(size_t, const_line_t)> f) const {
			switch (tr->type) {
			case text_object::line: {
				auto l = (text_objects::line*)tr;
				auto L = lines.begin();
				for (size_t i = 0; i < l->offset; ++i, L++);
				f(l->offset, L);
			} break;
			case text_object::line_range: {
				auto lr = (text_objects::line_range*)tr;
				auto L = lines.begin();
				for (size_t i = 0; i < lr->offset; ++i, L++);
				for (size_t i = 0; i < lr->size; ++i, L++) f(i + lr->offset, L);
			} break;
			}
		}

		void insert_at(text_object* tr, const string& pld) {
			switch (tr->type) {
			case text_object::line:
			case text_object::line_range: {
				auto ix = ((text_objects::line*)tr)->offset;
				auto L = lines.begin();
				for (; ix > 0; --ix) L++;
				lines.insert(L, pld);
			} break;
			}
		}

		void write();

		
	};
}
