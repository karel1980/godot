/**************************************************************************/
/*  test_rich_text_label.h                                                       */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef TEST_RICH_TEXT_LABEL_H
#define TEST_RICH_TEXT_LABEL_H

#include "scene/gui/rich_text_label.h"

#include "tests/test_macros.h"

namespace TestRichTextLabel {

TEST_CASE("[SceneTree][RichTextLabel] line wrapping") {
	RichTextLabel *rich_text_label = memnew(RichTextLabel);
	SceneTree::get_singleton()->get_root()->add_child(rich_text_label);
	rich_text_label->grab_focus();

	// Set size for boundary.
	rich_text_label->set_size(Size2(800, 200));
	rich_text_label->set_text("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec vasius mattis leo, sed porta ex lacinia bibendum. Nunc bibendum pellentesque.");
	CHECK(rich_text_label->get_text() == "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec vasius mattis leo, sed porta ex lacinia bibendum. Nunc bibendum pellentesque.");
	CHECK(rich_text_label->get_content_height() == 46);

	// Set size for boundary.
	rich_text_label->set_size(Size2(800, 200));
	rich_text_label->set_text("L.");
	CHECK(rich_text_label->get_text() == "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec vasius mattis leo, sed porta ex lacinia bibendum. Nunc bibendum pellentesque.");
	CHECK(rich_text_label->get_content_height() == 23);

	// SIGNAL_WATCH(text_edit, "text_set");
	// SIGNAL_WATCH(text_edit, "text_changed");
	// SIGNAL_WATCH(text_edit, "lines_edited_from");
	// SIGNAL_WATCH(text_edit, "caret_changed");

	// text_edit->set_line_wrapping_mode(TextEdit::LineWrappingMode::LINE_WRAPPING_BOUNDARY);
	// SIGNAL_CHECK_FALSE("text_set");
	// SIGNAL_CHECK_FALSE("text_changed");
	// SIGNAL_CHECK_FALSE("lines_edited_from");
	// SIGNAL_CHECK_FALSE("caret_changed");

	// CHECK(text_edit->is_line_wrapped(0));
	// CHECK(text_edit->get_line_wrap_count(0) == 1);
	// CHECK(text_edit->get_line_wrap_index_at_column(0, 130) == 1);
	// CHECK(text_edit->get_line_wrapped_text(0).size() == 2);

	// SIGNAL_UNWATCH(text_edit, "text_set");
	// SIGNAL_UNWATCH(text_edit, "text_changed");
	// SIGNAL_UNWATCH(text_edit, "lines_edited_from");
	// SIGNAL_UNWATCH(text_edit, "caret_changed");

	// ERR_PRINT_OFF;
	// CHECK_FALSE(text_edit->is_line_wrapped(-1));
	// CHECK_FALSE(text_edit->is_line_wrapped(1));
	// CHECK(text_edit->get_line_wrap_count(-1) == 0);
	// CHECK(text_edit->get_line_wrap_count(1) == 0);
	// CHECK(text_edit->get_line_wrap_index_at_column(-1, 0) == 0);
	// CHECK(text_edit->get_line_wrap_index_at_column(0, -1) == 0);
	// CHECK(text_edit->get_line_wrap_index_at_column(1, 0) == 0);
	// CHECK(text_edit->get_line_wrap_index_at_column(0, 10000) == 0);
	// CHECK(text_edit->get_line_wrapped_text(-1).size() == 0);
	// CHECK(text_edit->get_line_wrapped_text(1).size() == 0);
	// ERR_PRINT_ON;

	memdelete(rich_text_label);
}


} // namespace RichTextLabel

#endif // TEST_RICH_TEXT_LABEL_H
