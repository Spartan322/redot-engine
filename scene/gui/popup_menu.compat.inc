/**************************************************************************/
/*  popup_menu.compat.inc                                                 */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             REDOT ENGINE                               */
/*                        https://redotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2024-present Redot Engine contributors                   */
/*                                          (see REDOT_AUTHORS.md)        */
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

#ifndef DISABLE_DEPRECATED

void PopupMenu::_add_shortcut_bind_compat_36493(const Ref<Shortcut> &p_shortcut, int p_id, bool p_global) {
	add_shortcut(p_shortcut, p_id, p_global, false);
}

void PopupMenu::_add_icon_shortcut_bind_compat_36493(const Ref<Texture2D> &p_icon, const Ref<Shortcut> &p_shortcut, int p_id, bool p_global) {
	add_icon_shortcut(p_icon, p_shortcut, p_id, p_global, false);
}

void PopupMenu::_clear_bind_compat_79965() {
	clear(false);
}

void PopupMenu::_set_system_menu_root_compat_87452(const String &p_special) {
	if (p_special == "_dock") {
		set_system_menu(NativeMenu::DOCK_MENU_ID);
	} else if (p_special == "_apple") {
		set_system_menu(NativeMenu::APPLICATION_MENU_ID);
	} else if (p_special == "_window") {
		set_system_menu(NativeMenu::WINDOW_MENU_ID);
	} else if (p_special == "_help") {
		set_system_menu(NativeMenu::HELP_MENU_ID);
	}
}

String PopupMenu::_get_system_menu_root_compat_87452() const {
	switch (get_system_menu()) {
		case NativeMenu::APPLICATION_MENU_ID:
			return "_apple";
		case NativeMenu::WINDOW_MENU_ID:
			return "_window";
		case NativeMenu::HELP_MENU_ID:
			return "_help";
		case NativeMenu::DOCK_MENU_ID:
			return "_dock";
		default:
			return "";
	}
}

void PopupMenu::_bind_compatibility_methods() {
	ClassDB::bind_compatibility_method(D_METHOD("add_shortcut", "shortcut", "id", "global"), &PopupMenu::_add_shortcut_bind_compat_36493, DEFVAL(-1), DEFVAL(false));
	ClassDB::bind_compatibility_method(D_METHOD("add_icon_shortcut", "texture", "shortcut", "id", "global"), &PopupMenu::_add_icon_shortcut_bind_compat_36493, DEFVAL(-1), DEFVAL(false));
	ClassDB::bind_compatibility_method(D_METHOD("clear"), &PopupMenu::_clear_bind_compat_79965);

	ClassDB::bind_compatibility_method(D_METHOD("set_system_menu_root", "special"), &PopupMenu::_set_system_menu_root_compat_87452);
	ClassDB::bind_compatibility_method(D_METHOD("get_system_menu_root"), &PopupMenu::_get_system_menu_root_compat_87452);
}

#endif
