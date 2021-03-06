//
// C++ Interface: OrientationAdapter
//
// Description: 
//
//
// Author: Erik Ogenvik <erik@ogenvik.org>, (C) 2007
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.//
//
#ifndef EMBEROGRE_GUI_ADAPTERS_ATLASORIENTATIONADAPTER_H
#define EMBEROGRE_GUI_ADAPTERS_ATLASORIENTATIONADAPTER_H

#include "AdapterBase.h"

namespace Ember {
namespace OgreView {

namespace Gui {

namespace Adapters {

namespace Atlas {

/**
	@author Erik Ogenvik <erik@ogenvik.org>
*/
class OrientationAdapter : public AdapterBase
{
public:
    OrientationAdapter(const ::Atlas::Message::Element& element, CEGUI::Window* xWindow, CEGUI::Window* yWindow, CEGUI::Window* zWindow, CEGUI::Window* scalarWindow);

    virtual ~OrientationAdapter();
	
	/**
	Updates the gui with new values.
	*/
	virtual void updateGui(const ::Atlas::Message::Element& element);
	
protected:
	CEGUI::Window* mXWindow;
	CEGUI::Window* mYWindow;
	CEGUI::Window* mZWindow;
	CEGUI::Window* mScalarWindow;
	
	bool window_TextChanged(const CEGUI::EventArgs& e);

	virtual void fillElementFromGui();
	virtual bool _hasChanges();
};

}

}

}

}

}

#endif
