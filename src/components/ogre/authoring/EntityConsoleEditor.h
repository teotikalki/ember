/*
 Copyright (C) 2016 erik

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef COMPONENTS_OGRE_AUTHORING_ENTITYCONSOLEEDITOR_H_
#define COMPONENTS_OGRE_AUTHORING_ENTITYCONSOLEEDITOR_H_

#include "framework/ConsoleCommandWrapper.h"
#include "framework/ConsoleObject.h"

namespace Ember
{
namespace OgreView
{
namespace Authoring
{

class EntityConsoleEditor : public ConsoleObject
{
public:
	EntityConsoleEditor();
	virtual ~EntityConsoleEditor();

	/**
	 * @copydoc ConsoleObject::runCommand
	 */
	virtual void runCommand(const std::string &command, const std::string &args);

	/**
	 * @brief Command for settings property on an entity.
	 */
	const ConsoleCommandWrapper SetProperty;
};

}
}
}
#endif /* COMPONENTS_OGRE_AUTHORING_ENTITYCONSOLEEDITOR_H_ */
