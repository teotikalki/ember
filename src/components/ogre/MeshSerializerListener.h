//
// C++ Interface: MeshSerializerListener
//
// Description: 
//
//
// Author: Erik Ogenvik <erik@ogenvik.org>, (C) 2009
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
#ifndef EMBEROGREMESHSERIALIZERLISTENER_H
#define EMBEROGREMESHSERIALIZERLISTENER_H

#include <OgreMeshSerializer.h>

namespace Ember {
namespace OgreView {

/**
@brief Allows the usage of relative skeleton names.

@author Erik Ogenvik <erik@ogenvik.org>
*/
class MeshSerializerListener : public Ogre::MeshSerializerListener
{
public:
	/**
	 * @brief Ctor.
	 * @param requireTangents True if tangents should be created if missing.
	 */
    MeshSerializerListener(bool requireTangents);

    ~MeshSerializerListener();
    
	virtual void processMaterialName(Ogre::Mesh *mesh, Ogre::String *name);
	virtual void processSkeletonName(Ogre::Mesh *mesh, Ogre::String *name);
	virtual void processMeshCompleted(Ogre::Mesh*);
private:

	/**
	 * If true, meshes should have tangents. If a mesh if found without tangents an attempt to generate ones from the existing mesh data will be performed.
	 */
	bool mRequireTangents;
};

}

}

#endif
