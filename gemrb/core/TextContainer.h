/* GemRB - Infinity Engine Emulator
 * Copyright (C) 2014 The GemRB Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef TEXTCONTAINER_H
#define TEXTCONTAINER_H

#include "Region.h"

#include <list>
#include <string>

typedef std::string String;

namespace GemRB {

class Font;
class Palette;

class TextSpan
{
private:
	String text;
	Font* font;
	Palette* pal;
public:
	// construct a "inline" span that calculates its own region based on font, palette, and string
	TextSpan(const String& string, const Font* font, const Palette* pal);
	// construct a "block" span with dimentions determined by rgn
	TextSpan(const String& string, const Font* font, const Palette* pal, const Region& rgn);
	~TextSpan();
};

class TextContainer
{
	std::list<TextSpan*> spans;
	Region frame;
	Font* font;
	Palette* pallete;
public:
	TextContainer(Region& frame, const Font* font, const Palette* pal);
	~TextContainer();

	// Creates a basic "inline" span using the containers font/palette
	void AppendText(const String& text);
	void AppendSpan(TextSpan* span);
};

}
#endif