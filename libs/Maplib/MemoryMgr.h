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

#ifndef MEMORYMGR_H_
#define MEMORYMGR_H_

//
// Define to track memory leaks
//
#ifdef _WIN32
#define TRACKOBJECTS
#endif

#include <ma.h>
#include <maheap.h>

#ifdef TRACKOBJECTS
#include <MAUtil/Map.h>
#include <MAUtil/Vector.h>
#include "DebugPrintf.h"
using namespace MAUtil;
#endif

namespace Util
{
	//=========================================================================
	class MemoryMgr
	//=========================================================================
	{
	public:
		template<class T>
		static T* track( T* p, const char* label )
		{
			#ifdef TRACKOBJECTS
			m_keys.add( p );
			m_values.add( label );
			#endif
			return p;
		}

		static void untrack( void* p )
		{
			#ifdef TRACKOBJECTS
			for ( int i = 0; i < m_keys.size( ); i++ )
			{
				if ( m_keys[i] == p )
				{
					m_keys.remove( i );
					m_values.remove( i );
					return;
				}
			}
			#endif
		}

		static void dump( )
		{
			#ifdef TRACKOBJECTS

			int count = m_keys.size( );
			DebugPrintf( "Dump: %d objects remaining\n", count );
			for ( int i = 0; i < count; i++ )
				DebugPrintf( "   %s\n", m_values[ i ] );

			#endif

		}

	private:
		#ifdef TRACKOBJECTS
		static Vector<void*> m_keys;
		static Vector<const char*> m_values;
		#endif
	};

#ifdef TRACKOBJECTS
	#define newobject( type, obj ) MemoryMgr::track<type>( (obj), #type"   ("__FUNCTION__")" )
	#define deleteobject( obj ) { if ( (obj) != NULL ) { MemoryMgr::untrack( obj ); delete (obj); (obj) = NULL; } }
#else
	#define newobject( type, obj ) ( obj )
	#define deleteobject( obj ) { if ( (obj) != NULL ) { delete (obj); (obj) = NULL; } }
#endif

}

#endif // MEMORYMGR_H_
