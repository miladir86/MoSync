/* Copyright (C) 2010 Mobile Sorcery AB

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.
*/

#ifndef SOFTKEYBAR_H_
#define SOFTKEYBAR_H_

#include <MAUI/Layout.h>
#include <MAUI/Font.h>
#include <MAUI/Label.h>

#include "Action.h"
//#include "MemoryMgr.h"

using namespace MAUI;
using namespace Util;

namespace UI
{
	//=========================================================================
	class SoftKeyBar : public Layout
	//=========================================================================
	{
	public:
							SoftKeyBar( int x, int y, int width, int height, Widget* parent );
		virtual				~SoftKeyBar( );
		//
		// Widget overrides
		//
		virtual void		setWidth( int width );
		virtual void		setHeight( int height );
		//
		// Key handling
		//
		virtual bool		handleKeyPress( int keyCode );
		virtual bool		handleKeyRelease( int keyCode );
		//
		// Actions
		//
		virtual Action*		getLeftAction( ) const;
		virtual void		setLeftAction( Action* action );
		virtual Action*		getRightAction( ) const;
		virtual void		setRightAction( Action* action );

	private:
		Label*				m_leftLabel;
		Label*				m_rightLabel;
		Action*				m_leftAction;
		Action*				m_rightAction;
		Font*				m_font;
	};
}

#endif // SOFTKEYBAR_H_
