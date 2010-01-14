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

#ifndef ACTION_H_
#define ACTION_H_

#include "ICloneable.h"

using namespace Util;

namespace UI
{
	//
	// Abstract
	//
	class Action : ICloneable<Action>
	{
	public:
		//
		// Constructor/destructor
		//
								Action( ) { }
		virtual					~Action( ) { }
		//
		// Public methods
		//
		void					perform( ) { performPrim( ); }
		//
		// Pure virtual for client to implement
		//
		virtual const char*		getShortName( ) const = 0;
		virtual Action*			clone( ) const = 0;

	protected:
		//
		// Protected pure virtual for client to implement
		//
		virtual void			performPrim( ) = 0;
	};
}

#endif /* ACTION_H_ */
