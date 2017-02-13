#pragma once
#include "cmmn.h"

namespace ted {
	struct text_object {
		enum type_t {
			line, line_range
		} type;
		virtual ~text_object() {}
	protected:
		text_object(type_t t) : type(t) {}
	};

	namespace text_objects {
		struct line : public text_object {
			size_t offset;

			line(size_t o = 0) : offset(o), text_object(type_t::line) {}
		};
		struct line_range : public text_object {
			size_t offset, size;
			line_range(size_t of, size_t s) : offset(of), size(s), text_object(type_t::line_range) {}
		};
	}


}
