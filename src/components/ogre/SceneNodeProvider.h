/*
 Copyright (C) 2009 Erik Ogenvik <erik@ogenvik.org>

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

#ifndef SCENENODEPROVIDER_H_
#define SCENENODEPROVIDER_H_

#include "INodeProvider.h"

namespace Ogre
{
class SceneNode;
class MovableObject;
}

namespace Ember
{
namespace OgreView
{

class SceneNodeProvider: public INodeProvider
{
public:
	SceneNodeProvider(Ogre::SceneNode& parentNode, const std::string& name, Ogre::MovableObject* object = 0);
	virtual ~SceneNodeProvider();
	virtual Ogre::Node& getNode() const;
	virtual Ogre::Node* getParentNode() const;
	virtual INodeProvider* createChildProvider(const std::string& name, Ogre::MovableObject* attachedObject = 0);
	virtual void setVisible(bool visible);

	/**
	 * General method for turning on and off debug visualizations. Subclasses might support more types of visualizations than the ones defined here.
	 * @param visualization The type of visualization. Currently supports "OgreBBox".
	 * @param visualize Whether to visualize or not.
	 */
	virtual void setVisualize(const std::string& visualization, bool visualize);

	/**
	 * @brief Gets whether a certain visualization is turned on or off.
	 * @param visualization The type of visualization. Currently supports "OgreBBox".
	 * @return true if visualization is turned on, else false
	 */
	virtual bool getVisualize(const std::string& visualization) const;

	/**
	 * @brief Sets the position and orientation of the node.
	 * @param position The position.
	 * @param orientation The orientation.
	 */
	virtual void setPositionAndOrientation(const Ogre::Vector3& position, const Ogre::Quaternion& orientation);

protected:

	Ogre::SceneNode& mParentNode;
	Ogre::SceneNode* mNode;
	Ogre::MovableObject* mAttachedObject;
};

}

}

#endif /* SCENENODEPROVIDER_H_ */
