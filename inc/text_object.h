#pragma once
#include "cmmn.h"

namespace ted {
	struct text_object {
		virtual ~text_object() {}
	};

	namespace text_objects {
		struct line : public text_object {
		};
		struct line_range : public text_object {
		};
	}
}
